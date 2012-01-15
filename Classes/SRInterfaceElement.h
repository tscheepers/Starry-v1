//
//  Copyright (c) 2012, Infinite Droplets V.O.F.
//  All rights reserved.
//  
//  Starry was released under the BSD Licence
//

#import <Foundation/Foundation.h>
#import "Texture2D.h"

@interface SRInterfaceElement : NSObject {
	CGRect bounds;
	Texture2D* texture;
	NSString* identifier;
	BOOL clickable;
}

@property (assign) CGRect bounds;
@property (assign) Texture2D* texture;
@property (assign) NSString* identifier;
@property (assign) BOOL clickable;


-(id)initWithBounds:(CGRect)theBounds texture:(Texture2D*)theTexture identifier:(NSString*)theIdentifier clickable:(BOOL)isClickable;

@end
