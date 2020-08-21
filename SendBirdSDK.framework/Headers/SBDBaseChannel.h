//
//  SBDBaseChannel.h
//  SendBirdSDK
//
//  Created by Jed Gyeong on 5/19/16.
//  Copyright © 2016 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SBDUser.h"
#import "SBDUserMessage.h"
#import "SBDAdminMessage.h"
#import "SBDFileMessage.h"
#import "SBDError.h"
#import "SBDMember.h"
#import "SBDScheduledUserMessage.h"
#import "SBDScheduledUserMessageParams.h"
#import "SBDConstants.h"
#import "SBDThreadInfoUpdateEvent.h"
#import "SBDMessageChangeLogsParams.h"

@class SBDPreviousMessageListQuery, SBDOperatorListQuery;
@class SBDThumbnailSize;
@class SBDThumbnail;
@class SBDFileMessage;
@class SBDUserMessage;
@class SBDMessageListQuery;
@class SBDGroupChannel;
@class SBDOpenChannel;
@class SBDUserMessageParams, SBDFileMessageParams;


/// An object that adopts the `SBDChannelDelegate` protocol is responsible for receiving the events in the channel. Some of delegate methods are common for the `SBDBaseChannel`. However, there are delegate methods for the `SBDOpenChannel` and `SBDGroupChannel` exclusive. The `SBDChannelDelegate` can be added by [`addChannelDelegate:identifier:`](../Classes/SBDMain.html#//api/name/addChannelDelegate:identifier:) in `SBDMain`. Every `SBDChannelDelegate` method which is added is going to receive events.
/// @warning If the object that adopts the `SBDChannelDelegate` protocol is invalid, the delegate has to be removed by the identifier via [`removeChannelDelegateForIdentifier:`](../Classes/SBDMain.html#//api/name/removeChannelDelegateForIdentifier:) in `SBDMain`. If you miss this, it will cause the crash.

///  This protocol deals with the below events.
///  * Receives a message in the [`SBDBaseChannel`](../Classes/SBDBaseChannel.html).
///  * Receives an event when a message is updated in the [`SBDBaseChannel`](../Classes/SBDBaseChannel.html).
///  * Receives an event when a member read a message in the [`SBDGroupChannel`](../Classes/SBDGroupChannel.html).
///  * Receives an event when a member typed something in the [`SBDGroupChannel`](../Classes/SBDGroupChannel.html).
///  * Receives an event when a new member joined the [`SBDGroupChannel`](../Classes/SBDGroupChannel.html).
///  * Receives an event when a member left from the [`SBDGroupChannel`](../Classes/SBDGroupChannel.html).
///  * Receives an event when a participant entered the [`SBDOpenChannel`](../Classes/SBDOpenChannel.html).
///  * Receives an event when a participant exited the [`SBDOpenChannel`](../Classes/SBDOpenChannel.html).
///  * Receives an event when a participant was muted or unmuted in the [`SBDOpenChannel`](../Classes/SBDOpenChannel.html).
///  * Receives an event when a participant was banned or unbanned in the [`SBDOpenChannel`](../Classes/SBDOpenChannel.html).
///  * Receives an event when the [`SBDOpenChannel`](../Classes/SBDOpenChannel.html) was frozen or unfrozen.
///  * Receives an event when the property of the [`SBDBaseChannel`](../Classes/SBDBaseChannel.html) was changed.
///  * Receives an event when the [`SBDBaseChannel`](../Classes/SBDBaseChannel.html) was deleted.
///  * Receives an event when a message in the [`SBDBaseChannel`](../Classes/SBDBaseChannel.html) was deleted.
///  * Receives an event when meta data in the [`SBDBaseChannel`](../Classes/SBDBaseChannel.html) was changed.
///  * Receives an event when meta counters in the [`SBDBaseChannel`](../Classes/SBDBaseChannel.html) were changed.
///  * Receives an event when a group channel was hidden.
///  * Receives an event when a reaction of message in a group channel was updated.
///  * Receives an event when operators are updated
@protocol SBDChannelDelegate <NSObject>

@optional

/// A callback when a message is received.
/// @param sender The channel where the message is received.
/// @param message The received message.
- (void)channel:(SBDBaseChannel * _Nonnull)sender didReceiveMessage:(SBDBaseMessage * _Nonnull)message;

/// A callback when a message is updated.
/// @param sender The channel where the message is updated.
/// @param message The updated message.
- (void)channel:(SBDBaseChannel * _Nonnull)sender didUpdateMessage:(SBDBaseMessage * _Nonnull)message;

/// A delegate is called when someone mentioned the user.
/// @param channel The channel mention was occured in.
/// @param message The message mention was occured about.
- (void)channel:(nonnull SBDBaseChannel *)channel didReceiveMention:(nonnull SBDBaseMessage *)message;

/// A callback when read receipts updated.
/// @param sender The group channel where the read receipt updated.
- (void)channelDidUpdateReadReceipt:(SBDGroupChannel * _Nonnull)sender;

/// A callback when delivery receipts updated.
/// @param sender The group channel where the delivery receipt updated.
/// @since 3.0.162
- (void)channelDidUpdateDeliveryReceipt:(SBDGroupChannel * _Nonnull)sender;

/// A callback when user sends typing status.
/// @param sender The group channel where the typing status updated.
- (void)channelDidUpdateTypingStatus:(SBDGroupChannel * _Nonnull)sender;

/// A callback when users are invited by inviter.
/// @param sender The group channel where the invitation is occured.
/// @param inviter Inviter. It can be nil.
/// @param invitees Invitees.
- (void)channel:(SBDGroupChannel * _Nonnull)sender didReceiveInvitation:(NSArray<SBDUser *> * _Nullable)invitees inviter:(SBDUser * _Nullable)inviter;

/// A callback when user declined the invitation.
/// @param sender The group channel where the invitation is occured.
/// @param invitee Inviter. It can be nil.
/// @param inviter Invitee.
- (void)channel:(SBDGroupChannel * _Nonnull)sender didDeclineInvitation:(SBDUser * _Nonnull)invitee inviter:(SBDUser * _Nullable)inviter;

/// A callback when new member joined to the group channel.
/// @param sender The group channel.
/// @param user   The new user joined to the channel.
- (void)channel:(SBDGroupChannel * _Nonnull)sender userDidJoin:(SBDUser * _Nonnull)user;


/// A callback when current member left from the group channel.
/// @param sender The group channel.
/// @param user   The member left from the channel.
- (void)channel:(SBDGroupChannel * _Nonnull)sender userDidLeave:(SBDUser * _Nonnull)user;

/// A callback when a user enter an open channel.
/// @param sender The open channel.
/// @param user   The user
- (void)channel:(SBDOpenChannel * _Nonnull)sender userDidEnter:(SBDUser * _Nonnull)user;

/// A callback when a user exit an open channel.
/// @param sender The open channel.
/// @param user   The user.
- (void)channel:(SBDOpenChannel * _Nonnull)sender userDidExit:(SBDUser * _Nonnull)user;

/// A callback when a user was muted in the channel.
/// @param sender The channel.
/// @param user   The user who was muted.
- (void)channel:(SBDBaseChannel * _Nonnull)sender userWasMuted:(SBDUser * _Nonnull)user;

/// A callback when a user was unmuted in the channel.
/// @param sender The channel.
/// @param user   The user who was unmuted.

- (void)channel:(SBDBaseChannel * _Nonnull)sender userWasUnmuted:(SBDUser * _Nonnull)user;

/// A callback when a user was banned in the channel.
/// @param sender The channel.
/// @param user   The user who was banned.
- (void)channel:(SBDBaseChannel * _Nonnull)sender userWasBanned:(SBDUser * _Nonnull)user;

/// A callback when a user was unbanned in the channel.
/// @param sender The channel.
/// @param user   The user who was unbanned.
- (void)channel:(SBDBaseChannel * _Nonnull)sender userWasUnbanned:(SBDUser * _Nonnull)user;

/// A callback when an channel was frozen.
/// @param sender The channel.
- (void)channelWasFrozen:(SBDBaseChannel * _Nonnull)sender;


/// A callback when an channel was unfrozen.
/// @param sender The channel.
- (void)channelWasUnfrozen:(SBDBaseChannel * _Nonnull)sender;


/// A callback when an open channel was changed.
/// @param sender The open channel.
- (void)channelWasChanged:(SBDBaseChannel * _Nonnull)sender;

/// A callback when an open channel was deleted.
/// @param channelUrl The channel url.
/// @param channelType The Type of channel, types of open channel or group channel.
- (void)channelWasDeleted:(NSString * _Nonnull)channelUrl channelType:(SBDChannelType)channelType;

/// A callback when a message was removed in the channel.
/// @param sender    The base channel.
/// @param messageId The message ID which was removed.
- (void)channel:(SBDBaseChannel * _Nonnull)sender messageWasDeleted:(long long)messageId;

/// A callback when meta data was created in the channel.
/// @param sender The channel that the meta data was created.
/// @param createdMetaData The created meta data.
- (void)channel:(SBDBaseChannel * _Nonnull)sender createdMetaData:(NSDictionary<NSString *, NSString *> * _Nullable)createdMetaData;

/// A callback when meta data was updated in the channel.
/// @param sender The channel that the meta data was updated.
/// @param updatedMetaData The updated meta data.
- (void)channel:(SBDBaseChannel * _Nonnull)sender updatedMetaData:(NSDictionary<NSString *, NSString *> * _Nullable)updatedMetaData;

/// A callback when meta data was deleted in the channel.
/// @param sender The channel that the meta data was deleted.
/// @param deletedMetaDataKeys The keys of the deleted meta data.
- (void)channel:(SBDBaseChannel * _Nonnull)sender deletedMetaDataKeys:(NSArray<NSString *> * _Nullable)deletedMetaDataKeys;

/// A callback when meta counters were created in the channel.
/// @param sender The channel that the meta counters were created.
/// @param createdMetaCounters The created meta counters.
- (void)channel:(SBDBaseChannel * _Nonnull)sender createdMetaCounters:(NSDictionary<NSString *, NSNumber *> * _Nullable)createdMetaCounters;

/// A callback when meta counters were updated in the channel.
/// @param sender The channel that the meta counters were updated.
/// @param updatedMetaCounters The updated meta counters.
- (void)channel:(SBDBaseChannel * _Nonnull)sender updatedMetaCounters:(NSDictionary<NSString *, NSNumber *> * _Nullable)updatedMetaCounters;

/// A callback when meta counters were deleted in the channel.
/// @param sender The channel that the meta counters were deleted.
/// @param deletedMetaCountersKeys The keys of the deleted meta counters.
- (void)channel:(SBDBaseChannel * _Nonnull)sender deletedMetaCountersKeys:(NSArray<NSString *> * _Nullable)deletedMetaCountersKeys;

/// A callback when the channel was hidden on the other device or by Platform API.
/// @param sender The channel that was hidden on the other device or by Platform API.
- (void)channelWasHidden:(SBDGroupChannel * _Nonnull)sender;

/// A callback when a reaction was updated.
/// @param sender The channel that the reaction was updated.
/// @param reactionEvent The updated reaction event.
- (void)channel:(SBDBaseChannel * _Nonnull)sender updatedReaction:(SBDReactionEvent * _Nonnull)reactionEvent;

/// A callback when operators were updated in the channel.
/// @param sender The channel that the operators was updated.
///
/// @since 3.0.174
- (void)channelDidUpdateOperators:(SBDBaseChannel * _Nonnull)sender;

/// Invoked when the thread information is updated.
/// @param channel The channel that has the message thread.
/// @param threadInfoUpdateEvent The [`SBDThreadInfoUpdateEvent`](../Classes/SBDThreadInfoUpdateEvent.html) object that has the latest information about the thread.
/// @since 3.0.181
- (void)channel:(nonnull SBDBaseChannel *)channel didUpdateThreadInfo:(nonnull SBDThreadInfoUpdateEvent *)threadInfoUpdateEvent;

@end


/// The `SBDBaseChannel` class represents the channel where users chat each other. The `SBDOpenChannel` and the `SBDGroupChannel` are derived from this class. This class provides the common methods for the `SBDOpenChannel` and the `SBDGroupChannel`.
/// * Send a user message to the channel.
/// * Send a file message to the channel.
/// * Delete a message of the channel.
/// * Create a query for loading messages of the channel.
/// * Manipulate meta counters and meta <span>data</span> of the channel.
/// The channel objects are maintained as a single instance in an application. If you create or get channels from the same channel URL, they must be the same instances.
@interface SBDBaseChannel : NSObject


/// The channel URL.
@property (strong, nonatomic, nonnull) NSString *channelUrl;

/// The name of channel.
@property (strong, nonatomic, nonnull) NSString *name;

/// The channel cover image URL.
@property (strong, nonatomic, nullable) NSString *coverUrl;

/// User who creates the channel
/// @since 3.0.199
@property (nonatomic, strong, nullable, readonly) SBDUser *creator;

/// The timestamp when the channel is created.
@property (atomic) NSUInteger createdAt;

/// The custom data of the channel.
@property (strong, nonatomic, nullable) NSString *data;

/// The custom type of the channel.
@property (strong, nonatomic, nullable) NSString *customType;

/// The flag for a frozen channel.
/// @since 3.0.89
/// Was moved from SBDOpenChannel
@property (atomic, setter=setFreeze:) BOOL isFrozen;

/// Represents the channel is ephemeral or not.
/// @since 3.0.90
@property (nonatomic, readonly) BOOL isEphemeral;

/// Sends a user message without <span>data</span>.
/// @param message           The message text.
/// @param completionHandler The handler block to execute. `userMessage` is a user message which is returned from the Sendbird server. The message has a message ID.
/// @return Returns a temporary user message being sent to the Sendbird server.
/// The message has a request ID instead of a message ID.
/// The request status of the message is pending.
/// If you try to send a message with an invalid parameter, the returned message is a user message with no properties.
/// You can perform a validation of pending message by checking for the existence of the request ID.
- (nonnull SBDUserMessage *)sendUserMessage:(NSString * _Nullable)message
                          completionHandler:(nullable void (^)(SBDUserMessage * _Nullable userMessage, SBDError * _Nullable error))completionHandler;

