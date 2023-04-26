//
//  SBDOpenChannelParams.h
//  SendBirdSDK
//
//  Created by Tez Park on 2020/11/03.
//  Copyright © 2020 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SBDUser;

NS_ASSUME_NONNULL_BEGIN

/// The `SBDOpenChannelParams` class contain parameters for `open channel`. When you want to create a open channel or update a open channel, use this class. Add what you want to create with, add which properties you want to update, and pass this class to `SBDOpenChannel`. You can use this class with apis that are `[SBDOpenChannel createChannel:completionHandler:]` or `[SBDOpenChannel updateChannel:completionHandler:]`.
/// For more information, see [Open Channel](https://sendbird.com/docs/chat/v3/ios/guides/open-channel).
/// @since 3.0.206
@interface SBDOpenChannelParams : NSObject <NSCopying>

/// The name of the channel.
@property (nonatomic, strong, nullable) NSString *name;

/// The channel URL. If nil, channel url will be determined randomly.
@property (nonatomic, strong, nullable) NSString *channelUrl;

/// The cover url of open channel.
/// Please set it using the `setCoverUrl:` function.
@property (nonatomic, strong, nullable) NSString *coverUrl;

/// The cover image data of open channel.
/// Please set it using the `setCoverImage:coverImageName:` function.
@property (nonatomic, strong, nullable) NSData *coverImage;

/// The cover image file name of open channel.
/// Please set it using the `setCoverImage:coverImageName:` function.
@property (nonatomic, strong, nullable) NSString *coverImageName;

/// The data for channel.
@property (nonatomic, strong, nullable) NSString *data;

/// The operator user IDs of channel.
@property (nonatomic, strong, nullable) NSArray<NSString *> *operatorUserIds;

/// The custom type for channel.
@property (nonatomic, strong, nullable) NSString *customType;


/// Set operators with list of user instance.
/// @param operators The list of operators.
/// @see operatorUserIds
/// @since 3.0.206
- (void)setOperators:(NSArray <SBDUser *> *)operators;


@end

NS_ASSUME_NONNULL_END
