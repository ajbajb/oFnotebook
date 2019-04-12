#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    // the number of frames we will save
    numFrames = 200;
    
    // we will display each frame at this size
    // we will also resize the captured pixels to this size
    // to save on memory
    frameSize = 64;
    
    // frames are layed out in square grid, so rows and columns are
    // square root of numFrames
    gridWidth = int(sqrt(numFrames));
    
    // the window will be frameSize * the gridWidth
    int windowSize = frameSize * gridWidth;
    ofSetWindowShape(windowSize, windowSize);
    
    grabber.setup(320, 240);
    
    // allocate memory for all the textures
    textures.assign(numFrames, ofTexture());
    for (int i = 0; i < textures.size(); i++)
    {
        textures[i].allocate(frameSize, frameSize, GL_RGB);
    }

}

//--------------------------------------------------------------
void ofApp::update()
{
    grabber.update();
    if (grabber.isFrameNew())
    {
        // save the current frame's pixels
        // this is what we missed earlier
        
        ofPixels currentPixels;
        currentPixels = grabber.getPixels();
        // resize the pixel array to be the size we will display
        currentPixels.resize(frameSize, frameSize);
        
        // add the current frame pix to the end of the frames vector
        frames.push_back(currentPixels);
    }
    
    // if the amount of frames we are saving is larger than the amount of
    // frames we want to save
    while (frames.size() > numFrames)
    {
        // remove the first frame (which is the oldest)
        frames.erase(frames.begin());
    }
    
    // load all the frame pixels into the textures
    for ( int i = 0; i < frames.size(); i++)
    {
        textures[i].loadData(frames[i]);
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    // iterate over textures
    // 1d for-loop!
    for (int i = 0; i < textures.size(); i++)
    {
        // this is how we get the 2d locations from a 1d loop
        int x = i % gridWidth;
        int y = i / gridWidth;
        
        //draw texture at that location
        textures[i].draw(x * frameSize, y * frameSize, frameSize, frameSize);
    }
    
    
    
    
    string frameStr = ofToString(ofGetFrameRate());
    ofDrawBitmapString(frameStr, 20, 20);
    

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
