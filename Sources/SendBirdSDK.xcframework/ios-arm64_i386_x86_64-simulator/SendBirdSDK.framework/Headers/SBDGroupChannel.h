//
//  SBDGroupChannel.h
//  SendBirdSDK
//
//  Created by Jed Gyeong on 5/23/16.
//  Copyright © 2016 SENDBIRD.COM. All rights reserved.
//

#import "SBDBaseChannel.h"
#import "SBDGroupChannelListQuery.h"
#import "SBDBaseMessage.h"
#import "SBDUser.h"
#import "SBDMember.h"
#import "SBDTypes.h"
#import "SBDBannedUserListQuery.h"
#import "SBDConstants.h"
#import "SBDMappable.h"

@class SBDUser, SBDMember;
@class SBDGroupChannel, SBDGroupChannelParams, SBDGroupChannelTotalUnreadMessageCountParams;
@class SBDGroupChannelListQuery, SBDGroupChannelMemberListQuery, SBDPublicGroupChannelListQuery, SBDUserListQuery;
@class SBDUnreadItemCount;

/**
 *  The `SBDGroupChannel` class represents a group channel which is a private chat. The user who wants to join the group channel has to be invited by another user who is already joined the channel. This class is derived from `SBDBaseChannel`. If the `SBDChannelDelegate` is added, the user will automatically receive all messages from the group channels where the user belongs after connection. The `SBDGroupChannel` provides the features of general messaging apps.
 *
 *  * Typing indicator.
 *  * Read status for each message.
 *  * Unread message count in the channel.
 *  * Lastest message in the channel.
 *
 *  The `SBDGroupChannel` has a special property, `isDistinct`. The distinct property enabled group channel is always reuesd for same channel <span>members</span>. If a new member gets invited or the member left from the channel, then the distinct property disabled automatically. If you don't set distinct property on the channel, it always create new channel for the same <span>members</span>.
 *
 *  For more information, see [Group Channel](https://docs.sendbird.com/ios#group_channel).
 *
 */
@interface SBDGroupChannel : SBDBaseChannel <SBDMappable>

/**
 *  Last message of the channel.
 */
@property (strong, nonatomic, nullable) SBDBaseMessage *lastMessage;

/**
 *  Represents the channel is super channel or not.
 *  NO by default.
 */
@property (nonatomic, setter=setSuper:) BOOL isSuper;

/**
 *  Represents the channel is broadcast channel or not.
 *  NO by default.
 *
 *  @since 3.0.171
 */
@property (nonatomic) BOOL isBroadcast;

/**
 *  Represents the channel is public channel or private one.
 *  NO by default.
 */
@property (nonatomic, setter=setPublic:) BOOL isPublic;

/**
 *  Represents that the channel has access code to enter.
 *
 *  @since 3.0.116
 */
@property (atomic, readonly, getter=isAccessCodeRequired) BOOL accessCodeRequired;

/**
 *  Represents the channel is distinct or not.
 */
@property (atomic) BOOL isDistinct;

/**
 *  Represents a boolean whether the public group channel is discoverable.
 *  It is only for a public group channel.
 *  The default value is YES(true) if the channel is a public group channel.
 *  If the channel is not a public group channel, the default value is NO(false).
 *
 *  @since 3.0.136
 */
@property (nonatomic, readonly, getter=isDiscoverable) BOOL discoverable;

/**
 *  Unread message count of the channel.
 */
@property (nonatomic) NSUInteger unreadMessageCount;

/**
 *  The number of mentions that user does not read yet in the channel.
 *
 *  @since 3.0.103
 */
@property (nonatomic, readonly) NSUInteger unreadMentionCount;

/**
 *  Channel <span>members</span>.
 *  Note: Number of member for SuperGroupChannel is limited to 10
 */
@property (strong, nonatomic, readonly, nullable) NSMutableArray<SBDMember *> *members;

/**
 *  The number of <span>members</span>.
 */
@property (atomic, readonly) NSUInteger memberCount;

/**
 *  The number of joined <span>members</span>.
 */
@property (atomic, readonly) NSUInteger joinedMemberCount;

/// Timestamp when current user joined
/// @since 3.0.224
@property (atomic, assign, readonly) long long joinedAt;

/**
 *  The flag for sending mark as read.
 *
 *  @deprecated 3.0.42.
 */
@property (atomic) BOOL sendMarkAsReadEnable DEPRECATED_ATTRIBUTE;

/**
 *  Represents push notification is on or off. If true, push notification is on.
 *
 *  @deprecated 3.0.128. (Use `myPushTriggerOption` instead.)
 */
@property (atomic, readonly) BOOL isPushEnabled DEPRECATED_ATTRIBUTE;

/**
 *  Represents which push notification for the current user to receive in a group channel.
 *
 *  @since 3.0.128
 */
@property (atomic, readonly) SBDGroupChannelPushTriggerOption myPushTriggerOption;

/**
 *  Represents this channel is hidden or not.
 */
@property (atomic) BOOL isHidden;

/**
 Current member's state in the channel.
 */
@property (atomic) SBDMemberState myMemberState;

/**
 *  The role of current user in the channel.
 */
@property (atomic, readonly) SBDRole myRole;

/**
 The muted state of the current user in the channel.
 */
@property (atomic, readonly) SBDMutedState myMutedState;

/**
 *  The preference lets to know counts in the channel. The default value is `SBDCountPreferenceAll`.
 *
 *  @since 3.0.102
 */
@property (atomic, readonly) SBDCountPreference myCountPreference;

/**
 *  The time stamp when the current user got a invitation from other user in the channel.
 *
 *  @since 3.0.107
 */
@property (atomic, readonly) long long invitedAt;

/**
 The hidden state of the channel.
 
 @since 3.0.122
 */
@property (atomic, readonly) SBDGroupChannelHiddenState hiddenState;

/**
 A last read information for the current user.
 
 @since 3.0.138
 */
@property (nonatomic, readonly) long long myLastRead;

/**
 Message offset of a channel. User can only see messages after this offset.
 
 @since 3.0.157
 */
@property (atomic, readonly) long long messageOffsetTimestamp;

/// A value that sets the message survival time in seconds. In the channel that is created or updated with this option, the read messages are automatically deleted after a determined amount of time. The default value is `-1` that represents the disappearing message is disabled.
/// @discussion This feature is available in a 1-on-1 group channel.
/// @since 3.0.172
@property (atomic, readonly) NSInteger messageSurvivalSeconds;

/**
 *  DO NOT USE this initializer. You can only get an instance type of `SBDGroupChannel` from SDK.
 */
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wnullability"
- (nullable instancetype)init NS_UNAVAILABLE;
#pragma clang diagnostic pop

/**
 *  Refreshes this channel instance.
 *
 *  @param completionHandler The handler block to execute.
 */
- (void)refreshWithCompletionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/**
 *  Creates a query for my group channel list.
 *
 *  @return SBDGroupChannelListQuery instance for the current user.
 */
+ (nullable SBDGroupChannelListQuery *)createMyGroupChannelListQuery;

/**
 *  Creates a query for public group channel list.
 *
 *  @return SBDPublicGroupChannelListQuery  The instance to query public group channels.
 */
+ (nullable SBDPublicGroupChannelListQuery *)createPublicGroupChannelListQuery;

/**
 *  Creates a query for members in group channel list.
 *
 *  @return SBDGroupChannelMemberListQuery  The instance of the members in group channel.
 */
- (nullable SBDGroupChannelMemberListQuery *)createMemberListQuery;

/**
 *  Creates a query instance for banned user list of the channel.
 *
 *  @return SBDUserListQuery The instance for the banned user list. Query only banned user list.
 *  @since 3.0.89
 */
- (nullable SBDBannedUserListQuery *)createBannedUserListQuery;

/**
 *  Creates a group channel with user objects.
 *
 *  @param users             The users to be <span>members</span> of the channel.
 *  @param isDistinct        If YES, the channel which has the same users is returned.
 *  @param completionHandler The handler block to execute. `channel` is the group channel instance which has the `users` as <span>members</span>.
 */
+ (void)createChannelWithUsers:(NSArray<SBDUser *> * _Nonnull)users
                    isDistinct:(BOOL)isDistinct
             completionHandler:(nonnull void (^)(SBDGroupChannel * _Nullable channel, SBDError * _Nullable error))completionHandler;

