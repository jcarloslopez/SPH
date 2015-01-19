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
	ofSetColor(0,111,255);
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


