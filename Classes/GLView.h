//
//  Copyright (c) 2012, Infinite Droplets V.O.F.
//  All rights reserved.
//  
//  Starry was released under the BSD Licence
//


#import <UIKit/UIKit.h>
#import <OpenGLES/EAGL.h>
#import <OpenGLES/ES1/gl.h>
#import <OpenGLES/ES1/glext.h>

@protocol GLViewDelegate
- (void)drawView:(UIView *)theView;
- (void)setupView:(UIView *)theView;
@end

@interface GLView : UIView 
{
    
@private

    GLint backingWidth;
    GLint backingHeight;
    
    EAGLContext *context;    
    GLuint viewRenderbuffer, viewFramebuffer;
    GLuint depthRenderbuffer;
    
    NSTimer *animationTimer;
    NSTimeInterval animationInterval;
    
    id <GLViewDelegate>     delegate; //GLViewController
}
@property NSTimeInterval animationInterval;
@property (readwrite,assign) /* weak ref */ id <GLViewDelegate> delegate;
- (void)startAnimation;
- (void)stopAnimation;
- (void)drawView;
@end
