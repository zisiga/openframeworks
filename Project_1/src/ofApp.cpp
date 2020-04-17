#include "ofApp.h"

ofVec2f flower, flower2, lips, clock1, clock2, orbit;
ofImage flowerImage, flower2Image, lipsImage, clock1Image, clock2Image;
float degrees, degrees2, degrees3;
float getLarger;

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetFullscreen(true);
    ofSetFrameRate(60);
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F);
    fbo.begin();
    ofClear(255, 255, 255);
    fbo.end();
    ofSetCircleResolution(100);
    ofEnableSmoothing();

    credits.init("fonts/Lekton-Regular.ttf", 15);
    credits.setText("The examination that places individuals in a field of surveillance also situates them in a nework of writings; it engages them in a whole mass of documents that capture and fix them.");
    ofSetBackgroundColor(224, 133, 104);

    degrees = 0;
    degrees2 = 20;
    degrees3 = 90;

    getLarger = 20;

    flowerImage.load("images/flower.png");
    flower2Image.load("images/flower2.png");
    lipsImage.load("images/lips.png");
    clock1Image.load("images/clock1.png");
    clock2Image.load("images/clock2.png");
}

//--------------------------------------------------------------
void ofApp::update()
{
    degrees++;
}

ofPoint myMouse;
float i = 0;
float a = 200;
float offset = 0;
float step = 0.1;
float speed = 0;

//--------------------------------------------------------------
void ofApp::draw()
{
    ofPushMatrix();
    ofTranslate(myMouse.x, myMouse.y * 3);

    //quotes text
    ofSetColor(0);
    credits.drawCenter(400, 340);
    //wrapping width for text
    credits.wrapTextX(600);

    //Invisible circle
    // ofSetColor(206, 71, 39, 206);
    ofPoint mainCircle(ofGetWidth(), 200);
    ofDrawCircle(mainCircle, 800);

    //Circles that are moving
    ofSetColor(206, 71, 39, 206); // color changes of both circles
    offset += step;
    if (offset > 44 || offset < -44)
    {
        step *= -1;
    }

    ofDrawCircle(mainCircle + offset, 640);
    ofDrawCircle(mainCircle - offset, 540);
    ofDrawCircle(mainCircle + offset, 440);
    ofDrawCircle(mainCircle - offset, 340);
    ofDrawCircle(mainCircle + offset, 240);
    ofDrawCircle(mainCircle - offset, 840);
    ofDrawCircle(mainCircle + offset, 940);
    ofDrawCircle(mainCircle - offset, 1140);

    ofPopMatrix();

    //flower orbit
    flower = mainCircle + 200;
    ofSetColor(70, 104, 114);
    orbit = flower.rotate(degrees, mainCircle);
    flowerImage.draw(flower - 20, 300, 300);

    flower = mainCircle + 400;
    ofSetColor(70, 104, 114);
    orbit = flower.rotate(degrees, mainCircle);
    flowerImage.draw(flower - 10, 300, 300);

    flower = mainCircle + 600;
    ofSetColor(70, 104, 114);
    orbit = flower.rotate(degrees, mainCircle);
    flowerImage.draw(flower - 10, 300, 300);

    clock2 = mainCircle + 80;
    orbit = clock2.rotate(degrees2, mainCircle);
    clock2Image.draw(clock2 - 20, 400, 400);

    //flower2 orbit
    // flower2 = flower +600;
    // orbit = flower2.rotate(degrees2, flower);
    // flower2Image.draw(flower2-20,300,300);

    //flower2 = flower +800;
    // orbit = flower2.rotate(degrees2, flower);
    //flower2Image.draw(flower2-20,300,300);

    //  flower2 = flower +400;
    //  orbit = flower2.rotate(degrees2, flower);
    //flower2Image.draw(flower2-20,300,300);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    int step = 200;
    if (key == OF_KEY_LEFT)
        myMouse.x = myMouse.x - step;
    if (key == OF_KEY_RIGHT)
        myMouse.x = myMouse.x + step;

    //if(keyPressed == "l"){
    //getLarger += 3;
    // }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
    mouseX = x;
    mouseY = y;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
    speed = 0.1;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
}