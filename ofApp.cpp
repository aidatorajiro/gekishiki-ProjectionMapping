#include "ofApp.h"
using namespace std;
using namespace utils;

int width  = 640;
int height = 360;

ofVideoGrabber videoGrabber;
ofImage        face;
ofxFaceTracker tracker;
bool           isDetect; 
hirokoPJObject mainobject;
hirokoPJObject faceobject;

//--------------------------------------------------------------
ofxPanel gui;
ofxSlider<int> Rmin;
ofxSlider<int> Rmax;
ofxSlider<int> Gmin;
ofxSlider<int> Gmax;
ofxSlider<int> Bmin;
ofxSlider<int> Bmax;
void ofApp::setup(){
	ofSetFrameRate( 60 );
    ofxGuiSetFont("Helvetica.ttf",10,true,true);
    ofxGuiSetTextPadding(4);
    ofxGuiSetDefaultWidth(512);
    ofxGuiSetDefaultHeight(16);
    gui.setup("color setting");
    gui.add(Rmin.setup("Rmin", 0, 0, 256));
    gui.add(Rmax.setup("Rmax", 0, 0, 256));
    gui.add(Gmin.setup("Gmin", 0, 0, 256));
    gui.add(Gmax.setup("Gmax", 0, 0, 256));
    gui.add(Bmin.setup("Bmin", 0, 0, 256));
    gui.add(Bmax.setup("Bmax", 0, 0, 256));
    gui.setPosition(width, height);
    
	videoGrabber.setVerbose(true);
	videoGrabber.initGrabber(width, height);
	
	tracker.setup();
}

//--------------------------------------------------------------
void ofApp::detectFace() {
	srand(time(NULL));
	ofHttpResponse pictdata = ofLoadURL("https://graph.facebook.com/" + itos(abs(rand() * rand() % 10000000)) + "/picture?redirect=false&width=200");
	while (pictdata.data.getText().find("UlIqmHJn-SK", 0) != string::npos) {
		srand(time(NULL));
		pictdata = ofLoadURL("https://graph.facebook.com/" + itos(abs(rand() * rand() % 10000000)) + "/picture?redirect=false&width=200");
	}
	
	ofHttpResponse pict = ofLoadURL(replaceAll(regexpmatch(pictdata.data.getText().c_str(), "https:[^\"]+", 1)[0], "\\", ""));
	face.loadImage(pict.data);
	
	tracker.reset();
	isDetect = tracker.update(ofxCv::toCv(face));
}

//--------------------------------------------------------------
void ofApp::update(){
	videoGrabber.update();
	if (videoGrabber.isFrameNew()) {
		ofxCvColorImage color;
        color.setFromPixels(videoGrabber.getPixels(), width, height);
        mainobject.setVerticesByImage(color, Rmin, Rmax, Gmin, Gmax, Bmin, Bmax);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
    mainobject.update();
    gui.draw();
	
	face.draw(0, 0);
	if (isDetect) {
		tracker.getImageMesh().draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	ofApp::detectFace();
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
