#ifndef KERNELS_H

#include "ofMain.h"

class Kernels {
	public:
		Kernels(float _h);
		float poly6(float r);
		ofVec3f poly6Gradient(ofVec3f r);
		float poly6Laplacian(ofVec3f r);
		ofVec3f spiky(ofVec3f r);
		ofVec3f spikyGradient(ofVec3f r,float rn);
		ofVec3f spikyLaplacian(ofVec3f r);
		ofVec3f viscosity(ofVec3f r);
		ofVec3f viscosityGradient(ofVec3f r);
		float viscosityLaplacian(float r);


	private:
		float h;
		float h2;
		float h3;
		float h6;
		float h9;
		float wPoly6;
		float wPoly6Gradient;
		float wPoly6Laplacian;
		float wSpiky;
		float wSpikyGradient;
		float wSpikyLaplacian;
		float wViscosity;
		float wViscosityGradient;
		float wViscosityLaplacian;


};

#endif