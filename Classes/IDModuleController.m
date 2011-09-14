//
//  IDModuleController.m
//  Campus App
//
//  Created by Thijs Scheepers on 02-05-11.
//  Copyright 2011 Infinite Droplets. All rights reserved.
//

#import "IDModuleController.h"
#import <sys/utsname.h>


@implementation IDModuleController

@synthesize moduleAbsoluteName,moduleVersionString,firstFetch,
            navController;

- (id) init {
    
    self = [super init];
    if (self) {
        
        moduleAbsoluteName = [[NSString alloc] initWithString:@"unknown"];
        moduleVersionString = [[NSString alloc] initWithString:@"unknown"];
        firstFetch = YES;  
        
    }
    return self;
}

- (void) fetchData {
    firstFetch = NO;
}

- (void) setModuleAbsoluteName:(NSString *)aModuleAbsoluteName {
    
    [moduleAbsoluteName release];
    moduleAbsoluteName = aModuleAbsoluteName;
}

- (void) setModuleVersionString:(NSString *)aModuleVersionString {
    
    [moduleVersionString release];
    moduleVersionString = aModuleVersionString;
}

- (void) announceViewController:(UIViewController*)viewController {
    
    navController = [[UINavigationController alloc] initWithRootViewController:viewController];
    [[navController navigationBar] setTintColor:[UIColor colorWithRed:0/255.f
                                                               green:30/255.f
                                                                blue:115/255.f
                                                               alpha:1]];
    [[navController navigationBar] setTranslucent:YES];
}
    
- (NSURLRequest*) getURLRequestWithForcedDownload:(BOOL)forced {
    
    struct utsname systemInfo;
    uname(&systemInfo);
    
    NSMutableDictionary* postData = [[NSMutableDictionary alloc] init];
    // Collecting system data
    [postData setObject: [[UIDevice currentDevice] uniqueIdentifier]                                    forKey:@"deviceId"];
    [postData setObject: [[UIDevice currentDevice] name]                                                forKey:@"deviceName"];
    [postData setObject: [NSString stringWithCString:systemInfo.machine encoding:NSUTF8StringEncoding]  forKey:@"deviceModel"];
    [postData setObject: [[UIDevice currentDevice] systemName]                                          forKey:@"systemName"];
    [postData setObject: [[UIDevice currentDevice] systemVersion]                                       forKey:@"systemVersion"];
    // Sending download options
    [postData setObject: [NSString stringWithFormat:@"%@",forced?@"true":@"false"]                      forKey:@"forcedDownload"];
    [postData setObject: moduleAbsoluteName                                                             forKey:@"module"];
    [postData setObject: moduleVersionString                                                            forKey:@"moduleVersion"];
    [postData setObject: [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleVersion"]       forKey:@"version"];
    [postData setObject: [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleIdentifier"]    forKey:@"app"];
    
    NSString* postString = [[NSString alloc] init];
    
    for (id dataKey in postData) {
        NSString * stringOfKey = (NSString*) dataKey;
        NSString * stringOfValue = [postData objectForKey:stringOfKey];
        
        // Encoding
        stringOfKey   = [stringOfKey    stringByAddingPercentEscapesUsingEncoding: NSUTF8StringEncoding];
        stringOfValue = [stringOfValue  stringByAddingPercentEscapesUsingEncoding: NSUTF8StringEncoding];
        
        if([postString length] == 0) {
            postString = [postString stringByAppendingFormat:@"%@=%@",stringOfKey,stringOfValue];
        } else {
            postString = [postString stringByAppendingFormat:@"&%@=%@",stringOfKey,stringOfValue];
        }
    }
    
    [postData release];
    
    NSLog(@"Er wordt om druppeltjes uit de wolk gevraagt met een regendans: \n      %@",[postString stringByReplacingOccurrencesOfString:@"&" withString:@"\n      "]);
    
    NSURL* url = [[NSURL alloc] initWithString:@"http://ideeapp.com/iphone-test"];
   
    NSMutableURLRequest *request = [[NSMutableURLRequest alloc] initWithURL:url];
    
    [url release];
    
    [request setHTTPMethod:@"POST"];
    [request setHTTPBody:[postString dataUsingEncoding:NSUTF8StringEncoding]];
    
    //[postString release];
    
    return (NSURLRequest*)request;
}

@end
