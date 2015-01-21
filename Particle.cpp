#include "Particle.h"
#define boxSizeX 0.1f
#define boxSizeY 0.1f
#define boxSizeZ 0.1f

Particle::Particle(ofVec3f _pos,float _mass,int _index,float _r){
	pos = _pos;
	vel = ofVec3f(0);
	r = _r;
	mass = _mass;
	density = 0.0f;
	pressure = 0.0f;
	forces = ofVec3f(0);
	acc = ofVec3f(0);
	index = _index;
}

void Particle::draw ()
{
	//if(index==4||index==9||index==13||index==19||index==29||index==34||index==39||index==44||index==72||index==73||index==74||index==97||index==98||index==99||index==104||index==109||index==122||index==123||index==124){
	//	ofSetColor(255,0,0);	
	//}else{
		ofSetColor(0,111,255);
	//}
	ofDrawSphere( pos.x, pos.y,pos.z ,r);
}

void Particle::checkBoundaries(){
	if(pos.x >= boxSizeX/2 - r){
		vel.x = -vel.x*0.7;
		pos.x = boxSizeX/2 -r;
	}
	if(pos.x <= -boxSizeX/2 +r){
		vel.x = -vel.x*0.7;
		pos.x = -boxSizeX/2 +r;
	}

	if(pos.y >= boxSizeY/2 - r){
		vel.y = -vel.y*0.7;
		pos.y = boxSizeY/2 -r;
	}

	if(pos.y <= -boxSizeY/2 +r){
		vel.y = -vel.y *0.7;
		pos.y = -boxSizeY/2 +r;
	}

	if(pos.z >= boxSizeZ/2 - r){
		vel.z = -vel.z*0.7;
		pos.z = boxSizeZ/2 -r;
	}
	if(pos.z <= -boxSizeZ/2 +r){
		vel.z = -vel.z*0.7;
		pos.z = -boxSizeZ/2 +r;
	}
}


