//
//  Copyright (c) 2012, Infinite Droplets V.O.F.
//  All rights reserved.
//  
//  Starry was released under the BSD Licence
//

#import "SRModule.h"


@implementation SRModule

@synthesize visible, hiding, alphaValue, xValueIcon, initialXValueIcon, elements, keyboardVisible;

-(void)show {
	xValueIcon = initialXValueIcon;
	alphaValue = 0.0f;
	visible = YES;
	hiding = FALSE;
}

-(void)hide {
	hiding = TRUE;
}

-(void)draw {
	//std drawing?
}

@end
