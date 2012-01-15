//
//  Copyright (c) 2012, Infinite Droplets V.O.F.
//  All rights reserved.
//  
//  Starry was released under the BSD Licence
//

#import <Foundation/Foundation.h>
#import "SRConstellationLine.h"
#import <OpenGLES/EAGL.h>
#import <OpenGLES/ES1/gl.h>
#import <OpenGLES/ES1/glext.h>
#import "OpenGLCommon.h"
#import "Texture2D.h"

@interface SRConstellation : NSObject {		
	NSMutableArray* lines;
	NSString* name;
	float ra;
	float dec;
	
	Texture2D* nameTexture;
	Vertex3D texturePosition;
	
	GLfloat constellationPoints[200];
}
	
@property (nonatomic, assign) float ra;
@property (nonatomic, assign) float dec;
@property (nonatomic, retain) NSMutableArray *lines;
@property (nonatomic, retain) NSString *name;
@property (nonatomic, retain) Texture2D *nameTexture;

-(void)calculateRADec;
-(void)draw;
-(void)drawText;
-(void)makeArray;

-(Vertex3D)myCurrentPosition;
-(NSString*)localizedName;

@end
