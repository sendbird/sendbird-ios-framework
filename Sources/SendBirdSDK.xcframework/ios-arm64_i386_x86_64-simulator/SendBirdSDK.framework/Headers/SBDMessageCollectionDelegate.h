//
//  SBDMessageCollectionDelegate.h
//  SendBirdSDK
//
//  Created by Jed Gyeong on 5/24/21.
//  Copyright © 2021 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SBDMessageCollection.h"
#import "SBDMessageContext.h"
#import "SBDGroupChannel.h"

@class SBDMessageCollection;
@class SBDMessageContext;
@class SBDGroupChannel;

NS_ASSUME_NONNULL_BEGIN

/// Methods that are invoked when the event of the message collection occurs.
/// @since 3.1.0
@protocol SBDMessageCollectionDelegate <NSObject>

@optional

/// Invoked when the messages are added.
/// @param collection Message collection object.
/// @param context The reason why the messages are added.
/// @param channel The channel that has the messages.
/// @param messages Messages to be added.
/// @since 3.1.0
- (void)messageCollection:(SBDMessageCollection *)collection
                  context:(SBDMessageContext *)context
                  channel:(SBDGroupChannel *)channel
            addedMessages:(NSArray<SBDBaseMessage *> *)messages;

/// Invoked when the message are updated.
/// @param collection Message collection object.
/// @param context The reason why the messages are updated.
/// @param channel The channel that has the messages.
/// @param messages Messages to be updated.
/// @since 3.1.0
- (void)messageCollection:(SBDMessageCollection *)collection
                  context:(SBDMessageContext *)context
                  channel:(SBDGroupChannel *)channel
          updatedMessages:(NSArray<SBDBaseMessage *> *)messages;

/// Invoked when the message are deleted.
/// @param collection Message collection object.
/// @param context The reason why the messages are deleted.
/// @param channel The channel that has the messages.
/// @param messages Messages to be deleted.
/// @since 3.1.0
- (void)messageCollection:(SBDMessageCollection *)collection
                  context:(SBDMessageContext *)context
                  channel:(SBDGroupChannel *)channel
          deletedMessages:(NSArray<SBDBaseMessage *> *)messages;

/// Invoked when the channel that has the message collection is updated.
/// @param collection Message collection object.
/// @param context The reason why the channel are changed.
/// @param channel The channel that has the message collection has.
/// @since 3.1.0
- (void)messageCollection:(SBDMessageCollection *)collection
                  context:(SBDMessageContext *)context
           updatedChannel:(SBDGroupChannel *)channel;

/// Invoked when the channel that has the message collection is deleted.
/// @param collection Message collection object.
/// @param context The reason why the channel are deleted.
/// @param channelUrl Channel URL that has been deleted.
/// @since 3.1.0
- (void)messageCollection:(SBDMessageCollection *)collection
                  context:(SBDMessageContext *)context
           deletedChannel:(NSString *)channelUrl;

/// Invoked when the huge gap has been detected.
/// @param collection Message collection object.
/// @since 3.1.0
- (void)didDetectHugeGap:(SBDMessageCollection *)collection;

@end

NS_ASSUME_NONNULL_END
