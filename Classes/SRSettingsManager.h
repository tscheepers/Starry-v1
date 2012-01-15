//
//  Copyright (c) 2012, Infinite Droplets V.O.F.
//  All rights reserved.
//  
//  Starry was released under the BSD Licence
//

#import <Foundation/Foundation.h>


@interface SRSettingsManager : NSObject {
	double brightnessFactor;
	BOOL showConstellations;
	BOOL showRedOverlay;

	BOOL showPlanetLabels;
	BOOL showPositionOverlay;
}

@property (nonatomic,readwrite) double brightnessFactor;
@property (nonatomic,readwrite) BOOL showConstellations;
@property (nonatomic,readwrite) BOOL showPlanetLabels;

@property (nonatomic,readwrite) BOOL showPositionOverlay;
@property (nonatomic,readwrite) BOOL showRedOverlay;

@end
