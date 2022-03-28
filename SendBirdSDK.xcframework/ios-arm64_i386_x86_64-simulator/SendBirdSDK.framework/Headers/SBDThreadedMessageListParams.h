//
//  SBDThreadedMessageListParams.h
//  SendBirdSDK
//
//  Created by Jed Gyeong on 3/16/20.
//  Copyright © 2020 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SBDTypes.h"

/// An object that represents the parameters for the [`getThreadedMessagesByTimestamp:params:completionHandler:`](../Classes/SBDBaseMessage.html#//api/name/getThreadedMessagesByTimestamp:params:completionHandler:) method. The method returns messages according to the properties in this object.
/// @note This class is available from 3.0.181
@interface SBDThreadedMessageListParams : NSObject

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

/// Determines whether to include the parent message text in the results when the messages are replies in a thread. If the type of the parent message is [`SBDUserMessage`](../Classes/SBDUserMessage.html), the value is a [`message`](../Classes/SBDUserMessage.html#//api/name/message). If it is [`SBDFileMessage`](../Classes/SBDFileMessage.html), the value is the [`name`](../Classes/SBDFileMessage.html#//api/name/name) of the uploaded file.
/// @note The default value is `NO`.
/// @since 3.0.181
/// @deprecated 3.0.236  (Use `includeParentMessageInfo` instead.)
@property (nonatomic) BOOL includeParentMessageText
DEPRECATED_ATTRIBUTE;

/// Restricts the search scope only to retrieve the messages with the multiple specified custom message types. When the custom type filtering is not needed, the value should be set to `nil`.
/// @note The default value is `nil`.
/// @since 3.0.213
@property (strong, nonatomic, nullable) NSArray<NSString *> *customTypes;

/// @since 3.0.236
@property (atomic) BOOL includeParentMessageInfo;

@end
