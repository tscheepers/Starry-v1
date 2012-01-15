//
//  Copyright (c) 2012, Infinite Droplets V.O.F.
//  All rights reserved.
//  
//  Starry was released under the BSD Licence
//

#import <Foundation/Foundation.h>
#import <OpenGLES/EAGL.h>
#import <OpenGLES/ES1/gl.h>
#import <OpenGLES/ES1/glext.h>

#import "Texture2D.h"
#import "SRStar.h"
#import "SRInterfaceElement.h"


@interface SRStarInfo : NSObject {	
	SRStar* currentStar;
	
	NSMutableArray* elements;
	
	Texture2D* starImage;
	Texture2D* starText;
	Texture2D* interfaceBackground;
	
	float alphaValue;
	float alphaValueName;
	
	BOOL hiding;
	NSTimer* showTimer;
	
	int pictureBgX;
	int navBgX;
}

@property (nonatomic, assign) BOOL hiding;
@property (nonatomic, assign) float alphaValue;
@property (nonatomic, assign) float alphaValueName;

//+ (SRMessierInfo*)shared;
- (void)starClicked:(SRStar*)theStar;
- (void)starUpdate:(SRStar*)theStar;
- (void)draw;
- (void)show; 
- (void)hide; 

@end
