//
//  Point3D.h
//  OpenNI
//
//  Created by Daniel Shein on 2/5/12.
//  Copyright (c) 2012 LoFT. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <XnTypes.h>

@interface Point3D : NSObject
{
    float _x, _y, _z;
}

@property (nonatomic, assign) float x,y,z;

+ (Point3D*) pointWithXnPoint:(const XnPoint3D*) point;
+ (Point3D*) pointWithX:(float)x Y:(float)y Z:(float)z;

- (id) initWithX:(float)x Y:(float)y Z:(float)z;
- (id) initWithXnPoint:(const XnPoint3D*)point;
- (const XnPoint3D) xnPoint3D;

@end
