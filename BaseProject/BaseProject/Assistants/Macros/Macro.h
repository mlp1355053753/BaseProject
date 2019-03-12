//
//  Macro.h
//  BaseProject
//
//  Created by apple on 2019/3/12.
//  Copyright © 2019 mlp. All rights reserved.
//

#ifndef Macro_h
#define Macro_h


/**
 * 获取系统对象
 */
#define kApplication        [UIApplication sharedApplication]
#define kAppWindow          [UIApplication sharedApplication].delegate.window
#define kAppDelegate        [FCAppDelegate shareAppDelegate]
#define kRootViewController [UIApplication sharedApplication].delegate.window.rootViewController
#define kTOP_VIEW            [[UIApplication sharedApplication] keyWindow].rootViewController.view
#define kUserDefaults       [NSUserDefaults standardUserDefaults]
#define kNotificationCenter [NSNotificationCenter defaultCenter]


/**
 * 添加、移除、发送 通知
 */
#define NotificationCenterAddObserver(x, y, z)  [[NSNotificationCenter defaultCenter] addObserver: self selector: x name: y object: z]
#define NotificationCenterRemoveObserver        [[NSNotificationCenter defaultCenter] removeObserver:self]
#define KPostNotification(name,obj) [[NSNotificationCenter defaultCenter] postNotificationName:name object:obj];


/**
 * 获取 IDFA 和 UUID
 */
#define kIDFA    [[[ASIdentifierManager sharedManager] advertisingIdentifier] UUIDString]
#define kUUID   [[[UIDevice currentDevice] identifierForVendor] UUIDString]


/**
 * 获取屏幕宽和高
 */
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 80000 // 当前Xcode支持iOS8及以上
#define kSCREEN_WIDTH       ([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)]?[UIScreen mainScreen].nativeBounds.size.width/[UIScreen mainScreen].nativeScale:[UIScreen mainScreen].bounds.size.width)
#define kSCREENH_HEIGHT     ([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)]?[UIScreen mainScreen].nativeBounds.size.height/[UIScreen mainScreen].nativeScale:[UIScreen mainScreen].bounds.size.height)
#define kSCREEN_SIZE        ([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)]?CGSizeMake([UIScreen mainScreen].nativeBounds.size.width/[UIScreen mainScreen].nativeScale,[UIScreen mainScreen].nativeBounds.size.height/[UIScreen mainScreen].nativeScale):[UIScreen mainScreen].bounds.size)
#else
#define kSCREEN_WIDTH       [UIScreen mainScreen].bounds.size.width
#define kSCREENH_HEIGHT     [UIScreen mainScreen].bounds.size.height
#define kSCREEN_SIZE        [UIScreen mainScreen].bounds.size
#endif

//状态栏、导航条、tabar 高度
#define kHEIGHT_TABBAR     (kIPhoneX ? 83.0f : 49.0f)
#define kHEIGHT_STATUS     (kIPhoneX ? 44.0f : 20.0f)
#define kHEIGHT_NAVIBAR    44.0f

#define kSCREEN_WIDTH_320 dSCREEN_WIDTH <= 320.0
#define Iphone6ScaleWidth KScreenWidth/375.0
#define Iphone6ScaleHeight KScreenHeight/667.0
// 根据ip6的屏幕来拉伸
#define kRealValue(with) ((with)*(kSCREEN_WIDTH/375.0f))

// 像素
#define kPixelValue(s)         ([[UIScreen mainScreen] scale] > 0.0 ? 1.0 / [[UIScreen mainScreen] scale] : 1.0) * (s)


/**
 * 判断当前的iPhone设备/系统版本
 */
// 判断是否为iPhone
#define kIS_IPHONE (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
// 判断是否为 iPhone 4S/4
#define kIPhone4 [[UIScreen mainScreen] bounds].size.width == 320.0f && [[UIScreen mainScreen] bounds].size.height == 480.0f
// 判断是否为 iPhone 5SE
#define kIPhone5SE [[UIScreen mainScreen] bounds].size.width == 320.0f && [[UIScreen mainScreen] bounds].size.height == 568.0f

// 判断是否为iPhone 6/6s/7
#define kIPhone6_6s [[UIScreen mainScreen] bounds].size.width == 375.0f && [[UIScreen mainScreen] bounds].size.height == 667.0f

