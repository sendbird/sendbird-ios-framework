//
//  SBDBaseMessageParams.h
//  SendBirdSDK
//
//  Created by sendbird-young on 2018. 3. 5..
//  Copyright © 2018년 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBDTypes.h"
#import "SBDMessageMetaArray.h"

@class SBDUser;

/**
 *  The `SBDBaseMessageParams` class represents the base class which has parameters to create a channel or update a channel. The `SBDUserMessageParams`, the `SBDFileMessageParams` are derived from this class.
 */
@interface SBDBaseMessageParams : NSObject <NSCopying>

/**
 *  Message data. The default value is nil.
 *
 *  @since 3.0.90
 */
@property (copy, nonatomic, nullable) NSString *data;

/**
 *  Customize message's type to filter. The default value is nil.
 *
 *  @since 3.0.90
 */
@property (copy, nonatomic, nullable) NSString *customType;

/**
 The push notification delivery option that determines how to deliver the push notification when sending a user or a file message. The default value is `SBDPushNotificationDeliveryOptionDefault`.
 */
@property (nonatomic) SBDPushNotificationDeliveryOption pushNotificationDeliveryOption;

/**
 Meta array keys.
 @deprecated in 3.0.179 Use `metaArrays` instead
 */
@property (copy, nonatomic, nullable) NSArray<NSString *> *metaArrayKeys DEPRECATED_ATTRIBUTE;

/**
 Meta array with keys and values
 @since 3.0.179
 */
@property (copy, nonatomic, nullable) NSArray<SBDMessageMetaArray *> *metaArrays;

/**
 *
 *  @since 3.0.103
 */
@property (nonatomic) SBDMentionType mentionType;

/**
 *  Can mention to specific users.
 *  If sends a message with this field, the message will be arrived to mentioned users.
 *  The default value is nil.
 *
 *  @since 3.0.90
 */
@property (copy, nonatomic, nullable) NSArray <NSString *> *mentionedUserIds;

/**
 *  Can set the `mentionedUserIds` by this method either.
 *
 *  @param mentionedUsers The list of users will be receive mention.
 *  @since 3.0.90
 */
- (void)setMentionedUsers:(nonnull NSArray <SBDUser *> *)mentionedUsers;

/// The unique ID of a parent message. A parent message is a message that has a thread of replies. If the message sent through the [`sendUserMessageWithParams:completionHandler:`](../Classes/SBDBaseChannel.html#//api/name/sendUserMessageWithParams:completionHandler:) or [`sendFileMessageWithParams:completionHandler:`](../Classes/SBDBaseChannel.html#//api/name/sendFileMessageWithParams:completionHandler:) method is a parent message, the value of this property is 0. If the message is a reply to a parent message, the value is the message ID of the parent message.
/// @note The default value is `0`.
/// @since 3.0.181
@property (atomic) long long parentMessageId;

@end
