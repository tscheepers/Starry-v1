//
//  Copyright (c) 2012, Infinite Droplets V.O.F.
//  All rights reserved.
//  
//  Starry was released under the BSD Licence
//

#import <UIKit/UIKit.h>
#import "OpenGLCommon.h"

typedef struct {
	float red;
	float green;
	float blue;
	float alpha;
} StarColor;

static inline StarColor StarColorMake(float inRed, float inGreen, float inBlue, float inAlpha)
{
    StarColor ret;
	ret.red = inRed;
	ret.green = inGreen;
	ret.blue = inBlue;
	ret.alpha = inAlpha;
    return ret;
}

@interface SRStar : NSObject {
	
	int starID;
	NSString *name;
	NSString *bayer;
	NSString *gliese;
	NSString *hip;
	/* NSString * x;
	NSString * y;
	NSString * z;
	NSString * mag;
	NSString * ci; */
	Vertex3D position;
	float mag;
	float ci;
	
	BOOL selected;
	
}



@property (nonatomic, readwrite) int starID;
@property (nonatomic, retain) NSString * name;
@property (nonatomic, retain) NSString * bayer;
@property (nonatomic, retain) NSString * gliese;
@property (nonatomic, retain) NSString * hip;
/*@property (nonatomic, retain) NSString * x;
@property (nonatomic, retain) NSString * y;
@property (nonatomic, retain) NSString * z;
@property (nonatomic, retain) NSString * ci;
@property (nonatomic, retain) NSString * mag;*/
@property (nonatomic, readwrite) BOOL selected;
@property (nonatomic, readwrite) Vertex3D position;
@property (nonatomic, readwrite) float mag;
@property (nonatomic, readwrite) float ci;

-(BOOL)visibleWithZoom:(float)zoomf;
-(float)size;
-(StarColor)color;
-(float)alpha;
-(Vertex3D)myCurrentPosition;
-(Vertex3D)position;

@end