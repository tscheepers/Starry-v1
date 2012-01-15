//
//  Copyright (c) 2012, Infinite Droplets V.O.F.
//  All rights reserved.
//  
//  Starry was released under the BSD Licence
//

#import "SterrenAppDelegate.h"
#import "GLView.h"
#import "SRLocation.h"
#import "SRObjectManager.h"
#import "ConstantsAndMacros.h"
#import "SRLocation.h"

@implementation SterrenAppDelegate

@synthesize window, glView, uiElementsView, location, timeManager, objectManager, settingsManager;

- (void)applicationDidFinishLaunching:(UIApplication *)application {
    
    NSLog(@"\n #\n #           _        __ _       _ _             _                 _      _       \n #          (_)      / _(_)     (_) |           | |               | |    | |      \n #           _ _ __ | |_ _ _ __  _| |_ ___    __| |_ __ ___  _ __ | | ___| |_ ___ \n #          | | '_ \\|  _| | '_ \\| | __/ _ \\  / _` | '__/ _ \\| '_ \\| |/ _ \\ __/ __|\n #          | | | | | | | | | | | | ||  __/ | (_| | | | (_) | |_) | |  __/ |_\\__ \\ \n #          |_|_| |_|_| |_|_| |_|_|\\__\\___|  \\__,_|_|  \\___/| .__/|_|\\___|\\__|___/\n #                                                          | |                   \n #                                                          |_|  \n # \n");
	
	objectManager = [[SRObjectManager alloc] init];
	location = [[SRLocation alloc] init];
	timeManager = [[SRTimeManager alloc] init];
	settingsManager = [[SRSettingsManager alloc] init];
	
	// Loading screen annimation;
	glView.animationInterval = 1.0 / kRenderingFrequency;
	[glView startAnimation];
    
}

- (void)applicationWillResignActive:(UIApplication *)application {
	glView.animationInterval = 1.0 / kInactiveRenderingFrequency;
}


- (void)applicationDidBecomeActive:(UIApplication *)application {
	glView.animationInterval = 1.0 / 60.0;
}

- (void)applicationWillTerminate:(UIApplication *)application {
	// De locatie opslaan voor het geval de applicatie opnieuw opstart
	NSUserDefaults *prefs = [NSUserDefaults standardUserDefaults];
	[prefs setFloat:	[location latitude]						forKey:@"SRlat"];
	[prefs setFloat:	[location longitude]					forKey:@"SRlong"];
	[prefs setBool:		[location staticValues]					forKey:@"SRstaticCoordinates"];
	[prefs setBool:		[settingsManager showRedOverlay]		forKey:@"SRshowRedOverlay"];
	[prefs setBool:		[settingsManager showConstellations]	forKey:@"SRshowConstellations"];
	[prefs setBool:		[settingsManager showPlanetLabels]		forKey:@"SRshowPlanetLabels"];
	[prefs setBool:		[settingsManager showPositionOverlay]	forKey:@"SRshowPositionOverlay"];
	[prefs setBool:		[location useCompass]					forKey:@"SRuseCompass"];
	[prefs setFloat:	[settingsManager brightnessFactor]		forKey:@"SRbrightness"];
	[prefs synchronize];
}

- (void)dealloc {
	[window release];
	[glView release];
	[super dealloc];
}

@end
