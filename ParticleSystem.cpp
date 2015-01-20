#include "ParticleSystem.h"
#define side 0.04
#define ppedge 5
#define dt 0.002
#define rest_density 1000.0f
#define pressure_stiffness 3.0f
#define viscosity_mu 0.0f
#define kernel_part 25
#define gravity -10.0f

// https://aulavirtual.uv.es/dotlrn/classes/c033/34864/c15c033a34864gA/file-storage/view/public/temasclase/tema4/sph/init_sph.cpp
// https://aulavirtual.uv.es/dotlrn/classes/c033/34864/c15c033a34864gA/file-storage/view/public/temasclase/tema4/sph/kelager.06.pdf
// https://aulavirtual.uv.es/dotlrn/classes/c033/34864/c15c033a34864gA/file-storage/view/public/temasclase/tema4/sph/Salida_1_step.txt

ParticleSystem::ParticleSystem(ofVec3f origen){
	ofLogToFile("logfile.txt", true);

	float inc = side/ppedge;
	int index_count = 0;
	float volume = side*side*side;
	num_particles = (int) pow(ppedge,3.0);
	particle_mass = rest_density*volume/num_particles;

	float radio = pow((3*particle_mass)/(4*PI*rest_density),1.0f/3.0f); // 5.19

	smoothing_length = pow((3*volume*kernel_part)/(4*PI*num_particles),1.0f/3.0f);// 5.14
	
	ofLog() << "dt " << dt << endl;
	ofLog() << "num_particles " << num_particles << endl;
	ofLog() << "mass " << particle_mass << endl;
	ofLog() << "smoothing " << smoothing_length << endl;
	ofLog() << "HashTable " << nextPrime(num_particles*2) << endl;
	ofLog() << "Radio " << radio << endl;

	kernel = new Kernels(smoothing_length);
	t = new HashTable(nextPrime(num_particles*2),smoothing_length);

	for (int i = 0; i < ppedge; i++){
		for (int j = 0; j < ppedge; j++){
			for (int k = 0; k < ppedge; k++){
				particulas.push_back(new Particle(ofVec3f(origen.x+i*inc,origen.y+j*inc,origen.z+k*inc),particle_mass,index_count,radio));
				index_count++;
			}
		}
	}
	
	frame=false;
}

void ParticleSystem::update()
{   
	
	if(!frame){
		t->limpiar();
		
		for(int i=0; i<particulas.size(); i++){
			t->insertar(particulas[i]->pos, i);
		}
		ofLog() << "index | neighbors size " << endl;
		for(int i=0; i<particulas.size(); i++){
			particulas[i]->neighbors = t->getVecinos(particulas[i]->pos);
			ofLog() << i << " " << particulas[i]->neighbors.size() << endl;
		}

		//Reset parameters
		for (int i = 0; i < particulas.size(); i++){
			particulas[i]->forces = ofVec3f(0);
			particulas[i]->acc = ofVec3f(0);
			particulas[i]->density = 0;
		}
		ofLog() << "index | density | pressure";
		//Compute density and pressure
		for (int i = 0; i < particulas.size(); i++){
			for (int j = 0; j< particulas.size(); j++){
				//Density
				float r = particulas[j]->pos.distance(particulas[i]->pos);
				if(r < smoothing_length){
					particulas[i]->density += particulas[j]->mass * kernel->poly6(r); 
				}
			}
			//Pressure
			particulas[i]->pressure = pressure_stiffness * (particulas[i]->density - rest_density); 
			ofLog() << particulas[i]->index << " "<< particulas[i]->density << " " << particulas[i]->pressure << endl;
		}
		//Compute internal forces
		ofLog() << "index | forces";
		for (int i = 0; i < particulas.size(); i++){
			for (int j = 0; j< particulas.size(); j++){
				ofVec3f r = particulas[j]->pos-particulas[i]->pos;
				float rn = particulas[j]->pos.distance(particulas[i]->pos);
				if(rn < smoothing_length && particulas[i]->index != particulas[j]->index ){
					particulas[i]->forces += particulas[j]->mass * (0.5f*(particulas[i]->pressure+particulas[j]->pressure)) / particulas[j]->density * kernel->spikyGradient(r,rn); // Pressure
					particulas[i]->forces += viscosity_mu*(particulas[j]->vel - particulas[i]->vel)*(particulas[j]->mass/particulas[j]->density)*kernel->viscosityLaplacian(rn); //Viscosity
				}
			}

			ofLog() << particulas[i]->index << " " << particulas[i]->forces << endl;
		}

		//Time integration and collision handling
		for (int i = 0; i < particulas.size(); i++){
			particulas[i]->acc = (particulas[i]->forces / particulas[i]->density) + ofVec3f(0,gravity,0) ;
			particulas[i]->vel += particulas[i]->acc*dt;
			particulas[i]->pos += particulas[i]->vel*dt;
			particulas[i]->checkBoundaries();
		}
		
		frame=true;
	}
}

void ParticleSystem::draw ()
{
	for (int i = 0; i < particulas.size(); i++){
		particulas[i]->draw();
	}
}

int ParticleSystem::nextPrime(int n){
    int smaller;

    if (n > 2){
        smaller = 1;
        n--;

        while ((smaller * smaller) <= n)
        {
            n++;
            smaller = 2;

            while (((n % smaller) > 0) && ((smaller * smaller) <= n))
                smaller++;
        }

        return n;
    }else if (n < 0){
        return 0;
	}else{
		return 2;
	}
}