/// Sends a user message without <span>data</span>. The message will be translated into the target languages.
/// @param message           The message text.
/// @param targetLanguages   The target languages that the message will be translated into.
/// @param completionHandler The handler block to execute. `userMessage` is a user message which is returned from the Sendbird server. The message has a message ID.
/// @return Returns a temporary user message being sent to the Sendbird server.
/// The message has a request ID instead of a message ID.
/// The request status of the message is pending.
/// If you try to send a message with an invalid parameter, the returned message is a user message with no properties.
/// You can perform a validation of pending message by checking for the existence of the request ID.
/// @deprecated in 3.0.116 Use `sendUserMessageWithParams:completionHandler:` instead.
- (nonnull SBDUserMessage *)sendUserMessage:(NSString * _Nullable)message
                            targetLanguages:(NSArray<NSString *> * _Nullable)targetLanguages
                          completionHandler:(nullable void (^)(SBDUserMessage * _Nullable userMessage, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/// Sends a user message with <span>data</span>.
/// @param message        The message text.
/// @param data           The message <span>data</span>.
/// @param completionHandler The handler block to execute. `userMessage` is a user message which is returned from the Sendbird server. The message has a message ID.
/// @return Returns a temporary user message being sent to the Sendbird server.
/// The message has a request ID instead of a message ID.
/// The request status of the message is pending.
/// If you try to send a message with an invalid parameter, the returned message is a user message with no properties.
/// You can perform a validation of pending message by checking for the existence of the request ID.
/// @deprecated in 3.0.116 Use `sendUserMessageWithParams:completionHandler:` instead.
- (nonnull SBDUserMessage *)sendUserMessage:(NSString * _Nullable)message
                                       data:(NSString * _Nullable)data
                          completionHandler:(nullable void (^)(SBDUserMessage * _Nullable userMessage, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/// Sends a user message with <span>data</span>. The message will be translated into the target languages.
/// @param message        The message text.
/// @param data           The message <span>data</span>.
/// @param targetLanguages   The target languages that the message will be translated into.
/// @param completionHandler The handler block to execute. `userMessage` is a user message which is returned from the Sendbird server. The message has a message ID.
/// @return Returns a temporary user message being sent to the Sendbird server.
/// The message has a request ID instead of a message ID.
/// The request status of the message is pending.
/// If you try to send a message with an invalid parameter, the returned message is a user message with no properties.
/// You can perform a validation of pending message by checking for the existence of the request ID.
/// @deprecated in 3.0.116 Use `sendUserMessageWithParams:completionHandler:` instead.
- (nonnull SBDUserMessage *)sendUserMessage:(NSString * _Nullable)message
                                       data:(NSString * _Nullable)data
                            targetLanguages:(NSArray<NSString *> * _Nullable)targetLanguages
                          completionHandler:(nullable void (^)(SBDUserMessage * _Nullable userMessage, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/// Sends a user message with <span>data</span> and <span>custom message type</span>.
/// @param message        The message text.
/// @param data           The message <span>data</span>.
/// @param customType     Custom message type.
/// @param completionHandler The handler block to execute. `userMessage` is a user message which is returned from the Sendbird server. The message has a message ID.
/// @return Returns a temporary user message being sent to the Sendbird server.
/// The message has a request ID instead of a message ID.
/// The request status of the message is pending.
/// If you try to send a message with an invalid parameter, the returned message is a user message with no properties.
/// You can perform a validation of pending message by checking for the existence of the request ID.
/// @deprecated in 3.0.116 Use `sendUserMessageWithParams:completionHandler:` instead.
- (nonnull SBDUserMessage *)sendUserMessage:(NSString * _Nullable)message
                                       data:(NSString * _Nullable)data
                                 customType:(NSString * _Nullable)customType
                          completionHandler:(nullable void (^)(SBDUserMessage * _Nullable userMessage, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/// Sends a user message with <span>data</span> and <span>custom message type</span>. The message will be translated into the target languages.
/// @param message        The message text.
/// @param data           The message <span>data</span>.
/// @param customType     Custom message type.
/// @param targetLanguages   The target languages that the message will be translated into.
/// @param completionHandler The handler block to execute. `userMessage` is a user message which is returned from the Sendbird server. The message has a message ID.
/// @return Returns a temporary user message being sent to the Sendbird server.
/// The message has a request ID instead of a message ID.
/// The request status of the message is pending.
/// If you try to send a message with an invalid parameter, the returned message is a user message with no properties.
/// You can perform a validation of pending message by checking for the existence of the request ID.
/// @deprecated in 3.0.116 Use `sendUserMessageWithParams:completionHandler:` instead.
- (nonnull SBDUserMessage *)sendUserMessage:(NSString * _Nullable)message
                                       data:(NSString * _Nullable)data
                                 customType:(NSString * _Nullable)customType
                            targetLanguages:(NSArray<NSString *> * _Nullable)targetLanguages
                          completionHandler:(nullable void (^)(SBDUserMessage * _Nullable userMessage, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/// Sends a string message of params. The message is translated into the target languages.
/// @param params               The instance of SBDUserMessageParams that can has parameters related with string message.
/// @param completionHandler    The handler block to be executed after the message was sent. This block has no return value and takes two argument, one is a file message was sent and other is an error made when there is something wrong to message.
/// @return Returns a temporary user message being sent to the Sendbird server.
/// The message has a request ID instead of a message ID.
/// The request status of the message is pending.
/// If you try to send a message with an invalid parameter, the returned message is a user message with no properties.
/// You can perform a validation of pending message by checking for the existence of the request ID.
- (nonnull SBDUserMessage *)sendUserMessageWithParams:(nonnull SBDUserMessageParams *)params
                                    completionHandler:(nullable void (^)(SBDUserMessage * _Nullable userMessage, SBDError * _Nullable error))completionHandler;

/// Attempts to resend a failed user message received by the failure callback. Only failed message MUST be passed, not a succeeded message or a pending message
/// @param failedMessage  A message to send. A failed message is passed to the callback when fails to send a message
/// @param completionHandler  The handler block to be executed after the message is sent. This block has no return value and takes two arguments. One is a user message. If the message is successfully sent, the complete message instance is delivered. If the message fails to be sent, a failed message based on the pending message is delivered. Another factor is errors. If the message fails to be sent, a message error is dispatched
/// @return Returns a temporary user message being sent to the Sendbird server.
/// @since 3.0.141
/// @code
/// SBDUserMessageParams *params = [[SBDUserMessageParams alloc] initWithMessage:text_message];
/// // set some properties of params
/// [channel sendUserMessageWithParams:params completionHandler:^(SBDUserMessage * _Nullable message, SBDError * _Nullable error) {
///   if (error != nil) {
///     // handle failure of sending message
///     // if user wants to resend...
///     [channel resendUserMessageWithMessage:message completionHandler:^(SBDUserMessage * _Nullable message, SBDError * _Nullable error) {
///       // do something.
///     }];
///   } else {
///     // success to send message
///   }
/// }];
/// @endcode
- (nonnull SBDUserMessage *)resendUserMessageWithMessage:(nonnull SBDUserMessage *)failedMessage
                                       completionHandler:(nullable SBDUserMessageHandler)completionHandler;

/// Sends a file message with binary <span>data</span>. The binary <span>data</span> is uploaded to Sendbird file storage and a URL of the file will be generated.
///
/// @param file              File <span>data</span>.
/// @param filename          File<span>name</span>.
/// @param type              The mime type of file.
/// @param size              File size.
/// @param data              Custom <span>data</span>.
/// @param completionHandler The handler block to execute. `fileMessage` is a user message which is returned from the Sendbird server. The message has a message ID and an URL.
/// @return Returns a temporary file message being sent to the Sendbird server.
/// The message has a request ID instead of a message ID.
/// The request status of the message is pending.
/// If you try to send a message with an invalid parameter, the returned message is a user message with no properties.
/// You can perform a validation of pending message by checking for the existence of the request ID.
- (nonnull SBDFileMessage *)sendFileMessageWithBinaryData:(NSData * _Nonnull)file
                                                 filename:(NSString * _Nonnull)filename
                                                     type:(NSString * _Nonnull)type
                                                     size:(NSUInteger)size
                                                     data:(NSString * _Nullable)data
                                        completionHandler:(nullable void (^)(SBDFileMessage * _Nullable fileMessage, SBDError * _Nullable error))completionHandler;

/// Sends a file message with binary <span>data</span>. The binary <span>data</span> is uploaded to Sendbird file storage and a URL of the file will be generated.
/// @param file              File <span>data</span>.
/// @param filename          File<span>name</span>.
/// @param type              The mime type of file.
/// @param size              File size.
/// @param data              Custom <span>data</span>.
/// @param customType        Custom message type.
/// @param completionHandler The handler block to execute. `fileMessage` is a user message which is returned from the Sendbird server. The message has a message ID and an URL.
/// @return Returns a temporary file message being sent to the Sendbird server.
/// The message has a request ID instead of a message ID.
/// The request status of the message is pending.
/// If you try to send a message with an invalid parameter, the returned message is a user message with no properties.
/// You can perform a validation of pending message by checking for the existence of the request ID.
/// @deprecated in 3.0.116 Use `sendFileMessageWithParams:completionHandler:` instead.
- (nonnull SBDFileMessage *)sendFileMessageWithBinaryData:(NSData * _Nonnull)file
                                                 filename:(NSString * _Nonnull)filename
                                                     type:(NSString * _Nonnull)type
                                                     size:(NSUInteger)size
                                                     data:(NSString * _Nullable)data
                                               customType:(NSString * _Nullable)customType
                                        completionHandler:(nullable void (^)(SBDFileMessage * _Nullable fileMessage, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/// Sends a file message with file URL.
/// @param url               File URL.
/// @param type              The type of file.
/// @param size              File size.
/// @param data              Custom <span>data</span>.
/// @param completionHandler The handler block to execute. `fileMessage` is a user message which is returned from the Sendbird server. The message has a message ID.
/// @return Returns a temporary file message being sent to the Sendbird server.
/// The message has a request ID instead of a message ID.
/// The request status of the message is pending.
/// If you try to send a message with an invalid parameter, the returned message is a user message with no properties.
/// You can perform a validation of pending message by checking for the existence of the request ID.
/// @deprecated in 3.0.29.
- (nonnull SBDFileMessage *)sendFileMessageWithUrl:(NSString * _Nonnull)url
                                              size:(NSUInteger)size
                                              type:(NSString * _Nonnull)type
                                              data:(NSString * _Nullable)data
                                 completionHandler:(nullable void (^)(SBDFileMessage * _Nullable fileMessage, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/// Sends a file message with file URL.
/// @param url               File URL.
/// @param filename          File<span>name</span>.
/// @param type              The type of file.
/// @param size              File size.
/// @param data              Custom <span>data</span>.
/// @param completionHandler The handler block to execute. `fileMessage` is a user message which is returned from the Sendbird server. The message has a message ID.
/// @return Returns a temporary file message being sent to the Sendbird server.
/// The message has a request ID instead of a message ID.
/// The request status of the message is pending.
/// If you try to send a message with an invalid parameter, the returned message is a user message with no properties.
/// You can perform a validation of pending message by checking for the existence of the request ID.
- (nonnull SBDFileMessage *)sendFileMessageWithUrl:(NSString * _Nonnull)url
                                          filename:(NSString * _Nullable)filename
                                              size:(NSUInteger)size
                                              type:(NSString * _Nonnull)type
                                              data:(NSString * _Nullable)data
                                 completionHandler:(nullable void (^)(SBDFileMessage * _Nullable fileMessage, SBDError * _Nullable error))completionHandler;

/// Sends a file message with file URL and <span>custom message type</span>.
/// @param url               File URL.
/// @param type              The type of file.
/// @param size              File size.
/// @param data              Custom <span>data</span>.
/// @param customType        Custom message type.
/// @param completionHandler The handler block to execute. `fileMessage` is a user message which is returned from the Sendbird server. The message has a message ID.
/// @return Returns a temporary file message being sent to the Sendbird server.
/// The message has a request ID instead of a message ID.
/// The request status of the message is pending.
/// If you try to send a message with an invalid parameter, the returned message is a user message with no properties.
/// You can perform a validation of pending message by checking for the existence of the request ID.
/// @deprecated in 3.0.29.
- (nonnull SBDFileMessage *)sendFileMessageWithUrl:(NSString * _Nonnull)url
                                              size:(NSUInteger)size
                                              type:(NSString * _Nonnull)type
                                              data:(NSString * _Nullable)data
                                        customType:(NSString * _Nullable)customType
                                 completionHandler:(nullable void (^)(SBDFileMessage * _Nullable fileMessage, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/// Sends a file message with file URL and <span>custom message type</span>.
/// @param url               File URL.
/// @param filename          File<span>name</span>.
/// @param type              The type of file.
/// @param size              File size.
/// @param data              Custom <span>data</span>.
/// @param customType        Custom message type.
/// @param completionHandler The handler block to execute. `fileMessage` is a user message which is returned from the Sendbird server. The message has a message ID.
/// @return Returns a temporary file message being sent to the Sendbird server.
/// The message has a request ID instead of a message ID.
/// The request status of the message is pending.
/// If you try to send a message with an invalid parameter, the returned message is a user message with no properties.
/// You can perform a validation of pending message by checking for the existence of the request ID.
- (nonnull SBDFileMessage *)sendFileMessageWithUrl:(NSString * _Nonnull)url
                                          filename:(NSString * _Nullable)filename
                                              size:(NSUInteger)size
                                              type:(NSString * _Nonnull)type
                                              data:(NSString * _Nullable)data
                                        customType:(NSString * _Nullable)customType
                                 completionHandler:(nullable void (^)(SBDFileMessage * _Nullable fileMessage, SBDError * _Nullable error))completionHandler;

/// Sends a file message with binary <span>data</span>. The binary <span>data</span> is uploaded to Sendbird file storage and a URL of the file will be generated. The uploading progress callback can be implemented.
/// @param file              File <span>data</span>.
/// @param filename          File<span>name</span>.
/// @param type              The mime type of file.
/// @param size              File size.
/// @param data              Custom <span>data</span>.
/// @param progressHandler   The handler block to monitor progression.  `bytesSent` is the number of bytes sent since the last time this method was called. `totalBytesSent` is the total number of bytes sent so far. `totalBytesExpectedToSend` is the expected length of the body <span>data</span>. These parameters are the same to the declaration of [`URLSession:task:didSendBodyData:totalBytesSent:totalBytesExpectedToSend:`](https://developer.apple.com/reference/foundation/nsurlsessiontaskdelegate/1408299-urlsession?language=objc).
/// @param completionHandler The handler block to execute. `fileMessage` is a user message which is returned from the Sendbird server. The message has a message ID and an URL.
/// @return Returns a temporary file message being sent to the Sendbird server.
/// The message has a request ID instead of a message ID.
/// The request status of the message is pending.
/// If you try to send a message with an invalid parameter, the returned message is a user message with no properties.
/// You can perform a validation of pending message by checking for the existence of the request ID.
///
/// @deprecated in 3.0.116 Use `sendFileMessageWithParams:completionHandler:` instead.
- (nonnull SBDFileMessage *)sendFileMessageWithBinaryData:(NSData * _Nonnull)file
                                                 filename:(NSString * _Nonnull)filename
                                                     type:(NSString * _Nonnull)type
                                                     size:(NSUInteger)size
                                                     data:(NSString * _Nullable)data
                                          progressHandler:(nullable void (^)(int64_t bytesSent, int64_t totalBytesSent, int64_t totalBytesExpectedToSend))progressHandler
                                        completionHandler:(nullable void (^)(SBDFileMessage * _Nullable fileMessage, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/// Sends a file message with binary <span>data</span>. The binary <span>data</span> is uploaded to Sendbird file storage and a URL of the file will be generated. The uploading progress callback can be implemented.
/// @param file              File <span>data</span>.
/// @param filename          File<span>name</span>.
/// @param type              The mime type of file.
/// @param size              File size.
/// @param data              Custom <span>data</span>.
/// @param customType        Custom message type.
/// @param progressHandler   The handler block to monitor progression.  `bytesSent` is the number of bytes sent since the last time this method was called. `totalBytesSent` is the total number of bytes sent so far. `totalBytesExpectedToSend` is the expected length of the body <span>data</span>. These parameters are the same to the declaration of [`URLSession:task:didSendBodyData:totalBytesSent:totalBytesExpectedToSend:`](https://developer.apple.com/reference/foundation/nsurlsessiontaskdelegate/1408299-urlsession?language=objc).
/// @param completionHandler The handler block to execute. `fileMessage` is a user message which is returned from the Sendbird server. The message has a message ID and an URL.
/// @return Returns a temporary file message being sent to the Sendbird server.
/// The message has a request ID instead of a message ID.
/// The request status of the message is pending.
/// If you try to send a message with an invalid parameter, the returned message is a user message with no properties.
/// You can perform a validation of pending message by checking for the existence of the request ID.
/// @deprecated in 3.0.116 Use `sendFileMessageWithParams:completionHandler:` instead.
- (nonnull SBDFileMessage *)sendFileMessageWithBinaryData:(NSData * _Nonnull)file
                                                 filename:(NSString * _Nonnull)filename
                                                     type:(NSString * _Nonnull)type
                                                     size:(NSUInteger)size
                                                     data:(NSString * _Nullable)data
                                               customType:(NSString * _Nullable)customType
                                          progressHandler:(nullable void (^)(int64_t bytesSent, int64_t totalBytesSent, int64_t totalBytesExpectedToSend))progressHandler
                                        completionHandler:(nullable void (^)(SBDFileMessage * _Nullable fileMessage, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/// Sends a file message with binary <span>data</span>. The binary <span>data</span> is uploaded to Sendbird file storage and a URL of the file will be generated. The uploading progress callback can be implemented.
/// @param file              File <span>data</span>.
/// @param filename          File<span>name</span>.
/// @param type              The mime type of file.
/// @param size              File size.
/// @param thumbnailSizes    Thumbnail sizes. This parameter is the array of `SBDThumbnailSize` object and works for image file only.
/// @param data              Custom <span>data</span>.
/// @param customType        Custom message type.
/// @param progressHandler   The handler block to monitor progression.  `bytesSent` is the number of bytes sent since the last time this method was called. `totalBytesSent` is the total number of bytes sent so far. `totalBytesExpectedToSend` is the expected length of the body <span>data</span>. These parameters are the same to the declaration of [`URLSession:task:didSendBodyData:totalBytesSent:totalBytesExpectedToSend:`](https://developer.apple.com/reference/foundation/nsurlsessiontaskdelegate/1408299-urlsession?language=objc).
/// @param completionHandler The handler block to execute. `fileMessage` is a user message which is returned from the Sendbird server. The message has a message ID and an URL.
/// @return Returns a temporary file message being sent to the Sendbird server.
/// The message has a request ID instead of a message ID.
/// The request status of the message is pending.
/// If you try to send a message with an invalid parameter, the returned message is a user message with no properties.
/// You can perform a validation of pending message by checking for the existence of the request ID.
- (nonnull SBDFileMessage *)sendFileMessageWithBinaryData:(NSData * _Nonnull)file
                                                 filename:(NSString * _Nonnull)filename
                                                     type:(NSString * _Nonnull)type
                                                     size:(NSUInteger)size
                                           thumbnailSizes:(NSArray<SBDThumbnailSize *> * _Nullable)thumbnailSizes
                                                     data:(NSString * _Nullable)data
                                               customType:(NSString * _Nullable)customType
                                          progressHandler:(nullable void (^)(int64_t bytesSent, int64_t totalBytesSent, int64_t totalBytesExpectedToSend))progressHandler
                                        completionHandler:(nullable void (^)(SBDFileMessage * _Nullable fileMessage, SBDError * _Nullable error))completionHandler;

/// Sends a file message with binary <span>data</span>. The binary <span>data</span> is uploaded to Sendbird file storage and a URL of the file will be generated. The uploading progress callback can be implemented.
/// @param filepath          File path to be sent.
/// @param type              The mime type of file.
/// @param thumbnailSizes    Thumbnail sizes. This parameter is the array of `SBDThumbnailSize` object and works for image file only.
/// @param data              Custom <span>data</span>.
/// @param customType        Custom message type.
/// @param progressHandler   The handler block to monitor progression.  `bytesSent` is the number of bytes sent since the last time this method was called. `totalBytesSent` is the total number of bytes sent so far. `totalBytesExpectedToSend` is the expected length of the body <span>data</span>. These parameters are the same to the declaration of [`URLSession:task:didSendBodyData:totalBytesSent:totalBytesExpectedToSend:`](https://developer.apple.com/reference/foundation/nsurlsessiontaskdelegate/1408299-urlsession?language=objc).
/// @param completionHandler The handler block to execute. `fileMessage` is a user message which is returned from the Sendbird server. The message has a message ID and an URL.
/// @return Returns a temporary file message being sent to the Sendbird server.
/// The message has a request ID instead of a message ID.
/// The request status of the message is pending.
/// If you try to send a message with an invalid parameter, the returned message is a user message with no properties.
/// You can perform a validation of pending message by checking for the existence of the request ID.
- (nonnull SBDFileMessage *)sendFileMessageWithFilePath:(NSString * _Nonnull)filepath
                                                   type:(NSString * _Nonnull)type
                                         thumbnailSizes:(NSArray<SBDThumbnailSize *> * _Nullable)thumbnailSizes
                                                   data:(NSString * _Nullable)data
                                             customType:(NSString * _Nullable)customType
                                        progressHandler:(nullable void (^)(int64_t bytesSent, int64_t totalBytesSent, int64_t totalBytesExpectedToSend))progressHandler
                                      completionHandler:(nullable void (^)(SBDFileMessage * _Nullable fileMessage, SBDError * _Nullable error))completionHandler;

/**
 Sends a file message with file or file URL of params without progress. If the params has a binary file, it will upload data to Sendbird storage. If not, the params has a file url, it will send a message with file url.
 
 @param params               The instance of SBDFileMessageParams that can has parameters related with file.
 @param completionHandler    The handler block to be executed after the message was sent. This block has no return value and takes two argument, one is a file message was sent and other is an error made when there is something wrong to message.
 
 @return Returns a temporary file message being sent to the Sendbird server.
 The message has a request ID instead of a message ID.
 The request status of the message is pending.
 If you try to send a message with an invalid parameter, the returned message is a user message with no properties.
 You can perform a validation of pending message by checking for the existence of the request ID.
 */
- (nonnull SBDFileMessage *)sendFileMessageWithParams:(nonnull SBDFileMessageParams *)params
                                    completionHandler:(nullable void (^)(SBDFileMessage * _Nullable fileMessage, SBDError * _Nullable error))completionHandler;

/**
 Sends a file message with file or file URL of params with progress. If the params has a binary file, it will upload data to Sendbird storage. If not, the params has a file url, it will send a message with file url.
 
 @param params               The instance of SBDFileMessageParams that can has parameters related with file.
 @param progressHandler      The handler block to be used to monitor progression. `bytesSent` is the number of bytes sent since this method was called. `totalBytesSent` is the total number of bytes sent so far. `totalBytesExpectedToSend` is the expected length of the body data. These parameters are the same to the declaration of [`URLSession:task:didSendBodyData:totalBytesSent:totalBytesExpectedToSend:`](https://developer.apple.com/reference/foundation/nsurlsessiontaskdelegate/1408299-urlsession?language=objc).
 @param completionHandler    The handler block to be executed after the message was sent. This block has no return value and takes two argument, one is a file message was sent and other is an error made when there is something wrong to message.
 
 @return Returns a temporary file message being sent to the Sendbird server.
 The message has a request ID instead of a message ID.
 The request status of the message is pending.
 If you try to send a message with an invalid parameter, the returned message is a user message with no properties.
 You can perform a validation of pending message by checking for the existence of the request ID.
 */
- (nonnull SBDFileMessage *)sendFileMessageWithParams:(nonnull SBDFileMessageParams *)params
                                      progressHandler:(nullable void (^)(int64_t bytesSent, int64_t totalBytesSent, int64_t totalBytesExpectedToSend))progressHandler
                                    completionHandler:(nullable void (^)(SBDFileMessage * _Nullable fileMessage, SBDError * _Nullable error))completionHandler;

/// Sends a file message with file or file URL of params with progress. If the params has a binary file, it will upload data to Sendbird storage. If not, the params has a file url, it will send a message with file url.
/// @param params               The instance of SBDFileMessageParams that can has parameters related with file.
/// @param progressHandler      The handler block to be used to monitor progression. `bytesSent` is the number of bytes sent since this method was called. `totalBytesSent` is the total number of bytes sent so far. `totalBytesExpectedToSend` is the expected length of the body data. These parameters are the same to the declaration of [`URLSession:task:didSendBodyData:totalBytesSent:totalBytesExpectedToSend:`](https://developer.apple.com/reference/foundation/nsurlsessiontaskdelegate/1408299-urlsession?language=objc).
/// @param sentMessageHandler    The handler block to be executed after each message was sent. This block has no return value and takes two argument, one is a file message was sent and other is an error made when there is something wrong to message.
/// @param completionHandler    The handler block to be executed after every message was sent. This block has no return value and takes an error. If the sending message can't start at all because of the connection issue, the error isn't nil.
/// @return Returns a temporary file message being sent to the Sendbird server.
/// The message has a request ID instead of a message ID.
/// The request status of the message is pending.
/// If you try to send a message with an invalid parameter, the returned message is a user message with no properties.
/// You can perform a validation of pending message by checking for the existence of the request ID.
/// @since  3.0.116
- (nonnull NSArray<SBDFileMessage *> *)sendFileMessagesWithParams:(nonnull NSArray<SBDFileMessageParams *> *)params
                                                  progressHandler:(nullable void (^)(NSString * _Nullable requestId, int64_t bytesSent, int64_t totalBytesSent, int64_t totalBytesExpectedToSend))progressHandler
                                               sentMessageHandler:(nullable void (^)(SBDFileMessage * _Nonnull message, SBDError * _Nullable error))sentMessageHandler
                                                completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/// Attempts to resend a failed file message received by the failure callback. Only failed message MUST be passed, not a succeeded message or a pending message. If the failed message has a file URL, it means the failed message was created after failure of sending a file message command. So the method retries to send a file message command. If the failed message does not have a file URL, it means the failed message was created from failure of uploading a binary data. So the method retries to upload a binary data frist.
/// @param failedMessage  A message to send. A failed message is passed to the callback when fails to send a message
/// @param binaryData Data to resend. If the failed message has a file URL, the method will not send binary data. If the failed message does not have a file URL, the method will send binary data first and send a file message command with file url.
/// @param completionHandler  The handler block to be executed after the message is sent. This block has no return value and takes two arguments. One is a file message. If the message is successfully sent, the complete message instance is delivered. If the message fails to be sent, a failed message based on the pending message is delivered except invalid parameter error. If failed because of invalid parameter, message is nil. Another factor is errors. If the message fails to be sent, a message error is dispatched.
/// @return Returns a temporary file message being sent to the Sendbird server.
/// @since 3.0.147
/// @code
/// SBDFileMessageParams *params = [[SBDFileMessageParams alloc] initWithFile:binaryData];
/// // set some properties of params
/// [channel sendFileMessageWithParams:params completionHandler:^(SBDFileMessage * _Nullable message, SBDError * _Nullable error) {
///   if (error != nil) {
///     // handle failure of sending message
///     // if user wants to resend...
///     [channel resendFileMessageWithMessage:message binaryData:params.file completionHandler:^(SBDFileMessage * _Nullable message, SBDError * _Nullable error) {
///       // do something.
///     }];
///   }
///   else {
///     // success to send message
///   }
/// }];
/// @endcode
- (nonnull SBDFileMessage *)resendFileMessageWithMessage:(nonnull SBDFileMessage *)failedMessage
                                              binaryData:(nullable NSData *)binaryData
                                       completionHandler:(nullable SBDFileMessageHandler)completionHandler;

/// Attempts to resend a failed file message received by the failure callback. Only failed message MUST be passed, not a succeeded message or a pending message. If the failed message has a file URL, it means the failed message was created after failure of sending a file message command. So the method retries to send a file message command. If the failed message does not have a file URL, it means the failed message was created from failure of uploading a binary data. So the method retries to upload a binary data frist.
/// @param failedMessage  A message to send. A failed message is passed to the callback when fails to send a message
/// @param binaryData Data to resend. If the failed message has a file URL, the method will not send binary data. If the failed message does not have a file URL, the method will send binary data first and send a file message command with file url.
/// @param progressHandler      The handler block to be used to monitor progression. `bytesSent` is the number of bytes sent since this method was called. `totalBytesSent` is the total number of bytes sent so far. `totalBytesExpectedToSend` is the expected length of the body data. These parameters are the same to the declaration of [`URLSession:task:didSendBodyData:totalBytesSent:totalBytesExpectedToSend:`](https://developer.apple.com/reference/foundation/nsurlsessiontaskdelegate/1408299-urlsession?language=objc).
/// @param completionHandler  The handler block to be executed after the message is sent. This block has no return value and takes two arguments. One is a file message. If the message is successfully sent, the complete message instance is delivered. If the message fails to be sent, a failed message based on the pending message is delivered except invalid parameter error. If failed because of invalid parameter, message is nil. Another factor is errors. If the message fails to be sent, a message error is dispatched.
/// @return Returns a temporary file message being sent to the Sendbird server.
/// @since 3.0.147
/// @code
/// SBDFileMessageParams *params = [[SBDFileMessageParams alloc] initWithFile:binaryData];
/// // set some properties of params
/// [channel sendFileMessageWithParams:params completionHandler:^(SBDFileMessage * _Nullable message, SBDError * _Nullable error) {
///   if (error != nil) {
///     // handle failure of sending message
///     // if user wants to resend...
///     [channel resendFileMessageWithMessage:failedMessage binaryData:params.file progressHandler:^(int64_t bytesSent, int64_t totalBytesSent, int64_t totalBytesExpectedToSend) {
///        // do something in progress
///      } completionHandler:^(SBDFileMessage * _Nullable message, SBDError * _Nullable error) {
///        // do something.
///      }];
///    }
///    else {
///      // success to send message
///    }
/// }];
/// @endcode
- (nonnull SBDFileMessage *)resendFileMessageWithMessage:(nonnull SBDFileMessage *)failedMessage
                                              binaryData:(nullable NSData *)binaryData
                                         progressHandler:(nullable SBDBinaryProgressHandler)progressHandler
                                       completionHandler:(nullable SBDFileMessageHandler)completionHandler;

#pragma mark - Load message list
/// Creates `SBDPreviousMessageListQuery` instance for getting the previous messages list of the channel.
/// @return Returns the message list of the channel.
- (nullable SBDPreviousMessageListQuery *)createPreviousMessageListQuery;

/// Creates `SBDMessageListQuery` instance for getting the previous messages list of the channel.
/// @return Returns the message list of the channel.
/// @deprecated in 3.0.28.
- (nullable SBDMessageListQuery *)createMessageListQuery DEPRECATED_ATTRIBUTE;


/// Creates `SBDOperatorListQuery` instance for getting operators in the channel.
/// @return The operator list in the channel.
/// @since  3.0.94
- (nullable SBDOperatorListQuery *)createOperatorListQuery;

#pragma mark - Meta Counters

/// Creates the meta counters for the channel.
/// @param metaCounters      The meta counters to be set
/// @param completionHandler The handler block to execute. `metaCounters` is the meta counters which are set on Sendbird server.
- (void)createMetaCounters:(NSDictionary<NSString *, NSNumber *> * _Nonnull)metaCounters
         completionHandler:(nullable void (^)(NSDictionary<NSString *, NSNumber *> * _Nullable metaCounters, SBDError * _Nullable error))completionHandler;


/// Gets the meta counters with keys for the channel.
/// @param keys              The keys to get meta counters.
/// @param completionHandler The handler block to execute. `metaCounters` is the meta counters which are set on Sendbird server.
- (void)getMetaCountersWithKeys:(NSArray<NSString *> * _Nullable)keys
              completionHandler:(nullable void (^)(NSDictionary<NSString *, NSNumber *> * _Nullable metaCounters, SBDError * _Nullable error))completionHandler;


/// Gets all meta counters for the channel.
/// @param completionHandler The handler block to execute. `metaCounters` is the meta counters which are returned from Sendbird server.
- (void)getAllMetaCountersWithCompletionHandler:(nullable void (^)(NSDictionary<NSString *, NSNumber *> * _Nullable metaCounters, SBDError * _Nullable error))completionHandler;


/// Updates the meta counters for the channel.
/// @param metaCounters      The meta counters to be updated.
/// @param completionHandler The handler block to execute. `metaCounters` is the meta counters which are updated on Sendbird server.
- (void)updateMetaCounters:(NSDictionary<NSString *, NSNumber *> * _Nonnull)metaCounters
         completionHandler:(nullable void (^)(NSDictionary<NSString *, NSNumber *> * _Nullable metaCounters, SBDError * _Nullable error))completionHandler;

/// Increases the meta counters for the channel.
/// @param metaCounters      The meta counters to be increased.
/// @param completionHandler The handler block to execute. `metaCounters` is the meta counters which are increased on Sendbird server.
- (void)increaseMetaCounters:(NSDictionary<NSString *, NSNumber *> * _Nonnull)metaCounters
           completionHandler:(nullable void (^)(NSDictionary<NSString *, NSNumber *> * _Nullable metaCounters, SBDError * _Nullable error))completionHandler;

/// Decreases the meta counters for the channel.
/// @param metaCounters      The meta counters to be decreased.
/// @param completionHandler The handler block to execute. `metaCounters` is the meta counters which are decreased on Sendbird server.
- (void)decreaseMetaCounters:(NSDictionary<NSString *, NSNumber *> * _Nonnull)metaCounters
           completionHandler:(nullable void (^)(NSDictionary<NSString *, NSNumber *> * _Nullable metaCounters, SBDError * _Nullable error))completionHandler;

/// Deletes the meta counters with key for the channel.
/// @param key               The key to be deleted.
/// @param completionHandler The handler block to execute.
- (void)deleteMetaCountersWithKey:(NSString * _Nonnull)key
                completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/// Deletes all meta counters for the channel.
/// @param completionHandler The handler block to execute.
- (void)deleteAllMetaCountersWithCompletionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

#pragma mark - Meta Data
/// Creates the meta <span>data</span> for the channel.
/// @param metaData          The meta <span>data</span> to be set.
/// @param completionHandler The handler block to execute. `metaData` is the meta <span>data</span> which are set on Sendbird server.
- (void)createMetaData:(NSDictionary<NSString *, NSString *> * _Nonnull)metaData
     completionHandler:(nullable void (^)(NSDictionary<NSString *, NSString *> * _Nullable metaData, SBDError * _Nullable error))completionHandler;

/// Gets the meta <span>data</span> for the channel.
/// @param keys              The keys to get meta <span>data</span>.
/// @param completionHandler The handler block to execute. `metaData` is the meta <span>data</span> which are set on Sendbird server.
- (void)getMetaDataWithKeys:(NSArray<NSString *> * _Nullable)keys
          completionHandler:(nullable void (^)(NSDictionary<NSString *, NSString *> * _Nullable metaData, SBDError * _Nullable error))completionHandler;

/// Gets all meta <span>data</span> for the channel.
/// @param completionHandler The handler block to execute. `metaData` is the meta <span>data</span> which are set on Sendbird server.
- (void)getAllMetaDataWithCompletionHandler:(nullable void (^)(NSDictionary<NSString *, NSString *> * _Nullable metaData, SBDError * _Nullable error))completionHandler;

/// Updates the meta <span>data</span> for the channel.
/// @param metaData          The meta <span>data</span> to be updated.
/// @param completionHandler The handler block to execute. `metaData` is the meta counters which are updated on Sendbird server.
- (void)updateMetaData:(NSDictionary<NSString *, NSString *> * _Nonnull)metaData
     completionHandler:(nullable void (^)(NSDictionary<NSString *, NSString *> * _Nullable metaData, SBDError * _Nullable error))completionHandler;

/// Deletes meta <span>data</span> with key for the channel.
/// @param key               The key to be deleted.
/// @param completionHandler The handler block to execute.
- (void)deleteMetaDataWithKey:(NSString * _Nonnull)key
            completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/// Deletes all meta <span>data</span> for the channel.
/// @param completionHandler The handler block to execute.
- (void)deleteAllMetaDataWithCompletionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

#pragma mark - Delete message
/// Deletes a message. The message's sender has to be the current user.
/// @param message           The message to be deleted.
/// @param completionHandler The handler block to execute.
- (void)deleteMessage:(SBDBaseMessage * _Nonnull)message
    completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/// Deletes a message. The message's sender has to be the current user.
/// @param messageId           The message id to be deleted.
/// @param completionHandler The handler block to execute.
/// @since 3.0.179
- (void)deleteMessageWithMessageId:(long long)messageId
                 completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

#pragma mark - Update message

/// Updates a user message. The message text, data, and custom type can be updated
/// @param userMessage       The user message to be updated.
/// @param messageText       New message text.
/// @param data              New data.
/// @param customType        New custom type.
/// @param completionHandler The handler block to execute.
- (void)updateUserMessage:(SBDUserMessage * _Nonnull)userMessage
              messageText:(NSString * _Nullable)messageText
                     data:(NSString * _Nullable)data
               customType:(NSString * _Nullable)customType
        completionHandler:(nullable void (^)(SBDUserMessage * _Nullable userMessage, SBDError * _Nullable error))completionHandler;

/// Updates a user message. The text message, data, custom type from user message params can be updated.
/// @param messageId            The message ID of the message to be updated.
/// @param params               The user message params that has updating fields.
/// @param completionHandler    The handler block to be executed after update.
///                             This block has no return value and takes two argument.
///                             the one is updated message type of SBDUserMessage. the other is an error made when there is something wrong to process.
///
/// @since 3.0.110

- (void)updateUserMessageWithMessageId:(long long)messageId
                     userMessageParams:(nonnull SBDUserMessageParams *)params
                     completionHandler:(nullable void (^)(SBDUserMessage * _Nullable message, SBDError * _Nullable error))completionHandler;


/// Updates a file message. The data and custom type can be updated
/// @param fileMessage       The file message to be updated.
/// @param data              New data.
/// @param customType        New custom type.
/// @param completionHandler The handler block to execute.
- (void)updateFileMessage:(SBDFileMessage * _Nonnull)fileMessage
                     data:(NSString * _Nullable)data
               customType:(NSString * _Nullable)customType
        completionHandler:(nullable void (^)(SBDFileMessage * _Nullable fileMessage, SBDError * _Nullable error))completionHandler;

/// Updates a file message. The data, custom type from file message params can be updated.
/// @param messageId            The message ID of the message to be updated.
/// @param params               The file message params that has updating fields.
/// @param completionHandler    The handler block to be executed after update.
///                           This block has no return value and takes two argument.
///                           the one is updated message type of SBDFileMessage. the other is an error made when there is something wrong to process.
/// @since 3.0.110

- (void)updateFileMessageWithMessageId:(long long)messageId
                     fileMessageParams:(nonnull SBDFileMessageParams *)params
                     completionHandler:(nullable void (^)(SBDFileMessage * _Nullable message, SBDError * _Nullable error))completionHandler;


/// Requests to translate the text message into the target languages. You can get a user message with the `translations` property after the request, but the request does not trigger an update event on the message and does not get the message by `getMessageChangeLogsWithToken:`. If you request a message through methods such as `getPreivousMessage:` or `getNextMessage:`, you will get a translated message.
/// A translation request can affect not only your message, but also other people's messages.
/// @param message  The string type of the message of the user message instance will be translated.
/// @param targetLanguages   The target languages that the message will be translated into. e.g. @"en", @"es", @"ch"
/// @param completionHandler  The handler block to be executed after translation. This block has no return value and takes two arguments. One is a user message. If succeeded to translate text of the message, the message instance with translations is delivered. If failed to translate, nil is delivered. Another factor is an error. If failed to request, an error is dispatched.
/// @since 3.0.148
/// @code
/// SBDUserMessage *userMessage; // received from event or get from API (`getPreviousMessages:`)
/// [channel translateUserMessage:userMessage targerLanguages:target_languages completionHandler:^(SBDUserMessage * _Nullable message, SBDError * _Nullable error) {
///    if (error != nil) {
///        // handle error
///        return;
///    }
///
///    NSDictionary *translations = message.translations;
///    // do somthing.
/// }];
/// @endcode

- (void)translateUserMessage:(nonnull SBDUserMessage *)message
             targetLanguages:(nonnull NSArray<NSString *> *)targetLanguages
           completionHandler:(nullable SBDUserMessageHandler)completionHandler;

/// Checks the channel type.
/// @return If YES, this channel is a group channel.
- (BOOL)isGroupChannel;

/// Checks the channel type.
/// @return If YES, this channel is an open channel.
- (BOOL)isOpenChannel;

#pragma mark - Get messages by timestamp.

/// Gets the next messages by the timestamp with a limit and ordering.
/// @param timestamp         The standard timestamp to load messages.
/// @param limit             The limit for the number of messages. The returned messages could be more than this number if there are messages which have the same timestamp.
/// @param reverse           If yes, the latest message is the index 0.
/// @param completionHandler The handler block to execute. The `messages` is the array of `SBDBaseMessage` instances.
/// @deprecated 3.0.40 (Use `getMessagesByTimestamp:params:completionHandler:` instead.)
- (void)getNextMessagesByTimestamp:(long long)timestamp
                             limit:(NSInteger)limit
                           reverse:(BOOL)reverse
                 completionHandler:(nullable void (^)(NSArray<SBDBaseMessage *> * _Nullable messages, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/// Gets the next messages by the timestamp with a limit and ordering.
/// @param timestamp         The standard timestamp to load messages.
/// @param limit             The limit for the number of messages. The returned messages could be more than this number if there are messages which have the same timestamp.
/// @param reverse           If yes, the latest message is the index 0.
/// @param messageType       Message type to filter messages.
/// @param customType        Custom type to filter messages. If filtering isn't required, set nil.
/// @param completionHandler The handler block to execute. The `messages` is the array of `SBDBaseMessage` instances.
- (void)getNextMessagesByTimestamp:(long long)timestamp
                             limit:(NSInteger)limit
                           reverse:(BOOL)reverse
                       messageType:(SBDMessageTypeFilter)messageType
                        customType:(NSString * _Nullable)customType
                 completionHandler:(nullable void (^)(NSArray<SBDBaseMessage *> * _Nullable messages, SBDError * _Nullable error))completionHandler;

/// Gets the next messages by the timestamp with a limit and ordering.
/// @param timestamp         The standard timestamp to load messages.
/// @param limit             The limit for the number of messages. The returned messages could be more than this number if there are messages which have the same timestamp.
/// @param reverse           If yes, the latest message is the index 0.
/// @param messageType       Message type to filter messages.
/// @param customType        Custom type to filter messages. If filtering isn't required, set nil.
/// @param senderUserIds     Returns messages whose sender user id matches sender user ids.
/// @param completionHandler The handler block to execute. The `messages` is the array of `SBDBaseMessage` instances.
/// @since 3.0.106
- (void)getNextMessagesByTimestamp:(long long)timestamp
                             limit:(NSInteger)limit
                           reverse:(BOOL)reverse
                       messageType:(SBDMessageTypeFilter)messageType
                        customType:(NSString * _Nullable)customType
                     senderUserIds:(NSArray<NSString *> * _Nullable)senderUserIds
                 completionHandler:(nullable void (^)(NSArray<SBDBaseMessage *> * _Nullable messages, SBDError * _Nullable error))completionHandler;

/// Gets the next messages by the timestamp. The messages can have meta array.
/// @param timestamp The standard timestamp to load messages.
/// @param limit The limit for the number of messages. The returned messages could be more than this number if there are messages which have the same timestamp.
/// @param reverse If YES, the latest message is the index 0.
/// @param messageType Message type to filter messages.
/// @param customType Custom type to filter messages. If filtering isn't required, set nil.
/// @param senderUserIds Returns messages whose sender user id matches sender user ids.
/// @param includeMetaArray If YES, the `messages` has meta array.
/// @param completionHandler The handler block to execute. The `messages` is the array of `SBDBaseMessage` instances.
/// @since 3.0.116
- (void)getNextMessagesByTimestamp:(long long)timestamp
                             limit:(NSInteger)limit
                           reverse:(BOOL)reverse
                       messageType:(SBDMessageTypeFilter)messageType
                        customType:(NSString * _Nullable)customType
                     senderUserIds:(NSArray<NSString *> * _Nullable)senderUserIds
                  includeMetaArray:(BOOL)includeMetaArray
                 completionHandler:(nullable void (^)(NSArray<SBDBaseMessage *> * _Nullable messages, SBDError * _Nullable error))completionHandler;

/// Requests to next messages by the timestamp with filters of inclusive timestamp, limit, reverse, message type, custom type, sender user ids, include meta array.
/// @param timestamp The standard timestamp to load messages.
/// @param inclusiveTimestamp Whether the response has messages including timestamp or not. If true (YES), results contain messages that created at the timestamp. If false (NO), results have messages that created after the timestamp
/// @param limit The limit for the number of messages. The returned messages could be more than this number if there are messages which have the same timestamp.
/// @param reverse If YES, the latest message is the index 0.
/// @param messageType Message type to filter messages.
/// @param customType Custom type to filter messages. If filtering isn't required, set nil.
/// @param senderUserIds Returns messages whose sender user id matches sender user ids.
/// @param includeMetaArray If YES, the `messages` has meta array.
/// @param completionHandler The handler block to execute. The `messages` is the array of `SBDBaseMessage` instances.
/// @since 3.0.140
/// @deprecated 3.0.169 (Use `getMessagesByTimestamp:params:completionHandler:` instead.)
- (void)getNextMessagesByTimestamp:(long long)timestamp
                inclusiveTimestamp:(BOOL)inclusiveTimestamp
                             limit:(NSInteger)limit
                           reverse:(BOOL)reverse
                       messageType:(SBDMessageTypeFilter)messageType
                        customType:(NSString * _Nullable)customType
                     senderUserIds:(NSArray<NSString *> * _Nullable)senderUserIds
                  includeMetaArray:(BOOL)includeMetaArray
                 completionHandler:(nullable SBDGetMessagesHandler)completionHandler
DEPRECATED_ATTRIBUTE;

/// Requests to next messages by the timestamp with filters of inclusive timestamp, limit, reverse, message type, custom type, sender user ids, include meta array, and include reactions.
/// @param timestamp The standard timestamp to load messages.
/// @param inclusiveTimestamp Whether the response has messages including timestamp or not. If true (YES), results contain messages that created at the timestamp. If false (NO), results have messages that created after the timestamp
/// @param limit The limit for the number of messages. The returned messages could be more than this number if there are messages which have the same timestamp.
/// @param reverse If YES, the latest message is the index 0.
/// @param messageType Message type to filter messages.
/// @param customType Custom type to filter messages. If filtering isn't required, set nil.
/// @param senderUserIds Returns messages whose sender user id matches sender user ids.
/// @param includeMetaArray If YES, the `messages` has meta array.
/// @param includeReactions If YES, the `messages` has reactions.
/// @param completionHandler The handler block to execute. The `messages` is the array of `SBDBaseMessage` instances.
/// @since 3.0.169
- (void)getNextMessagesByTimestamp:(long long)timestamp
                inclusiveTimestamp:(BOOL)inclusiveTimestamp
                             limit:(NSInteger)limit
                           reverse:(BOOL)reverse
                       messageType:(SBDMessageTypeFilter)messageType
                        customType:(NSString * _Nullable)customType
                     senderUserIds:(NSArray<NSString *> * _Nullable)senderUserIds
                  includeMetaArray:(BOOL)includeMetaArray
                  includeReactions:(BOOL)includeReactions
                 completionHandler:(nullable SBDGetMessagesHandler)completionHandler;

/// Gets the previous messages by the timestamp with a limit and ordering.
/// @param timestamp         The standard timestamp to load messages.
/// @param limit             The limit for the number of messages. The returned messages could be more than this number if there are messages which have the same timestamp.
/// @param reverse           If yes, the latest message is the index 0.
/// @param completionHandler The handler block to execute. The `messages` is the array of `SBDBaseMessage` instances.
/// @deprecated 3.0.40 (Use `getMessagesByTimestamp:params:completionHandler:` instead.)
- (void)getPreviousMessagesByTimestamp:(long long)timestamp
                                 limit:(NSInteger)limit
                               reverse:(BOOL)reverse
                     completionHandler:(nullable void (^)(NSArray<SBDBaseMessage *> * _Nullable messages, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;


/// Gets the previous messages by the timestamp with a limit and ordering.
/// @param timestamp         The standard timestamp to load messages.
/// @param limit             The limit for the number of messages. The returned messages could be more than this number if there are messages which have the same timestamp.
/// @param reverse           If yes, the latest message is the index 0.
/// @param messageType       Message type to filter messages.
/// @param customType        Custom type to filter messages. If filtering isn't required, set nil.
/// @param completionHandler The handler block to execute. The `messages` is the array of `SBDBaseMessage` instances.
- (void)getPreviousMessagesByTimestamp:(long long)timestamp
                                 limit:(NSInteger)limit
                               reverse:(BOOL)reverse
                           messageType:(SBDMessageTypeFilter)messageType
                            customType:(NSString * _Nullable)customType
                     completionHandler:(nullable void (^)(NSArray<SBDBaseMessage *> * _Nullable messages, SBDError * _Nullable error))completionHandler;

/// Gets the previous messages by the timestamp with a limit and ordering.
/// @param timestamp         The standard timestamp to load messages.
/// @param limit             The limit for the number of messages. The returned messages could be more than this number if there are messages which have the same timestamp.
/// @param reverse           If yes, the latest message is the index 0.
/// @param messageType       Message type to filter messages.
/// @param customType        Custom type to filter messages. If filtering isn't required, set nil.
/// @param senderUserIds     Returns messages whose sender user id matches sender user ids.
/// @param completionHandler The handler block to execute. The `messages` is the array of `SBDBaseMessage` instances.
/// @since 3.0.106
- (void)getPreviousMessagesByTimestamp:(long long)timestamp
                                 limit:(NSInteger)limit
                               reverse:(BOOL)reverse
                           messageType:(SBDMessageTypeFilter)messageType
                            customType:(NSString * _Nullable)customType
                         senderUserIds:(NSArray<NSString *> * _Nullable)senderUserIds
                     completionHandler:(nullable void (^)(NSArray<SBDBaseMessage *> * _Nullable messages, SBDError * _Nullable error))completionHandler;

/// Gets the previous messages by the timestamp. The messages can have meta array.
/// @param timestamp The standard timestamp to load messages.
/// @param limit The limit for the number of messages. The returned messages could be more than this number if there are messages which have the same timestamp.
/// @param reverse If YES, the latest message is the index 0.
/// @param messageType Message type to filter messages.
/// @param customType Custom type to filter messages. If filtering isn't required, set nil.
/// @param senderUserIds Returns messages whose sender user id matches sender user ids.
/// @param includeMetaArray If YES, the `messages` has meta array.
/// @param completionHandler The handler block to execute. The `messages` is the array of `SBDBaseMessage` instances.
/// @since 3.0.116
- (void)getPreviousMessagesByTimestamp:(long long)timestamp
                                 limit:(NSInteger)limit
                               reverse:(BOOL)reverse
                           messageType:(SBDMessageTypeFilter)messageType
                            customType:(NSString * _Nullable)customType
                         senderUserIds:(NSArray<NSString *> * _Nullable)senderUserIds
                      includeMetaArray:(BOOL)includeMetaArray
                     completionHandler:(nullable void (^)(NSArray<SBDBaseMessage *> * _Nullable messages, SBDError * _Nullable error))completionHandler;

/// Requests to previous messages by the timestamp with filters of inclusive timestamp, limit, reverse, message type, custom type, sender user ids, include meta array.
/// @param timestamp The standard timestamp to load messages.
/// @param inclusiveTimestamp Whether the response has messages including timestamp or not. If true (YES), results contain messages that created at the timestamp. If false (NO), results have messages that created before the timestamp
/// @param limit The limit for the number of messages. The returned messages could be more than this number if there are messages which have the same timestamp.
/// @param reverse If YES, the latest message is the index 0.
/// @param messageType Message type to filter messages.
/// @param customType Custom type to filter messages. If filtering isn't required, set nil.
/// @param senderUserIds Returns messages whose sender user id matches sender user ids.
/// @param includeMetaArray If YES, the `messages` has meta array.
/// @param completionHandler The handler block to execute. The `messages` is the array of `SBDBaseMessage` instances.
/// @since 3.0.140
/// @deprecated in 3.0.169 (Use `getMessagesByTimestamp:params:completionHandler:` instead.)
- (void)getPreviousMessagesByTimestamp:(long long)timestamp
                    inclusiveTimestamp:(BOOL)inclusiveTimestamp
                                 limit:(NSInteger)limit
                               reverse:(BOOL)reverse
                           messageType:(SBDMessageTypeFilter)messageType
                            customType:(NSString * _Nullable)customType
                         senderUserIds:(NSArray<NSString *> * _Nullable)senderUserIds
                      includeMetaArray:(BOOL)includeMetaArray
                     completionHandler:(nullable SBDGetMessagesHandler)completionHandler
DEPRECATED_ATTRIBUTE;


/// Requests to previous messages by the timestamp with filters of inclusive timestamp, limit, reverse, message type, custom type, sender user ids, include meta array, and include reactions.
/// @param timestamp The standard timestamp to load messages.
/// @param inclusiveTimestamp Whether the response has messages including timestamp or not. If true (YES), results contain messages that created at the timestamp. If false (NO), results have messages that created before the timestamp
/// @param limit The limit for the number of messages. The returned messages could be more than this number if there are messages which have the same timestamp.
/// @param reverse If YES, the latest message is the index 0.
/// @param messageType Message type to filter messages.
/// @param customType Custom type to filter messages. If filtering isn't required, set nil.
/// @param senderUserIds Returns messages whose sender user id matches sender user ids.
/// @param includeMetaArray If YES, the `messages` has meta array.
/// @param includeReactions If YES, the `messages` has reactions.
/// @param completionHandler The handler block to execute. The `messages` is the array of `SBDBaseMessage` instances.
/// @since 3.0.169
- (void)getPreviousMessagesByTimestamp:(long long)timestamp
                    inclusiveTimestamp:(BOOL)inclusiveTimestamp
                                 limit:(NSInteger)limit
                               reverse:(BOOL)reverse
                           messageType:(SBDMessageTypeFilter)messageType
                            customType:(NSString * _Nullable)customType
                         senderUserIds:(NSArray<NSString *> * _Nullable)senderUserIds
                      includeMetaArray:(BOOL)includeMetaArray
                      includeReactions:(BOOL)includeReactions
                     completionHandler:(nullable SBDGetMessagesHandler)completionHandler;

/// Gets the previous and next message by the timestamp with a limit and ordering.
/// @param timestamp         The standard timestamp to load messages.
/// @param prevLimit         The previous limit for the number of messages. The returned messages could be more than this number if there are messages which have the same timestamp.
/// @param nextLimit         The next limit for the number of messages. The returned messages could be more than this number if there are messages which have the same timestamp.
/// @param reverse           If yes, the latest message is the index 0.
/// @param completionHandler The handler block to execute. The `messages` is the array of `SBDBaseMessage` instances.
/// @deprecated 3.0.40 (Use `getMessagesByTimestamp:params:completionHandler:` instead.)
- (void)getPreviousAndNextMessagesByTimestamp:(long long)timestamp
                                    prevLimit:(NSInteger)prevLimit
                                    nextLimit:(NSInteger)nextLimit
                                      reverse:(BOOL)reverse
                            completionHandler:(nullable void (^)(NSArray<SBDBaseMessage *> * _Nullable messages, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/// Gets the previous and next message by the timestamp with a limit and ordering.
/// @param timestamp         The standard timestamp to load messages.
/// @param prevLimit         The previous limit for the number of messages. The returned messages could be more than this number if there are messages which have the same timestamp.
/// @param nextLimit         The next limit for the number of messages. The returned messages could be more than this number if there are messages which have the same timestamp.
/// @param reverse           If yes, the latest message is the index 0.
/// @param messageType       Message type to filter messages.
/// @param customType        Custom type to filter messages. If filtering isn't required, set nil.
/// @param completionHandler The handler block to execute. The `messages` is the array of `SBDBaseMessage` instances.
- (void)getPreviousAndNextMessagesByTimestamp:(long long)timestamp
                                    prevLimit:(NSInteger)prevLimit
                                    nextLimit:(NSInteger)nextLimit
                                      reverse:(BOOL)reverse
                                  messageType:(SBDMessageTypeFilter)messageType
                                   customType:(NSString * _Nullable)customType
                            completionHandler:(nullable void (^)(NSArray<SBDBaseMessage *> * _Nullable messages, SBDError * _Nullable error))completionHandler;


/// Gets the previous and next message by the timestamp with a limit and ordering.
/// @param timestamp         The standard timestamp to load messages.
/// @param prevLimit         The previous limit for the number of messages. The returned messages could be more than this number if there are messages which have the same timestamp.
/// @param nextLimit         The next limit for the number of messages. The returned messages could be more than this number if there are messages which have the same timestamp.
/// @param reverse           If yes, the latest message is the index 0.
/// @param messageType       Message type to filter messages.
/// @param customType        Custom type to filter messages. If filtering isn't required, set nil.
/// @param senderUserIds     Returns messages whose sender user id matches sender user ids.
/// @param completionHandler The handler block to execute. The `messages` is the array of `SBDBaseMessage` instances.
/// @since 3.0.106
- (void)getPreviousAndNextMessagesByTimestamp:(long long)timestamp
                                    prevLimit:(NSInteger)prevLimit
                                    nextLimit:(NSInteger)nextLimit
                                      reverse:(BOOL)reverse
                                  messageType:(SBDMessageTypeFilter)messageType
                                   customType:(NSString * _Nullable)customType
                                senderUserIds:(NSArray<NSString *> * _Nullable)senderUserIds
                            completionHandler:(nullable void (^)(NSArray<SBDBaseMessage *> * _Nullable messages, SBDError * _Nullable error))completionHandler;


/// Gets the previous and next messages by the timestamp. The messages can have meta array.
/// @param timestamp The standard timestamp to load messages.
/// @param prevLimit The previous limit for the number of messages. The returned messages could be more than this number if there are messages which have the same timestamp.
/// @param nextLimit The next limit for the number of messages. The returned messages could be more than this number if there are messages which have the same timestamp.
/// @param reverse If YES, the latest message is the index 0.
/// @param messageType Message type to filter messages.
/// @param customType Custom type to filter messages. If filtering isn't required, set nil.
/// @param senderUserIds Returns messages whose sender user id matches sender user ids.
/// @param includeMetaArray If YES, the `messages` has meta array.
/// @param completionHandler The handler block to execute. The `messages` is the array of `SBDBaseMessage` instances.
/// @since 3.0.116
- (void)getPreviousAndNextMessagesByTimestamp:(long long)timestamp
                                    prevLimit:(NSInteger)prevLimit
                                    nextLimit:(NSInteger)nextLimit
                                      reverse:(BOOL)reverse
                                  messageType:(SBDMessageTypeFilter)messageType
                                   customType:(NSString * _Nullable)customType
                                senderUserIds:(NSArray<NSString *> * _Nullable)senderUserIds
                             includeMetaArray:(BOOL)includeMetaArray
                            completionHandler:(nullable void (^)(NSArray<SBDBaseMessage *> * _Nullable messages, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/// Gets the previous and next messages by the timestamp with filters of prev limit, next limit, reverse, message type, custom type, sender user ids, include meta array, and include reactions.
/// @param timestamp The standard timestamp to load messages.
/// @param prevLimit The previous limit for the number of messages. The returned messages could be more than this number if there are messages which have the same timestamp.
/// @param nextLimit The next limit for the number of messages. The returned messages could be more than this number if there are messages which have the same timestamp.
/// @param reverse If YES, the latest message is the index 0.
/// @param messageType Message type to filter messages.
/// @param customType Custom type to filter messages. If filtering isn't required, set nil.
/// @param senderUserIds Returns messages whose sender user id matches sender user ids.
/// @param includeMetaArray If YES, the `messages` has meta array.
/// @param includeReactions If YES, the `messages` has reactions.
/// @param completionHandler The handler block to execute. The `messages` is the array of `SBDBaseMessage` instances.
/// @since 3.0.169
- (void)getPreviousAndNextMessagesByTimestamp:(long long)timestamp
                                    prevLimit:(NSInteger)prevLimit
                                    nextLimit:(NSInteger)nextLimit
                                      reverse:(BOOL)reverse
                                  messageType:(SBDMessageTypeFilter)messageType
                                   customType:(NSString * _Nullable)customType
                                senderUserIds:(NSArray<NSString *> * _Nullable)senderUserIds
                             includeMetaArray:(BOOL)includeMetaArray
                             includeReactions:(BOOL)includeReactions
                            completionHandler:(nullable void (^)(NSArray<SBDBaseMessage *> * _Nullable messages, SBDError * _Nullable error))completionHandler;

#pragma mark - Get messages by message ID.

/// Gets the next messages by the message ID with a limit and ordering.
/// @param messageId         The standard message ID to load messages.
/// @param limit             The limit for the number of messages. The returned messages could be more than this number if there are messages which have the same timestamp.
/// @param reverse           If yes, the latest message is the index 0.
/// @param completionHandler The handler block to execute. The `messages` is the array of `SBDBaseMessage` instances.
/// @deprecated 3.0.40 (Use `getMessagesByMessageId:params:completionHandler:` instead.)
- (void)getNextMessagesByMessageId:(long long)messageId
                             limit:(NSInteger)limit
                           reverse:(BOOL)reverse
                 completionHandler:(nullable void (^)(NSArray<SBDBaseMessage *> * _Nullable messages, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/// Gets the next messages by the message ID with a limit and ordering.
/// @param messageId         The standard message ID to load messages.
/// @param limit             The limit for the number of messages. The returned messages could be more than this number if there are messages which have the same timestamp.
/// @param reverse           If yes, the latest message is the index 0.
/// @param messageType       Message type to filter messages.
/// @param customType        Custom type to filter messages. If filtering isn't required, set nil.
/// @param completionHandler The handler block to execute. The `messages` is the array of `SBDBaseMessage` instances.
- (void)getNextMessagesByMessageId:(long long)messageId
                             limit:(NSInteger)limit
                           reverse:(BOOL)reverse
                       messageType:(SBDMessageTypeFilter)messageType
                        customType:(NSString * _Nullable)customType
                 completionHandler:(nullable void (^)(NSArray<SBDBaseMessage *> * _Nullable messages, SBDError * _Nullable error))completionHandler;

/// Gets the next messages by the message ID with a limit and ordering.
/// @param messageId         The standard message ID to load messages.
/// @param limit             The limit for the number of messages. The returned messages could be more than this number if there are messages which have the same timestamp.
/// @param reverse           If yes, the latest message is the index 0.
/// @param messageType       Message type to filter messages.
/// @param customType        Custom type to filter messages. If filtering isn't required, set nil.
/// @param senderUserIds     Returns messages whose sender user id matches sender user ids.
/// @param completionHandler The handler block to execute. The `messages` is the array of `SBDBaseMessage` instances.
/// @since 3.0.106
- (void)getNextMessagesByMessageId:(long long)messageId
                             limit:(NSInteger)limit
                           reverse:(BOOL)reverse
                       messageType:(SBDMessageTypeFilter)messageType
                        customType:(NSString * _Nullable)customType
                     senderUserIds:(NSArray<NSString *> * _Nullable)senderUserIds
                 completionHandler:(nullable void (^)(NSArray<SBDBaseMessage *> * _Nullable messages, SBDError * _Nullable error))completionHandler;

/// Gets the next messages by the message ID. The messages can have meta array.
/// @param messageId The standard message ID to load messages.
/// @param limit The limit for the number of messages. The returned messages could be more than this number if there are messages which have the same timestamp.
/// @param reverse If YES, the latest message is the index 0.
/// @param messageType Message type to filter messages.
/// @param customType Custom type to filter messages. If filtering isn't required, set nil.
/// @param senderUserIds Returns messages whose sender user id matches sender user ids.
/// @param includeMetaArray If YES, the `messages` has meta array.
/// @param completionHandler The handler block to execute. The `messages` is the array of `SBDBaseMessage` instances.
/// @since 3.0.116
/// @deprecated 3.0.169 (Use `getMessagesByMessageId:params:completionHandler:` instead.)
- (void)getNextMessagesByMessageId:(long long)messageId
                             limit:(NSInteger)limit
                           reverse:(BOOL)reverse
                       messageType:(SBDMessageTypeFilter)messageType
                        customType:(NSString * _Nullable)customType
                     senderUserIds:(NSArray<NSString *> * _Nullable)senderUserIds
                  includeMetaArray:(BOOL)includeMetaArray
                 completionHandler:(nullable void (^)(NSArray<SBDBaseMessage *> * _Nullable messages, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;


/// Gets the next messages by the message ID with filters of limit, reverse, message type, custom type, sender user ids, include meta array, and include reactions.
/// @param messageId The standard message ID to load messages.
/// @param limit The limit for the number of messages. The returned messages could be more than this number if there are messages which have the same timestamp.
/// @param reverse If YES, the latest message is the index 0.
/// @param messageType Message type to filter messages.
/// @param customType Custom type to filter messages. If filtering isn't required, set nil.
/// @param senderUserIds Returns messages whose sender user id matches sender user ids.
/// @param includeMetaArray If YES, the `messages` has meta array.
/// @param includeReactions If YES, the `messages` has reactions.
/// @param completionHandler The handler block to execute. The `messages` is the array of `SBDBaseMessage` instances.
/// @since 3.0.169
/// @deprecated 3.0.175 (Use `getMessagesByMessageId:params:completionHandler:` instead.)
- (void)getNextMessagesByMessageId:(long long)messageId
                             limit:(NSInteger)limit
                           reverse:(BOOL)reverse
                       messageType:(SBDMessageTypeFilter)messageType
                        customType:(NSString * _Nullable)customType
                     senderUserIds:(NSArray<NSString *> * _Nullable)senderUserIds
                  includeMetaArray:(BOOL)includeMetaArray
                  includeReactions:(BOOL)includeReactions
                 completionHandler:(nullable void (^)(NSArray<SBDBaseMessage *> * _Nullable messages, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;


/// Gets the next messages by the message ID with filters of limit, reverse, message type, custom type, sender user ids, include meta array, and include reactions.
/// @param messageId The standard message ID to load messages.
/// @param inclusiveTimestamp Whether the response has messages including timestamp or not. If true (YES), results contain messages that created at the timestamp. If false (NO), results have messages that created after the timestamp
/// @param limit The limit for the number of messages. The returned messages could be more than this number if there are messages which have the same timestamp.
/// @param reverse If YES, the latest message is the index 0.
/// @param messageType Message type to filter messages.
/// @param customType Custom type to filter messages. If filtering isn't required, set nil.
/// @param senderUserIds Returns messages whose sender user id matches sender user ids.
/// @param includeMetaArray If YES, the `messages` has meta array.
/// @param includeReactions If YES, the `messages` has reactions.
/// @param completionHandler The handler block to execute. The `messages` is the array of `SBDBaseMessage` instances.
/// @since 3.0.175
- (void)getNextMessagesByMessageId:(long long)messageId
                inclusiveTimestamp:(BOOL)inclusiveTimestamp
                             limit:(NSInteger)limit
                           reverse:(BOOL)reverse
                       messageType:(SBDMessageTypeFilter)messageType
                        customType:(NSString * _Nullable)customType
                     senderUserIds:(NSArray<NSString *> * _Nullable)senderUserIds
                  includeMetaArray:(BOOL)includeMetaArray
                  includeReactions:(BOOL)includeReactions
                 completionHandler:(nullable void (^)(NSArray<SBDBaseMessage *> * _Nullable messages, SBDError * _Nullable error))completionHandler;

/// Gets the previous messages by the message ID with a limit and ordering.
/// @param messageId         The standard message ID to load messages.
/// @param limit             The limit for the number of messages. The returned messages could be more than this number if there are messages which have the same timestamp.
/// @param reverse           If yes, the latest message is the index 0.
/// @param completionHandler The handler block to execute. The `messages` is the array of `SBDBaseMessage` instances.
/// @deprecated in v3.0.40.
- (void)getPreviousMessagesByMessageId:(long long)messageId
                                 limit:(NSInteger)limit
                               reverse:(BOOL)reverse
                     completionHandler:(nullable void (^)(NSArray<SBDBaseMessage *> * _Nullable messages, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/// Gets the previous messages by the message ID with a limit and ordering.
/// @param messageId         The standard message ID to load messages.
/// @param limit             The limit for the number of messages. The returned messages could be more than this number if there are messages which have the same timestamp.
/// @param reverse           If yes, the latest message is the index 0.
/// @param messageType       Message type to filter messages.
/// @param customType        Custom type to filter messages. If filtering isn't required, set nil.
/// @param completionHandler The handler block to execute. The `messages` is the array of `SBDBaseMessage` instances.
- (void)getPreviousMessagesByMessageId:(long long)messageId
                                 limit:(NSInteger)limit
                               reverse:(BOOL)reverse
                           messageType:(SBDMessageTypeFilter)messageType
                            customType:(NSString * _Nullable)customType
                     completionHandler:(nullable void (^)(NSArray<SBDBaseMessage *> * _Nullable messages, SBDError * _Nullable error))completionHandler;

/// Gets the previous messages by the message ID with a limit and ordering.
/// @param messageId         The standard message ID to load messages.
/// @param limit             The limit for the number of messages. The returned messages could be more than this number if there are messages which have the same timestamp.
/// @param reverse           If yes, the latest message is the index 0.
/// @param messageType       Message type to filter messages.
/// @param customType        Custom type to filter messages. If filtering isn't required, set nil.
/// @param senderUserIds     Returns messages whose sender user id matches sender user ids.
/// @param completionHandler The handler block to execute. The `messages` is the array of `SBDBaseMessage` instances.
/// @since 3.0.106
- (void)getPreviousMessagesByMessageId:(long long)messageId
                                 limit:(NSInteger)limit
                               reverse:(BOOL)reverse
                           messageType:(SBDMessageTypeFilter)messageType
                            customType:(NSString * _Nullable)customType
                         senderUserIds:(NSArray<NSString *> * _Nullable)senderUserIds
                     completionHandler:(nullable void (^)(NSArray<SBDBaseMessage *> * _Nullable messages, SBDError * _Nullable error))completionHandler;

/// Gets the previous messages by the message ID. The messages can have meta array.
/// @param messageId The standard message ID to load messages.
/// @param limit The limit for the number of messages. The returned messages could be more than this number if there are messages which have the same timestamp.
/// @param reverse If YES, the latest message is the index 0.
/// @param messageType Message type to filter messages.
/// @param customType Custom type to filter messages. If filtering isn't required, set nil.
/// @param senderUserIds Returns messages whose sender user id matches sender user ids.
/// @param includeMetaArray If YES, the `messages` has meta array.
/// @param completionHandler The handler block to execute. The `messages` is the array of `SBDBaseMessage` instances.
/// @since 3.0.116
/// @deprecated 3.0.169 (Use `getMessagesByMessageId:params:completionHandler:` instead.)
- (void)getPreviousMessagesByMessageId:(long long)messageId
                                 limit:(NSInteger)limit
                               reverse:(BOOL)reverse
                           messageType:(SBDMessageTypeFilter)messageType
                            customType:(NSString * _Nullable)customType
                         senderUserIds:(NSArray<NSString *> * _Nullable)senderUserIds
                      includeMetaArray:(BOOL)includeMetaArray
                     completionHandler:(nullable void (^)(NSArray<SBDBaseMessage *> * _Nullable messages, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/// Gets the previous messages by the message ID with filters of prev limit, next limit, reverse, message type, custom type, sender user ids, include meta array, and include reactions.
/// @param messageId The standard message ID to load messages.
/// @param limit The limit for the number of messages. The returned messages could be more than this number if there are messages which have the same timestamp.
/// @param reverse If YES, the latest message is the index 0.
/// @param messageType Message type to filter messages.
/// @param customType Custom type to filter messages. If filtering isn't required, set nil.
/// @param senderUserIds Returns messages whose sender user id matches sender user ids.
/// @param includeMetaArray If YES, the `messages` has meta array.
/// @param includeReactions If YES, the `messages` has reactions.
/// @param completionHandler The handler block to execute. The `messages` is the array of `SBDBaseMessage` instances.
/// @since 3.0.169
/// @deprecated 3.0.175 (Use `getMessagesByMessageId:params:completionHandler:` instead.)
- (void)getPreviousMessagesByMessageId:(long long)messageId
                                 limit:(NSInteger)limit
                               reverse:(BOOL)reverse
                           messageType:(SBDMessageTypeFilter)messageType
                            customType:(NSString * _Nullable)customType
                         senderUserIds:(NSArray<NSString *> * _Nullable)senderUserIds
                      includeMetaArray:(BOOL)includeMetaArray
                      includeReactions:(BOOL)includeReactions
                     completionHandler:(nullable void (^)(NSArray<SBDBaseMessage *> * _Nullable messages, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/// Gets the previous messages by the message ID with filters of prev limit, next limit, reverse, message type, custom type, sender user ids, include meta array, and include reactions.
/// @param messageId The standard message ID to load messages.
/// @param inclusiveTimestamp Whether the response has messages including timestamp or not. If true (YES), results contain messages that created at the timestamp. If false (NO), results have messages that created after the timestamp
/// @param limit The limit for the number of messages. The returned messages could be more than this number if there are messages which have the same timestamp.
/// @param reverse If YES, the latest message is the index 0.
/// @param messageType Message type to filter messages.
/// @param customType Custom type to filter messages. If filtering isn't required, set nil.
/// @param senderUserIds Returns messages whose sender user id matches sender user ids.
/// @param includeMetaArray If YES, the `messages` has meta array.
/// @param includeReactions If YES, the `messages` has reactions.
/// @param completionHandler The handler block to execute. The `messages` is the array of `SBDBaseMessage` instances.
/// @since 3.0.175
- (void)getPreviousMessagesByMessageId:(long long)messageId
                    inclusiveTimestamp:(BOOL)inclusiveTimestamp
                                 limit:(NSInteger)limit
                               reverse:(BOOL)reverse
                           messageType:(SBDMessageTypeFilter)messageType
                            customType:(NSString * _Nullable)customType
                         senderUserIds:(NSArray<NSString *> * _Nullable)senderUserIds
                      includeMetaArray:(BOOL)includeMetaArray
                      includeReactions:(BOOL)includeReactions
                     completionHandler:(nullable void (^)(NSArray<SBDBaseMessage *> * _Nullable messages, SBDError * _Nullable error))completionHandler;

/// Gets the previous and next message by the message ID with a limit and ordering.
/// @param messageId         The standard message ID to load messages.
/// @param prevLimit         The previous limit for the number of messages. The returned messages could be more than this number if there are messages which have the same timestamp.
/// @param nextLimit         The next limit for the number of messages. The returned messages could be more than this number if there are messages which have the same timestamp.
/// @param reverse           If yes, the latest message is the index 0.
/// @param completionHandler The handler block to execute. The `messages` is the array of `SBDBaseMessage` instances.
/// @deprecated 3.0.40. (Use `getMessagesByMessageId:params:completionHandler:` instead.)
- (void)getPreviousAndNextMessagesByMessageId:(long long)messageId
                                    prevLimit:(NSInteger)prevLimit
                                    nextLimit:(NSInteger)nextLimit
                                      reverse:(BOOL)reverse
                            completionHandler:(nullable void (^)(NSArray<SBDBaseMessage *> * _Nullable messages, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;


/// Gets the previous and next message by the message ID with a limit and ordering.
/// @param messageId         The standard message ID to load messages.
/// @param prevLimit         The previous limit for the number of messages. The returned messages could be more than this number if there are messages which have the same timestamp.
/// @param nextLimit         The next limit for the number of messages. The returned messages could be more than this number if there are messages which have the same timestamp.
/// @param reverse           If yes, the latest message is the index 0.
/// @param messageType       Message type to filter messages.
/// @param customType        Custom type to filter messages. If filtering isn't required, set nil.
/// @param completionHandler The handler block to execute. The `messages` is the array of `SBDBaseMessage` instances.
- (void)getPreviousAndNextMessagesByMessageId:(long long)messageId
                                    prevLimit:(NSInteger)prevLimit
                                    nextLimit:(NSInteger)nextLimit
                                      reverse:(BOOL)reverse
                                  messageType:(SBDMessageTypeFilter)messageType
                                   customType:(NSString * _Nullable)customType
                            completionHandler:(nullable void (^)(NSArray<SBDBaseMessage *> * _Nullable messages, SBDError * _Nullable error))completionHandler;

/// Gets the previous and next message by the message ID with a limit and ordering.
/// @param messageId         The standard message ID to load messages.
/// @param prevLimit         The previous limit for the number of messages. The returned messages could be more than this number if there are messages which have the same timestamp.
/// @param nextLimit         The next limit for the number of messages. The returned messages could be more than this number if there are messages which have the same timestamp.
/// @param reverse           If yes, the latest message is the index 0.
/// @param messageType       Message type to filter messages.
/// @param customType        Custom type to filter messages. If filtering isn't required, set nil.
/// @param senderUserIds     Returns messages whose sender user id matches sender user ids.
/// @param completionHandler The handler block to execute. The `messages` is the array of `SBDBaseMessage` instances.
/// @since 3.0.106
- (void)getPreviousAndNextMessagesByMessageId:(long long)messageId
                                    prevLimit:(NSInteger)prevLimit
                                    nextLimit:(NSInteger)nextLimit
                                      reverse:(BOOL)reverse
                                  messageType:(SBDMessageTypeFilter)messageType
                                   customType:(NSString * _Nullable)customType
                                senderUserIds:(NSArray<NSString *> * _Nullable)senderUserIds
                            completionHandler:(nullable void (^)(NSArray<SBDBaseMessage *> * _Nullable messages, SBDError * _Nullable error))completionHandler;

/// Gets the previous and next message by the message ID with a limit and ordering.
/// @param messageId The standard message ID to load messages.
/// @param prevLimit The previous limit for the number of messages. The returned messages could be more than this number if there are messages which have the same timestamp.
/// @param nextLimit The next limit for the number of messages. The returned messages could be more than this number if there are messages which have the same timestamp.
/// @param reverse If YES, the latest message is the index 0.
/// @param messageType Message type to filter messages.
/// @param customType Custom type to filter messages. If filtering isn't required, set nil.
/// @param senderUserIds Returns messages whose sender user id matches sender user ids.
/// @param includeMetaArray If YES, the `messages` has meta array.
/// @param completionHandler The handler block to execute. The `messages` is the array of `SBDBaseMessage` instances.
/// @since 3.0.116
/// @deprecated 3.0.169 (Use `getMessagesByMessageId:params:completionHandler:` instead.)
- (void)getPreviousAndNextMessagesByMessageId:(long long)messageId
                                    prevLimit:(NSInteger)prevLimit
                                    nextLimit:(NSInteger)nextLimit
                                      reverse:(BOOL)reverse
                                  messageType:(SBDMessageTypeFilter)messageType
                                   customType:(NSString * _Nullable)customType
                                senderUserIds:(NSArray<NSString *> * _Nullable)senderUserIds
                             includeMetaArray:(BOOL)includeMetaArray
                            completionHandler:(nullable void (^)(NSArray<SBDBaseMessage *> * _Nullable messages, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;


/// Gets the previous and next message by the message ID with with filters of prev limit, next limit, reverse, message type, custom type, sender user ids, include meta array, and include reactions.
/// @param messageId The standard message ID to load messages.
/// @param prevLimit The previous limit for the number of messages. The returned messages could be more than this number if there are messages which have the same timestamp.
/// @param nextLimit The next limit for the number of messages. The returned messages could be more than this number if there are messages which have the same timestamp.
/// @param reverse If YES, the latest message is the index 0.
/// @param messageType Message type to filter messages.
/// @param customType Custom type to filter messages. If filtering isn't required, set nil.
/// @param senderUserIds Returns messages whose sender user id matches sender user ids.
/// @param includeMetaArray If YES, the `messages` has meta array.
/// @param includeReactions If YES, the `messages` has reactions.
/// @param completionHandler The handler block to execute. The `messages` is the array of `SBDBaseMessage` instances.
/// @since 3.0.169
- (void)getPreviousAndNextMessagesByMessageId:(long long)messageId
                                    prevLimit:(NSInteger)prevLimit
                                    nextLimit:(NSInteger)nextLimit
                                      reverse:(BOOL)reverse
                                  messageType:(SBDMessageTypeFilter)messageType
                                   customType:(NSString * _Nullable)customType
                                senderUserIds:(NSArray<NSString *> * _Nullable)senderUserIds
                             includeMetaArray:(BOOL)includeMetaArray
                             includeReactions:(BOOL)includeReactions
                            completionHandler:(nullable void (^)(NSArray<SBDBaseMessage *> * _Nullable messages, SBDError * _Nullable error))completionHandler;

/// Retrieves previous or next messages based on a specified timestamp in the channel.
/// @param timestamp Specifies the timestamp to be the reference point for messages to retrieve, in Unix milliseconds format. Messages sent before or after the timestamp can be retrieved.
/// @param params Contains a set of parameters you can set regarding the messages in the results.
/// @param completionHandler The handler block to be executed. The `messages` is the messages of the channel. The `error` indicates whether there is an error. If there is no error, the value is null.
/// @since 3.0.181
- (void)getMessagesByTimestamp:(long long)timestamp
                        params:(nonnull SBDMessageListParams *)params
             completionHandler:(nullable void (^)(NSArray<SBDBaseMessage *> * _Nullable messages, SBDError * _Nullable error))completionHandler;

/// Retrieves previous or next messages based on their message ID in a specific channel.
/// @param messageId Specifies the message ID to be the reference point for messages to retrieve. Messages sent before or after the message with the matching message ID can be retrieved.
/// @param params Contains a set of parameters you can set regarding the messages in the results.
/// @param completionHandler The handler block to be executed. The `messages` is the messages of the channel. The `error` indicates whether there is an error. If there is no error, the value is null.
/// @since 3.0.181
- (void)getMessagesByMessageId:(long long)messageId
                        params:(nonnull SBDMessageListParams *)params
             completionHandler:(nullable void (^)(NSArray<SBDBaseMessage *> * _Nullable messages, SBDError * _Nullable error))completionHandler;

/// Builds a base channel object from serialized <span>data</span>.
/// @param data Serialized <span>data</span>.
/// @return SBDBaseChannel object.
+ (nullable instancetype)buildFromSerializedData:(NSData * _Nonnull)data;

/// Serializes base channel object.
/// @return Serialized <span>data</span>.
- (nullable NSData *)serialize;

/// Cancels the file message uploading.
/// @param requestId The request ID of the file message that is been uploading.
/// @param completionHandler The handler block to execute. If the `result` is `YES`, then the uploading task of the `requestId` has been cancelled.
+ (void)cancelUploadingFileMessageWithRequestId:(NSString * _Nonnull)requestId
                              completionHandler:(nullable void (^)(BOOL result, SBDError * _Nullable error))completionHandler;

/// Copies a user message to the target channel.
/// @param message User message object.
/// @param targetChannel Target channel object.
/// @param completionHandler The handler block to execute. The `userMessage` is a user message which is returned from the Sendbird server. The message has a message ID.
/// @return Returns the temporary user message with a request ID. It doesn't have a message ID.
- (nonnull SBDUserMessage *)copyUserMessage:(SBDUserMessage * _Nonnull)message
                            toTargetChannel:(SBDBaseChannel * _Nonnull)targetChannel
                          completionHandler:(nullable void (^)(SBDUserMessage * _Nullable userMessage, SBDError * _Nullable error))completionHandler;

/// Copies a file message to the target channel.
/// @param message File message object.
/// @param targetChannel Target channel object.
/// @param completionHandler The handler block to execute. The `fileMessage` is a user message which is returned from the Sendbird server. The message has a message ID.
/// @return Returns the temporary file message with a request ID. It doesn't have a message ID.
- (nonnull SBDFileMessage *)copyFileMessage:(SBDFileMessage * _Nonnull)message
                            toTargetChannel:(SBDBaseChannel * _Nonnull)targetChannel
                          completionHandler:(nullable void (^)(SBDFileMessage * _Nullable fileMessage,  SBDError * _Nullable error))completionHandler;

#pragma mark - Message change logs
/// Gets the changelogs of the messages with token.
/// @param token The token that is used to get more changelogs.
/// @param completionHandler The handler block to execute. The `updatedMessages` is the messages that were updated. The `deletedMessageIds` is the list of the deleted message IDs. If there are more changelogs that are not returned yet, the `hasMore` is YES. The `token` can be used to get more changedlogs.
- (void)getMessageChangeLogsWithToken:(NSString * _Nullable)token
                    completionHandler:(nullable void (^)(NSArray<SBDBaseMessage *> * _Nullable updatedMessages,
                                                         NSArray<NSNumber *> * _Nullable deletedMessageIds,
                                                         BOOL hasMore,
                                                         NSString * _Nullable token,
                                                         SBDError * _Nullable error))completionHandler;

/// Gets the changelogs of the messages with token and meta array
/// @param token The token that is used to get more changelogs.
/// @param includeMetaArray If YES, the `updatedMessages` has meta array.
/// @param completionHandler The handler block to execute. The `updatedMessages` is the messages that were updated. The `deletedMessageIds` is the list of the deleted message IDs. If there are more changelogs that are not returned yet, the `hasMore` is YES. The `token` can be used to get more changedlogs.
/// @since 3.0.116
- (void)getMessageChangeLogsWithToken:(NSString * _Nullable)token
                     includeMetaArray:(BOOL)includeMetaArray
                    completionHandler:(nullable void (^)(NSArray<SBDBaseMessage *> * _Nullable updatedMessages,
                                                         NSArray<NSNumber *> * _Nullable deletedMessageIds,
                                                         BOOL hasMore,
                                                         NSString * _Nullable token,
                                                         SBDError * _Nullable error))completionHandler;


/// Gets the changelogs of the messages with token, meta array, and reactions.
/// @param token The token that is used to get more changelogs.
/// @param includeMetaArray If YES, the `updatedMessages` has meta array.
/// @param includeReactions If YES, the `updatedMessages` has reactions.
/// @param completionHandler The handler block to execute. The `updatedMessages` is the messages that were updated. The `deletedMessageIds` is the list of the deleted message IDs. If there are more changelogs that are not returned yet, the `hasMore` is YES. The `token` can be used to get more changedlogs.
/// @since 3.0.169
- (void)getMessageChangeLogsWithToken:(NSString * _Nullable)token
                     includeMetaArray:(BOOL)includeMetaArray
                     includeReactions:(BOOL)includeReactions
                    completionHandler:(nullable void (^)(NSArray<SBDBaseMessage *> * _Nullable updatedMessages,
                                                         NSArray<NSNumber *> * _Nullable deletedMessageIds,
                                                         BOOL hasMore,
                                                         NSString * _Nullable token,
                                                         SBDError * _Nullable error))completionHandler;

/// Requests updated messages and deleted message IDs by the timestamp in this channel.
/// @param timestamp  The number of milli-seconds(msec). Requests changelogs by that time. This value must not be negative.
/// @param completionHandler  The handler block to execute. The `updatedMessages` is the messages that were updated. The `deletedMessageIds` is the list of the deleted message IDs. If there are more changelogs, but doesn't returned, then the `hasMore` is YES. The `token` can be used to get next more changedlogs.
/// @since 3.0.122
- (void)getMessageChangeLogsByTimestamp:(long long)timestamp
                      completionHandler:(nonnull void (^)(NSArray<SBDBaseMessage *> * _Nullable updatedMessages,
                                                          NSArray<NSNumber *> * _Nullable deletedMessageIds,
                                                          BOOL hasMore,
                                                          NSString * _Nullable token,
                                                          SBDError * _Nullable error))completionHandler;

/// Requests updated messages contains metaarray and deleted message IDs by the timestamp in this channel.
/// @param timestamp  The number of milli-seconds(msec). Requests changelogs by that time. This value must not be negative.
/// @param includeMetaArray If YES, the `updatedMessages` has meta array.
/// @param completionHandler  The handler block to execute. The `updatedMessages` is the messages that were updated. The `deletedMessageIds` is the list of the deleted message IDs. If there are more changelogs, but doesn't returned, then the `hasMore` is YES. The `token` can be used to get next more changedlogs.
/// @since 3.0.122
- (void)getMessageChangeLogsByTimestamp:(long long)timestamp
                       includeMetaArray:(BOOL)includeMetaArray
                      completionHandler:(nonnull void (^)(NSArray<SBDBaseMessage *> * _Nullable updatedMessages,
                                                          NSArray<NSNumber *> * _Nullable deletedMessageIds,
                                                          BOOL hasMore,
                                                          NSString * _Nullable token,
                                                          SBDError * _Nullable error))completionHandler;


/// Requests updated messages contains metaarray and reactions, and deleted message IDs by the timestamp in this channel.
/// @param timestamp  The number of milli-seconds(msec). Requests changelogs by that time. This value must not be negative.
/// @param includeMetaArray If YES, the `updatedMessages` has meta array.
/// @param includeReactions If YES, the `updatedMessages` has reactions.
/// @param completionHandler  The handler block to execute. The `updatedMessages` is the messages that were updated. The `deletedMessageIds` is the list of the deleted message IDs. If there are more changelogs, but doesn't returned, then the `hasMore` is YES. The `token` can be used to get next more changedlogs.
/// @since 3.0.169
- (void)getMessageChangeLogsByTimestamp:(long long)timestamp
                       includeMetaArray:(BOOL)includeMetaArray
                       includeReactions:(BOOL)includeReactions
                      completionHandler:(nonnull void (^)(NSArray<SBDBaseMessage *> * _Nullable updatedMessages,
                                                          NSArray<NSNumber *> * _Nullable deletedMessageIds,
                                                          BOOL hasMore,
                                                          NSString * _Nullable token,
                                                          SBDError * _Nullable error))completionHandler;

/// Retrieves the changelogs since a specified token regarding the updated messages or the unique IDs of deleted messages in the channel.
/// @param token Specifies the token to be the reference point for the changelogs to retrieve.
/// @param params Contains a set of parameters you can set regarding the messages in the results.
/// @param completionHandler The handler block to execute. The `updatedMessages` retrieves the updated messages. The `deletedMessageIds` retrieves the unique ID of deleted messages. The `hasMore` indicates whether there are more changelogs to be retrieved. The `token` retrieves the token of the last changelog in the results. The `error` indicates whether there is an error. If there is no error, the value is `nil`.
/// @since 3.0.181
- (void)getMessageChangeLogsSinceToken:(nullable NSString *)token
                                params:(nonnull SBDMessageChangeLogsParams *)params
                     completionHandler:(nonnull void (^)(NSArray<SBDBaseMessage *> * _Nullable updatedMessages,
                                                         NSArray<NSNumber *> * _Nullable deletedMessageIds,
                                                         BOOL hasMore,
                                                         NSString * _Nullable token,
                                                         SBDError * _Nullable error))completionHandler;

/// Retrieves the changelogs since a specified timestamp, in Unix milliseconds format, regarding the updated messages or the unique IDs of deleted messages in the channel.
/// @param timestamp Specifies the timestamp to be the reference point for changelogs to retrieve, in Unix milliseconds format.
/// @param params Contains a set of parameters you can set regarding the messages in the results.
/// @param completionHandler The handler block to execute. The `updatedMessages` retrieves the updated messages. The `deletedMessageIds` retrieves the unique ID of deleted messages. The `hasMore` indicates whether there are more changelogs to be retrieved. The `token` retrieves the token of the last changelog in the results. The `error` indicates whether there is an error. If there is no error, the value is `nil`.
/// @since 3.0.181
- (void)getMessageChangeLogsSinceTimestamp:(long long)timestamp
                                    params:(nonnull SBDMessageChangeLogsParams *)params
                         completionHandler:(nonnull void (^)(NSArray<SBDBaseMessage *> * _Nullable updatedMessages,
                                                             NSArray<NSNumber *> * _Nullable deletedMessageIds,
                                                             BOOL hasMore,
                                                             NSString * _Nullable token,
                                                             SBDError * _Nullable error))completionHandler;

#pragma mark - Meta Arrays

/// Creates keys of meta array for the message.
/// @param message The message object. This method creates `keys` in it.
/// @param keys Keys of meta array.
/// @param completionHandler The handler block to execute. The `message` is a base message object that has the keys for its meta array.
/// @since 3.0.116
- (void)createMessageMetaArrayKeysWithMessage:(nonnull SBDBaseMessage *)message
                                         keys:(nonnull NSArray<NSString *> *)keys
                            completionHandler:(nullable void (^)(SBDBaseMessage * _Nullable message, SBDError * _Nullable error))completionHandler;

/// Deletes keys from meta array of the message.
/// @param message The message object. This method deletes keys of meta array of it.
/// @param keys Keys to be deleted.
/// @param completionHandler The handler block to execute.
/// @since 3.0.116
- (void)deleteMessageMetaArrayKeysWithMessage:(nonnull SBDBaseMessage *)message
                                         keys:(nonnull NSArray<NSString *> *)keys
                            completionHandler:(nullable void (^)(SBDBaseMessage * _Nullable message, SBDError * _Nullable error))completionHandler;

/// Adds meta array to the message.
/// @param message The message object. This method adds pairs of key and value to this message.
/// @param keyValues Pairs of key-value to be added.
/// @param completionHandler The handler block to execute.
/// @since 3.0.116
/// @see use `addMessageMetaArrayValuesWithMessage:metaArrays:completionHandler:` as possible.
- (void)addMessageMetaArrayValuesWithMessage:(nonnull SBDBaseMessage *)message
                                   keyValues:(nonnull NSDictionary<NSString *, NSArray<NSString *> *> *)keyValues
                           completionHandler:(nullable void (^)(SBDBaseMessage * _Nullable message, SBDError * _Nullable error))completionHandler;


/// Adds the array of meta array into the message.
/// @param message The message instance. The metaArrays will added into the message.
/// @param metaArrays An array of message meta array will be added into the message.
/// the string of the value in the metaArray MUST NOT exist with same key.
/// @param completionHandler The handler block to execute after adding message meta arrays.
/// The `message` of the handler is updated message.
/// If failed to add message meta arrays, the `error` of the handler is not nil(null).
/// @discussion The `metaArrays` are upserted into the message.
/// If a key in the metaArrays is new, the key will be inserted with the value.
/// If a key in the metaArrays is already created,
/// the value of the messageMetaArray will be inserted so strings in the value MUST be new one.
/// @since 3.0.148
/// @code
/// SBDGroupChannel *channel;
/// SBDUserMessageParams *params = [[SBDUserMessageParams alloc] initWithMessage:message];
/// params.metaArrayKeys = key_array;
/// [channel sendUserMessageWithParams:params completionHandler:^(SBDUserMessage * _Nullable message, SBDError * _Nullable error) {
///   // message has metaArrays
///
///   NSArray<SBDMessageMetaArray *> *metaArrays = adding_meta_arrays;
///   [channel addMessageMetaArrayValuesWithMessage:message metaArrays:metaArrays completionHandler:^(SBDBaseMessage * _Nullable message, SBDError * _Nullable error) {
///     // added metaArrays into the message.
///   }];
/// }];
/// @endcode
- (void)addMessageMetaArrayValuesWithMessage:(nonnull SBDBaseMessage *)message
                                  metaArrays:(nonnull NSArray<SBDMessageMetaArray *> *)metaArrays
                           completionHandler:(nullable SBDBaseMessageHandler)completionHandler;


/// Removes meta array from the message.
/// @param message The message object. This method removes pairs of key and value from this message.
/// @param keyValues Pairs of key-value to be removed.
/// @param completionHandler The handler block to execute.
/// @since 3.0.116
/// @see use `removeMessageMetaArrayValuesWithMessage:metaArrays:completionHandler:` as possible.
- (void)removeMessageMetaArrayValuesWithMessage:(nonnull SBDBaseMessage *)message
                                      keyValues:(nonnull NSDictionary<NSString *, NSArray<NSString *> *> *)keyValues
                              completionHandler:(nullable void (^)(SBDBaseMessage * _Nullable message, SBDError * _Nullable error))completionHandler;


/// Removes the array of meta array from the message.
/// @param message The message instance. The metaArrays will removed from the message.
/// @param metaArrays An array of message meta array will be removed from the message.
/// the string of the value in the metaArray MUST exist with same key.
/// @param completionHandler The handler block to execute after removing message meta arrays.
/// The `message` of the handler is removed message.
/// If failed to remove message meta arrays, the `error` of the handler is not nil(null).
/// @discussion The `metaArrays` are removed from the message.
/// If a key in the metaArrays has an emtpy array of the value, the key will be removed.
/// If not, the value of the messageMetaArray will be removed from the message.
/// The order of the meta array is guaranteed.
/// @since 3.0.148
/// @code
/// SBDGroupChannel *channel;
/// SBDUserMessageParams *params = [[SBDUserMessageParams alloc] initWithMessage:message];
/// params.metaArrayKeys = key_array;
/// [channel sendUserMessageWithParams:params completionHandler:^(SBDUserMessage * _Nullable message, SBDError * _Nullable error) {
///   // message has metaArrays
///   NSArray<SBDMessageMetaArray *> *metaArrays = removing_meta_arrays;
///   [channel removeMessageMetaArrayValuesWithMessage:message metaArrays:metaArrays completionHandler:^(SBDBaseMessage * _Nullable message, SBDError * _Nullable error) {
///     // removed metaArrays into the message.
///   }];
/// }];
/// @endcode
- (void)removeMessageMetaArrayValuesWithMessage:(nonnull SBDBaseMessage *)message
                                     metaArrays:(nonnull NSArray<SBDMessageMetaArray *> *)metaArrays
                              completionHandler:(nullable SBDBaseMessageHandler)completionHandler;

/// Gets the current user's muted information in this channel.
/// @param completionHandler The handler block to be executed.
/// @since 3.0.118
- (void)getMyMutedInfoWithCompletionHandler:(nullable void (^)(BOOL isMuted, NSString * _Nonnull description, long long startAt, long long endAt, long long remainingDuration, SBDError * _Nullable error))completionHandler;

# pragma mark - Report

/// Reports a user in a channel of inappropriate activities.
/// @param offendingUser The user who is being reported.
/// @param reportCategory The category in which the report is being submitted. Valid choices are 'suspicious', 'harassing', 'spam', and 'inappropriate'.
/// @param reportDescription An open ended description for why the report is being submitted.
/// @param completionHandler The handler block to execute.
/// @since 3.0.154
- (void)reportUser:(nonnull SBDUser *)offendingUser
    reportCategory:(SBDReportCategory)reportCategory
 reportDescription:(nullable NSString *)reportDescription
 completionHandler:(nullable SBDErrorHandler)completionHandler;


/// Reports current channel instance of inappropriate activities.
/// @param reportCategory The category in which the report is being submitted. Valid choices are 'suspicious', 'harassing', 'spam', and 'inappropriate'.
/// @param reportDescription An open ended description for why the report is being submitted.
/// @param completionHandler The handler block to execute.
/// @since 3.0.154
- (void)reportChannelWithCategory:(SBDReportCategory)reportCategory
                reportDescription:(nullable NSString *)reportDescription
                completionHandler:(nullable SBDErrorHandler)completionHandler;

/// Reports a malicious message in the channel
///
/// @param message The message object which is being reported.
/// @param reportCategory The category in which the report is being submitted. Valid choices are 'suspicious', 'harassing', 'spam', and 'inappropriate'.
/// @param reportDescription An open ended description for why the report is being submitted.
/// @param completionHandler The handler block to execute.
/// @since 3.0.154
- (void)reportMessage:(nonnull SBDBaseMessage *)message
       reportCategory:(SBDReportCategory)reportCategory
    reportDescription:(nullable NSString *)reportDescription
    completionHandler:(nullable SBDErrorHandler)completionHandler;

#pragma mark - Reactions
/// @brief Adds a reaction to a message.
/// @discussion This method adds a reaction to a existing message. If the [`requestState`](../Classes/SBDUserMessage.html#//api/name/requestState) of `SBDUserMessage` or the [`requestState`](../Classes/SBDFileMessage.html#//api/name/requestState) of `SBDFileMessage` is not [`SBDMessageRequestStateSucceeded`](../Constants/SBDMessageRequestState.html), the `error` in `completionHandler` will not `nil`.
/// @note This is idempotent.
/// @note This feature is only available in group channels.
/// @param message The message object that the reaction will be added.
/// @param key The reaction key to be added.
/// @param completionHandler The handler block to be executed. If succeeded, the `reactionEvent` will have the information of the reaction.
/// @since 3.0.169
- (void)addReactionWithMessage:(nonnull SBDBaseMessage *)message
                           key:(nonnull NSString *)key
             completionHandler:(nullable void (^)(SBDReactionEvent * _Nullable reactionEvent, SBDError * _Nullable error))completionHandler;

/// @brief Deletes a reaction from a message.
/// @discussion This method deletes a reaction from a existing message. If the [`requestState`](../Classes/SBDUserMessage.html#//api/name/requestState) of `SBDUserMessage` or the [`requestState`](../Classes/SBDFileMessage.html#//api/name/requestState) of `SBDFileMessage` is not [`SBDMessageRequestStateSucceeded`](../Constants/SBDMessageRequestState.html), the `error` in `completionHandler` will not `nil`.
/// @note This is idempotent.
/// @note This feature is only available in group channels.
/// @param message The message object that has the reaction key.
/// @param key The reaction key to be deleted.
/// @param completionHandler The handler block to be executed. If succeeded, the `reactionEvent` will have the information of the reaction.
/// @since 3.0.169
- (void)deleteReactionWithMessage:(nonnull SBDBaseMessage *)message
                              key:(nonnull NSString *)key
                completionHandler:(nullable void (^)(SBDReactionEvent * _Nullable reactionEvent, SBDError * _Nullable error))completionHandler;

#pragma mark - Operator
/// Adds operators to the channel.
/// @param userIds The user IDs to be operators.
/// @param completionHandler The handler block to be executed.
/// @since 3.0.189
- (void)addOperatorsWithUserIds:(nonnull NSArray<NSString *> *)userIds
              completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/// Removes operators from the channel.
/// @param userIds The user IDs to be removed from the operators.
/// @param completionHandler The handler block to be executed.
/// @since 3.0.189
- (void)removeOperatorsWithUserIds:(nonnull NSArray<NSString *> *)userIds
                 completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/// Removes all operators from the channel.
/// @param completionHandler The handler block to be executed.
/// @since 3.0.189
- (void)removeAllOperatorsWithCompletionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

@end
