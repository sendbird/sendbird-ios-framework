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
/// @since 3.1.0
@interface SBDMessageCollection : SBDBaseCollection

/// Message collection delegate.
/// @since 3.1.0
@property (weak, nullable) id<SBDMessageCollectionDelegate> delegate;

/// Starting point of the collection.
/// @since 3.1.0
@property (atomic, readonly) long long startingPoint;

/// If YES, there may be the messages on the next page.
/// @since 3.1.0
@property (atomic, readonly) BOOL hasNext;

/// If YES, there may be the messages on the previous page.
/// @since 3.1.0
@property (atomic, readonly) BOOL hasPrevious;

/// @since 3.1.0
@property (atomic, nullable, readonly) SBDMessageListParams *params;

/// The channel object that the message collection has.
/// @since 3.1.0
@property (strong, nonnull, readonly) SBDGroupChannel *channel;

/// Initializes the message collection with the starting point and the parameter.
/// @param channel Channel object.
/// @param startingPoint Starting point where the message collection loads messages from.
/// @param params Message list parameter.
/// @since 3.1.0
- (instancetype)initWithChannel:(SBDGroupChannel *)channel
                  startingPoint:(long long)startingPoint
                         params:(SBDMessageListParams *)params;

/// Starts the message collection with the policy. The result of the
/// @param initPolicy The policy for the message collection.
/// @param cacheResultHandler The callback to call when the messages are loaded from the cache. The `messages` is the messages that are loaded from the cache. The `error` will be returned when the loading message failed.
/// @param apiResultHandler The callback to call when the messages are loaded from the server. The `messages` is the messages that are loaded from the server. The `error` will be returned when the loading message failed.
/// @since 3.1.0
- (void)startCollectionWithInitPolicy:(SBDMessageCollectionInitPolicy)initPolicy
                   cacheResultHandler:(nullable void (^)(NSArray<SBDBaseMessage *> * _Nullable messages, SBDError * _Nullable error))cacheResultHandler
                     apiResultHandler:(nullable void (^)(NSArray<SBDBaseMessage *> * _Nullable messages, SBDError * _Nullable error))apiResultHandler;

/// Invalidates the object.
/// @since 3.1.0
- (void)dispose;

/// Loads messages of the next page.
/// @param completionHandler The callback to call when the load is complete. The `error` will be returned when the loading message failed.
/// @since 3.1.0
- (void)loadNextWithCompletionHandler:(nullable void (^)(NSArray<SBDBaseMessage *> * _Nullable messages, SBDError * _Nullable error))completionHandler;

/// Loads messages of the previous page.
/// @param completionHandler The callback to call when the load is complete. The `error` will be returned when the loading message failed.
/// @since 3.1.0
- (void)loadPreviousWithCompletionHandler:(nullable void (^)(NSArray<SBDBaseMessage *> * _Nullable messages, SBDError * _Nullable error))completionHandler;

/// Returns the succeeded messages that are already loaded in memory.
/// @since 3.1.0
- (nonnull NSArray<SBDBaseMessage *> *)getSucceededMessages;

/// Returns the pending messages that are already loaded in memory.
/// @since 3.1.0
- (nonnull NSArray<SBDBaseMessage *> *)getPendingMessages;

/// Returns the failed messages that are already loaded in memory.
/// @since 3.1.0
- (nonnull NSArray<SBDBaseMessage *> *)getFailedMessages;

/// Removes failed messages from DB.
/// @params messages The failed messages to be removed from DB.
/// @param completionHandler The callback to call when the method is complete. The `error` will be returned when the removing failed messages failed.
/// @since 3.1.0
- (void)removeFailedMessages:(nonnull NSArray<SBDBaseMessage *> *)messages
           completionHandler:(nullable void (^)(NSArray<NSString *> * _Nullable requestIds,
                                                SBDError * _Nullable error))completionHandler;

/// Removes all failed messages.
/// @param completionHandler The callback to call when the method is complete. The `error` will be returned when the removing failed messages failed.
/// @since 3.1.0
- (void)removeAllFailedMessagesWithCompletionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

@end

NS_ASSUME_NONNULL_END
