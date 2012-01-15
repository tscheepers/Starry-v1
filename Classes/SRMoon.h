//
//  Copyright (c) 2012, Infinite Droplets V.O.F.
//  All rights reserved.
//  
//  Starry was released under the BSD Licence
//

#import <Foundation/Foundation.h>
#import "OpenGLCommon.h"
#import "Texture2D.h"

@interface SRMoon : NSObject {
	Vertex3D position;
	int phase;
	
	Texture2D* nameTexture;
}

-(void)recalculatePosition:(NSDate*)theDate;
-(void)draw;
-(Vertex3D)myCurrentPosition;

@property (readonly) Vertex3D position;
@property (readonly) int phase;


@end
