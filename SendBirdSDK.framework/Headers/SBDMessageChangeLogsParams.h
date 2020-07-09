//
//  SBDMessageChangeLogsParams.h
//  SendBirdSDK
//
//  Created by Jed Gyeong on 5/6/20.
//  Copyright © 2020 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SBDPreviousMessageListQuery;
@class SBDMessageListParams;

/// An object that represents the parameters for the [`getMessageChangeLogsSinceTimestamp:params:completionHandler:`](../Classes/SBDBaseChannel.html#//api/name/getMessageChangeLogsSinceTimestamp:params:completionHandler:) and the [`getMessageChangeLogsSinceToken:params:completionHandler:`](../Classes/SBDBaseChannel.html#//api/name/getMessageChangeLogsSinceToken:params:completionHandler:) methods. The methods return updated messages and the IDs of deleted messages along with additional data according to the properties in this object.
/// @note This class is available from 3.0.181
@interface SBDMessageChangeLogsParams : NSObject <NSCopying>

/// Determines whether to include the metaarray information of the updated messages in the results.
/// @note The default value is `NO`.
/// @since 3.0.181
@property (atomic) BOOL includeMetaArray;

/// Determines whether to include the reactions of the updated messages in the results.
/// @note The default value is `NO`.
/// @since 3.0.181
@property (atomic) BOOL includeReactions;

/// Determines whether to include the replies of the updated messages in the results.
/// @note The default value is `NO`.
/// @since 3.0.181
@property (atomic) BOOL includeReplies;

/// Determines whether to include the parent message text in the results when the updated messages are threaded replies. If the type of the parent message is [`SBDUserMessage`](../Classes/SBDUserMessage.html), the value is a [`message`](../Classes/SBDUserMessage.html#//api/name/message). If it is [`SBDFileMessage`](../Classes/SBDFileMessage.html), the value is the [`name`](../Classes/SBDFileMessage.html#//api/name/name) of the uploaded file.
/// @note The default value is `NO`.
/// @since 3.0.181
@property (atomic) BOOL includeParentMessageText;

/// Determines whether to include the thread information of the updated messages in the results when the results contain parent messages.
/// @note The default value is `NO`.
/// @since 3.0.181
@property (atomic) BOOL includeThreadInfo;


/// Create `SBDPreviousMessageListQuery` from a given SBDPreviousMessageListQuery instance.
/// @param query previous message list query
/// @return A created instance of `SBDMessageChangeLogsParams`
/// @since 3.0.185
+ (nonnull SBDMessageChangeLogsParams *)createWithPreviousMessageListQuery:(nullable SBDPreviousMessageListQuery *)query;

/// Create `SBDMessageListParams` from a given SBDMessageListParams instance.
/// @param params previous message list query
/// @return A created instance of `SBDMessageChangeLogsParams`
/// @since 3.0.185
+ (nonnull SBDMessageChangeLogsParams *)createWithMessageListParams:(nullable SBDMessageListParams *)params;


@end
