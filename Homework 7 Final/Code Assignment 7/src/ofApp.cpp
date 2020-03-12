#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFullscreen(true);
    ofSetFrameRate(60);
    fbo.allocate(ofGetWidth(),ofGetHeight(),GL_RGBA32F);
    fbo.begin();
    ofClear(255,255,255);
    fbo.end();
    ofSetCircleResolution(50);
    
    
    Title.init("SourceSansPro-Light.otf", 50);
    Title.setText("The Secret Garden");
    credits.init("SourceSansPro-Light.otf", 12);
    credits.setText("Story: Frances Hodgson Burnett, Production: Amber Hurwitz");
    ofSetBackgroundColor(32,32,32);
    

}

//--------------------------------------------------------------
void ofApp::update(){

}

int movement = 0;

bool mouseHasBeenPressed= false;



//--------------------------------------------------------------
void ofApp::draw(){
    
    //movingthing
    ofSetColor(160,160,160);
    ofPoint movingthing(ofGetWidth()/2 + movement, 600);
    ofDrawCircle(movingthing,70);
    
    //Draw our title to the screen
    //Giving it a color first with TItle.setColor
    ofSetColor(0,0,0);
     Title.setColor(0,255,128,255);
     Title.drawCenter(ofGetWidth()/2,ofGetHeight()/2-200);
    
    //Draw a sun that appears when you press the mouse is pressed
    if (mouseHasBeenPressed == true) {
        ofSetColor(255,255,51);
        ofPoint Sun(100, 100);
        ofDrawCircle(Sun,150);
    }
    

    
    
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key == OF_KEY_LEFT) {
        movement =movement - 20;
    } else if (key == OF_KEY_RIGHT){
         movement =movement + 20;
    }

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
    if(mouseHasBeenPressed == true){
        mouseHasBeenPressed = false;
    }
    else {
        mouseHasBeenPressed = true;
        
    }
}
//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
