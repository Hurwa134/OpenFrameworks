#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFullscreen(true);
    ofSetFrameRate(60);
    
    ofBackground(0);
    
    fbo.allocate(ofGetWidth(),ofGetHeight(),GL_RGBA32F);
    fbo.begin();
    ofClear(255,255,255);
    fbo.end();
    ofSetCircleResolution(50);
    
    keyhole.load("keyhole.png");
    
    
    Title.init("SourceSansPro-Light.otf", 50);
    Title.setText("The Secret Garden");
    credits.init("SourceSansPro-Light.otf", 12);
    credits.setText("Story: Frances Hodgson Burnett, Production: Amber Hurwitz");
    ofSetBackgroundColor(32,32,32);
    
    sceneoneSound.load("secretgardensound.mp3");
    scenetwoSound.load("violin.mp3");
    scenethreeSound.load("JazzTrio.mp3");
}

//--------------------------------------------------------------
void ofApp::update() {
    noise.freqR.set(0.5, 0.5);
    noise.freqG.set(0.5, 0.5);
    noise.freqB.set(0.5,0.5);
    noise.speed.set(0.5, 0.5, 0.5);
    noise.mul.set(1.0, 0.5, 0.5);
    noise.add.set(0.5, 0.5, 0.5);
    noise.colorR.set(0.5, 0.5, 0.5);
    noise.colorG.set(0.5, 0.5, 0.5);
    noise.colorB.set(0.5, 0.5, 0.5);
    noise.alpha = 1.0;
}

int movement = 0;

bool mouseHasBeenPressed= false;

float seconds;



//--------------------------------------------------------------
void ofApp::draw(){
    
    seconds = ofGetFrameNum()/60.0;
    if (seconds >0 && seconds <4) {
          introScene();
    }
    
    if (seconds >4 && seconds <12) {
        sceneOne();
    }
    
    if (seconds >12 && seconds <24) {
        sceneTwo();
    }
    
    if (seconds >24 && seconds <36) {
        sceneThree();
    }
    if (seconds >36) {
        creditScene();
    }
    
}
void ofApp::introScene(){
    //movingthing
    ofSetColor(160,160,160);
    movement ++;
    ofPoint movingthing(ofGetWidth()/2 + movement, 600);
    ofDrawCircle(movingthing,70);
    
    //Draw our title to the screen
    //Giving it a color first with Title.setColor
    ofSetColor(0,0,0);
    Title.setColor(0,255,128,255);
    Title.drawCenter(ofGetWidth()/2,ofGetHeight()/2-200);
    
    }


void ofApp::sceneOne(){
    ofBackground(255, 120, 140);
    //clouds, grey trees, mansion, horizontal path
    //movingthing
    ofSetColor(160,160,160);
    movement += -5;
    ofPoint movingthing(ofGetWidth()/2 + movement, 600);
    ofDrawCircle(movingthing,70);
    
    if (sceneoneSound.isPlaying()==false) {
        sceneoneSound.play();
    }
  
    
}

void ofApp::sceneTwo(){
     ofBackground(80, 120, 80);
    //this sets the ball at the center of screen
    movement = 0;
    //add color to keyhole
    noise.draw();
    //keyhole
    keyhole.draw(0,0);
    
    if (sceneoneSound.isPlaying()==true) {
        sceneoneSound.stop();
        
    }
    
    if (scenetwoSound.isPlaying()==false) {
        scenetwoSound.play();
    }
}

void ofApp::sceneThree(){
     ofBackground(140, 80, 140);
    //Garden, with blue sky, yellow sun, green trees, flowers, yellow path
    //movingthing
    ofSetColor(255,165,0);
    movement += 3;
    ofPoint movingthing(ofGetWidth()/2 + movement, 600);
    ofDrawCircle(movingthing,70);
    
    if (scenetwoSound.isPlaying()==true) {
        scenetwoSound.stop();
        
    }
    
    if (scenethreeSound.isPlaying()==false) {
        scenethreeSound.play();
    }
}

void ofApp::creditScene(){
    ofBackground(0, 0, 0);
    //text "by Amber Hurwitz", story by author
    //Draw our title to the screen
    //Giving it a color first with Title.setColor
    credits.setColor(255,255,255,255);
    credits.drawCenter(ofGetWidth()/2,ofGetHeight()/2-200);
    
    if (scenethreeSound.isPlaying()==true) {
        scenethreeSound.stop();
    }
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
   
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {
    
}
