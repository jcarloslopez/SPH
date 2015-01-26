#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	ofSetSmoothLighting(true);
	ofEnableDepthTest();

	directionalLight.setDiffuseColor(ofColor(255.f, 255.f, 255.f));
	directionalLight.setSpecularColor(ofColor(255.f, 255.f, 255.f));
	directionalLight.setDirectional();
    
	directionalLight.setOrientation( ofVec3f(90, 90, 90) );
	ofEnableLighting();

	ps = new ParticleSystem(ofVec3f(0));
	cube = ofMesh::box(0.1, 0.1, 0.1,1,1,1);
	cam.setScale(0.001f);
	setCam=false;

}

//--------------------------------------------------------------
void ofApp::update(){
	ps->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	ofBackground(200);
	ofSetWindowTitle(ofToString(ofGetFrameRate()));

	cam.begin();

	directionalLight.disable();
	cube.drawWireframe();
	directionalLight.enable();

	ps->draw();

	cam.end();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if(key == OF_KEY_LEFT) ps->frame=!ps->frame;
	if(key == OF_KEY_CONTROL) cam.setPosition(ofPoint(0, 0, 0.1));  
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
