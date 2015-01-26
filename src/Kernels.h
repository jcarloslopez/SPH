#ifndef KERNELS_H

#include "ofMain.h"

class Kernels {
	public:
		Kernels(float _h);
		float poly6(float r);
		ofVec3f spikyGradient(ofVec3f r,float rn);
		float viscosityLaplacian(float r);

	private:
		float h;
		float h2;
		float h6;
		float h9;
		float wPoly6;
		float wSpikyGradient;
		float wViscosityLaplacian;


};

#endif