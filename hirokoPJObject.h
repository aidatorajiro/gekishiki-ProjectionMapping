#include <math.h>
#include "utils.h"
#include "ofMain.h"
#include "ofxOpenCv.h"
using namespace std;
using namespace utils;

class hirokoPJObject : public ofMesh {
public:
	hirokoPJObject();
	
	float  frame;
	string movetype;
	float  movespeed;
	ofMesh moveparent;
	
	void setVerticesByStr(string str);
    void setVerticesByImage(ofxCvColorImage src, int Rmax, int Rmin, int Gmax, int Gmin, int Bmax, int Bmin);
	void setPosition(int x, int y, int z);
	void update();
};