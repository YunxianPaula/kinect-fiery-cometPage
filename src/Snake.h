#pragma once
#include "ofMain.h"



class particle{
// our particle class
public:
    particle(ofVec3f startPoint, ofColor col);
    ~particle();
    void update();
    void draw();
    ofVec3f location, direction, velocity;
    int size;
    ofColor col;
    float speed;
};


class Snake : public ofBaseApp{
public:
    void setup(ofColor _c);
    void update();
    void draw();
    void addLocation(int x, int y);
    ofColor targetC;
    deque <ofPoint> linePoints;
    
 
    
    // for our particle system
    vector<particle> particles;
    int maxAge, maxParticles;
    
    bool b_drawParticles;
};
