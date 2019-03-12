//
//  UrlMacro.h
//  BaseProject
//
//  Created by apple on 2019/3/12.
//  Copyright © 2019 mlp. All rights reserved.
//

#ifndef UrlMacro_h
#define UrlMacro_h


#ifdef DEBUG

//测试环境
#define kDEFAULT_URL_HOST @"https://www.baidu.com"

#define kDEFAULT_URL_WEB @"http://news.baidu.com"

#else

//线上环境
#define kDEFAULT_URL_HOST @"https://www.hao123.com"

#define kDEFAULT_URL_WEB @"http://www.iqiyi.com"

#endif

/**
 * 测试环境支持修改地址
 */
#define kURL_HTTP_KEY @"URL_HOST_KEY"    // 缓存HTTP_URL的KEY
#define kURL_WEB_KEY @"URL_WEB_KEY"      // 缓存WEB_URL的KEY

//从缓存中读取URL
#define kCACHE_URL(key) [[NSUserDefaults standardUserDefaults] objectForKey:key]

//获取HTTP基础接口（如果缓存中存在则从缓存中获取，否则使用默认的接口）
#define kBASE_URL_HTTP  kCACHE_URL(URL_HOST_KEY) && ![kCACHE_URL(URL_HOST_KEY) isEqualToString:@""] ? kCACHE_URL(URL_HOST_KEY) : kDEFAULT_URL_HOST

//获取WEB基础接口（如果缓存中存在则从缓存中获取，否则使用默认的接口）
#define kBASE_URL_WEB  kCACHE_URL(kURL_WEB_KEY) && ![kCACHE_URL(kURL_WEB_KEY) isEqualToString:@""] ? kCACHE_URL(kURL_WEB_KEY) : kDEFAULT_URL_WEB


#endif /* UrlMacro_h */
