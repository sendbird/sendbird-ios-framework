//
//  SBDConstants.h
//  SendBirdSDK
//
//  Created by sendbird-young on 12/10/2018.
//  Copyright © 2018 SENDBIRD.COM. All rights reserved.
//

#ifndef SBDConstants_h
#define SBDConstants_h

#import <Foundation/Foundation.h>
#import "SBDError.h"
#import "SBDTypes.h"

@class SBDGroupChannel, SBDOpenChannel;
@class SBDBaseMessage, SBDUserMessage, SBDFileMessage;
@class SBDUser;
@class SBDError;
@class SBDReactionEvent;
@class SBDPoll, SBDPollOption;

typedef void (^SBDOpenChannelHandler)(SBDOpenChannel * _Nullable channel, SBDError * _Nullable error);
typedef void (^SBDUserMessageHandler)(SBDUserMessage * _Nullable message, SBDError * _Nullable error);
typedef void (^SBDFileMessageHandler)(SBDFileMessage * _Nullable message, SBDError * _Nullable error);
typedef void (^SBDBaseMessageHandler)(SBDBaseMessage * _Nullable message, SBDError * _Nullable error);
typedef void (^SBDGetMessagesHandler)(NSArray<SBDBaseMessage *> * _Nullable messages, SBDError * _Nullable error);
typedef void (^SBDBinaryProgressHandler)(int64_t bytesSent, int64_t totalBytesSent, int64_t totalBytesExpectedToSend);
typedef void (^SBDMessageChangeLogsHandler)(NSArray<SBDBaseMessage *> * _Nullable updatedMessages,
                                            NSArray<NSNumber *> * _Nullable deletedMessageIds,
                                            BOOL hasMore,
                                            NSString * _Nullable token,
                                            SBDError * _Nullable error);
typedef void(^SBDChannelChangeLogsHandler)(NSArray <SBDGroupChannel *> * _Nullable updatedChannels,
                                           NSArray <NSString *> * _Nullable deletedChannelUrls,
                                           BOOL hasMore,
                                           NSString * _Nullable token,
                                           SBDError * _Nullable error);
typedef void(^SBDSnoozePeriodHandler)(BOOL enabled,
                                      long long startTimestamp,
                                      long long endTimestamp,
                                      SBDError * _Nullable error);
typedef void(^SBDPushTriggerOptionHandler)(SBDPushTriggerOption pushTriggerOption,
                                           SBDError * _Nullable error);
typedef void(^SBDGetPushTokensHandler)(NSArray<NSString *> * _Nonnull pushTokens,
                                       SBDPushTokenType pushTokenType,
                                       BOOL hasMore,
                                       NSString * _Nullable token,
                                       SBDError * _Nullable error);
typedef void(^SBDGroupChannelPushTriggerOptionHandler)(SBDGroupChannelPushTriggerOption pushTriggerOption,
                                                       SBDError * _Nullable error);
typedef void(^SBDErrorHandler)(SBDError * _Nullable error);
typedef void(^SBDVoidHandler)(void);
typedef void(^SBDUserHandler)(SBDUser * _Nullable user, SBDError * _Nullable error);
typedef void(^SBDPollHandler)(SBDPoll * _Nullable poll, SBDError * _Nullable error);
typedef void(^SBDPollListHandler)(NSArray <SBDPoll *> * _Nullable polls,
                                  NSString * _Nullable token,
                                  SBDError * _Nullable error);
typedef void(^SBDPollOptionHandler)(SBDPollOption * _Nullable poll, SBDError * _Nullable error);
typedef void(^SBDVoterListHandler)(NSArray <SBDUser *> * _Nullable users,
                                  NSInteger voteCount,
                                  NSString * _Nullable token,
                                  SBDError * _Nullable error);

/// Posted immediately after a change in the channel collection object.
/// @since 3.0.227
extern NSString * _Nonnull const SBDGroupChannelCollectionChangeNotification;

/// Posted immediately after a change in the message collection object.
/// @since 3.0.227
extern NSString * _Nonnull const SBDMessageCollectionChangeNotification;

#endif /* SBDConstants_h */
