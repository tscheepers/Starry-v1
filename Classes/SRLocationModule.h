//
//  Copyright (c) 2012, Infinite Droplets V.O.F.
//  All rights reserved.
//  
//  Starry was released under the BSD Licence
//


#import <Foundation/Foundation.h>
#import "SRModule.h"
#import "SRInterfaceElement.h"
#import "SRLocation.h"
#import "Texture2D.h"

@interface SRLocationModule : SRModule {
	SRLocation* locationManager;
	
	float longitude;
	float latitude;
	
	BOOL latVisible;
	BOOL longVisible;
	
	BOOL GPS;
	BOOL Compass;
}

@property (readonly) float latitude;
@property (readonly) float longitude;
@property (readonly) SRLocation* locationManager;
@property (readwrite) BOOL latVisible;
@property (readwrite) BOOL longVisible;
@property (readonly) BOOL GPS;
@property (readonly) BOOL Compass;

-(id)initWithSRLocation:(SRLocation*)aLocation;
-(void)updateDisplayedLocationData;

-(void)toggleGPS;
-(void)toggleCompass;

/*-(void)hideLongitude;
-(void)showLongitude;
-(void)hideLatitude;
-(void)showLatitude;*/

@end
