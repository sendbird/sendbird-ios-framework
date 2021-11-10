//
//  SBDMessageListParams.h
//  SendBirdSDK
//
//  Created by Jed Gyeong on 4/20/20.
//  Copyright © 2020 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBDTypes.h"

@class SBDBaseMessage;
@class SBDBaseMessageParams;

/// An object that represents the parameters for the [`getMessagesByTimestamp:params:completionHandler:`](../Classes/SBDBaseChannel.html#//api/name/getMessagesByTimestamp:params:completionHandler:) and the [`getMessagesByMessageId:params:completionHandler:`](../Classes/SBDBaseChannel.html#//api/name/getMessagesByMessageId:params:completionHandler:) methods. The methods return messages according to the properties in this object.
/// @note This class is available from 3.0.181
@interface SBDMessageListParams : NSObject <NSCopying>

/// The number of messages to retrieve that were sent before the specified timestamp or message ID.
/// @note The default value is `0`.
/// @since 3.0.181
@property (atomic) NSInteger previousResultSize;

/// The number of messages to retrieve that were sent after the specified timestamp or message ID.
/// @note The default value is `0`.
/// @since 3.0.181
@property (atomic) NSInteger nextResultSize;

/// Determines whether to include the messages with the matching timestamp or message ID in the results.
/// @note The default value is `NO`.
/// @since 3.0.181
@property (atomic) BOOL isInclusive;

/// Determines whether to sort the retrieved messages in reverse order. If `NO`, the results are in ascending order.
/// @note The default value is `NO`.
/// @since 3.0.181
@property (atomic) BOOL reverse;

/// Restricts the search scope only to retrieve the messages with the specified message type.
/// @note The default value is `SBDMessageTypeFilterAll`.
/// @since 3.0.181
@property (atomic) SBDMessageTypeFilter messageType;

/// Restricts the search scope only to retrieve the messages with the specified custom message type. When the custom type filtering is not needed, the value should be set to `nil`.
/// If the `customTypes` is set, this property is ignored.
/// @note The default value is `nil`.
/// @since 3.0.181
@property (strong, nullable) NSString *customType;

/// Restricts the search scope only to retrieve the messages sent by the users with the specified user IDs. When the user ID filtering is not needed, the value should be set to `nil`.
/// @note The default value is `nil`.
/// @since 3.0.181
@property (strong, nullable) NSArray<NSString *> *senderUserIds;

/// Determines whether to include the metaarray information of the messages in the results.
/// @note The default value is `NO`.
/// @since 3.0.181
@property (atomic) BOOL includeMetaArray;

/// Determines whether to include the reactions to the messages in the results.
/// @note The default value is `NO`.
/// @since 3.0.181
@property (atomic) BOOL includeReactions;

/// Determines whether to include the replies to the messages in the results.
/// @note The default value is `NO`.
/// @deprecated 3.0.236 (Use `replyType` instead.)
@property (nonatomic) BOOL includeReplies
DEPRECATED_ATTRIBUTE;

/// Determines whether to include the parent message text in the results when the messages are replies in a thread. If the type of the parent message is [`SBDUserMessage`](../Classes/SBDUserMessage.html), the value is a [`message`](../Classes/SBDUserMessage.html#//api/name/message). If it is [`SBDFileMessage`](../Classes/SBDFileMessage.html), the value is the [`name`](../Classes/SBDFileMessage.html#//api/name/name) of the uploaded file.
/// @note The default value is `NO`.
/// @deprecated 3.0.236 (Use `includeParentMessageInfo` instead.)
@property (nonatomic) BOOL includeParentMessageText
DEPRECATED_ATTRIBUTE;

/// Determines whether to include the thread information of the messages in the results when the results contain root messages.
/// @note The default value is `NO`.
/// @since 3.0.181
@property (atomic) BOOL includeThreadInfo;

/// Determines whether to include poll information of the message in the results
/// @note The default value is `NO`
/// @since 3.0.232
@property (atomic) BOOL includePollDetails;

/// Determines whether to include parent message info.
/// @note The default value is `NO`
/// @since 3.0.236
@property (atomic) BOOL includeParentMessageInfo;

/// Determines which reply types to include.
/// @note The default value is `SBDReplyTypeNone`
/// @since 3.0.236
@property (atomic) SBDReplyType replyType;

/// Determines whether to include only messages from the subChannel to which you belong in the results.
/// @note The default value is `NO`.
/// @warning This value is only used in open channels.
/// @since 3.0.204
@property (atomic) BOOL showSubChannelMessagesOnly;


/// Restricts the search scope only to retrieve the messages with the multiple specified custom message types. When the custom type filtering is not needed, the value should be set to `nil`.
/// @note The default value is `nil`.
/// @since 3.0.213
@property (strong, nonatomic, nullable) NSArray<NSString *> *customTypes;

/// Checks that the message belongs to the `SBDMessageListParams` object.
/// @param message The message object to be checked.
/// @return If YES, the message belongs to the `SBDMessageListParams` object.
/// @since 3.0.232
- (BOOL)belongsTo:(nonnull SBDBaseMessage *)message;

/// Checks that the messageParams belongs to the `SBDMessageListParams` object.
/// @param params The messageParams object to be checked.
/// @return If YES, the messageParams belongs to the `SBDMessageListParams` object.
/// @since 3.0.232
- (BOOL)belongsToMessageParams:(nonnull SBDBaseMessageParams *)params;
@end
