//
//  Copyright (c) 2012, Infinite Droplets V.O.F.
//  All rights reserved.
//  
//  Starry was released under the BSD Licence
//

#import <Foundation/Foundation.h>
#import "OpenGLCommon.h"

@interface SRConstellationLine : NSObject {
	Vector3D start;
	Vector3D end;
}

@property (assign) Vector3D start;
@property (assign) Vector3D end;

@end
