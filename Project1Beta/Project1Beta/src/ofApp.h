#pragma once

#include "ofMain.h"
#include "ofxTextSuite.h"
#include "ofxGLSLSimplexNoise.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
        void introScene();
        void sceneOne();
        void sceneTwo();
        void sceneThree();
        void creditScene();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofSoundPlayer sceneoneSound;
    ofSoundPlayer scenetwoSound;
    ofSoundPlayer scenethreeSound;
    
    ofxGLSLSimplexNoise noise;
    
    ofFbo fbo;
    ofTrueTypeFont MyFont;
    ofxTextBlock        Title;
    ofxTextBlock        credits;
    TextBlockAlignment  alignment;  //constants for controlling state
    
    ofImage keyhole;
    
};
