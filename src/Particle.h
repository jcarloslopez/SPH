#ifndef PARTICLE_H
#define PARTICLE_H
#include "ofMain.h"

class Particle {
	public:
		Particle(ofVec3f,float,int,float);
		void draw();
		void checkBoundaries();

		ofVec3f pos;
		ofVec3f vel;
		ofVec3f acc;
		ofVec3f forces;
		float mass;
		float density;
		float pressure;
		int index;
		float r;
		vector<int> neighbors;
};

#endif