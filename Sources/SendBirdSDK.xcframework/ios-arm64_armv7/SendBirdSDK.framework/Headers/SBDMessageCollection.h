//
//  SBDMessageCollection.h
//  SendBirdSDK
//
//  Created by Jed Gyeong on 5/24/21.
//  Copyright © 2021 SENDBIRD.COM. All rights reserved.
//

#import "SBDBaseCollection.h"
#import "SBDGroupChannel.h"
#import "SBDMessageListParams.h"
#import "SBDMessageCollectionDelegate.h"
#import "SBDBaseChannel.h"
#import "SBDMain.h"
#import "SBDTypes.h"

NS_ASSUME_NONNULL_BEGIN

/// An object that accesses the cache for the messages.
/// @since 3.0.227
@interface SBDMessageCollection : SBDBaseCollection

/// Message collection delegate.
@property (weak, nullable) id<SBDMessageCollectionDelegate> delegate;

/// Starting point of the collection.
@property (atomic, readonly) long long startingPoint;

/// If YES, there may be the messages on the next page.
@property (atomic, readonly) BOOL hasNext;

/// If YES, there may be the messages on the previous page.
@property (atomic, readonly) BOOL hasPrevious;

/// Initializes the message collection with the starting point and the parameter.
/// @param channel Channel object.
/// @param startingPoint Starting point where the message collection loads messages from.
/// @param params Message list parameter.
- (instancetype)initWithChannel:(SBDGroupChannel *)channel
                  startingPoint:(long long)startingPoint
                         params:(SBDMessageListParams *)params;

/// Starts the message collection with the policy. The result of the
/// @param initPolicy The policy for the message collection.
/// @param cacheResultHandler The callback to call when the messages are loaded from the cache. The `messages` is the messages that are loaded from the cache. The `error` will be returned when the loading message failed.
/// @param apiResultHandler The callback to call when the messages are loaded from the server. The `messages` is the messages that are loaded from the server. The `error` will be returned when the loading message failed.
- (void)startCollectionWithInitPolicy:(SBDInitPolicy)initPolicy
                   cacheResultHandler:(nullable void (^)(NSArray<SBDBaseMessage *> * _Nullable messages, SBDError * _Nullable error))cacheResultHandler
                     apiResultHandler:(nullable void (^)(NSArray<SBDBaseMessage *> * _Nullable messages, SBDError * _Nullable error))apiResultHandler;

/// Invalidates the object.
- (void)invalidate;

/// Loads messages of the next page.
/// @param completionHandler The callback to call when the load is complete. The `error` will be returned when the loading message failed.
- (void)loadNextWithCompletionHandler:(nullable void (^)(NSArray<SBDBaseMessage *> * _Nullable messages, SBDError * _Nullable error))completionHandler;

/// Loads messages of the previous page.
/// @param completionHandler The callback to call when the load is complete. The `error` will be returned when the loading message failed.
- (void)loadPreviousWithCompletionHandler:(nullable void (^)(NSArray<SBDBaseMessage *> * _Nullable messages, SBDError * _Nullable error))completionHandler;

@end

NS_ASSUME_NONNULL_END
