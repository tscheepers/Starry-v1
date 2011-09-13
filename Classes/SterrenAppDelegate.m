//
//  SterrenAppDelegate.m
//
//  A part of Sterren.app, planetarium iPhone application.
//  Created by: Jan-Willem Buurlage and Thijs Scheepers
//  Copyright 2006-2009 Mote of Life. All rights reserved.
//
//  Use without premission by Mote of Life is not authorised.
//
//  Mote of Life is a registred company at the Dutch Chamber of Commerce.
//  Chamber of Commerce registration number: 37126951
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
    
    NSLog(@"\n #\n #           _        __ _       _ _             _                 _      _       \n #          (_)      / _(_)     (_) |           | |               | |    | |      \n #           _ _ __ | |_ _ _ __  _| |_ ___    __| |_ __ ___  _ __ | | ___| |_ ___ \n #          | | '_ \\|  _| | '_ \\| | __/ _ \\  / _` | '__/ _ \\| '_ \\| |/ _ \\ __/ __|\n #          | | | | | | | | | | | | ||  __/ | (_| | | | (_) | |_) | |  __/ |_\\__ \\ \n #          |_|_| |_|_| |_|_| |_|_|\\__\\___|  \\__,_|_|  \\___/| .__/|_|\\___|\\__|___/\n #                                                          | |                   \n #                                                          |_|  \n # \n # Welkom l337 h4x0r,\n # \n # Dit is een Starry door Jan-Willem Buurlage & Infinite Droplets!\n # \n # Zoek je nog een baantje in de buurt van Enschede? http://infinitedroplets.com/werken_bij_id.html\n # \n # Dit is: %@\n # Versie: %@ \n #",
          [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleIdentifier"],
          [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleVersion"]);
	
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
