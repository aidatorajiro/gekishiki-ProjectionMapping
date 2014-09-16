#include <iostream>
#include "utils.h"
#include "hirokoPJObject.h"
#include "ofMain.h"
#include "ofxGui.h"
#include "ofxFaceTracker.h"
using namespace std;
using namespace utils;

class ofApp : public ofBaseApp {
public:
	void setup();
	void detectFace();
	void update();
	void draw();
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
};