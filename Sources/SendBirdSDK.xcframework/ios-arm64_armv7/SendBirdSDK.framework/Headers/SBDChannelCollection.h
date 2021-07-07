//
//  SBDChannelCollection.h
//  SendBirdSDK
//
//  Created by Jed Gyeong on 4/22/21.
//  Copyright © 2021 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SBDBaseCollection.h"
#import "SBDChannelCollectionDelegate.h"
#import "SBDError.h"
#import "SBDGroupChannel.h"
#import "SBDGroupChannelListQuery.h"

NS_ASSUME_NONNULL_BEGIN

/// An object that accesses the cache for the group channels.
/// @since 3.0.227
@interface SBDChannelCollection : SBDBaseCollection<SBDConnectionDelegate>

/// The channels that the collection has fetched.
@property (strong, readonly) NSArray<SBDGroupChannel *> *channelList;

/// If YES, the next page might exist.
@property (atomic, readonly) BOOL hasNext;

/// Collection delegate.
@property (weak, nullable) id<SBDChannelCollectionDelegate> delegate;

/// Initializes the collection object.
/// @param query SBDGroupChannelListQuery object.
- (instancetype)initWithQuery:(SBDGroupChannelListQuery *)query;

/// Loads next page.
/// @param completionHandler The completion handler to be executed.
- (void)loadNextWithCompletionHandler:(nullable void (^)(NSArray<SBDGroupChannel *> * _Nullable channels, SBDError * _Nullable error))completionHandler;

/// Invalidates the object.
- (void)invalidate;

@end

NS_ASSUME_NONNULL_END
