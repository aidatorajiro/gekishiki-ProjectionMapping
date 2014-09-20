#include "detectFace.h"
using namespace std;
using namespace utils;

void detectFace::threadedFunction() {
	tracker.setup();
	
	srand(time(NULL));
	ofHttpResponse pictdata = ofLoadURL("https://graph.facebook.com/" + itos(abs(rand() * rand() % 10000000)) + "/picture?redirect=false&width=1000");
	while (pictdata.data.getText().find("UlIqmHJn-SK", 0) != string::npos) {
		srand(time(NULL));
		pictdata = ofLoadURL("https://graph.facebook.com/" + itos(abs(rand() * rand() % 10000000)) + "/picture?redirect=false&width=1000");
	}
	
	ofHttpResponse pict = ofLoadURL(replaceAll(regexpmatch(pictdata.data.getText().c_str(), "https:[^\"]+", 1)[0], "\\", ""));
	
	ofImage face;
	face.setUseTexture(false);
	face.loadImage(pict.data);
	
	tracker.reset();
	tracker.update(ofxCv::toCv(face));
	
	obj.addVertices(tracker.getImageMesh().getVertices());
}