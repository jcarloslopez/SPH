#include "Kernels.h"
Kernels::Kernels(float _h){
	h = _h;
	h2 = h*h;
	h6 = h*h*h*h*h*h;
	h9 = h*h*h*h*h*h*h*h*h;

	wPoly6 = 315.0f / (64.0f*PI*h9);
	wSpikyGradient = -45.0f / (PI*h6);
	wViscosityLaplacian = 45.0f / (PI*h6);
}
float Kernels::poly6(float r){ 
	return wPoly6 * (h2-(r*r))*(h2-(r*r))*(h2-(r*r));
}
ofVec3f Kernels::spikyGradient(ofVec3f r,float fn){
	return (wSpikyGradient*(h-fn)*(h-fn)*(r.getNormalized()));
}
float Kernels::viscosityLaplacian(float r){ 
	return (wViscosityLaplacian*(h-r));
}
