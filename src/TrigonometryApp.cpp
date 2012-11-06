#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/CinderMath.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class TrigonometryApp : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    float t;
    float angle;
    float x, y;
    float freq;
    float amp;
    float period;
    float step;
};

void TrigonometryApp::setup()
{
    amp = 50;
    freq = 0.5f;
    period = 1.0f;
    step = 5;
    
}

void TrigonometryApp::mouseDown( MouseEvent event )
{

}

void TrigonometryApp::update()
{
}

void TrigonometryApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    float tOffset = 0;
    gl::pushMatrices();
    t = getElapsedSeconds();
    gl::translate(Vec2f(0,getWindowHeight()/2));
    for (int i = 0; i < getWindowWidth(); i += step) {
        y = amp * sin( 2 * pi * t * freq  + tOffset);
        gl::drawSolidEllipse(Vec2f(i, y), 4, 4);
        tOffset += 2 * pi * period * step/ getWindowWidth();
        
    }
    
    gl::popMatrices();
    
    
    
}

CINDER_APP_BASIC( TrigonometryApp, RendererGl )
