#include "detectFace.h"
using namespace std;
using namespace utils;

void detectFace::threadedFunction() {
	/*
	 srand(time(NULL));
	 ofHttpResponse pictdata = ofLoadURL("https://graph.facebook.com/" + itos(abs(rand() * rand() % 10000000)) + "/picture?redirect=false&width=9999");
	 while (pictdata.data.getText().find("UlIqmHJn-SK", 0) != string::npos) {
	 srand(time(NULL));
	 pictdata = ofLoadURL("https://graph.facebook.com/" + itos(abs(rand() * rand() % 10000000)) + "/picture?redirect=false&width=9999");
	 }
	 
	 ofHttpResponse pict = ofLoadURL(replaceAll(regexpmatch(pictdata.data.getText().c_str(), "https:[^\"]+", 1)[0], "\\", ""));
	 face.loadImage(pict.data);
	 
	 tracker.reset();
	 */
}