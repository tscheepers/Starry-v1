//
//  Copyright (c) 2012, Infinite Droplets V.O.F.
//  All rights reserved.
//  
//  Starry was released under the BSD Licence
//

#import <Foundation/Foundation.h>
#import "SRModule.h"
#import "SRInterfaceElement.h"
#import "SRTimeManager.h"
#import "Texture2D.h"

@interface SRTimeModule : SRModule {
	SRTimeManager* manager;
}

@property (readonly) SRTimeManager* manager;

-(void)switchPlay:(BOOL)aFlag;

@end
