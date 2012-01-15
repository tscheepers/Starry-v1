//
//  Copyright (c) 2012, Infinite Droplets V.O.F.
//  All rights reserved.
//  
//  Starry was released under the BSD Licence
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <CoreMotion/CoreMotion.h>
#import <UIKit/UIKit.h>
#import "GLView.h"
#import "OpenGLCommon.h"

@interface SRCamera : NSObject {
	int touchX;
	int touchY;
	
	float sphereRadius;
	
	float deltaXRadians, deltaYRadians;
	
	float lookAtX;
	float lookAtY;
	float lookAtZ;
	
	float altitude;
	float azimuth;
    float azimuthCompassAdjustment;
	
	float deacco;
	float hSpeed;
	float vSpeed;
	int accH;
	int accV;
	
	GLfloat fieldOfView;
	GLView* theView;
	
	CGRect rect;
	GLfloat size;
	
	BOOL swipeHor;
	BOOL swipeVer;
	BOOL tapZoom;
	BOOL zoomOut;
	BOOL planetView;
	
	int zoomDeltaX;
	int zoomDeltaY;
	
	//float rotationY1;
	//float rotationZ;
	
	float preRA;
	float tSteps;
	float oSteps;
	float hSteps;
	float vSteps;
	
	BOOL usingCompass;

	
	GLfloat zoomingValue; 
	
	CLLocationManager* locationManager;
    CMMotionManager* motionManager;
    
    NSTimer * timer;
	
	int iPadWidth;
	int iPadHeight;
    
}

@property (readwrite) BOOL planetView;
@property (readwrite) float altitude;
@property (readwrite) float azimuth;
@property (readonly) float fieldOfView;

- (void)recalculateCompassAdjustment;
- (GLfloat)zoomingValue;
- (id)initWithView:(GLView*)view;
- (void)adjustView;
- (void)rotateCameraWithX:(int)deltaX Y:(int)deltaY;
- (void)zoomCameraWithDelta:(int)delta centerX:(int)cx centerY:(int)cy;
- (void)zoomCameraWithX:(int)deltaX andY:(int)deltaY;
- (void)zoomCameraOut;
- (void)initiateHorizontalSwipeWithX:(int)theX;
- (void)initiateVerticalSwipeWithY:(int)theY;
- (void)reenable;
- (void)resetZoomValue;
//- (void)RAAndDecForPoint:(CGPoint)point;

-(float)calculateAzimuthWithX:(int)deltaX Y:(int)deltaY;
-(float)calculateAltitudeWithX:(int)deltaX Y:(int)deltaY;

- (void)doAnimations:(float)timeElapsed;
-(void)positionStayInFocus:(id)object;

@end
