//
//  Copyright (c) 2012, Infinite Droplets V.O.F.
//  All rights reserved.
//  
//  Starry was released under the BSD Licence
//

#import <Foundation/Foundation.h>
#import <OpenGLES/EAGL.h>
#import <OpenGLES/ES1/gl.h>
#import <OpenGLES/ES1/glext.h>

@class SRTimeModule;

@interface SRTimeManager : NSObject {
	NSDate* simulatedDate;
		
	int totalInterval;
	int speed;
	int speedPause;
	float elapsed;
	
	SRTimeModule* moduleInstance;
	
	NSCalendar* gregorian;
	
	BOOL playing;
}

@property (readonly) NSDate* simulatedDate;
@property (assign) int totalInterval;
@property (assign) int speed;
@property (assign) SRTimeModule *moduleInstance;
@property (readonly) float elapsed;
@property (readonly) BOOL playing;

-(id)init;
-(NSString*)theTime;
-(NSString*)theDate;
-(int)speed;
-(void)tickOfTime:(NSTimeInterval)timeElapsed;
-(void)fwd;
-(void)rew;
-(void)reset;
-(void)playPause;
-(BOOL)isGoingFast;

@end
