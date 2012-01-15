//
//  Copyright (c) 2012, Infinite Droplets V.O.F.
//  All rights reserved.
//  
//  Starry was released under the BSD Licence
//


#import <UIKit/UIKit.h>
#import "GLView.h"

#import "SRCamera.h"
#import "SRRenderer.h"
#import "SRStar.h"

@interface GLViewController : UIViewController <GLViewDelegate> {
	SRCamera *camera;
	GLView *theView;
	SRRenderer *renderer;
	
	int lastTouchCount;
	int dTouch;
	GLfloat initialTouchDistance;
	GLfloat lastTouchDistance;
	CGPoint pinchCenter;
	
	BOOL UIClick;
	BOOL ScreenClick;
	
	int dX;
	int dY;
	
	int iPadWidth;
	int iPadHeight;
}

@property (assign) SRCamera *camera;
@property (readonly) GLView *theView;
@property (readonly) int iPadHeight;
@property (readonly) int iPadWidth;
@property (readonly) SRRenderer *renderer;

-(void)checkScreenObjectClicked:(NSSet *)touches;

@end
