//
//  SBDGroupChannelCollection.h
//  SendBirdSDK
//
//  Created by Jed Gyeong on 4/22/21.
//  Copyright © 2021 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SBDBaseCollection.h"
#import "SBDGroupChannelCollectionDelegate.h"
#import "SBDError.h"
#import "SBDGroupChannel.h"
#import "SBDGroupChannelListQuery.h"

NS_ASSUME_NONNULL_BEGIN

/// An object that accesses the cache for the group channels.
/// @since 3.1.0
@interface SBDGroupChannelCollection : SBDBaseCollection<SBDConnectionDelegate>

/// The channels that the collection has fetched.
/// @since 3.1.0
@property (strong, readonly) NSArray<SBDGroupChannel *> *channelList;

/// If YES, the next page might exist.
/// @since 3.1.0
@property (atomic, readonly) BOOL hasMore;

/// Collection delegate.
/// @since 3.1.0
@property (weak, nullable) id<SBDGroupChannelCollectionDelegate> delegate;

/// @since 3.1.0
@property (strong, nullable, readonly) SBDGroupChannelListQuery *query;

/// Initializes the collection object.
/// @param query SBDGroupChannelListQuery object.
/// @since 3.1.0
- (instancetype)initWithQuery:(SBDGroupChannelListQuery *)query;

/// Loads more page.
/// @param completionHandler The completion handler to be executed.
/// @since 3.1.0
- (void)loadMoreWithCompletionHandler:(nullable void (^)(NSArray<SBDGroupChannel *> * _Nullable channels, SBDError * _Nullable error))completionHandler;

/// Invalidates the object.
/// @since 3.1.0
- (void)dispose;

@end

NS_ASSUME_NONNULL_END
