//
//  VersionMacro.h
//  BaseProject
//
//  Created by apple on 2019/3/12.
//  Copyright © 2019 mlp. All rights reserved.
//

#ifndef VersionMacro_h
#define VersionMacro_h


#ifdef UMKey_EnterPrise
#define kDISTRIBUTECHANNEL  @"ios1"              /**< 推广渠道代号， 渠道名称：ios1 ， 企业版本*/
#else
#define kDISTRIBUTECHANNEL  @"ios"              /**< 推广渠道代号， 渠道名称：ios ，*/
#endif

#define kVERSIONCODE        @"001"              /**< 应用版本code，每次发包递增 */
#define kCLIENTTYPE         @"1"                /**< 1:App 2:PC 3:H5 */
#define kDVICE_BRAND        @"iPhone"           /**< iPhone, xiaomi*/
#define kCHANNEL            @"fanka"            /**< 产品渠道 */
#define kH5Ref              @"fcApp"            /**< H5的Referer */
#define kOSType             @"2"                /**< 系统类型 (1:android 2:iOS) */
#define kGetWay             @"1"                /**< 下载渠道(1,app store) */

#define kUS                 @"app store"     //待定

#define loginSMSReqType             @"1"    /**< 登录验证码的请求类型，0:h5  1.其他 */

#pragma mark - 埋点相关的初始版本号和channel
#define kTRACKINGINITIALVERSION     @"1"
#define kTRACKINGCHANNEL            @"fcapp"


#endif /* VersionMacro_h */
