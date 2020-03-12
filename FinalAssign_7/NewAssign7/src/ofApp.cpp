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
    
    ofSetVerticalSync(true);
    
    // we add this listener before setting up so the initial circle resolution is correct
    
    gui.setup(); // most of the time you don't need a name
    gui.add(radius.setup("radius", 140, 10, 300));
    gui.add(happy.setup("happy"));
    gui.add(angry.setup("angry"));
    gui.add(surprised.setup("surprised"));
    gui.add(color.setup("color", ofColor(100, 100, 140), ofColor(0, 0), ofColor(255, 255)));
    gui.add(volume.setup("volume",0.5,0,1));
    
    sound.load("sound.wav");
    sound.play();
 
    
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
    happy_y_lefteye = left_y_eye-10;
    
    happy_x_righteye = right_x_eye;
    happy_y_righteye = right_y_eye-10;
    
    //our angry eyes
    angry_x_lefteye = left_x_eye;
    angry_y_lefteye = left_y_eye+20;
    
    angry_x_righteye = right_x_eye;
    angry_y_righteye = right_y_eye+20;
    
//    //my mouth
//
//    mouthHeight = 40;
//    mouthWidth = 120;
    
    //Size of the screen
    
    windowWidth = ofGetWindowWidth();
    windowHeight = ofGetWindowHeight();
    
    //Center of screen
    
    centerWidth = ofGetWindowWidth()/2;
    centerHeight = ofGetWindowHeight()/2;
}

//--------------------------------------------------------------
void ofApp::update(){
    sound.setVolume(volume);
    
//    seconds = ofGetFrameNum()/60.0;
//
//
//    if (happy == true ) {
//        // show the happy expression
//        left_x_eye =  happy_x_lefteye;
//        left_y_eye = happy_y_lefteye;
//        right_x_eye = happy_x_righteye;
//        right_y_eye = happy_y_righteye;
//
//    }
//    if (angry == true ){
//        // Transition to another expression over the course of one second
//        float transitionAmount = seconds - 2.0;
//        // change the position
//        left_x_eye = ofLerp(happy_x_lefteye, angry_x_lefteye,transitionAmount);
//        left_y_eye = ofLerp(happy_y_lefteye, angry_y_lefteye,transitionAmount);
//        right_x_eye = ofLerp(happy_x_righteye, angry_x_righteye,transitionAmount);
//        right_y_eye = ofLerp(happy_y_righteye, angry_y_righteye,transitionAmount);
//    }
//
//    if (surprised == true ) {
//        // surprised eyes
//        left_x_eye = (face_x_position -50);
//        left_y_eye = (face_y_position -40);
//        right_x_eye = (face_x_position +50);
//        right_y_eye = (face_y_position -40);
//    }
    
    
    
    
    
    
    
    
    //    if (seconds >3 && seconds <5) {
    //        // Show the angry expression for two sec
    //        left_x_eye =  angry_x_lefteye;
    //        left_y_eye = angry_y_lefteye;
    //        right_x_eye = angry_x_righteye;
    //        right_y_eye = angry_y_righteye;
    //
    //    }
    //    if (seconds > 5 && seconds <6) {
    //        // Transition to another expression over the course of one second
    //        left_x_eye =  happy_x_lefteye;
    //        left_y_eye = happy_y_lefteye;
    //        right_x_eye = happy_x_righteye;
    //        right_y_eye = happy_y_righteye;
    //
    //        //This is where we use ofLerp
    //
    //        float transitionAmount = seconds - 5.0;
    //
    //    }
    //    if(seconds<8) {
    //        // Show an expression for two seconds
    //
    //
    //    }
    //
    //    if (seconds<9) {
    //        //Transition to another expresssion over the course of one second
    //
    //        //This is where we use ofLerp
    //        float transitionAmount = seconds - 8.0;
    //    }
    //
    //
    //    if(seconds<11) {
    //        //Show an expression for two seconds
    //    }
    //
    //}
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    //1.draw black background
    ofBackground(0, 0, 0);
    //3.draw the face
    ofSetColor(color);
    ofFill();
    ofDrawCircle(face_x_position, face_y_position, 200);
    // Draw left eye
    ofSetColor(0,0,255);
    ofFill();
    ofDrawCircle(left_x_eye, left_y_eye, 35);
    // Draw right eye
    ofSetColor(0,0,255);
    ofFill();
    ofDrawCircle(right_x_eye, right_y_eye, 35);
 
    
    if (happy == true ) {
        // draw face cirlce
        ofSetColor(235, 242, 19);
        ofFill();
        ofDrawCircle(face_x_position, face_y_position, 200);
        
        //our happy eyes
        happy_x_lefteye = left_x_eye;
        happy_y_lefteye = left_y_eye-20;
        
        happy_x_righteye = right_x_eye;
        happy_y_righteye = right_y_eye-20;
        
        //my mouth
        mouthHeight = 40;
        mouthWidth = 120;
        ofSetColor(255,255,255);
        ofDrawRectangle(ofGetWindowWidth()/2,ofGetWindowHeight()/2+30,mouthWidth, mouthHeight);
        
        
    }
    if (angry == true ){
        // Transition to another expression over the course of one second
        float transitionAmount = seconds - 2.0;
        // change the position
        // draw face circle
        ofSetColor(237, 126, 119);
        ofFill();
     
        
        //our angry eyes
        ofSetColor(255, 0, 0);
        angry_x_lefteye = left_x_eye;
        angry_y_lefteye = left_y_eye+5;
        angry_x_righteye = right_x_eye;
        angry_y_righteye = right_y_eye+5;
        ofDrawCircle (ofGetWindowWidth()/2-40,ofGetWindowHeight()/2-20,23);
        ofDrawCircle (ofGetWindowWidth()/2+40,ofGetWindowHeight()/2-20,23);
        
        //my mouth
        mouthHeight = 40;
        mouthWidth = 120;
        ofSetColor(255,255,255);
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofDrawRectangle(ofGetWindowWidth()/2,ofGetWindowHeight()/2+30,mouthWidth, mouthHeight);
        
        if (surprised == true){
            
            //face color
          
            
            //our surprised eyes
            ofSetColor(0,0,0);
            ofFill();
            ofDrawCircle(ofGetWindowWidth()/2-40,ofGetWindowHeight()/2-20,radius);
            ofDrawCircle(ofGetWindowWidth()/2+40,ofGetWindowHeight()/2-20,radius);
            
            //my surprised mouth
            ofSetColor(0,0,0);
            ofDrawCircle(ofGetWindowWidth()/2,ofGetWindowHeight()/2+30,radius);
        }
    }
    
    gui.draw();
    ofSetColor(255,255,0);
    ofFill();
    ofDrawCircle(ofGetWidth()-100,100,radius);
    
    
    
    
    
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

