//
//  IDModuleController.h
//  Campus App
//
//  Created by Thijs Scheepers on 02-05-11.
//  Copyright 2011 Infinite Droplets. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface IDModuleController : NSObject {
    NSString* moduleAbsoluteName;
    NSString* moduleVersionString;
    BOOL firstFetch;
    
    UINavigationController* navController;
   
}

@property (nonatomic, retain) NSString *moduleAbsoluteName;
@property (nonatomic, retain) NSString *moduleVersionString;
@property (readonly) BOOL firstFetch;

@property (nonatomic, retain) UINavigationController *navController;

// Methoden toepasbaar voor alle modules

- (void) fetchData;
- (NSURLRequest*) getURLRequestWithForcedDownload:(BOOL)forced;
- (void) announceViewController:(UIViewController*)viewController;

@end