/**
 *  Creates a group channel with user IDs.
 *
 *  @param userIds           The user IDs to be <span>members</span> of the channel.
 *  @param isDistinct        If YES, the channel which has the same users is returned.
 *  @param completionHandler The handler block to execute. `channel` is the group channel instance which has the `users` as <span>members</span>.
 */
+ (void)createChannelWithUserIds:(NSArray<NSString *> * _Nonnull)userIds
                      isDistinct:(BOOL)isDistinct
               completionHandler:(nonnull void (^)(SBDGroupChannel * _Nullable channel, SBDError * _Nullable error))completionHandler;

/**
 *  Creates a group channel with user objects.
 *
 *  @param name              The name of group channel.
 *  @param users             The users to be <span>members</span> of the channel.
 *  @param coverUrl          The cover image url of group channel.
 *  @param data              The custom data of group channel.
 *  @param completionHandler The handler block to execute.
 *
 *  @deprecated 3.0.116. (Use `createChannelWithParams:progressHandler:completionHandler:` instead.)
 */
+ (void)createChannelWithName:(NSString * _Nullable)name
                        users:(NSArray<SBDUser *> * _Nonnull)users
                     coverUrl:(NSString * _Nullable)coverUrl
                         data:(NSString * _Nullable)data
            completionHandler:(nonnull void (^)(SBDGroupChannel * _Nullable channel, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/**
 *  Creates a group channel with user objects.
 *
 *  @param name              The name of group channel.
 *  @param users             The users to be <span>members</span> of the channel.
 *  @param coverImage        The cover image data of group channel.
 *  @param coverImageName    The cover image file name of group channel.
 *  @param data              The custom data of group channel.
 *  @param progressHandler   The handler block to monitor progression. `bytesSent` is the number of bytes sent since the last time this method was called. `totalBytesSent` is the total number of bytes sent so far. `totalBytesExpectedToSend` is the expected length of the body <span>data</span>. These parameters are the same to the declaration of [`URLSession:task:didSendBodyData:totalBytesSent:totalBytesExpectedToSend:`](https://developer.apple.com/reference/foundation/nsurlsessiontaskdelegate/1408299-urlsession?language=objc).
 *  @param completionHandler The handler block to execute.
 *
 *  @deprecated 3.0.116. (Use `createChannelWithParams:progressHandler:completionHandler:` instead.)
 */
+ (void)createChannelWithName:(NSString * _Nullable)name
                        users:(NSArray<SBDUser *> * _Nonnull)users
                   coverImage:(NSData * _Nonnull)coverImage
               coverImageName:(NSString * _Nonnull)coverImageName
                         data:(NSString * _Nullable)data
              progressHandler:(nullable void (^)(int64_t bytesSent, int64_t totalBytesSent, int64_t totalBytesExpectedToSend))progressHandler
            completionHandler:(nonnull void (^)(SBDGroupChannel * _Nullable channel, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/**
 *  Create a group channel with user IDs. The group channel is distinct.
 *
 *  @param name              The name of group channel.
 *  @param userIds           The user IDs to be <span>members</span> of the channel.
 *  @param coverUrl          The cover image url of group channel.
 *  @param data              The custom data of group channel.
 *  @param completionHandler The handler block to execute. `channel` is the group channel instance which has the `userIds` as <span>members</span>.
 *
 *  @deprecated 3.0.116. (Use `createChannelWithParams:progressHandler:completionHandler:` instead.)
 */
+ (void)createChannelWithName:(NSString * _Nullable)name
                      userIds:(NSArray<NSString *> * _Nonnull)userIds
                     coverUrl:(NSString * _Nullable)coverUrl
                         data:(NSString * _Nullable)data
            completionHandler:(nonnull void (^)(SBDGroupChannel * _Nullable channel, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/**
 *  Create a group channel with user IDs. The group channel is distinct.
 *
 *  @param name              The name of group channel.
 *  @param userIds           The user IDs to be <span>members</span> of the channel.
 *  @param coverImage        The cover image data of group channel.
 *  @param coverImageName    The cover image file name of group channel.
 *  @param data              The custom data of group channel.
 *  @param progressHandler   The handler block to monitor progression. `bytesSent` is the number of bytes sent since the last time this method was called. `totalBytesSent` is the total number of bytes sent so far. `totalBytesExpectedToSend` is the expected length of the body <span>data</span>. These parameters are the same to the declaration of [`URLSession:task:didSendBodyData:totalBytesSent:totalBytesExpectedToSend:`](https://developer.apple.com/reference/foundation/nsurlsessiontaskdelegate/1408299-urlsession?language=objc).
 *  @param completionHandler The handler block to execute. `channel` is the group channel instance which has the `userIds` as <span>members</span>.
 *
 *  @deprecated 3.0.116. (Use `createChannelWithParams:progressHandler:completionHandler:` instead.)
 */
+ (void)createChannelWithName:(NSString * _Nullable)name
                      userIds:(NSArray<NSString *> * _Nonnull)userIds
                   coverImage:(NSData * _Nonnull)coverImage
               coverImageName:(NSString * _Nonnull)coverImageName
                         data:(NSString * _Nullable)data
              progressHandler:(nullable void (^)(int64_t bytesSent, int64_t totalBytesSent, int64_t totalBytesExpectedToSend))progressHandler
            completionHandler:(nonnull void (^)(SBDGroupChannel * _Nullable channel, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/**
 *  Creates a group channel with user objects. The group channel is distinct.
 *
 *  @param name              The name of group channel.
 *  @param isDistinct        If YES, the channel which has the same users is returned.
 *  @param users             The users to be <span>members</span> of the channel.
 *  @param coverUrl          The cover image url of group channel.
 *  @param data              The custom data of group channel.
 *  @param completionHandler The handler block to execute. `channel` is the group channel instance which has the `users` as <span>members</span>.
 *
 *  @deprecated 3.0.116 (Use `createChannelWithParams:progressHandler:completionHandler:` instead.)
 */
+ (void)createChannelWithName:(NSString * _Nullable)name
                   isDistinct:(BOOL)isDistinct
                        users:(NSArray<SBDUser *> * _Nonnull)users
                     coverUrl:(NSString * _Nullable)coverUrl
                         data:(NSString * _Nullable)data
            completionHandler:(nonnull void (^)(SBDGroupChannel * _Nullable channel, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/**
 *  Creates a group channel with user objects. The group channel is distinct.
 *
 *  @param name              The name of group channel.
 *  @param isDistinct        If YES, the channel which has the same users is returned.
 *  @param users             The users to be <span>members</span> of the channel.
 *  @param coverImage        The cover image data of group channel.
 *  @param coverImageName    The cover image file name of group channel.
 *  @param data              The custom data of group channel.
 *  @param progressHandler   The handler block to monitor progression. `bytesSent` is the number of bytes sent since the last time this method was called. `totalBytesSent` is the total number of bytes sent so far. `totalBytesExpectedToSend` is the expected length of the body <span>data</span>. These parameters are the same to the declaration of [`URLSession:task:didSendBodyData:totalBytesSent:totalBytesExpectedToSend:`](https://developer.apple.com/reference/foundation/nsurlsessiontaskdelegate/1408299-urlsession?language=objc).
 *  @param completionHandler The handler block to execute. `channel` is the group channel instance which has the `users` as <span>members</span>.
 *
 *  @deprecated 3.0.116. (Use `createChannelWithParams:progressHandler:completionHandler:` instead.)
 */
+ (void)createChannelWithName:(NSString * _Nullable)name
                   isDistinct:(BOOL)isDistinct
                        users:(NSArray<SBDUser *> * _Nonnull)users
                   coverImage:(NSData * _Nonnull)coverImage
               coverImageName:(NSString * _Nonnull)coverImageName
                         data:(NSString * _Nullable)data
              progressHandler:(nullable void (^)(int64_t bytesSent, int64_t totalBytesSent, int64_t totalBytesExpectedToSend))progressHandler
            completionHandler:(nonnull void (^)(SBDGroupChannel * _Nullable channel, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/**
 *  Creates a group channel with user IDs.
 *
 *  @param name              The name of group channel.
 *  @param isDistinct        If YES, the channel which has the same users is returned.
 *  @param userIds           The user IDs to participate the channel.
 *  @param coverUrl          The cover image url of group channel.
 *  @param data              The custom data of group channel.
 *  @param completionHandler The handler block to execute. `channel` is the group channel instance which has the `userIds` as <span>members</span>.
 *
 *  @deprecated 3.0.116. (Use `createChannelWithParams:progressHandler:completionHandler:` instead.)
 */
+ (void)createChannelWithName:(NSString * _Nullable)name
                   isDistinct:(BOOL)isDistinct
                      userIds:(NSArray<NSString *> * _Nonnull)userIds
                     coverUrl:(NSString * _Nullable)coverUrl
                         data:(NSString * _Nullable)data
            completionHandler:(nonnull void (^)(SBDGroupChannel * _Nullable channel, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/**
 *  Creates a group channel with user IDs.
 *
 *  @param name              The name of group channel.
 *  @param isDistinct        If YES, the channel which has the same users is returned.
 *  @param userIds           The user IDs to participate the channel.
 *  @param coverUrl          The cover image url of group channel.
 *  @param data              The custom data of group channel.
 *  @param customType        The custom type of group channel.
 *  @param completionHandler The handler block to execute. `channel` is the group channel instance which has the `userIds` as <span>members</span>.
 *
 *  @deprecated 3.0.116. (Use `createChannelWithParams:progressHandler:completionHandler:` instead.)
 */
+ (void)createChannelWithName:(NSString * _Nullable)name
                   isDistinct:(BOOL)isDistinct
                      userIds:(NSArray<NSString *> * _Nonnull)userIds
                     coverUrl:(NSString * _Nullable)coverUrl
                         data:(NSString * _Nullable)data
                   customType:(NSString * _Nullable)customType
            completionHandler:(nonnull void (^)(SBDGroupChannel * _Nullable channel, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/**
 *  Updates a group channel with user IDs.
 *
 *  @param name              The name of group channel.
 *  @param isDistinct        If YES, the channel which has the same users is returned.
 *  @param coverUrl          The cover image url of group channel.
 *  @param data              The custom data of group channel.
 *  @param completionHandler The handler block to execute. `channel` is the group channel instance which has the `userIds` as <span>members</span>.
 *
 *  @deprecated 3.0.116. (Use `updateChannelWithParams:progressHandler:completionHandler:` instead.)
 */
- (void)updateChannelWithName:(NSString * _Nullable)name
                   isDistinct:(BOOL)isDistinct
                     coverUrl:(NSString * _Nullable)coverUrl
                         data:(NSString * _Nullable)data
            completionHandler:(nonnull void (^)(SBDGroupChannel * _Nullable channel, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/**
 *  Updates a group channel with user IDs.
 *
 *  @param name              The name of group channel.
 *  @param isDistinct        If YES, the channel which has the same users is returned.
 *  @param coverUrl          The cover image url of group channel.
 *  @param data              The custom data of group channel.
 *  @param customType        The custom type of group channel.
 *  @param completionHandler The handler block to execute. `channel` is the group channel instance which has the `userIds` as <span>members</span>.
 *
 *  @deprecated 3.0.116. (Use `updateChannelWithParams:progressHandler:completionHandler:` instead.)
 */
- (void)updateChannelWithName:(NSString * _Nullable)name
                   isDistinct:(BOOL)isDistinct
                     coverUrl:(NSString * _Nullable)coverUrl
                         data:(NSString * _Nullable)data
                   customType:(NSString * _Nullable)customType
            completionHandler:(nonnull void (^)(SBDGroupChannel * _Nullable channel, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/**
 *  Updates a group channel with user IDs.
 *
 *  @param name              The name of group channel.
 *  @param coverUrl          The cover image url of group channel.
 *  @param data              The custom data of group channel.
 *  @param completionHandler The handler block to execute. `channel` is the group channel instance which has the `userIds` as <span>members</span>.
 *
 *  @deprecated 3.0.116. (Use `updateChannelWithParams:progressHandler:completionHandler:` instead.)
 */
- (void)updateChannelWithName:(NSString * _Nullable)name
                     coverUrl:(NSString * _Nullable)coverUrl
                         data:(NSString * _Nullable)data
            completionHandler:(nonnull void (^)(SBDGroupChannel * _Nullable channel, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/**
 *  Creates a group channel with user IDs.
 *
 *  @param name              The name of group channel.
 *  @param isDistinct        If YES, the channel which has the same users is returned.
 *  @param userIds           The user IDs to participate the channel.
 *  @param coverImage        The cover image data of group channel.
 *  @param coverImageName    The cover image file name of group channel.
 *  @param data              The custom data of group channel.
 *  @param progressHandler   The handler block to monitor progression. `bytesSent` is the number of bytes sent since the last time this method was called. `totalBytesSent` is the total number of bytes sent so far. `totalBytesExpectedToSend` is the expected length of the body <span>data</span>. These parameters are the same to the declaration of [`URLSession:task:didSendBodyData:totalBytesSent:totalBytesExpectedToSend:`](https://developer.apple.com/reference/foundation/nsurlsessiontaskdelegate/1408299-urlsession?language=objc).
 *  @param completionHandler The handler block to execute. `channel` is the group channel instance which has the `userIds` as <span>members</span>.
 *
 *  @deprecated 3.0.116. (Use `createChannelWithParams:progressHandler:completionHandler:` instead.)
 */
+ (void)createChannelWithName:(NSString * _Nullable)name
                   isDistinct:(BOOL)isDistinct
                      userIds:(NSArray<NSString *> * _Nonnull)userIds
                   coverImage:(NSData * _Nonnull)coverImage
               coverImageName:(NSString * _Nonnull)coverImageName
                         data:(NSString * _Nullable)data
              progressHandler:(nullable void (^)(int64_t bytesSent, int64_t totalBytesSent, int64_t totalBytesExpectedToSend))progressHandler
            completionHandler:(nonnull void (^)(SBDGroupChannel * _Nullable channel, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/**
 *  Creates a group channel with user IDs.
 *
 *  @param name              The name of group channel.
 *  @param isDistinct        If YES, the channel which has the same users is returned.
 *  @param userIds           The user IDs to participate the channel.
 *  @param coverImage        The cover image data of group channel.
 *  @param coverImageName    The cover image file name of group channel.
 *  @param data              The custom data of group channel.
 *  @param customType        The custom type of group channel.
 *  @param progressHandler   The handler block to monitor progression. `bytesSent` is the number of bytes sent since the last time this method was called. `totalBytesSent` is the total number of bytes sent so far. `totalBytesExpectedToSend` is the expected length of the body <span>data</span>. These parameters are the same to the declaration of [`URLSession:task:didSendBodyData:totalBytesSent:totalBytesExpectedToSend:`](https://developer.apple.com/reference/foundation/nsurlsessiontaskdelegate/1408299-urlsession?language=objc).
 *  @param completionHandler The handler block to execute. `channel` is the group channel instance which has the `userIds` as <span>members</span>.
 */
+ (void)createChannelWithName:(NSString * _Nullable)name
                   isDistinct:(BOOL)isDistinct
                      userIds:(NSArray<NSString *> * _Nonnull)userIds
                   coverImage:(NSData * _Nonnull)coverImage
               coverImageName:(NSString * _Nonnull)coverImageName
                         data:(NSString * _Nullable)data
                   customType:(NSString * _Nullable)customType
              progressHandler:(nullable void (^)(int64_t bytesSent, int64_t totalBytesSent, int64_t totalBytesExpectedToSend))progressHandler
            completionHandler:(nonnull void (^)(SBDGroupChannel * _Nullable channel, SBDError * _Nullable error))completionHandler;

/**
 *  Creates a group channel with user IDs.
 *
 *  @param name              The name of group channel.
 *  @param isDistinct        If YES, the channel which has the same users is returned.
 *  @param userIds           The user IDs to participate the channel.
 *  @param coverImageFilePath        The cover image file path of group channel.
 *  @param data              The custom data of group channel.
 *  @param customType        The custom type of group channel.
 *  @param progressHandler   The handler block to monitor progression. `bytesSent` is the number of bytes sent since the last time this method was called. `totalBytesSent` is the total number of bytes sent so far. `totalBytesExpectedToSend` is the expected length of the body <span>data</span>. These parameters are the same to the declaration of [`URLSession:task:didSendBodyData:totalBytesSent:totalBytesExpectedToSend:`](https://developer.apple.com/reference/foundation/nsurlsessiontaskdelegate/1408299-urlsession?language=objc).
 *  @param completionHandler The handler block to execute. `channel` is the group channel instance which has the `userIds` as <span>members</span>.
 *
 *  @deprecated 3.0.116. (Use `createChannelWithParams:progressHandler:completionHandler:` instead.)
 */
+ (void)createChannelWithName:(NSString * _Nullable)name
                   isDistinct:(BOOL)isDistinct
                      userIds:(NSArray<NSString *> * _Nonnull)userIds
           coverImageFilePath:(NSString * _Nonnull)coverImageFilePath
                         data:(NSString * _Nullable)data
                   customType:(NSString * _Nullable)customType
              progressHandler:(nullable void (^)(int64_t bytesSent, int64_t totalBytesSent, int64_t totalBytesExpectedToSend))progressHandler
            completionHandler:(nonnull void (^)(SBDGroupChannel * _Nullable channel, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/**
 *  Creates a group channel with `SBDGroupChannelParams` class.
 *
 *  @param params               The parameter instance of SBDGroupChannelParams what has properties to create group channel.
 *  @param completionHandler    The handler block to execute. `channel` is the group channel instance which has the `userIds` as <span>members</span>.
 */
+ (void)createChannelWithParams:(nonnull SBDGroupChannelParams *)params
              completionHandler:(nonnull void(^)(SBDGroupChannel * _Nullable channel, SBDError * _Nullable error))completionHandler;

/**
 *  Creates a group channel with `SBDGroupChannelParams` class.
 *
 *  @param params               The parameter instance of SBDGroupChannelParams what has properties to create group channel.
 *  @param progressHandler   The handler block to monitor progression. `bytesSent` is the number of bytes sent since the last time this method was called. `totalBytesSent` is the total number of bytes sent so far. `totalBytesExpectedToSend` is the expected length of the body <span>data</span>. These parameters are the same to the declaration of [`URLSession:task:didSendBodyData:totalBytesSent:totalBytesExpectedToSend:`](https://developer.apple.com/reference/foundation/nsurlsessiontaskdelegate/1408299-urlsession?language=objc).
 *  @param completionHandler    The handler block to execute. `channel` is the group channel instance which has the `userIds` as <span>members</span>.
 *  @since 3.0.215
 */
+ (void)createChannelWithParams:(nonnull SBDGroupChannelParams *)params
                progressHandler:(nullable void (^)(int64_t bytesSent, int64_t totalBytesSent, int64_t totalBytesExpectedToSend))progressHandler
              completionHandler:(nonnull void(^)(SBDGroupChannel * _Nullable channel, SBDError * _Nullable error))completionHandler;

/**
 Creates a group channel with `SBDGroupChannelParams` class. The `completionHandler` returns `isCreated`, which notifies the `channel` instance is created now.

 @param params The parameter instance of SBDGroupChannelParams what has properties to create group channel. The channel that is created by this method is always a distinct channel regardless of the `isDistinct` value of the `params`.
 @param completionHandler The handler block to be executed. If the `channel` instance is new, then `isCreated` is YES.
 @since 3.0.122
 */
+ (void)createDistinctChannelIfNotExistWithParams:(nonnull SBDGroupChannelParams *)params
                                completionHandler:(nonnull void(^)(SBDGroupChannel * _Nullable channel, BOOL isCreated, SBDError * _Nullable error))completionHandler;

/**
 Creates a group channel with `SBDGroupChannelParams` class. The `completionHandler` returns `isCreated`, which notifies the `channel` instance is created now.

 @param params The parameter instance of SBDGroupChannelParams what has properties to create group channel. The channel that is created by this method is always a distinct channel regardless of the `isDistinct` value of the `params`.
 @param progressHandler   The handler block to monitor progression. `bytesSent` is the number of bytes sent since the last time this method was called. `totalBytesSent` is the total number of bytes sent so far. `totalBytesExpectedToSend` is the expected length of the body <span>data</span>. These parameters are the same to the declaration of [`URLSession:task:didSendBodyData:totalBytesSent:totalBytesExpectedToSend:`](https://developer.apple.com/reference/foundation/nsurlsessiontaskdelegate/1408299-urlsession?language=objc).
 @param completionHandler The handler block to be executed. If the `channel` instance is new, then `isCreated` is YES.
 @since 3.0.215
 */
+ (void)createDistinctChannelIfNotExistWithParams:(nonnull SBDGroupChannelParams *)params
                                  progressHandler:(nullable void (^)(int64_t bytesSent, int64_t totalBytesSent, int64_t totalBytesExpectedToSend))progressHandler
                                completionHandler:(nonnull void(^)(SBDGroupChannel * _Nullable channel, BOOL isCreated, SBDError * _Nullable error))completionHandler;

/**
 *  Updates a group channel with user IDs.
 *
 *  @param name              The name of group channel.
 *  @param isDistinct        If YES, the channel which has the same users is returned.
 *  @param coverImage        The cover image data of group channel.
 *  @param coverImageName    The cover image file name of group channel.
 *  @param data              The custom data of group channel.
 *  @param progressHandler   The handler block to monitor progression. `bytesSent` is the number of bytes sent since the last time this method was called. `totalBytesSent` is the total number of bytes sent so far. `totalBytesExpectedToSend` is the expected length of the body <span>data</span>. These parameters are the same to the declaration of [`URLSession:task:didSendBodyData:totalBytesSent:totalBytesExpectedToSend:`](https://developer.apple.com/reference/foundation/nsurlsessiontaskdelegate/1408299-urlsession?language=objc).
 *  @param completionHandler The handler block to execute. `channel` is the group channel instance which has the `userIds` as <span>members</span>.
 *
 *  @deprecated 3.0.116. (Use `updateChannelWithParams:progressHandler:completionHandler:` instead.)
 */
- (void)updateChannelWithName:(NSString * _Nullable)name
                   isDistinct:(BOOL)isDistinct
                   coverImage:(NSData * _Nullable)coverImage
               coverImageName:(NSString * _Nullable)coverImageName
                         data:(NSString * _Nullable)data
              progressHandler:(nullable void (^)(int64_t bytesSent, int64_t totalBytesSent, int64_t totalBytesExpectedToSend))progressHandler
            completionHandler:(nonnull void (^)(SBDGroupChannel * _Nullable channel, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/**
 *  Updates a group channel with user IDs.
 *
 *  @param name              The name of group channel.
 *  @param isDistinct        If YES, the channel which has the same users is returned.
 *  @param coverImage        The cover image data of group channel.
 *  @param coverImageName    The cover image file name of group channel.
 *  @param data              The custom data of group channel.
 *  @param customType        The custom type of group channel.
 *  @param progressHandler   The handler block to monitor progression. `bytesSent` is the number of bytes sent since the last time this method was called. `totalBytesSent` is the total number of bytes sent so far. `totalBytesExpectedToSend` is the expected length of the body <span>data</span>. These parameters are the same to the declaration of [`URLSession:task:didSendBodyData:totalBytesSent:totalBytesExpectedToSend:`](https://developer.apple.com/reference/foundation/nsurlsessiontaskdelegate/1408299-urlsession?language=objc).
 *  @param completionHandler The handler block to execute. `channel` is the group channel instance which has the `userIds` as <span>members</span>.
 */
- (void)updateChannelWithName:(NSString * _Nullable)name
                   isDistinct:(BOOL)isDistinct
                   coverImage:(NSData * _Nullable)coverImage
               coverImageName:(NSString * _Nullable)coverImageName
                         data:(NSString * _Nullable)data
                   customType:(NSString * _Nullable)customType
              progressHandler:(nullable void (^)(int64_t bytesSent, int64_t totalBytesSent, int64_t totalBytesExpectedToSend))progressHandler
            completionHandler:(nonnull void (^)(SBDGroupChannel * _Nullable channel, SBDError * _Nullable error))completionHandler;

/**
 *  Updates a group channel with user IDs.
 *
 *  @param name              The name of group channel.
 *  @param isDistinct        If YES, the channel which has the same users is returned.
 *  @param coverImageFilePath        The cover image file path of group channel.
 *  @param data              The custom data of group channel.
 *  @param customType        The custom type of group channel.
 *  @param progressHandler   The handler block to monitor progression. `bytesSent` is the number of bytes sent since the last time this method was called. `totalBytesSent` is the total number of bytes sent so far. `totalBytesExpectedToSend` is the expected length of the body <span>data</span>. These parameters are the same to the declaration of [`URLSession:task:didSendBodyData:totalBytesSent:totalBytesExpectedToSend:`](https://developer.apple.com/reference/foundation/nsurlsessiontaskdelegate/1408299-urlsession?language=objc).
 *  @param completionHandler The handler block to execute. `channel` is the group channel instance which has the `userIds` as <span>members</span>.
 *
 *  @deprecated 3.0.116. (Use `updateChannelWithParams:progressHandler:completionHandler:` instead.)
 */
- (void)updateChannelWithName:(NSString * _Nullable)name
                   isDistinct:(BOOL)isDistinct
           coverImageFilePath:(NSString * _Nullable)coverImageFilePath
                         data:(NSString * _Nullable)data
                   customType:(NSString * _Nullable)customType
              progressHandler:(nullable void (^)(int64_t bytesSent, int64_t totalBytesSent, int64_t totalBytesExpectedToSend))progressHandler
            completionHandler:(nonnull void (^)(SBDGroupChannel * _Nullable channel, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/**
 *  Updates a group channel with user IDs.
 *
 *  @param name              The name of group channel.
 *  @param coverImage        The cover image data of group channel.
 *  @param coverImageName    The cover image file name of group channel.
 *  @param data              The custom data of group channel.
 *  @param progressHandler   The handler block to monitor progression. `bytesSent` is the number of bytes sent since the last time this method was called. `totalBytesSent` is the total number of bytes sent so far. `totalBytesExpectedToSend` is the expected length of the body <span>data</span>. These parameters are the same to the declaration of [`URLSession:task:didSendBodyData:totalBytesSent:totalBytesExpectedToSend:`](https://developer.apple.com/reference/foundation/nsurlsessiontaskdelegate/1408299-urlsession?language=objc).
 *  @param completionHandler The handler block to execute. `channel` is the group channel instance which has the `userIds` as <span>members</span>.
 *
 *  @deprecated 3.0.116. (Use `updateChannelWithParams:progressHandler:completionHandler:` instead.)
 */
- (void)updateChannelWithName:(NSString * _Nullable)name
                   coverImage:(NSData * _Nullable)coverImage
               coverImageName:(NSString * _Nullable)coverImageName
                         data:(NSString * _Nullable)data
              progressHandler:(nullable void (^)(int64_t bytesSent, int64_t totalBytesSent, int64_t totalBytesExpectedToSend))progressHandler
            completionHandler:(nonnull void (^)(SBDGroupChannel * _Nullable channel, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/**
 *  Update a group channel with `SBDGroupChannelParams` class.
 *
 *  @param params               The parameter instance of SBDGroupChannelParams what has properties to update group channel.
 *  @param completionHandler    The handler block to execute. `channel` is the group channel instance which has the `userIds` as <span>members</span>.
 */
- (void)updateChannelWithParams:(nonnull SBDGroupChannelParams *)params
              completionHandler:(nonnull void (^)(SBDGroupChannel * _Nullable channel, SBDError * _Nullable error))completionHandler;

/**
 *  Update a group channel with `SBDGroupChannelParams` class.
 *
 *  @param params               The parameter instance of SBDGroupChannelParams what has properties to update group channel.
 *  @param progressHandler   The handler block to monitor progression. `bytesSent` is the number of bytes sent since the last time this method was called. `totalBytesSent` is the total number of bytes sent so far. `totalBytesExpectedToSend` is the expected length of the body <span>data</span>. These parameters are the same to the declaration of [`URLSession:task:didSendBodyData:totalBytesSent:totalBytesExpectedToSend:`](https://developer.apple.com/reference/foundation/nsurlsessiontaskdelegate/1408299-urlsession?language=objc).
 *  @param completionHandler    The handler block to execute. `channel` is the group channel instance which has the `userIds` as <span>members</span>.
 *  @since 3.0.215
 */
- (void)updateChannelWithParams:(nonnull SBDGroupChannelParams *)params
                progressHandler:(nullable void (^)(int64_t bytesSent, int64_t totalBytesSent, int64_t totalBytesExpectedToSend))progressHandler
              completionHandler:(nonnull void (^)(SBDGroupChannel * _Nullable channel, SBDError * _Nullable error))completionHandler;

/**
 *  Gets a group channel instance with channel URL from server asynchronously.
 *
 *  @param channelUrl        The channel URL.
 *  @param completionHandler The handler block to execute. `channel` is the group channel instance which has the `channelUrl`.
 *
 *  @deprecated 3.0.116. DO NOT USE THIS METHOD.
 */
+ (void)getChannelWithoutCache:(NSString * _Nonnull)channelUrl
             completionHandler:(nullable void (^)(SBDGroupChannel * _Nullable channel, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/**
 *  Gets a group channel instance from channel URL asynchronously.
 *
 *  @param channelUrl        The channel URL.
 *  @param completionHandler The handler block to execute. `channel` is the group channel instance which has the `channelUrl`.
 */
+ (void)getChannelWithUrl:(NSString * _Nonnull)channelUrl
        completionHandler:(nullable void (^)(SBDGroupChannel * _Nullable channel, SBDError * _Nullable error))completionHandler;

/**
 *  Invites a single user to the group channel.
 *
 *  @param user              The user to be invited.
 *  @param completionHandler The handler block to execute.
 */
- (void)inviteUser:(SBDUser * _Nonnull)user
 completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/**
 *  Invites a single user to the group channel.
 *
 *  @param userId            The user ID to be invited.
 *  @param completionHandler The handler block to execute.
 */
- (void)inviteUserId:(NSString * _Nonnull)userId
   completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/**
 *  Invites multiple users to the group channel.
 *
 *  @param users             The user array to be invited.
 *  @param completionHandler The handler block to execute.
 */
- (void)inviteUsers:(NSArray<SBDUser *> * _Nonnull)users
  completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/**
 *  Invites multiple users to the group channel.
 *
 *  @param userIds           The IDs of users array to be invited.
 *  @param completionHandler The handler block to execute.
 */
- (void)inviteUserIds:(NSArray<NSString *> * _Nonnull)userIds
    completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/**
 *  Hides the group channel. The channel will be hid from the channel list, but it will be appeared again when the other user send a message in the channel.
 *
 *  @param completionHandler The handler block to execute.
 *
 *  @deprecated 3.0.63. (Use `hideChannelWithHidePreviousMessages:completionHandler:` instead.)
 */
- (void)hideChannelWithCompletionHandler:(nullable void (^)(SBDError *_Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/**
 *  Hides the group channel. The channel will be hid from the channel list, but it will be appeared again when the other user send a message in the channel.
 *
 *  @param hidePreviousMessages The option to hide the previous message of this channel when the channel will be appeared again.
 *  @param completionHandler The handler block to execute.
 */
- (void)hideChannelWithHidePreviousMessages:(BOOL)hidePreviousMessages
                          completionHandler:(nullable void (^)(SBDError *_Nullable error))completionHandler;

/**
 Hides the group channel with the auto unhide option. The channel will be hid from the channel list. If the `allowAutoUnhide` is YES, the channel will be appeared again when the other user send a message in the channel. However, if the `allowAutoUnhide` is NO, the channel will be appeared by `unhideChannelWithCompletionHandler:` method.

 @param hidePreviousMessages The option to hide the previous message of this channel when the channel will be appeared again.
 @param allowAutoUnhide The auto unhide option.
 @param completionHandler THe handle block to be executed.
 @since 3.0.122
 */
- (void)hideChannelWithHidePreviousMessages:(BOOL)hidePreviousMessages
                            allowAutoUnhide:(BOOL)allowAutoUnhide
                          completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/**
 Unhides the group channel.

 @param completionHandler THe handle block to be executed.
 @since 3.0.122
 */
- (void)unhideChannelWithCompletionHandler:(nullable void (^)(SBDError *_Nullable error))completionHandler;

/**
 *  Leaves the group channel. The channel will be disappeared from the channel list. If join the channel, the invitation is required.
 *
 *  @param completionHandler The handler block to execute.
 */
- (void)leaveChannelWithCompletionHandler:(nullable void (^)(SBDError *_Nullable error))completionHandler;

/**
 Deletes the group channel. The user has to be an operator of the channel.

 @param completionHandler The handler block to execute.
 @since 3.0.137
 */
- (void)deleteChannelWithCompletionHandler:(nullable void (^)(SBDError *_Nullable error))completionHandler;

/**
 *  Marks as read all group channels of the current user.
 *
 *  @param completionHandler The handler block to execute.
 *  @deprecated 3.0.94. (Use `markAsReadAllWithCompletionHandler:` in `SBDMain` class instead.)
 */
+ (void)markAsReadAllWithCompletionHandler:(nullable void (^)(SBDError *_Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/// Sends mark as read. The other <span>members</span> in the channel will receive an event. The event will be received in `channelDidUpdateReadReceipt:` of `SBDChannelDelegate`.
/// @deprecated 3.0.234. Use `markAsReadWithCompletionHandler:` instead.
- (void)markAsRead
DEPRECATED_ATTRIBUTE;

/// Sends mark as read. The other <span>members</span> in the channel will receive an event. The event will be received in `channelDidUpdateReadReceipt:` of `SBDChannelDelegate`.
/// @param completionHandler The handler block to execute.
/// @since 3.0.234
- (void)markAsReadWithCompletionHandler:(nullable void (^)(SBDError *_Nullable error))completionHandler;

/// Sends mark as delivered. The other <span>members</span> in the channel will receive an event. The event will be received in `channelDidUpdateDeliveryReceipt:` of `SBDChannelDelegate`.
/// @since 3.0.162
/// @deprecated 3.0.185.
/// @note The client doesn't have to call this method any longer.
- (void)markAsDelivered
DEPRECATED_ATTRIBUTE;

/**
 *  Starts typing. The other <span>members</span> in the channel will receive an event. The event will be received in `channelDidUpdateTypingStatus:` of `SBDChannelDelegate`.
 */
- (void)startTyping;

/**
 *  Ends typing. The other <span>members</span> in the channel will receive an event. The event will be received in `channelDidUpdateTypingStatus:` of `SBDChannelDelegate`.
 */
- (void)endTyping;

/**
 *  Internal use only.
 *
 *  @param channelUrl channelUrl
 *  @see +getChannelWithUrl:completionHandler:
 *  @warning *Important*: DON'T use this method. This method will be unavailable.
 *  @deprecated 3.0.116. DO NOT USE THIS METHOD.
 */
+ (SBDGroupChannel * _Nullable)getChannelFromCacheWithChannelUrl:(NSString * _Nonnull)channelUrl
DEPRECATED_ATTRIBUTE;

/// Returns how many <span>members</span> haven't been read the given message yet.
/// @param message The message.
/// @return Number of unread member count. Zero if all <span>members</span> read the message.
/// @deprecated 3.0.185. Use `getUnreadMemberCount:` instead.
- (int)getReadReceiptOfMessage:(SBDBaseMessage * _Nonnull)message
DEPRECATED_ATTRIBUTE;

/// Returns how many <span>members</span> haven't been read the given message yet.
/// @param message The message.
/// @return Number of unread member count. Zero if all <span>members</span> read the message.
/// @since 3.0.185
- (int)getUnreadMemberCount:(nonnull SBDBaseMessage *)message;

/**
 *  Returns the timestamp of the last seen at the channel by user.
 *
 *  @param user The user
 *
 *  @return the timestamp of the last seen at.
 *
 *  @deprecated 3.0.86. (Use `getReadMembersWithMessage:includeAllMembers:` instead.)
 */
- (long long)getLastSeenAtByUser:(SBDUser * _Nonnull)user
DEPRECATED_ATTRIBUTE;

/**
 *  Returns the timestamp of the last seen at the channel by user Id.
 *
 *  @param userId The user Id.
 *
 *  @return the timestamp of the last seen at.
 *
 *  @deprecated 3.0.86. (Use `getReadMembersWithMessage:includeAllMembers:` instead.)
 */
- (long long)getLastSeenAtByUserId:(NSString * _Nonnull)userId
DEPRECATED_ATTRIBUTE;

/**
 *  Returns the <span>members</span> who read the message.
 *
 *  @param message The message.
 *
 *  @return Members who read the message.
 *
 *  @deprecated 3.0.115. (Use `getReadMembersWithMessage:includeAllMembers:` instead.)
 */
- (nullable NSArray<SBDMember *> *)getReadMembersWithMessage:(SBDBaseMessage * _Nonnull)message
DEPRECATED_ATTRIBUTE;

/**
 Returns the <span>members</span> who read the message.

 @param message The message.
 @param includeAllMembers If YES, the return value includes the current user and the sender of the message.
 @return Members who read the message.
 @since 3.0.115
 */
- (nonnull NSArray<SBDMember *> *)getReadMembersWithMessage:(SBDBaseMessage * _Nonnull)message
                                          includeAllMembers:(BOOL)includeAllMembers;

/**
 *  Returns the <span>members</span> who didn't read the message.
 *
 *  @param message The message.
 *
 *  @return Members who don't read the message.
 *
 *  @deprecated 3.0.115. (Use `getUnreadMembersWithMessage:includeAllMembers:` instead.)
 */
- (nullable NSArray<SBDMember *> *)getUnreadMembersWithMessage:(SBDBaseMessage * _Nonnull)message
DEPRECATED_ATTRIBUTE;

/**
 Returns the <span>members</span> who didn't read the message.

 @param message The message.
 @param includeAllMembers If YES, the return value includes the current user and the sender of the message.
 @return Members who don't read the message.
 @since 3.0.115
 */
- (nonnull NSArray<SBDMember *> *)getUnreadMembersWithMessage:(SBDBaseMessage * _Nonnull)message
                                            includeAllMembers:(BOOL)includeAllMembers;

/**
 *  Returns the read status.
 *
 *  @return The read status. If there's no data, it will be nil.
 *
 *  @deprecated 3.0.115. (Use `getReadStatusIncludingAllMembers:` instead.)
 *
 *  ***The returned dictionary's structure***
 *
 *  <pre>
 *  {
 *  &nbsp;&nbsp;USER_ID: 
 *  &nbsp;&nbsp;&nbsp;&nbsp;{
 *  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"user": <span>SBDUser</span> object,
 *  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"last_seen_at": <span>NSNumber</span> object,
 *  &nbsp;&nbsp;&nbsp;&nbsp;},
 *  &nbsp;&nbsp;...
 *  }
 *  </pre>
 *
 *  `USER_ID` is the user ID as a key. Each `USER_ID` has a `NSDictionary` which includes `SBDUser` object and `NSNUmber` object. The "user" is a key of `SBDUser` object and the "last_seen_at" is a key of `NSNumber` object. The `NSNumber` object has a 64-bit integer value for the timestamp in millisecond.
 */
- (nullable NSDictionary<NSString *, NSDictionary<NSString *, NSObject *> *> *)getReadStatus
DEPRECATED_ATTRIBUTE;

/**
 Returns the read status.

 @param includeAllMembers If YES, the return value includes the current user and the sender of the message.
 @return The read status. If there's no data, it will be an empty dictionary.
 @since 3.0.115
 
 ***The returned dictionary's structure***
 
 <pre>
 {
 &nbsp;&nbsp;USER_ID:
 &nbsp;&nbsp;&nbsp;&nbsp;{
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"user": <span>SBDUser</span> object,
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"last_seen_at": <span>NSNumber</span> object,
 &nbsp;&nbsp;&nbsp;&nbsp;},
 &nbsp;&nbsp;...
 }
 </pre>
 
 `USER_ID` is the user ID as a key. Each `USER_ID` has a `NSDictionary` which includes `SBDUser` object and `NSNUmber` object. The "user" is a key of `SBDUser` object and the "last_seen_at" is a key of `NSNumber` object. The `NSNumber` object has a 64-bit integer value for the timestamp in millisecond.
 */
- (nonnull NSDictionary<NSString *, NSDictionary<NSString *, NSObject *> *> *)getReadStatusIncludingAllMembers:(BOOL)includeAllMembers;

/// Returns how many <span>members</span> haven't been delivery the given message yet.
/// @param message The message.
/// @return Number of undelivered member count. Zero if all <span>members</span> delivered the message.
/// @since 3.0.162
/// @deprecated 3.0.185. (Use `getUndeliveredMemberCount:` instead.)
- (int)getDeliveryReceipt:(SBDBaseMessage * _Nonnull)message
DEPRECATED_ATTRIBUTE;

/// Returns how many <span>members</span> haven't been delivery the given message yet.
/// @param message The message.
/// @return Number of undelivered member count. Zero if all <span>members</span> delivered the message.
/// @since 3.0.185
- (int)getUndeliveredMemberCount:(nonnull SBDBaseMessage *)message;

/**
 *  If other users are typing in the channel, YES is returned.
 *
 *  @return Returns YES when other users are typing in this channel.
 */
- (BOOL)isTyping;

/**
 *  Returns the <span>members</span> who are typing now.
 *
 *  @return The <span>members</span> who are typing now.
 *  @deprecated 3.0.202. (Use `getTypingUsers` instead.)
 */
- (nullable NSArray<SBDMember *> *)getTypingMembers
DEPRECATED_ATTRIBUTE;

/**
 *  Returns the users who are typing now.
 *
 *  @return The users who are typing now.
 *  @since 3.0.202
 */
- (nullable NSArray<SBDUser *> *)getTypingUsers;

/**
 *  Sets push notification on or off on the channel.
 *
 *  @param pushOn            Sets push on/off.
 *  @param completionHandler The handler block to execute.
 *  @deprecated 3.0.207. (Use `setMyPushTriggerOption:completionHandler:` instead.)
 */
- (void)setPushPreferenceWithPushOn:(BOOL)pushOn
                  completionHandler:(nullable void (^)(SBDError *_Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/**
 *  Gets push notification on off on the channel.
 *
 *  @param completionHandler The handler block of execute. The `pushOn` means that the push notification of the channel is on or off.
 *
 *  @deprecated 3.0.21. (Use `myPushTriggerOption` property instead.)
 */
- (void)getPushPreferenceWithCompletionHandler:(nullable void (^)(BOOL pushOn, SBDError *_Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/**
 *  Changes a setting that decides which push notification for the current user to receive in the group channel.
 *  If a value of option is `SBDGroupChannelPushTriggerOptionDefault`, a push trigger option in this group channel follows a push trigger option of the current user.
 *  It is related with `[SBDMain setPushTriggerOption:completionHandler:]`.
 *
 *  @param pushTriggerOption  The options to choose which push notification for the current user to receive.
 *  @param completionHandler  The handler block to execute when setting a push trigger option of the current user is completed.
 *
 *  @since 3.0.128
 */
- (void)setMyPushTriggerOption:(SBDGroupChannelPushTriggerOption)pushTriggerOption
             completionHandler:(nullable SBDErrorHandler)completionHandler;

/**
 *  Requests a setting that decides which push notification for the current user to receive in the group channel.
 *
 *  @param completionHandler  The handler block to execute when getting a push trigger option of the current user is completed.
 *
 *  @since 3.0.128
 */
- (void)getMyPushTriggerOptionWithCompletionHandler:(nonnull SBDGroupChannelPushTriggerOptionHandler)completionHandler;

/**
 *  Gets the total unread message count of all group channels.
 *
 *  @param completionHandler The handler block to execute. The `unreadCount` is the total count of unread messages in all of group channel which the current is a member.
 *
 *  @deprecated 3.0.116. (Use `getTotalUnreadMessageCountWithCompletionHandler:` in `SBDMain` class instead.)
 */
+ (void)getTotalUnreadMessageCountWithCompletionHandler:(nullable void (^)(NSUInteger unreadCount, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/**
 *  Gets the total unread channel count of all group channels.
 *
 *  @param completionHandler The handler block to execute. The `unreadCount` is the total count of unread channels in all of group channel which the current is a member.
 *
 *  @deprecated 3.0.116. (Use `getTotalUnreadChannelCountWithCompletionHandler:` in `SBDMain` class instead.)
 */
+ (void)getTotalUnreadChannelCountWithCompletionHandler:(nullable void (^)(NSUInteger unreadCount, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/**
 *  Gets the total unread message count of the channels that have the specific custom types.
 *
 *  @param customTypes The array of the custom types. If the array is nil or the length of the array is zero, the total unread message count will be the same result of the `getTotalUnreadMessageCountWithCompletionHandler:`.
 *  @param completionHandler The handler block to execute. The `unreadCount` is the total unread message count of the channels that have the specific custom types. If there isn't any error, the `error` will be nil.
 *  @deprecated 3.0.116. Use `getTotalUnreadMessageCountWithParams:completionHandler:` in `SBDMain` class instead.)
 */
+ (void)getTotalUnreadMessageCountWithChannelCustomTypes:(NSArray<NSString *> * _Nullable)customTypes
                                       completionHandler:(nullable void (^)(NSUInteger unreadCount, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/**
 *  Gets the total unread message count of the channels with filters of params.
 *
 *  @param params             The instance of parameters to filter.
 *  @param completionHandler  The handler block to be executed after getting total unread message count. This block has no return value and takes two argument, the one is the number of unread message and the other is error.
 *
 *  @since 3.0.97
 *  @deprecated 3.0.116. (Use `getTotalUnreadMessageCountWithParams:completionHandler:` in `SBDMain` class instead.)
 */
+ (void)getTotalUnreadMessageCountWithParams:(nonnull SBDGroupChannelTotalUnreadMessageCountParams *)params
                           completionHandler:(nonnull void (^)(NSUInteger unreadCount, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/**
 Builds a group channel object from serialized <span>data</span>.
 
 @param data Serialized <span>data</span>.
 @return SBDGroupChannel object.
 */
//+ (nullable instancetype)buildFromSerializedData:(NSData * _Nonnull)data;

/**
 Serializes group channel object.
 
 @return Serialized <span>data</span>.
 */
- (nullable NSData *)serialize;

/**
 *  Checks if there is a channel object in cache.
 *
 *  @param channelUrl Channel URL to check.
 *  @return If YES, cache has the channel.
 *
 *  @deprecated 3.0.116. DO NOT USE THIS METHOD.
 */
+ (BOOL)hasChannelInCache:(NSString * _Nonnull)channelUrl
DEPRECATED_ATTRIBUTE;


/**
 Checks if the channel has a member that has `userId`.

 @param userId User ID.
 @return If YES, the channel has the member.
 */
- (BOOL)hasMember:(NSString * _Nonnull)userId;


/**
 Gets member in the channel.

 @param userId User ID.
 @return `SBDUser` object as a member. If there is a member who has the `userId`, returns nil.
 */
- (nullable SBDMember *)getMember:(NSString * _Nonnull)userId;


/**
 Accpets the invitation.

 @param completionHandler The handler block to execute.
 */
- (void)acceptInvitationWithCompletionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/**
 *  Accpets the invitation from a public group channel that has access code.
 *
 *  @param accessCode   The string code is used to accept invitation from a public group channel.
 *  @param completionHandler    The handler block to be executed after accepting. This block has no return value and takes an argument that is an error made when there is something wrong to accept.
 *  @since 3.0.116
 */
- (void)acceptInvitationWithAccessCode:(nullable NSString *)accessCode completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/**
 Declines the invitation.

 @param completionHandler The handler block to execute.
 */
- (void)declineInvitationWithCompletionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;


/**
 Gets the inviter.

 @return Inviter.
 */
- (nullable SBDUser *)getInviter;

/**
 Resets the history in this channel.

 @param completionHandler The handler block to execute.
 */
- (void)resetMyHistoryWithCompletionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/**
 *  Gets the group channel count.
 *
 *  @param memberStateFilter The member state of the current user in the channels that are counted.
 *  @param completionHandler The handler block to execute.
 *
 *  @deprecated 3.0.116. (Use `getChannelCountWithMemberStateFilter:completionHandler:` in `SBDMain` class instead.)
 */
+ (void)getChannelCountWithMemberStateFilter:(SBDMemberStateFilter)memberStateFilter
                           completionHandler:(nullable void (^)(NSUInteger groupChannelCount, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/**
 *  Join a group channel
 *
 *  @param completionHandler    The handler block to execute.
 */
- (void)joinWithCompletionHandler:(nullable void(^)(SBDError * _Nullable error))completionHandler;

/**
 *  Join a public group channel that has access code.
 *
 *  @param accessCode   The string code is used to join a public group channel.
 *  @param completionHandler    The handler block to be executed after joining. This block has no return value and takes an argument that is an error made when there is something wrong to join.
 *  @since 3.0.116
 */
- (void)joinWithAccessCode:(nullable NSString *)accessCode completionHandler:(nullable void(^)(SBDError * _Nullable error))completionHandler;

#pragma mark - moderation

/**
 *  Bans a user for seconds. Let a user out and prevent to join again. If the user is already banned, duration will be updated from the time that was initialized.
 *
 *  @param userId               The user id to be banned.
 *  @param seconds              Seconds of ducation to be banned. Seconds should be larger than -1. If it is -1, user is banned forever. If it is 0, duration is set 10years by default.
 *  @param description          The reason why the user was banned.
 *  @param completionHandler    The handler block to be executed after the user is banned. This block has no return value and takes an argument that is an error made when there is something wrong to ban.
 *  @since 3.0.89
 */
- (void)banUserWithUserId:(nonnull NSString *)userId
                  seconds:(NSInteger)seconds
              description:(nullable NSString *)description
        completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/**
 *  Bans a user for seconds. Let a user out and prevent to join again. If the user is already banned, duration will be updated from the time that was initialized.
 *
 *  @param user                 The user to be banned.
 *  @param seconds              Seconds of ducation to be banned. Seconds should be larger than -1. If it is -1, user is banned forever. If it is 0, duration is set 10years by default.
 *  @param description          The reason why the user was banned.
 *  @param completionHandler    The handler block to be executed after the user is banned. This block has no return value and takes an argument that is an error made when there is something wrong to ban.
 *  @since 3.0.89
 */
- (void)banUser:(nonnull SBDUser *)user
        seconds:(NSInteger)seconds
    description:(nullable NSString *)description completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/**
 *  Remove ban for a user.
 *
 *  @param userId            The user id to be removed ban.
 *  @param completionHandler The handler block to be executed after remove ban. This block has no return value and takes an argument that is an error made when there is something wrong to remove ban.
 *  @since 3.0.89
 */
- (void)unbanUserWithUserId:(nonnull NSString *)userId
          completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/**
 *  Remove ban for a user.
 *
 *  @param user              The user to be removed ban.
 *  @param completionHandler The handler block to be executed after remove ban. This block has no return value and takes an argument that is an error made when there is something wrong to remove ban.
 *  @since 3.0.89
 */
- (void)unbanUser:(nonnull SBDUser *)user completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/**
 *  Mute the user. Muted user cannot send any messages to the group channel.
 *
 *  @param userId            The user id to be muted.
 *  @param completionHandler The handler block to be executed after mute. This block has no return value and takes an argument that is an error made when there is something wrong to mute the user.
 *  @since 3.0.89
 */
- (void)muteUserWithUserId:(nonnull NSString *)userId
         completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/**
 *  Mute the user. Muted user cannot send any messages to the group channel.
 *
 *  @param user              The user to be muted.
 *  @param completionHandler The handler block to be executed after mute. This block has no return value and takes an argument that is an error made when there is something wrong to mute the user.
 *  @since 3.0.89
 */
- (void)muteUser:(nonnull SBDUser *)user completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/**
 Mute the user with additional options. Muted user cannot send any messages to the group channel.

 @param user The user to be muted
 @param seconds The user cannot send any messages for this time.
 @param description The description that explains the reason why the user is muted.
 @param completionHandler The handler block to be executed after mute. This block has no return value and takes an argument that is an error made when there is something wrong to mute the user.
 @since 3.0.118
 */
- (void)muteUser:(nonnull SBDUser *)user
          seconds:(NSInteger)seconds
      description:(nullable NSString *)description
completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/**
 Mute the user with additional options. Muted user cannot send any messages to the group channel.
 
 @param userId The user ID to be muted
 @param seconds The user cannot send any messages for this time.
 @param description The description that explains the reason why the user is muted.
 @param completionHandler The handler block to be executed after mute. This block has no return value and takes an argument that is an error made when there is something wrong to mute the user.
 @since 3.0.118
 */
- (void)muteUserWithUserId:(nonnull NSString *)userId
                   seconds:(NSInteger)seconds
               description:(nullable NSString *)description
         completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/**
 *  Turn off mute the user.
 *
 *  @param userId            The user Id to be turned off mute.
 *  @param completionHandler The handler block to be executed after turn off mute. This block has no return value and takes an argument that is an error made when there is something wrong to turn off mute.
 *  @since 3.0.89
 */
- (void)unmuteUserWithUserId:(nonnull NSString *)userId
           completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/**
 *  Turn off mute the user.
 *
 *  @param user              The user to be turned off mute.
 *  @param completionHandler The handler block to be executed after turn off mute. This block has no return value and takes an argument that is an error made when there is something wrong to turn off mute.
 *  @since 3.0.89
 */
- (void)unmuteUser:(nonnull SBDUser *)user completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/**
 *  Freeze the channel. If channel is frozen, only operators can send messages to the channel.
 *
 *  @param completionHandler The handler block to be executed after freeze. This block has no return value and takes an argument that is an error made when there is something wrong to freeze.
 *  @since 3.0.89
 */
- (void)freezeWithCompletionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/**
 *  Stop to freeze the channel. If It is not frozen channel, this will be ignored.
 *
 *  @param completionHandler The handler block to be executed after stop to freeze. This block has no return value and takes an argument that is an error made when there is something wrong to stop to freeze.
 *  @since 3.0.89
 */
- (void)unfreezeWithCompletionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/**
 *  Get unread counts of message and invitation counts in super and non_super channels.
 *
 *  @param key  bitmask key composed of super/non_super unread message count, super/non_super invitation count.
 *  @param completionHandler  The handler block to be executed after getting unread item count. This block has no return value and takes two argument. the one is type of SBDUnreadItemCount that contains unsinged interger for count you requested. the other is an error made when there is something wrong to response.
 *
 *  @since 3.0.101
 *  @deprecated 3.0.103. (Use `getUnreadItemCountWithKey:completionHandler:` instead.)
 */
- (void)getUnreadItemCountWithKey:(SBDUnreadItemKey)key
                completionHandler:(nonnull void(^)(SBDUnreadItemCount * _Nullable count, SBDError * _Nullable error))completionHandler DEPRECATED_ATTRIBUTE;

/**
 *  Get unread counts of message and invitation counts in super and non_super channels.
 *
 *  @param key  bitmask key composed of super/non_super unread message count, super/non_super invitation count.
 *  @param completionHandler  The handler block to be executed after getting unread item count. This block has no return value and takes two argument. the one is type of SBDUnreadItemCount that contains unsinged interger for count you requested. the other is an error made when there is something wrong to response.
 *
 *  @since 3.0.103
 *  @deprecated 3.0.116. (Use `getUnreadItemCountWithKey:completionHandler:` in `SBDMain` class instead.)
 */
+ (void)getUnreadItemCountWithKey:(SBDUnreadItemKey)key
                completionHandler:(nonnull void(^)(SBDUnreadItemCount * _Nullable count, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/**
 *  Sets count preference of current user.
 *
 *  @param myCountPreference  Preference is type of `SBDCountPreference`. The default value is `SBDCountPreferenceAll`.
 *
 *  @since 3.0.102
 */
- (void)setMyCountPreference:(SBDCountPreference)myCountPreference
           completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/**
 Registers a scheduled user message. The message will be sent at the specified time in `params`.
 
 @param params The instance of `SBDScheduledUserMessageParams` that can has parameters related with a text message. It has also the specified time to send a user message.
 @param completionHandler The handler block to be executed.
 @since 3.0.119
 */
- (void)registerScheduledUserMessageWithParams:(nonnull SBDScheduledUserMessageParams *)params
                             completionHandler:(nullable void (^)(SBDScheduledUserMessage * _Nullable scheduledUserMessage, SBDError * _Nullable error))completionHandler;

/// Notifies the current user took a screenshot in this channel. The server is going to send an admin message to notify this in the group channel.
/// @param completionHandler The handler block to be executed.
/// @since 3.0.172
- (void)notifyScreenshotWasTakenWithCompletionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/// Compares two channel objects with the channel list order.
/// @param channelA First channel object.
/// @param channelB Second channel obejct.
/// @param order Order.
/// @since 3.0.227
+ (NSComparisonResult)compareWithChannelA:(nonnull SBDGroupChannel *)channelA
                                 channelB:(nonnull SBDGroupChannel *)channelB
                                    order:(SBDGroupChannelListOrder)order;

@end
