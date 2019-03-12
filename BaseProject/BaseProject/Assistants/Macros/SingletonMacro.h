//
//  SingletonMacro.h
//  BaseProject
//
//  Created by apple on 2019/3/12.
//  Copyright © 2019 mlp. All rights reserved.
//

#ifndef SingletonMacro_h
#define SingletonMacro_h

#if __has_feature(objc_arc)

#define dSINGLETON_FOR_CLASS_HEADER(classname) \
\
+ (classname *)sharedInstance;

#define dSINGLETON_FOR_CLASS(classname) \
\
static classname *shared##classname = nil; \
\
+ (classname *)sharedInstance \
{ \
static dispatch_once_t pred; \
dispatch_once(&pred, ^{ shared##classname = [[classname alloc] init]; }); \
return shared##classname; \
}

#else

#define dSINGLETON_FOR_CLASS_HEADER(classname) \
\
+ (classname *)sharedInstance;

#define dSINGLETON_FOR_CLASS(classname) \
\
static classname *shared##classname = nil; \
\
+ (classname *)sharedInstance \
{ \
static dispatch_once_t pred; \
dispatch_once(&pred, ^{ shared##classname = [[classname alloc] init]; }); \
return shared##classname; \
} \

#endif

#endif /* SingletonMacro_h */
