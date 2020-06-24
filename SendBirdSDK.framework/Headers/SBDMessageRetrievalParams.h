//
//  SBDMessageRetrievalParams.h
//  SendBirdSDK
//
//  Created by Jed Gyeong on 5/14/20.
//  Copyright © 2020 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBDTypes.h"

/// An object that represents the parameters for the [`getMessageWithParams:completionHandler:`](../Classes/SBDBaseMessage.html#//api/name/getMessageWithParams:completionHandler:) method. The method returns the message defined by the properties in this object.
/// @note This class is available from 3.0.181
@interface SBDMessageRetrievalParams : NSObject <NSCopying>

/// Specifies the URL of the channel to retrieve the message.
/// @since 3.0.181
@property (strong, nonnull) NSString *channelUrl;

/// Specifies the type of the channel.
/// @since 3.0.181
@property (atomic) SBDChannelType channelType;

/// Specifies the unique ID of the message to retrieve.
/// @since 3.0.181
@property (atomic) long long messageId;

/// Determines whether the metaarray of the message is included in the results.
/// @since 3.0.181
@property (atomic) BOOL includeMetaArray;

/// Determines whether to include the parent message text in the results when the message is a reply in a thread. If the type of the parent message is `SBDUserMessage`, the value is a [`message`](../Classes/SBDUserMessage.html#//api/name/message). If it is [`SBDFileMessage`](../Classes/SBDFileMessage.html), the value is the [`name`](../Classes/SBDFileMessage.html#//api/name/name) of the uploaded file.
/// @note The default value is `NO`.
/// @since 3.0.181
@property (atomic) BOOL includeParentMessageText;

/// Determines whether to include the thread information of the message when it is a parent message.
/// @note The default value is `NO`.
/// @since 3.0.181
@property (atomic) BOOL includeThreadInfo;

@end
