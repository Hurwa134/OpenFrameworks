
#include "ofApp.h"
#include "ofxJSON.h"
#include <time.h>

ofxJSONElement root;

float phase = 0.5;
float tempHigh;
int sunset;
int sunrise;
float temp;
float humidity;
float windSpeed;
float x;
int current;
bool Night;
ofTrueTypeFont OrbitronExtraBold;



//--------------------------------------------------------------
void ofApp::setup(){
    
    OrbitronExtraBold.load("Orbitron-ExtraBold.ttf",30);
    
    std::string url = "https://api.darksky.net/forecast/f85d8af7c1a3411894fc25245330f89f/40.6971494,-74.2598655";
    ofSetCircleResolution(100);
    // Now parse the JSON
    bool parsingSuccessful = root.open(url);
    
    if (parsingSuccessful)
    {
        ofLogNotice("ofApp::setup") << root.getRawString(true);
    } else {
        ofLogNotice("ofApp::setup") << "Failed to parse JSON.";
    }
    
    sunset = root["daily"]["data"][0]["sunsetTime"].asInt();
    sunrise = root["daily"]["data"][1]["sunriseTime"].asInt();
    current = time(NULL); // get current epoch
    temp = root["currently"]["temperature"].asFloat();
    humidity= root["currently"]["humidity"].asFloat();
    windSpeed= root["currently"]["windSpeed"].asFloat();
    
    x = ofMap(current, sunset, sunrise, 0, ofGetWidth());
    if (x > ofGetWidth() || x < 0)
    {// draw moon
        Night = true;
    }
    
    ofColor yellow = ofColor::yellow;
    ofColor black = ofColor::black;
    black.lerp(yellow, phase); // interpolating (LERPING) between colors
    ofSetBackgroundColor(black);
    
    
    gui.setup(); // most of the time you don't need a name
    gui.add(radius.setup("radius", humidity, 0, 1));
    gui.add(center.setup("center", {x, 100 * windSpeed}, {0, 0}, {ofGetWidth(), ofGetHeight()}));
    gui.add(color.setup("color", ofColor(temp, 100, 140), ofColor(0, 0), ofColor(255, 255)));
    gui.add(moonColor.setup("moonColor", ofColor(temp, 100, 140), ofColor(0, 0), ofColor(255, 255)));
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

std::ostringstream stream1;
std::ostringstream stream2;

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(200,200,0); // greenish
    
    OrbitronExtraBold.drawString("Celestial London",ofGetWidth()/2-70, 100);
   
    current = time(NULL);
    std::string currentTime = "Current epoch time is " + ofToString(current) + ".";
    
    if(ofGetFrameNum()==1){
        stream1<< "The temperature is "<<temp<<"."
        <<endl<<
        "The sunrise time is "<<sunrise<<"."
        <<endl
        <<"The sunset time is "<<sunset<<"."
        <<endl
        <<"The humidity is " <<humidity<<"."
        <<endl
        <<"The windSpeed is " <<windSpeed<<"."
        <<endl
        <<"Day of year" <<(current/86400)%365<< "."
        <<endl
        <<"# of hours" << (current/3600)%24<<"."
        <<endl
        <<"# of minutes" << (current/60)%60<<".";
    }

   // stream2 <<"The current time is" <<current<<".";
    
//    (Epoch/SecInDay)%365 = gives you the day in the year
//
//    Once you have the day of the year -> you can divide by number of seconds in an hour/or in a minute.

    
    
    ofSetBackgroundColor(0,0,0);

    ofDrawBitmapString(stream1.str(), 20, 100);
    //ofDrawBitmapString(stream2.str(), 20, 80);
    ofDrawBitmapString(currentTime,20, 80);
    

    ofSetColor(color);
    ofDrawCircle(center,100 * radius);
    if (Night)
    {//draw a moon
        ofSetColor(moonColor);
        float xpos = cos(ofGetElapsedTimeMillis()/100.0) * 100.0;
        float ypos = sin(ofGetElapsedTimeMillis()/100.0) *100.0;
        ofDrawCircle(xpos+900,ypos+300,100);
    }
    
    
    cout<<sunset<<","<<sunrise<<","<<current<<","<<x<<endl;
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    
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
