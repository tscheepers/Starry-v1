//
//  Copyright (c) 2012, Infinite Droplets V.O.F.
//  All rights reserved.
//  
//  Starry was released under the BSD Licence
//

#import <UIKit/UIKit.h>
#import "SRLocation.h"
#import "SRObjectManager.h"
#import "SRSettingsManager.h"

@class GLView;

@interface SterrenAppDelegate : NSObject <UIApplicationDelegate> {
    UIWindow *window;
    GLView *glView;
	UIView *uiElementsView;
	SRLocation* location;
	SRTimeManager* timeManager;
	SRObjectManager * objectManager;
	SRSettingsManager * settingsManager;
	
}

@property (nonatomic, retain) IBOutlet UIWindow *window;
@property (nonatomic, retain) IBOutlet GLView *glView;
@property (nonatomic, retain) IBOutlet UIView *uiElementsView;
@property (readonly) SRObjectManager * objectManager;
@property (readonly) SRSettingsManager* settingsManager;
@property (readonly) SRLocation* location;
@property (readonly) SRTimeManager* timeManager;

@end