// 判断是否为iPhone 6Plus/6sPlus/7PLus
#define kIPhone6Plus_6sPlus [[UIScreen mainScreen] bounds].size.width == 414.0f && [[UIScreen mainScreen] bounds].size.height == 736.0f

// 判断是否为iPhone X
#define kIPhoneX [UIScreen mainScreen].bounds.size.width == 375.0f && [UIScreen mainScreen].bounds.size.height == 812.0f


/**
 * 获取系统版本
 */
#define kIOS_SYSTEM_VERSION [[[UIDevice currentDevice] systemVersion] floatValue]

//判断 iOS 8 或更高的系统版本
#define kIOS_VERSION_8_OR_LATER (([[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0)? (YES):(NO))

//判断 iOS 9 或更高的系统版本
#define kIOS_VERSION_9_OR_LATER (([[[UIDevice currentDevice] systemVersion] floatValue] >= 9.0)? (YES):(NO))

//判断 iOS系统版本为x版本或更晚的版本 (包含x版本)
#define kIOS_VERSION_OR_LATER(x) (([[[UIDevice currentDevice] systemVersion] floatValue] >= x)? (YES):(NO))

//判断 iOS系统版本为x版本更早的版本 (不包含x版本)
#define kIOS_VERSION_EARLIER(x) (([[[UIDevice currentDevice] systemVersion] floatValue] < x)? (YES):(NO))


/**
 * 沙盒目录文件
 */
//获取temp
#define kPathTemp NSTemporaryDirectory()

//获取沙盒 Document
#define kPathDocument [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]

//获取沙盒 Cache
#define kPathCache [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject]


/**
 * GCD
 */
//GCD - 一次性执行
#define kDISPATCH_ONCE_BLOCK(onceBlock) static dispatch_once_t onceToken; dispatch_once(&onceToken, onceBlock);

//GCD - 在Main线程上运行
#define kDISPATCH_MAIN_THREAD(mainQueueBlock) dispatch_async(dispatch_get_main_queue(), mainQueueBlock);

//GCD - 开启异步线程
#define kDISPATCH_GLOBAL_QUEUE_DEFAULT(globalQueueBlock) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), globalQueueBlocl);


/**
 * 颜色
 */
#define CREATECOLOR(r, g, b, a)        [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:(a)]
#define kHEXCOLOR(c)      [UIColor colorWithRed:((c>>16)&0xFF)/255.0 green:((c>>8)&0xFF)/255.0 blue:(c&0xFF)/255.0 alpha:1.0]
#define kHEXCOLOR_ALPHA(c, a) [UIColor colorWithRed:((c>>16)&0xFF)/255.0 green:((c>>8)&0xFF)/255.0 blue:(c&0xFF)/255.0 alpha:a]
#define kRANDOM_COLOR     [UIColor colorWithHue:(arc4random() % 256 / 256.f) saturation:(arc4random() % 128 / 256.f) + .5f brightness:(arc4random() % 128 / 256.f) + .5f alpha:1.f]


/**
 * 字体 9系统及之后用平方字体
 */
#define kFONT(s)               kIOS_VERSION_9_OR_LATER ? [UIFont pingFangRegularWithSize:s] : [UIFont systemFontOfSize:s]
#define kFONT_BOLD(s)          kIOS_VERSION_9_OR_LATER ? [UIFont pingFangSemiboldWithSize:s] : [UIFont boldSystemFontOfSize:s]


/**
 * 判断数组 和 字典 是否为空
 */
#define kIsNOTNullOrEmptyOfArray(_ARRAY___) (_ARRAY___ && [_ARRAY___ isKindOfClass:[NSArray class]] && [_ARRAY___ count])
#define kIsNOTNullOrEmptyOfDictionary(_DICTIONARY___) (_DICTIONARY___ && [_DICTIONARY___ isKindOfClass:[NSDictionary class]] && [_DICTIONARY___ count])


/**
 * 设置NSError
 */
