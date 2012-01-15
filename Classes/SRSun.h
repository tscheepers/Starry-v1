//
//  Copyright (c) 2012, Infinite Droplets V.O.F.
//  All rights reserved.
//  
//  Starry was released under the BSD Licence
//


#import <Foundation/Foundation.h>
#import "SRPlanetaryObject.h"

@class SRRenderer;

@interface SRSun : SRPlanetaryObject {
	float ra;
	float dec;
}

//-(id)initWithEarth:(SRPlanetaryObject*)earth;
-(float)height:(float)latitude lon:(float)longitude elapsed:(float)elapsed;

@end
