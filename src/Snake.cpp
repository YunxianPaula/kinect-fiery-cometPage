#include "Snake.h"

void Snake::setup(ofColor _c){
    targetC = _c;
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    
    maxParticles = 1000;
    b_drawParticles = false;
}
//---------------------
void Snake::update(){
    
}
//---------------------
void Snake::draw(){
    
//    ofPushStyle();
//    ofSetLineWidth(4);
//    ofSetColor(255,0,0);
//    for (int i=1; i<linePoints.size(); i++){
//        ofDrawLine(linePoints[i].x, linePoints[i].y, linePoints[i-1].x, linePoints[i-1].y);
//    }
//    ofPopStyle();
    // loop through our particles vector updating each individual particle
    for (int i=0; i<particles.size(); i++){
        particles[i].update();
        particles[i].col.a -= 0.001; // decrement the alpha value of each particle's colour
    }
    
    // if we have more than maxParticles in our vector of particles then erase the first one in the vector
    if (particles.size() >= maxParticles){
        particles.erase(particles.begin());
    }
    
    
}
//---------------------
void Snake::addLocation(int x, int y){
    
    linePoints.push_front(ofPoint(x,y));
    if (linePoints.size()>50) linePoints.pop_back();
}


//--------------------------------------------------------------
particle::particle(ofVec3f startPoint, ofColor newCol){
    // constructor
    speed = 20;
    col = newCol;
    size = 10;
    location = startPoint;
    direction.set( ofRandom(-1,1), ofRandom(-1,1), ofRandom(-1,1) );
    velocity.set( ofRandom(-speed,speed), ofRandom(-speed,speed), ofRandom(-speed,speed) );
}

//--------------------------------------------------------------
particle::~particle(){
    
}

//--------------------------------------------------------------
void particle::update(){
    location += direction * velocity;
}

//--------------------------------------------------------------
void particle::draw(){
    ofPushStyle();
    ofFill();
    ofSetColor(col);
    ofDrawCircle(location, size);
    ofPopStyle();
}