#define kSetNSErrorFor(FUNC, ERROR_VAR, FORMAT,...)    \
if (ERROR_VAR) {    \
NSString *errStr = [NSString stringWithFormat:@"%s: " FORMAT,FUNC,##__VA_ARGS__]; \
*ERROR_VAR = [NSError errorWithDomain:@"NSCocoaErrorDomain" \
code:-1    \
userInfo:[NSDictionary dictionaryWithObject:errStr forKey:NSLocalizedDescriptionKey]]; \
}
#define kSetNSError(ERROR_VAR, FORMAT,...) kSetNSErrorFor(__func__, ERROR_VAR, FORMAT, ##__VA_ARGS__)


/**
 * 打印
 */
#ifdef RELEASE
#define NSLog(format, ...)
#else
#define NSLog(format, ...) printf("[%s] %s [第%d行] %s\n", __TIME__, __FUNCTION__, __LINE__, [[NSString stringWithFormat:format, ## __VA_ARGS__] UTF8String]);
#endif


/**
 * 拼接字符串
 */
#define NSStringFormat(format,...) [NSString stringWithFormat:format,##__VA_ARGS__]
//转换Integer为字符串
#define kNSStringFromInteger(section)    [NSString stringWithFormat: @"%@", @(section)]


/**
 * 数据验证
 */
#define StrValid(f) (f!=nil && [f isKindOfClass:[NSString class]] && ![f isEqualToString:@""])
#define SafeStr(f) (StrValid(f) ? f:@"")
#define HasString(str,eky) ([str rangeOfString:key].location!=NSNotFound)

#define ValidStr(f) StrValid(f)
#define ValidDict(f) (f!=nil && [f isKindOfClass:[NSDictionary class]])
#define ValidArray(f) (f!=nil && [f isKindOfClass:[NSArray class]] && [f count]>0)
#define ValidNum(f) (f!=nil && [f isKindOfClass:[NSNumber class]])
#define ValidClass(f,cls) (f!=nil && [f isKindOfClass:[cls class]])
#define ValidData(f) (f!=nil && [f isKindOfClass:[NSData class]])


/**
 * 设置系统时间
 */
#define SET_SYSTEM_DATE(x)              [(AppDelegate *)([UIApplication sharedApplication].delegate) setSystemDate:(x)]
#define GET_SYSTEM_DATE                 [(AppDelegate *)([UIApplication sharedApplication].delegate) getSystemTime]
#define GET_SYSTEM_DATE_STRING          [(AppDelegate *)([UIApplication sharedApplication].delegate) getSystemTimeString]
#define GET_RUNNING_TIME                [(AppDelegate *)([UIApplication sharedApplication].delegate) start_time]
/**
 * 获取一段时间间隔
 */
#define kStartTime CFAbsoluteTime start = CFAbsoluteTimeGetCurrent();
#define kEndTime  NSLog(@"Time: %f", CFAbsoluteTimeGetCurrent() - start)


/**
 * 设置 View 圆角
 */
#define ViewRadius(View, Radius)\
\
[View.layer setCornerRadius:(Radius)];\
[View.layer setMasksToBounds:YES]

// radians 转为 Degrees
#define RADIANS_TO_DEGREES(radians) ((radians) * (180.0 / M_PI))
// Degrees 转为 radians
#define DEGREES_TO_RADIANS(angle) ((angle) / 180.0 * M_PI)


/**
 * 单线
 */
#define SINGLE_LINE_WIDTH           (1.0f / [UIScreen mainScreen].scale)
#define SINGLE_LINE_ADJUST_OFFSET   ((1.0f / [UIScreen mainScreen].scale) / 2)


/**
 * 分页
 */
#define kGloabPageSize              @"20"


//-----------------------系统权限设置路径(iOS8以后适用)---------------------
//url
#define kSettingURL [NSURL URLWithString:UIApplicationOpenSettingsURLString]
//跳到设置_iOS8
#define kGoToSetting if([[UIApplication sharedApplication] canOpenURL:SettingURL]) { \
[[UIApplication sharedApplication] openURL:SettingURL];}
//跳到设置_iOS10
#define kGoToSetting_iOS10 if([[UIApplication sharedApplication] canOpenURL:SettingURL]) { \
[[UIApplication sharedApplication] openURL:[NSURL URLWithString:UIApplicationOpenSettingsURLString] options:@{} completionHandler:^(BOOL success) { \
\
}];}


#endif /* Macro_h */
