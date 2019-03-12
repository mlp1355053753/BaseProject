//
//  ReleaseConfigMacro.h
//  BaseProject
//
//  Created by apple on 2019/3/12.
//  Copyright © 2019 mlp. All rights reserved.
//


/*/********************* 重要的项目内配置文件，发布AppStore时一定要注意检查 *****************************
 
 1、检查证书
 2、接口地址改为正式环境：BaseURLMacro.h 类中
 3、版本号信息：NPVersionMacro_h 类中
 4、修改地址功能是否关闭
 5、有无写死的测试代码
 6、BundleID如果修改，注意接入腾讯人脸识别的license需要同步需改（server端）
 
 ***************************************************************************************************///


#ifndef ReleaseConfigMacro_h
#define ReleaseConfigMacro_h


//使用摇一摇修改IP地址功能能打开宏  《发布时》或不使用时《必须注释本宏》
#ifdef DEBUG
#define kUSE_SHAKE_WINDOW
#endif

//注意： 《如果是！！！！非！！！企业版发布》注释掉下面的宏定义
// 友盟推送
#define UMKey_EnterPrise
// Bugly
#define BuglyKey_EnterPrise


#endif /* ReleaseConfigMacro_h */
