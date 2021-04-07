//
//  SBDReactionEvent.h
//  SendBirdSDK
//
//  Created by Jed Gyeong on 2/13/20.
//  Copyright © 2020 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBDTypes.h"

/// Class to store reaction event info. The object is returned by not only the completion handler of [`addReactionWithMessage:key:completionHandler:`](../Classes/SBDBaseChannel.html#//api/name/addReactionWithMessage:key:completionHandler:) and [`deleteReactionWithMessage:key:completionHandler:`](../Classes/SBDBaseChannel.html#//api/name/deleteReactionWithMessage:key:completionHandler:) in `SBDBaseChannel` class but also [`channel:updatedReaction:`](../Protocols/SBDChannelDelegate.html#//api/name/channel:updatedReaction:) delegate of `SBDChannelDelegate` protocol. The object has to be applied to the message that has the identical message ID with the [`applyReactionEvent:`](../Classes/SBDBaseMessage.html#//api/name/applyReactionEvent:) method in `SBDBaseMessage` class.
/// @note This class is available in 3.0.169
@interface SBDReactionEvent : NSObject

/// Message ID that indentifies the message that has the reaction event.
/// @since 3.0.169
@property (nonatomic, readonly) long long messageId;

/// The reaction key.
/// @since 3.0.169
@property (strong, nonnull, readonly) NSString *key;

/// The user ID that identifies the user who adds or deletes the reaction key.
/// @since 3.0.169
@property (strong, nonnull, readonly) NSString *userId;

/// The operation that the user did. It will be adding a reaction or deleting a reaction.
/// @since 3.0.169
@property (atomic, readonly) SBDReactionEventAction operation;

/// The timestamp that represents when the reaction event occurs.
/// @since 3.0.169
@property (atomic, readonly) long long updatedAt;

@end
