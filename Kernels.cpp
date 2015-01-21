#include "Kernels.h"
Kernels::Kernels(float _h){
	h = _h;
	h2 = pow(h,2);
	h3 = pow(h,3);
	h6 = pow(h,6);
	h9 = pow(h,9);

	wPoly6 = 315.0f / (64.0f*PI*h9);
	//wPoly6Gradient = -945 / (32*PI*h9);
	//wPoly6Laplacian = -945 / (32*PI*h9);
	//wSpiky = 15 / (PI*h6);
	wSpikyGradient = -45.0f / (PI*h6);
	//wSpikyLaplacian = -90 / (PI*h6);
	//wViscosity = 15 / (2*PI*h3);
	//wViscosityGradient = 15 / (2*PI*h3);
	wViscosityLaplacian = 45.0f / (PI*h6);
}
float Kernels::poly6(float r){ ///////////////////
	return wPoly6 * (h2-(r*r))*(h2-(r*r))*(h2-(r*r));
}
ofVec3f Kernels::spikyGradient(ofVec3f r,float fn){ ////////////////
	return (wSpikyGradient*(h-fn)*(h-fn)*(r.getNormalized()));
}
float Kernels::viscosityLaplacian(float r){ ///////
	return (wViscosityLaplacian*(h-r));
}
/*
ofVec3f Kernels::poly6Gradient(ofVec3f r){
	//return (wPoly6Gradient*r)*SQR(h2-r.dot(r));
	return ofVec3f();
}
float Kernels::poly6Laplacian(ofVec3f r){
	//return ( wPoly6Laplacian * (h2 - r.dot(r)) * ( (3*h2) - (7*(r.dot(r)) ) ));
	return 0.0f;
}
ofVec3f Kernels::spiky(ofVec3f r){
	//return (wSpiky * ( CUBE(h-r) ) );
	return ofVec3f();
}

ofVec3f Kernels::spikyLaplacian(ofVec3f r){
	return ofVec3f();
}
ofVec3f Kernels::viscosity(ofVec3f r){
	return ofVec3f();
}
ofVec3f Kernels::viscosityGradient(ofVec3f r){
	return ofVec3f();
}
*/