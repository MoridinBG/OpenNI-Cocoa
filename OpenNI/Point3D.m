//
//  Point3D.m
//  OpenNI
//
//  Created by Daniel Shein on 2/5/12.
//  Copyright (c) 2012 LoFT. All rights reserved.
//

#import "Point3D.h"

@implementation Point3D
@synthesize x = _x;
@synthesize y = _y;
@synthesize z = _z;


- (id) initWithX:(float)x Y:(float)y Z:(float)z
{
    if (self = [super init])
    {
        _x = x;
        _y = y;
        _z = z;
    }
    
    return self;
}

- (id) initWithXnPoint:(const XnPoint3D*)point
{
    return [self initWithX:point->X Y:point->Y Z:point->Z];
}


+ (Point3D*) pointWithX:(float)x Y:(float)y Z:(float)z
{
    return [[Point3D alloc] initWithX:x Y:y Z:z];
}


+ (Point3D*) pointWithXnPoint:(const XnPoint3D*)point
{
    return [[Point3D alloc] initWithXnPoint:point];
}


- (const XnPoint3D) xnPoint3D
{
    XnPoint3D point;
    point.X = _x;
    point.Y = _y;
    point.Z = _z;
    
    return point;
}

- (NSString*) description
{
    return [NSString stringWithFormat:@"( %f, %f, %f )", _x, _y, _z];
}

@end
