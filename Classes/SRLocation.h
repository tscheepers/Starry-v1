//
//  Copyright (c) 2012, Infinite Droplets V.O.F.
//  All rights reserved.
//  
//  Starry was released under the BSD Licence
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "GLView.h"
#import "OpenGLCommon.h"

@interface SRLocation : NSObject <CLLocationManagerDelegate> {
	CLLocationManager *	locationManager;
	CLLocation *		myLocation;
	
	id interfaceDelegate;
	float longitude;
	float latitude;
	BOOL staticValues;
	BOOL useCompass;
	float heading;
}

@property (nonatomic, retain) CLLocationManager *locationManager; 
@property (nonatomic,readwrite) BOOL useCompass;
@property (readwrite, assign) float longitude;
@property (readwrite, assign) float latitude;
@property (readonly) BOOL staticValues;

- (void)locationManager:(CLLocationManager *)manager
    didUpdateToLocation:(CLLocation *)newLocation
           fromLocation:(CLLocation *)oldLocation;

- (void)locationManager:(CLLocationManager *)manager
       didFailWithError:(NSError *)error;


- (void)makeAwareOfInterface:(id)aInterface;
- (void)useStaticValues;
- (void)useGPSValues;


@end
