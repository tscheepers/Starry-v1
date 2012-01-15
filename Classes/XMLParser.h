//
//  Copyright (c) 2012, Infinite Droplets V.O.F.
//  All rights reserved.
//  
//  Starry was released under the BSD Licence
//

#import <UIKit/UIKit.h>
#import "SRObjectManager.h"
//#import "AQXMLParserDelegate.h";

@class SterrenAppDelegate, SRStar;

@interface XMLParser : NSObject {
	
	NSMutableString *currentElementValue;
	
	//SterrenAppDelegate *appDelegate;
	SRObjectManager *objectManager;
	SRStar *aStar;
	SRMessier*aMessier;
	SRConstellation *aConstellation;
	SRConstellationLine *aLine;
	Vector3D aPoint;
	
	BOOL stars; //1 = sterren, 0 = sterrenbeelden
	BOOL constellations;
	BOOL messier;
	BOOL start; //1 = start, 0 = end
}

- (XMLParser *) initXMLParser;

@end
