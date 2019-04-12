#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    numFrames = 200;
    frameSize = 200;
    
    grabber.setup(320, 240);
    
    // allocate memory and initalize pixels
    frames.assign(numFrames, ofPixels());
    textures.assign(numFrames, ofTexture());
    
    for (int i = 0; i < frames.size(); i++)
    {
        frames[i].allocate(frameSize, frameSize, OF_PIXELS_RGB);
        textures[i].allocate(frameSize, frameSize, GL_RGB);
        
        // set all pixels in every frame to 0 to start
        frames[i].set(0);
        textures[i].loadData(frames[i]);
    }

}

//--------------------------------------------------------------
void ofApp::update()
{
    grabber.update();
    if (grabber.isFrameNew())
    {
        ofPixels grabberPix = grabber.getPixels();
        grabberPix.resize(frameSize, frameSize);
        frames.push_back(grabberPix);
        
        while (frames.size() > numFrames)
        {
            frames.erase(frames.begin());
        }
    }
    
    for (int i = 0; i < frames.size(); i++)
    {
        textures[i].loadData(frames[i]);
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackgroundGradient(ofColor(0), ofColor(50), OF_GRADIENT_CIRCULAR);
    
    int frameSpacing = 5;
    int centerCube = (numFrames * frameSpacing) / 2;
    
    ofEnableDepthTest();
    cam.begin();
    for (int i = 0; i < textures.size(); i++)
    {
        ofPushMatrix();
        ofTranslate(-frameSize/2, -frameSize/2, i * frameSpacing - centerCube);
        textures[i].draw(0, 0, 0, frameSize, frameSize);
        ofPopMatrix();
    }
    cam.end();
    ofDisableDepthTest();
    
    string frameStr = "frame rate:: " + ofToString(ofGetFrameRate());
    ofDrawBitmapString(frameStr, 15, 15);

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
