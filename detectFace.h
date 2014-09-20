#pragma once
#include "utils.h"
#include "ofMain.h"
#include "ofxFaceTracker.h"
#include "hirokoPJObject.h"
#include <iostream>

using namespace std;
using namespace utils;

class detectFace : public ofThread {
public:
    void threadedFunction();
	
	ofxFaceTracker tracker;
	hirokoPJObject obj;
};