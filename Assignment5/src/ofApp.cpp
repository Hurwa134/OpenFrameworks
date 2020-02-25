#include "ofApp.h"

//Define global variables

float face_x_position;
float face_y_position;
float left_x_eye;
float left_y_eye;
float right_x_eye;
float right_y_eye;

//Define happy eye positions

float happy_x_lefteye;
float happy_y_lefteye;
float happy_x_righteye;
float happy_y_righteye;

//Define angry eye positions

float angry_x_lefteye;
float angry_y_lefteye;
float angry_x_righteye;
float angry_y_righteye;

//Draw mouth as a rectangle

float mouthHeight;
float mouthWidth;

// height and width

float windowWidth;
float windowHeight;

// center of screen

float centerWidth;
float centerHeight;

float seconds;


//polygon drawing

ofPath path;


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetCircleResolution(50);
    // these are our face x and y positions
    face_x_position = ofGetWidth()/2;
    face_y_position = ofGetHeight()/2;
    
    //our left eye x and y positions
    left_x_eye = (face_x_position -50);
    left_y_eye = (face_y_position -40);
    
    //our right eye x and y positions
    right_x_eye = (face_x_position +50);
    right_y_eye = (face_y_position -40);
    
    //our happy eyes
    happy_x_lefteye = left_x_eye;
    happy_y_lefteye = left_y_eye-20;
    
    happy_x_righteye = right_x_eye;
    happy_y_righteye = right_y_eye-20;
    
    //our angry eyes
    angry_x_lefteye = left_x_eye;
    angry_y_lefteye = left_y_eye+20;
    
    angry_x_righteye = right_x_eye;
    angry_y_righteye = right_y_eye+20;
    
    soundPlayer.load("Seagull.mp3");
    soundPlayer.setMultiPlay(true);
    
    //my mouth
    
    mouthHeight = 40;
    mouthWidth = 120;
    
    //Size of the screen
    
    windowWidth = ofGetWindowWidth();
    windowHeight = ofGetWindowHeight();
    
    //Center of screen
    
    centerWidth = ofGetWindowWidth()/2;
    centerHeight = ofGetWindowHeight()/2;
    


}

//--------------------------------------------------------------
void ofApp::update(){
    
   seconds = ofGetFrameNum()/60.0;
    // Show an expression for two sec
    
    if (seconds >0 && seconds <2) {
        // show the happy expression
        left_x_eye =  happy_x_lefteye;
        left_y_eye = happy_y_lefteye;
        right_x_eye = happy_x_righteye;
        right_y_eye = happy_y_righteye;
        
    }
    if (seconds >2 && seconds <3) {
        // Transition to another expression over the course of one second
        float transitionAmount = seconds - 2.0;
        // change the position
        left_x_eye = ofLerp(happy_x_lefteye, angry_x_lefteye,transitionAmount);
        left_y_eye = ofLerp(happy_y_lefteye, angry_y_lefteye,transitionAmount);
        right_x_eye = ofLerp(happy_x_righteye, angry_x_righteye,transitionAmount);
        right_y_eye = ofLerp(happy_y_righteye, angry_y_righteye,transitionAmount);
        
    }
    if (seconds >3 && seconds <5) {
        // Show the angry expression for two sec
        left_x_eye =  angry_x_lefteye;
        left_y_eye = angry_y_lefteye;
        right_x_eye = angry_x_righteye;
        right_y_eye = angry_y_righteye;
        
    }
    if (seconds > 5 && seconds <6) {
        // Transition to another expression over the course of one second
        left_x_eye =  happy_x_lefteye;
        left_y_eye = happy_y_lefteye;
        right_x_eye = happy_x_righteye;
        right_y_eye = happy_y_righteye;
        
        //This is where we use ofLerp
        
        float transitionAmount = seconds - 5.0;
    
    }
    if(seconds<8) {
        // Show an expression for two seconds
        
        
    }
    
    if (seconds<9) {
        //Transition to another expresssion over the course of one second
        
        //This is where we use ofLerp
           float transitionAmount = seconds - 8.0;
    }
    
    
    if(seconds<11) {
        //Show an expression for two seconds
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    //1.draw blue background
    ofBackground(48, 120, 245);
    //3.draw the face
    ofSetColor(237, 126, 119);
    ofFill();
    ofDrawCircle(face_x_position, face_y_position, 200);
    // Draw left an eye
    ofSetColor(0,0,255);
    ofFill();
    ofDrawCircle(left_x_eye, left_y_eye, 35);
    // Draw right eye
    ofSetColor(0,0,255);
    ofFill();
    ofDrawCircle(right_x_eye, right_y_eye, 35);
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetColor(255, 255, 255);
//    ofDrawRectangle(centerWidth, centerHeight + 70, mouthWidth, mouthHeight);
    
    if(seconds >= 2 && seconds < 4){
        ofDrawRectangle(centerWidth, centerHeight + 70, mouthWidth, mouthHeight);
        if(seconds == 2){
            soundPlayer.play();
        }
    }
    
    if(seconds >= 4 && seconds <6){
        ofDrawCircle(centerWidth, centerHeight + 70, 30);
        if(seconds == 4){
          soundPlayer.play();
        }
    }
    
    //draw a polygon
    
    if(seconds >=6 && seconds <8){
        
        path.setStrokeColor(0);
        path.setStrokeWidth(4);
        path.setFilled(false);
        path.moveTo(centerWidth-50, centerHeight+30);
        path.lineTo(centerWidth+50, centerHeight+30);
        path.lineTo(centerWidth+80, centerHeight+100);
        path.lineTo(centerWidth-80, centerHeight+100);
        path.close();
        
        path.draw();
        if(seconds == 6){
            soundPlayer.play();
        }
        
        
    }
        


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    

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
