//
//  SBDGroupChannelChangeLogsParams.h
//  SendBirdSDK
//
//  Created by Wooyoung Chung on 5/20/20.
//  Copyright © 2020 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SBDGroupChannelListQuery;

NS_ASSUME_NONNULL_BEGIN

/// An object that represents the parameters for the The method returns channels according to the properties in this object.
/// @note This class is available 3.0.182
@interface SBDGroupChannelChangeLogsParams : NSObject

/// Sets the custom types filter.
/// The property filters channels which have one of custom types.
/// @since 3.0.182
@property (nonatomic) NSArray<NSString *> *customTypes;

/// Determines whether to include the empty channels in the results.
/// @note The default value is `YES`.
/// @since 3.0.182
@property (atomic) BOOL includeEmptyChannel;

/// Determines whether to include the frozen channels in the results.
/// @note The default value is `YES`.
/// @since 3.0.182
@property (atomic) BOOL includeFrozenChannel;


/// Create `SBDGroupChannelChangeLogsParams` from a given SBDGroupChannelListQuery instance.
/// @param query group channel list query
/// @return A created instance of `SBDGroupChannelChangeLogsParams`
/// @since 3.0.185
+ (nonnull SBDGroupChannelChangeLogsParams *)createWithGroupChannelListQuery:(nullable SBDGroupChannelListQuery *)query;

@end

NS_ASSUME_NONNULL_END
