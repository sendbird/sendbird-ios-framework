//
//  SBDOGMetaData.h
//  SendBirdSDK
//
//  Created by Wooyoung Chung on 6/18/20.
//  Copyright © 2020 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class SBDOGImage;

/// Represents OpenGraph information
/// @since 3.0.193
@interface SBDOGMetaData : NSObject

/// The title of object as it should appear within the graph
@property (nonatomic, copy, readonly, nullable) NSString *title;

/// The canonical URL of object that will be used as its permanent ID in the graph
@property (nonatomic, copy, readonly, nullable) NSString *url;

/// A one to two sentence description of object.
@property (nonatomic, copy, readonly, nullable) NSString *desc;

/// An image object which should represent the object within the graph
@property (nonatomic, strong, readonly, nullable) SBDOGImage *defaultImage;

@end

NS_ASSUME_NONNULL_END

