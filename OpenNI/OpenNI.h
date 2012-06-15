//
//  OpenNICocoa.h
//  OpenNICocoa
//
//  Created by Daniel Shein on 1/17/12.
//  Copyright (c) 2012 LoFT. All rights reserved.
//

#import <Foundation/Foundation.h>

#pragma warning(push,0)
#import <XnOS.h>
#import <XnCppWrapper.h>
#import <XnOpenNI.h>
#import <XnCodecIDs.h>
#import <XnVNite.h>
#pragma warning(pop)

#import "Point3D.h"

typedef enum
{
    GestureTypeClick,
    GestureTypeWave,
    GestureTypeSwipeLeft,
    GestureTypeSwipeRight,    
    GestureTypeRaiseHand
} GestureType;


@protocol OpenNIDelegate <NSObject>

@required

- (void) openNiInitCompleteWithStatus:(NSNumber *)status andError:(NSError*)error;

@optional

- (void) frameReady;

- (void) userDidEnterWithId:(NSNumber *)nId;
- (void) userDidLeaveWithId:(NSNumber *)nId;

- (void) handDidBeginAt:(NSDictionary *)point forUserId:(NSNumber *)nId;
- (void) handDidMoveAt:(NSDictionary *)point forUserId:(NSNumber *)nId;
- (void) handDidStopForUserId:(NSNumber *)nId;

- (void) gestureRecognizedAt:(NSDictionary*)point withName:(NSString *)gestureName;

@end

@interface OpenNI : NSObject
{
    //Content Variables
    const XnDepthPixel *_depthMap;
    const XnUInt8 *_rgb;
    const XnLabel *_userLabelsMap;
    
    xn::DepthMetaData _depthMetaData;
    xn::ImageMetaData _imageMetaData;
    xn::SceneMetaData _sceneMetaData;
    
    CGSize _fullResolution, _croppedResolution, _offset;
}

@property (readonly) const XnDepthPixel *depthMap;
@property (readonly) const XnUInt8 *rgb;
@property (readonly) const XnLabel *userLabelsMap;
@property (readonly) CGSize fullResolution, croppedResolution, offset;

+ (OpenNI*) instance;
- (void) initOpenNiWithConfigFile:(NSString*)pathToConfigFile;
- (void) initOpenNi;
- (void) dealloc;

- (void) addDelegate:(id)delegate;
- (void) removeDelegate:(id)delegate;

- (XnStatus) startGeneratingFrames;
- (void) stopGeneratingFrames;

- (void) startRecordingToFile:(NSString*)filePath;
- (void) stopRecording;

- (void) startTrackingHandAtPosition:(Point3D*)point;
- (void) stopTrakcingHandWithUserId:(XnUserID)userId;

- (void) startDetectingGesture:(GestureType)gesture;
- (void) stopDetectingGesture:(GestureType)gesture;

@end
