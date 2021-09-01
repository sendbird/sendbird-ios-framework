//
//  SBDPlugin.h
//  SendBirdSDK
//
//  Created by Wooyoung Chung on 11/10/20.
//  Copyright © 2020 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBDMappable.h"

NS_ASSUME_NONNULL_BEGIN

/// A object to represent a plugin
/// @since 3.0.207
@interface SBDPlugin : NSObject <SBDMappable>

/// String indicates a plugin type
@property (nonatomic, copy, readonly, nullable) NSString *type;

/// String indicates a vendor who provides this plugin
@property (nonatomic, copy, readonly, nullable) NSString *vendor;

/// Dictionary contains details of this plugin
/// Key is string and value is any object
@property (nonatomic, strong, readonly, nullable) NSDictionary<NSString *, NSObject *> *detail;

@end

NS_ASSUME_NONNULL_END
