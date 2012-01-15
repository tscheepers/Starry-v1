//
//  Copyright (c) 2012, Infinite Droplets V.O.F.
//  All rights reserved.
//  
//  Starry was released under the BSD Licence
//

#import <Foundation/Foundation.h>
#import "OpenGLCommon.h"

@interface SRMessier : NSObject {
	Vertex3D position;
	float mag;
	NSString* name;
	NSString* constellation;
	float distance;
	NSString* RA;
	NSString* declination;
	NSString* type;
}

@property (nonatomic, readwrite) Vertex3D position;
@property (nonatomic, readwrite) float mag;
@property (nonatomic, readwrite) float distance;
@property (nonatomic, retain) NSString* declination;
@property (nonatomic, retain) NSString* name;
@property (nonatomic, retain) NSString* constellation;
@property (nonatomic, retain) NSString* RA;
@property (nonatomic, retain) NSString* type;

-(Vertex3D)myCurrentPosition;
-(BOOL)visibleWithZoom:(float)zoomf;

@end
