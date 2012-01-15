//
//  Copyright (c) 2012, Infinite Droplets V.O.F.
//  All rights reserved.
//  
//  Starry was released under the BSD Licence
//

#import "SRSettingsManager.h"


@implementation SRSettingsManager

@synthesize brightnessFactor,showRedOverlay,showConstellations, showPlanetLabels, showPositionOverlay;

-(id)init {
	if([super init]) {
		NSUserDefaults* prefs = [NSUserDefaults standardUserDefaults];
		
		brightnessFactor = [prefs floatForKey:@"SRbrightness"];
		if(brightnessFactor <= 0) {
			brightnessFactor = 1.0;
		}
		showConstellations = [prefs boolForKey:@"SRshowConstellations"];
		showRedOverlay = [prefs boolForKey:@"SRshowRedOverlay"];
		showPlanetLabels = [prefs boolForKey:@"SRshowPlanetLabels"];
		showPositionOverlay = [prefs boolForKey:@"SRshowPositionOverlay"];
		
	}
	return self;
}
-(void)setBrightnessFactor:(double)factor {
	if (factor > 3) {
		brightnessFactor = 3;
	}
	else if (factor < 0.5) {
		brightnessFactor = 0.5;
	}
	else {
		brightnessFactor = factor;
	}
}
@end
