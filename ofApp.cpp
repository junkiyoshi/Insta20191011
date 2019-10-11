#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(0);
	ofEnableDepthTest();

	auto ico_sphere = ofIcoSpherePrimitive(250, 4);
	this->mesh = ico_sphere.getMesh();

	for (auto& point : this->mesh.getVertices()) {

		mesh.addColor(ofColor(0, 0, 0));
	}
}

//--------------------------------------------------------------
void ofApp::update() {

	ofColor color;
	for (int i = 0; i < this->mesh.getVertices().size(); i++) {

		auto point = this->mesh.getVertices()[i];
		color.setHsb(ofMap(ofNoise(point.x * 0.005, point.y * 0.005, point.z * 0.005, ofGetFrameNum() * 0.008), 0, 1, 64 + 8, 192), 180, 230);
		// color.setHsb(ofMap(ofNoise(point.x * 0.008, point.y * 0.008, point.z * 0.008, ofGetFrameNum() * 0.01), 0, 1, 0, 40), 180, 230);
		
		mesh.setColor(i, color);
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateY(ofGetFrameNum() * 0.35);

	this->mesh.draw();

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}