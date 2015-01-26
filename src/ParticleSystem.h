#ifndef PARTICLESYSTEM_H

#include "ofMain.h"
#include "Particle.h"
#include "HashTable.h"
#include "Kernels.h"

class ParticleSystem {
	public:
		ParticleSystem(ofVec3f);
		void update();
		void draw();
		bool frame;
	private:
		int nextPrime(int n);
		vector<Particle*> particulas;
		HashTable *t;
		Kernels *kernel;
		float smoothing_length;
		float particle_mass;
		int num_particles;
		float volume;
		
};

#endif