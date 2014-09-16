#include "hirokoPJObject.h"
using namespace std;
using namespace utils;

hirokoPJObject::hirokoPJObject() {
	setMode(OF_PRIMITIVE_LINE_LOOP);
}

void hirokoPJObject::setVerticesByStr(string str) {
    clear();
	vector<string> vertexposes = split(str, '|');
	for (int i = 0; i < vertexposes.size(); i++) {
		vector<string> vertexpos = split(vertexposes[i], ',');
		addVertex(ofVec3f(stoi(vertexpos[0]),
						  stoi(vertexpos[1]),
						  stoi(vertexpos[2])));
	}
}

void hirokoPJObject::setVerticesByImage(ofxCvColorImage src, int Rmax, int Rmin, int Gmax, int Gmin, int Bmax, int Bmin) {
    ofxCvContourFinder  contour;
    ofxCvGrayscaleImage filtered;
    CvScalar            currentPixel;
    
    //消す(”set”VerticesByImageなので)
    clear();
    
    //メモリ領域を確保
	filtered.allocate(src.width, src.height);
    
    //srcの指定色範囲内を白に、それ以外を黒にしたものをfilteredに入れる
    for (int x = 0; x < src.width; x++) {
        for (int y = 0; y < src.height; y++) {
            currentPixel = cvGet2D(src.getCvImage(), y, x);
            if(isValueInRange(currentPixel.val[0], Rmax, Rmin) &&
               isValueInRange(currentPixel.val[1], Gmax, Gmin) &&
               isValueInRange(currentPixel.val[2], Bmax, Bmin)) {
                currentPixel.val[0] = currentPixel.val[1] = currentPixel.val[2] = 255;
            } else {
                currentPixel.val[0] = currentPixel.val[1] = currentPixel.val[2] = 0;
            }
            cvSet2D(filtered.getCvImage(), y, x, currentPixel);
        }
    }
    
    //filteredを認識させる(白い場所を認識する)
    contour.findContours(filtered, 50, src.width * src.height, 1, false);
    
    //メモリ領域を解放
	filtered.clear();
    
    //認識結果を保存
    if (!contour.blobs.empty()) {
		addVertices(contour.blobs[0].pts);
	}
}

void hirokoPJObject::setPosition(int x, int y, int z) {
	ofVec3f centroid = getCentroid();
	for (int i = 0; i < getVertices().size(); i++) {
		getVertices()[i].x += x - centroid.x;
		getVertices()[i].y += y - centroid.y;
		getVertices()[i].z += z - centroid.z;
	}
}

void hirokoPJObject::update() {
    ofPolyline polyline;
	polyline.clear();
	polyline.addVertices(moveparent.getVertices());
	frame++;
	
	if (movetype == "orbit") {
		ofVec2f point = polyline.getPointAtLength(fmodf(frame * movespeed, polyline.getLengthAtIndex(polyline.size())));
		setPosition(point.x, point.y, 0);
	}
	draw();
}