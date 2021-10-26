//
//  SBDMessageListQuery.h
//  SendBirdSDK
//
//  Created by Jed Gyeong on 6/2/16.
//  Copyright © 2016 SENDBIRD.COM. All rights reserved.
//

#import "SBDBaseChannel.h"

/**
 *  An object which retrieves messages from the given channel. The instance of this class is created by [`createPreviousMessageListQuery`](../Classes/SBDBaseChannel.html#//api/name/createPreviousMessageListQuery) in `SBDBaseChannel` class.
 */
@interface SBDPreviousMessageListQuery : NSObject

/**
 *  Sets the number of messages per page. The default value is 30.
 *  @since 3.0.106
 */
@property (atomic) NSUInteger limit;

/**
 *  Sets the order of messages. If YES, the latest message is the index 0. The default value is NO.
 *  @since 3.0.106
 */
@property (atomic) BOOL reverse;

/**
 *  Sets the message type to filter messages. The default value is `SBDMessageTypeFilterAll`.
 *
 *  @since 3.0.106
 *  @see Combined with `setMessageTypeFilter:`.
 */
@property (nonatomic) SBDMessageTypeFilter messageTypeFilter;

/**
 Sets the reply type to filter messages. The default value is `SBDReplyTypeNone`.
 @since 3.0.236
 */
@property (nonatomic) SBDReplyType replyType;


/**
 *  Sets the custom type to filter messages.
 *
 *  @since 3.0.106
 *  @see Combined with `setCustomTypeFilter:`.
 */
@property (copy, nonatomic, nullable) NSString *customTypeFilter;

/**
 *  Sets the custom types to filter messages.
 *
 *  @since 3.0.213
 *  @see Combined with `setCustomTypesFilter:`.
 */
@property (copy, nonatomic, nullable) NSArray<NSString *> *customTypesFilter;

/**
 *  Sets the senders' user IDs filter.
 *
 *  @since 3.0.106
 *  @see Combined with `setSenderUserIdsFilter:`.
 */
@property (copy, nonatomic, nullable) NSArray <NSString *> *senderUserIdsFilter;

/**
 If YES, the messages to be returned by `loadPreviousMessagesWithLimit:reverse:completionHandler:` have meta array.
 @since 3.0.116
 */
@property (nonatomic) BOOL includeMetaArray;

/**
 If YES, the messages to be returned by `loadPreviousMessagesWithLimit:reverse:completionHandler:` have reactions.
 @since 3.0.168
 */
@property (nonatomic) BOOL includeReactions;

/// Determines whether replies are included in the results.
/// @note The default value is `NO`.
/// @since 3.0.181
/// @deprecated 3.0.236 (Use `replyType` instead.)
@property (atomic) BOOL includeReplies
DEPRECATED_ATTRIBUTE;

/// Determines whether to include the parent message text in the results when the messages are replies in a thread. If the type of the parent message is [`SBDUserMessage`](../Classes/SBDUserMessage.html), the value is a [`message`](../Classes/SBDUserMessage.html#//api/name/message). If it is [`SBDFileMessage`](../Classes/SBDFileMessage.html), the value is the [`name`](../Classes/SBDFileMessage.html#//api/name/name) of the uploaded file.
/// @note The default value is `NO`.
/// @since 3.0.181
/// @deprecated 3.0.236 (Use `includeParentMessageInfo` instead.)
@property (atomic) BOOL includeParentMessageText
DEPRECATED_ATTRIBUTE;

/// Determines whether to include the thread information of the messages in the results when the results contain parent messages.
/// @note The default value is `NO`.
/// @since 3.0.181
@property (atomic) BOOL includeThreadInfo;

/// Determines whether to include poll information of the message in the results
/// @note The default value is `NO`
/// @since 3.0.232
@property (atomic) BOOL includePollDetails;

/// Determines whether to include only messages from the subChannel to which you belong in the results.
/// @note The default value is `NO`.
/// @warning This value is only used in open channels.
/// @since 3.0.204
@property (atomic) BOOL showSubChannelMessagesOnly;

/// Determines whether to include parent message information of the messages in the results when the results contain reply messages.
/// @note The default value is `NO`.
/// @since 3.0.236
@property (atomic) BOOL includeParentMessageInfo;


/**
 *  DO NOT USE this initializer. Use `[SBDBaseChannel createPreviousMessageListQuery]` instead.
 */
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wnullability"
- (nullable instancetype)init NS_UNAVAILABLE;
#pragma clang diagnostic pop

/**
 *  Shows if the query is loading.
 *
 *  @return Returns YES if the query is loading, otherwise returns NO.
 */
- (BOOL)isLoading;

/**
 *  Loads previous messages.
 *
 *  @param limit             The number of messages per page.
 *  @param reverse           If yes, the latest message is the index 0.
 *  @param completionHandler The handler block to execute. The `messages` is the array of `SBDBaseMessage` instances.
 */
- (void)loadPreviousMessagesWithLimit:(NSInteger)limit
                              reverse:(BOOL)reverse
                    completionHandler:(nullable void (^)(NSArray<SBDBaseMessage *> * _Nullable messages, SBDError * _Nullable error))completionHandler;

/**
 *  Loads previous messages.
 *
 *  @param completionHandler The handler block to execute. The `messages` is the array of `SBDBaseMessage` instances.
 */
- (void)loadWithCompletionHandler:(nullable void (^)(NSArray<SBDBaseMessage *> * _Nullable messages, SBDError * _Nullable error))completionHandler;

@end
