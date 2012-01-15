//
//  Copyright (c) 2012, Infinite Droplets V.O.F.
//  All rights reserved.
//  
//  Starry was released under the BSD Licence
//

#import "SRInterfaceElement.h"


@implementation SRInterfaceElement

@synthesize bounds, texture, identifier, clickable;

-(id)initWithBounds:(CGRect)theBounds texture:(Texture2D*)theTexture identifier:(NSString*)theIdentifier clickable:(BOOL)isClickable {
	if(self = [super init]) {
		bounds = theBounds;
		texture = theTexture;
		identifier = theIdentifier;
		clickable = isClickable;
	}
	return self;
}

- (void) dealloc {
	[texture release];
	[identifier release];
	[super dealloc];
}

@end
