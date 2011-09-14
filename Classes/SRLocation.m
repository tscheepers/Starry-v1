//
//  SRLocation.m
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


#import "SRLocation.h"
#import "SRLocationModule.h"

@implementation SRLocation

@synthesize locationManager,latitude,longitude,staticValues,useCompass;

- (id) init {
    self = [super init];
    if (self != nil) {
        self.locationManager = [[[CLLocationManager alloc] init] autorelease];
        self.locationManager.delegate = self;
		myLocation = [[CLLocation alloc] init];
		
		// Locatie opvragen van vorige keer
		NSUserDefaults *prefs = [NSUserDefaults standardUserDefaults];
		staticValues = [prefs boolForKey:@"SRstaticCoordinates"];
		useCompass = [prefs boolForKey:@"SRuseCompass"];
		
		if (staticValues) {
			longitude = [prefs floatForKey:@"SRlong"];
			latitude = [prefs floatForKey:@"SRlat"];
		}
		else {
			[self useGPSValues];
		}
		
    }
    return self;
}

- (void)locationManager:(CLLocationManager *)manager
    didUpdateToLocation:(CLLocation *)newLocation
           fromLocation:(CLLocation *)oldLocation {
	
	myLocation = newLocation;
	longitude = myLocation.coordinate.longitude;
	latitude = myLocation.coordinate.latitude;
	
	/* Debug values 
	longitude = 4.874036;
	latitude = 52.741535;
	NSLog(@"Debug, setting longitude and latitude naar die van Schagen"); */
	
	if(interfaceDelegate && [interfaceDelegate isKindOfClass:[SRLocationModule class]]) {
		[(SRLocationModule*)interfaceDelegate updateDisplayedLocationData];
	}
	
}

- (void)locationManager:(CLLocationManager *)manager
	   didFailWithError:(NSError *)error {
	NSLog(@"Er is een probleem met het opvragen van de locatie: %@", [error description]);
}

- (void)makeAwareOfInterface:(id)aInterface {
	interfaceDelegate = aInterface;
	/* Misschien in de toekomst een array maken voor medere interfaces, bijvoorbeeld voor een lijst met plaatsten */
}


-(void)useStaticValues {
	// Als er geen locatie service is kan deze ook niet worden uitgezet
	
    [locationManager stopUpdatingLocation];
    staticValues = YES;
}

-(void)useGPSValues {
	if ([locationManager locationServicesEnabled]) {
		[locationManager startUpdatingLocation];
		staticValues = NO;
	}
	else {
		//NSLog(@"No location data allowed");
		staticValues = YES;
	}
}

- (void)dealloc {
    [locationManager release];
	[myLocation release];
    [super dealloc];
}

-(void)setLatitude:(float)latValue {
	
	if (staticValues) {
		NSLog(@"Latitude is geset op een statische waarde:%f",latValue);
		latitude = latValue;
		[interfaceDelegate updateDisplayedLocationData];
	}
}

-(void)setLongitude:(float)longValue {
	if (staticValues) {
		NSLog(@"Longitude is geset op een statische waarde:%f",longValue);
		longitude = longValue;
		[interfaceDelegate updateDisplayedLocationData];
	}
}

@end
