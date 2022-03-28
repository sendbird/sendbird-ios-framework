//
//  SBDOpenChannel.h
//  SendBirdSDK
//
//  Created by Jed Gyeong on 5/23/16.
//  Copyright © 2016 SENDBIRD.COM. All rights reserved.
//

#import "SBDBaseChannel.h"
#import "SBDUser.h"
#import "SBDParticipantListQuery.h"
#import "SBDMutedUserListQuery.h"
#import "SBDBannedUserListQuery.h"
#import "SBDMappable.h"

@class SBDOpenChannel, SBDOpenChannelParams;
@class SBDOpenChannelListQuery;

/**
 *  The `SBDOpenChannel` class represents a public chat. This is a channel type which anyone can participate without a permission. It can handle thousands of users in one channel. This channel has participants instead of members of `SBDGroupChannel` and every participant is always online. A user can be included as an operator when a channel is created. The operator has a permission to mute, unmute, ban and unban participants. The muted user can see the messages in the channel, but can't say anything. The unbanned user can't enter the channel. If a user who is in the channel is banned, the user will be kicked from the channel.
 */
@interface SBDOpenChannel : SBDBaseChannel <SBDMappable>

/**
 *  The number of participants in this channel.
 */
@property (nonatomic) NSInteger participantCount;

/**
 *  The operators of this channel.
 */
@property (strong, nonatomic, readonly, nullable) NSMutableArray<SBDUser *> *operators;

/**
 *  Creates a query instance for open channel list.
 *
 *  @return The query instance for open channel list.
 */
+ (nullable SBDOpenChannelListQuery *)createOpenChannelListQuery;

/**
 *  Creates an open channel.
 *
 *  @param completionHandler The handler block to execute. `channel` is the open channel instance which is created. The name and cover URL of the channel are generated in Sendbird server.
 */
+ (void)createChannelWithCompletionHandler:(nonnull void (^)(SBDOpenChannel * _Nullable channel,
                                                             SBDError * _Nullable error))completionHandler;

/**
 *  Creates an open channel.
 *
 *  @param name              The name of the channel.
 *  @param channelUrl        The channel URL. If nil, channel url will be determined randomly.
 *  @param coverUrl          The cover image URL.
 *  @param data              The data for channel.
 *  @param operatorUserIds   The operator user IDs of channel.
 *  @param customType        The custom type for channel.
 *  @param completionHandler The handler block to execute. `channel` is the open channel instance which is created.
 */
+ (void)createChannelWithName:(NSString * _Nullable)name
                   channelUrl:(NSString * _Nullable)channelUrl
                     coverUrl:(NSString * _Nullable)coverUrl
                         data:(NSString * _Nullable)data
              operatorUserIds:(NSArray<NSString *> * _Nullable)operatorUserIds
                   customType:(NSString * _Nullable)customType
            completionHandler:(nonnull void (^)(SBDOpenChannel * _Nullable channel,
                                                SBDError * _Nullable error))completionHandler;

/**
 *  Creates an open channel.
 *
 *  @param name              The name of the channel.
 *  @param channelUrl        The channel URL. If nil, channel url will be determined randomly.
 *  @param coverImage        The cover image data of open channel.
 *  @param coverImageName    The cover image file name of open channel.
 *  @param data              The data for channel.
 *  @param operatorUserIds   The operator user IDs of channel.
 *  @param customType        The custom type for channel.
 *  @param progressHandler   The handler block to monitor progression. `bytesSent` is the number of bytes sent since the last time this method was called. `totalBytesSent` is the total number of bytes sent so far. `totalBytesExpectedToSend` is the expected length of the body <span>data</span>. These parameters are the same to the declaration of [`URLSession:task:didSendBodyData:totalBytesSent:totalBytesExpectedToSend:`](https://developer.apple.com/reference/foundation/nsurlsessiontaskdelegate/1408299-urlsession?language=objc).
 *  @param completionHandler The handler block to execute. `channel` is the open channel instance which is created.
 */
+ (void)createChannelWithName:(NSString * _Nullable)name
                   channelUrl:(NSString * _Nullable)channelUrl
                   coverImage:(NSData * _Nonnull)coverImage
               coverImageName:(NSString * _Nonnull)coverImageName
                         data:(NSString * _Nullable)data
              operatorUserIds:(NSArray<NSString *> * _Nullable)operatorUserIds
                   customType:(NSString * _Nullable)customType
              progressHandler:(nullable void (^)(int64_t bytesSent,
                                                 int64_t totalBytesSent,
                                                 int64_t totalBytesExpectedToSend))progressHandler
            completionHandler:(nonnull void (^)(SBDOpenChannel * _Nullable channel,
                                                SBDError * _Nullable error))completionHandler;

/**
 *  Creates a open channel with `SBDOpenChannelParams` class.
 *
 *  @param params  The parameter instance of SBDOpenChannelParams what has properties to create open channel.
 *  @param completionHandler The handler block to execute. `channel` is the open channel instance.
 *  @since 3.0.206
*/
+ (void)createChannelWithParams:(nonnull SBDOpenChannelParams *)params
              completionHandler:(nonnull void(^)(SBDOpenChannel * _Nullable channel, SBDError * _Nullable error))completionHandler;

/**
 *  Creates a open channel with `SBDOpenChannelParams` class.
 *
 *  @param params  The parameter instance of SBDOpenChannelParams what has properties to create open channel.
 *  @param progressHandler   The handler block to monitor progression. `bytesSent` is the number of bytes sent since the last time this method was called. `totalBytesSent` is the total number of bytes sent so far. `totalBytesExpectedToSend` is the expected length of the body <span>data</span>. These parameters are the same to the declaration of [`URLSession:task:didSendBodyData:totalBytesSent:totalBytesExpectedToSend:`](https://developer.apple.com/reference/foundation/nsurlsessiontaskdelegate/1408299-urlsession?language=objc).
 *  @param completionHandler The handler block to execute. `channel` is the open channel instance.
 *  @since 3.0.206
*/
+ (void)createChannelWithParams:(nonnull SBDOpenChannelParams *)params
                progressHandler:(nullable void (^)(int64_t bytesSent,
                                                   int64_t totalBytesSent,
                                                   int64_t totalBytesExpectedToSend))progressHandler
              completionHandler:(nonnull void(^)(SBDOpenChannel * _Nullable channel,
                                                 SBDError * _Nullable error))completionHandler;

/**
 *  Updates an open channel with properties.
 *
 *  @param name              The name of the channel.
 *  @param coverUrl          The cover image URL.
 *  @param data              The data for channel.
 *  @param operatorUsers     The operator users of channel.
 *  @param completionHandler The handler block to execute. `channel` is the open channel instance which is created.
 */
- (void)updateChannelWithName:(NSString * _Nullable)name
                     coverUrl:(NSString * _Nullable)coverUrl
                         data:(NSString * _Nullable)data
                operatorUsers:(NSArray<SBDUser *> * _Nullable)operatorUsers
            completionHandler:(nonnull void (^)(SBDOpenChannel * _Nullable channel,
                                                SBDError * _Nullable error))completionHandler;

/**
 *  Updates an open channel.
 *
 *  @param name              The name of the channel.
 *  @param coverImage        The cover image data of open channel.
 *  @param coverImageName    The cover image file name of open channel.
 *  @param data              The data for channel.
 *  @param operatorUserIds   The operator user IDs of channel.
 *  @param customType        The custom type for channel.
 *  @param progressHandler   The handler block to monitor progression. `bytesSent` is the number of bytes sent since the last time this method was called. `totalBytesSent` is the total number of bytes sent so far. `totalBytesExpectedToSend` is the expected length of the body <span>data</span>. These parameters are the same to the declaration of [`URLSession:task:didSendBodyData:totalBytesSent:totalBytesExpectedToSend:`](https://developer.apple.com/reference/foundation/nsurlsessiontaskdelegate/1408299-urlsession?language=objc).
 *  @param completionHandler The handler block to execute. `channel` is the open channel instance which is created.
 */
- (void)updateChannelWithName:(NSString * _Nullable)name
                   coverImage:(NSData * _Nullable)coverImage
               coverImageName:(NSString * _Nullable)coverImageName
                         data:(NSString * _Nullable)data
              operatorUserIds:(NSArray<NSString *> * _Nullable)operatorUserIds
                   customType:(NSString * _Nullable)customType
              progressHandler:(nullable void (^)(int64_t bytesSent,
                                                 int64_t totalBytesSent,
                                                 int64_t totalBytesExpectedToSend))progressHandler
            completionHandler:(nonnull void (^)(SBDOpenChannel * _Nullable channel,
                                                SBDError * _Nullable error))completionHandler;

/**
 *  Updates a open channel with `SBDOpenChannelParams` class.
 *
 *  @param params The parameter instance of SBDOpenChannelParams what has properties to update open channel.
 *  @param completionHandler The handler block to execute. `channel` is the open channel instance.
 *  @since 3.0.206
 */
- (void)updateChannelWithParams:(nonnull SBDOpenChannelParams *)params
              completionHandler:(nonnull void (^)(SBDOpenChannel * _Nullable channel,
                                                  SBDError * _Nullable error))completionHandler;

/**
 *  Updates a open channel with `SBDOpenChannelParams` class.
 *
 *  @param params The parameter instance of SBDOpenChannelParams what has properties to update open channel.
 *  @param progressHandler   The handler block to monitor progression. `bytesSent` is the number of bytes sent since the last time this method was called. `totalBytesSent` is the total number of bytes sent so far. `totalBytesExpectedToSend` is the expected length of the body <span>data</span>. These parameters are the same to the declaration of [`URLSession:task:didSendBodyData:totalBytesSent:totalBytesExpectedToSend:`](https://developer.apple.com/reference/foundation/nsurlsessiontaskdelegate/1408299-urlsession?language=objc).
 *  @param completionHandler The handler block to execute. `channel` is the open channel instance.
 *  @since 3.0.206
*/
- (void)updateChannelWithParams:(nonnull SBDOpenChannelParams *)params
                progressHandler:(nullable void (^)(int64_t bytesSent,
                                                   int64_t totalBytesSent,
                                                   int64_t totalBytesExpectedToSend))progressHandler
              completionHandler:(nonnull void (^)(SBDOpenChannel * _Nullable channel,
                                                  SBDError * _Nullable error))completionHandler;

/**
 *  Deletes open channel
 *
 *  @param completionHandler The handler block to execute. `channel` is the open channel instance which is deleted.
 *  @since 3.0.180
 */
- (void)deleteChannelWithCompletionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/**
 *  Gets an open channel instance from channel URL.
 *
 *  @param channelUrl        The channel URL.
 *  @param completionHandler The handler block to execute. `channel` is the open channel instance which has the `channelUrl`.
 */
+ (void)getChannelWithUrl:(NSString * _Nonnull)channelUrl
        completionHandler:(nullable void (^)(SBDOpenChannel * _Nullable channel, SBDError * _Nullable error))completionHandler;

/**
 *  Enters the channel.
 *
 *  @param completionHandler The handler block to execute.
 */
- (void)enterChannelWithCompletionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/**
 *  Exits the channel.
 *
 *  @param completionHandler The handler block to execute.
 */
- (void)exitChannelWithCompletionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/**
 *  Creates a query instance for getting participant list of the channel instance.
 *
 *  @return SBDUserListQuery instance for the participant list of the channel instance.
 */
- (nullable SBDParticipantListQuery *)createParticipantListQuery;

/**
 *  Creates a query instance for getting muted user list of the channel instance.
 *
 *  @return SBDUserListQuery instance for the muted user list.
 */
- (nullable SBDMutedUserListQuery *)createMutedUserListQuery;

/**
 *  Creates a query instance for getting banned user list of the channel instance.
 *
 *  @return SBDUserListQuery instance for the banned user list.
 */
- (nullable SBDBannedUserListQuery *)createBannedUserListQuery;

/**
 *  Refreshes the channel information.
 *
 *  @param completionHandler The handler block to execute.
 */
- (void)refreshWithCompletionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/**
 *  Bans a user with the user object.
 *
 *  @param user              The user object.
 *  @param seconds           Duration for ban in seconds.
 *  @param completionHandler The handler block to execute.
 */
- (void)banUser:(SBDUser * _Nonnull)user
        seconds:(int)seconds completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/**
 *  Bans a user with the user ID.
 *
 *  @param userId            The user ID.
 *  @param seconds           Duration for ban in seconds.
 *  @param completionHandler The handler block to execute.
 */
- (void)banUserWithUserId:(NSString * _Nonnull)userId
                  seconds:(int)seconds
        completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/**
 *  Unbans a user with the user object.
 *
 *  @param user              The user object.
 *  @param completionHandler The handler block to execute.
 */
- (void)unbanUser:(SBDUser * _Nonnull)user completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/**
 *  Unbans a user with the user ID.
 *
 *  @param userId            The user ID.
 *  @param completionHandler The handler block to execute.
 */
- (void)unbanUserWithUserId:(NSString * _Nonnull)userId
          completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/**
 *  Mutes auser with the user object.
 *
 *  @param user              The user object.
 *  @param completionHandler The handler block to execute.
 */
- (void)muteUser:(SBDUser * _Nonnull)user completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/**
 *  Mutes a user with the user ID.
 *
 *  @param userId            The user ID.
 *  @param completionHandler The handler block to execute.
 */
- (void)muteUserWithUserId:(NSString * _Nonnull)userId
         completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/**
 Mute the user with additional options. Muted user cannot send any messages to the open channel.
 
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
 Mute the user with additional options. Muted user cannot send any messages to the open channel.
 
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
 *  Unmutes a user with the user object.
 *
 *  @param user              The user object.
 *  @param completionHandler The handler block to execute.
 */
- (void)unmuteUser:(SBDUser * _Nonnull)user completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/**
 *  Unmutes a user with the user ID.
 *
 *  @param userId            The user ID.
 *  @param completionHandler The handler block to execute.
 */
- (void)unmuteUserWithUserId:(NSString * _Nonnull)userId
           completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/**
 *  Returns the user is an operator or not.
 *
 *  @param user The user object.
 *
 *  @return If YES, the user is an operator.
 */
- (BOOL)isOperatorWithUser:(SBDUser * _Nonnull)user;

/**
 *  Returns the user ID is an operator or not.
 *
 *  @param userId The user ID.
 *
 *  @return If YES, the user ID is an operator.
 */
- (BOOL)isOperatorWithUserId:(NSString * _Nonnull)userId;

/**
 Builds a open channel object from serialized <span>data</span>.
 
 @param data Serialized <span>data</span>.
 @return SBDOpenChannel object.
 */
//+ (nullable instancetype)buildFromSerializedData:(NSData * _Nonnull)data;

/**
 Serializes open channel object.
 
 @return Serialized <span>data</span>.
 */
- (nullable NSData *)serialize;


#pragma mark - Deprecated
/**
 *  Creates an open channel with properties.
 *
 *  @param name              The name of the channel.
 *  @param coverUrl          The cover image URL.
 *  @param data              The data for channel.
 *  @param operatorUsers     The operator users of channel.
 *  @param completionHandler The handler block to execute. `channel` is the open channel instance which is created.
 *
 *  @deprecated 3.0.116. (Use `createChannelWithParams:progressHandler:completionHandler:` instead.)
 */
+ (void)createChannelWithName:(NSString * _Nullable)name
                     coverUrl:(NSString * _Nullable)coverUrl
                         data:(NSString * _Nullable)data
                operatorUsers:(NSArray<SBDUser *> * _Nullable)operatorUsers
            completionHandler:(nonnull void (^)(SBDOpenChannel * _Nullable channel, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/**
 *  Creates an open channel with properties.
 *
 *  @param name              The name of the channel.
 *  @param coverImage        The cover image data of open channel.
 *  @param coverImageName    The cover image file name of open channel.
 *  @param data              The data for channel.
 *  @param operatorUsers     The operator users of channel.
 *  @param progressHandler   The handler block to monitor progression. `bytesSent` is the number of bytes sent since the last time this method was called. `totalBytesSent` is the total number of bytes sent so far. `totalBytesExpectedToSend` is the expected length of the body <span>data</span>. These parameters are the same to the declaration of [`URLSession:task:didSendBodyData:totalBytesSent:totalBytesExpectedToSend:`](https://developer.apple.com/reference/foundation/nsurlsessiontaskdelegate/1408299-urlsession?language=objc).
 *  @param completionHandler The handler block to execute. `channel` is the open channel instance which is created.
 *
 *  @deprecated 3.0.116. (Use `createChannelWithParams:progressHandler:completionHandler:` instead.)
 */
+ (void)createChannelWithName:(NSString * _Nullable)name
                   coverImage:(NSData * _Nonnull)coverImage
               coverImageName:(NSString * _Nonnull)coverImageName
                         data:(NSString * _Nullable)data
                operatorUsers:(NSArray<SBDUser *> * _Nullable)operatorUsers
              progressHandler:(nullable void (^)(int64_t bytesSent, int64_t totalBytesSent, int64_t totalBytesExpectedToSend))progressHandler
            completionHandler:(nonnull void (^)(SBDOpenChannel * _Nullable channel, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/**
 *  Creates an open channel.
 *
 *  @param name              The name of the channel.
 *  @param coverUrl          The cover image URL.
 *  @param data              The data for channel.
 *  @param operatorUserIds   The operator user IDs of channel.
 *  @param completionHandler The handler block to execute. `channel` is the open channel instance which is created.
 *
 *  @deprecated 3.0.116. (Use `createChannelWithParams:progressHandler:completionHandler:` instead.)
 */
+ (void)createChannelWithName:(NSString * _Nullable)name
                     coverUrl:(NSString * _Nullable)coverUrl
                         data:(NSString * _Nullable)data
              operatorUserIds:(NSArray<NSString *> * _Nullable)operatorUserIds
            completionHandler:(nonnull void (^)(SBDOpenChannel * _Nullable channel, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/**
 *  Creates an open channel.
 *
 *  @param name              The name of the channel.
 *  @param coverUrl          The cover image URL.
 *  @param data              The data for channel.
 *  @param operatorUserIds   The operator user IDs of channel.
 *  @param customType        The custom type for channel.
 *  @param completionHandler The handler block to execute. `channel` is the open channel instance which is created.
 *
 *  @deprecated 3.0.116. (Use `createChannelWithParams:progressHandler:completionHandler:` instead.)
 */
+ (void)createChannelWithName:(NSString * _Nullable)name
                     coverUrl:(NSString * _Nullable)coverUrl
                         data:(NSString * _Nullable)data
              operatorUserIds:(NSArray<NSString *> * _Nullable)operatorUserIds
                   customType:(NSString * _Nullable)customType
            completionHandler:(nonnull void (^)(SBDOpenChannel * _Nullable channel, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/**
 *  Creates an open channel.
 *
 *  @param name              The name of the channel.
 *  @param coverImage        The cover image data of open channel.
 *  @param coverImageName    The cover image file name of open channel.
 *  @param data              The data for channel.
 *  @param operatorUserIds   The operator user IDs of channel.
 *  @param progressHandler   The handler block to monitor progression. `bytesSent` is the number of bytes sent since the last time this method was called. `totalBytesSent` is the total number of bytes sent so far. `totalBytesExpectedToSend` is the expected length of the body <span>data</span>. These parameters are the same to the declaration of [`URLSession:task:didSendBodyData:totalBytesSent:totalBytesExpectedToSend:`](https://developer.apple.com/reference/foundation/nsurlsessiontaskdelegate/1408299-urlsession?language=objc).
 *  @param completionHandler The handler block to execute. `channel` is the open channel instance which is created.
 *
 *  @deprecated 3.0.116. (Use `createChannelWithParams:progressHandler:completionHandler:` instead.)
 */
+ (void)createChannelWithName:(NSString * _Nullable)name
                   coverImage:(NSData * _Nonnull)coverImage
               coverImageName:(NSString * _Nonnull)coverImageName
                         data:(NSString * _Nullable)data
              operatorUserIds:(NSArray<NSString *> * _Nullable)operatorUserIds
              progressHandler:(nullable void (^)(int64_t bytesSent, int64_t totalBytesSent, int64_t totalBytesExpectedToSend))progressHandler
            completionHandler:(nonnull void (^)(SBDOpenChannel * _Nullable channel, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/**
 *  Creates an open channel.
 *
 *  @param name              The name of the channel.
 *  @param coverImage        The cover image data of open channel.
 *  @param coverImageName    The cover image file name of open channel.
 *  @param data              The data for channel.
 *  @param operatorUserIds   The operator user IDs of channel.
 *  @param customType        The custom type for channel.
 *  @param progressHandler   The handler block to monitor progression. `bytesSent` is the number of bytes sent since the last time this method was called. `totalBytesSent` is the total number of bytes sent so far. `totalBytesExpectedToSend` is the expected length of the body <span>data</span>. These parameters are the same to the declaration of [`URLSession:task:didSendBodyData:totalBytesSent:totalBytesExpectedToSend:`](https://developer.apple.com/reference/foundation/nsurlsessiontaskdelegate/1408299-urlsession?language=objc).
 *  @param completionHandler The handler block to execute. `channel` is the open channel instance which is created.
 *
 *  @deprecated 3.0.116. (Use `createChannelWithParams:progressHandler:completionHandler:` instead.)
 */
+ (void)createChannelWithName:(NSString * _Nullable)name
                   coverImage:(NSData * _Nonnull)coverImage
               coverImageName:(NSString * _Nonnull)coverImageName
                         data:(NSString * _Nullable)data
              operatorUserIds:(NSArray<NSString *> * _Nullable)operatorUserIds
                   customType:(NSString * _Nullable)customType
              progressHandler:(nullable void (^)(int64_t bytesSent, int64_t totalBytesSent, int64_t totalBytesExpectedToSend))progressHandler
            completionHandler:(nonnull void (^)(SBDOpenChannel * _Nullable channel, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/**
 *  Creates an open channel.
 *
 *  @param name              The name of the channel.
 *  @param coverImageFilePath        The cover image file path of open channel.
 *  @param data              The data for channel.
 *  @param operatorUserIds   The operator user IDs of channel.
 *  @param customType        The custom type for channel.
 *  @param progressHandler   The handler block to monitor progression. `bytesSent` is the number of bytes sent since the last time this method was called. `totalBytesSent` is the total number of bytes sent so far. `totalBytesExpectedToSend` is the expected length of the body <span>data</span>. These parameters are the same to the declaration of [`URLSession:task:didSendBodyData:totalBytesSent:totalBytesExpectedToSend:`](https://developer.apple.com/reference/foundation/nsurlsessiontaskdelegate/1408299-urlsession?language=objc).
 *  @param completionHandler The handler block to execute. `channel` is the open channel instance which is created.
 *
 *  @deprecated 3.0.116. (Use `createChannelWithParams:progressHandler:completionHandler:` instead.)
 */
+ (void)createChannelWithName:(NSString * _Nullable)name
           coverImageFilePath:(NSString * _Nonnull)coverImageFilePath
                         data:(NSString * _Nullable)data
              operatorUserIds:(NSArray<NSString *> * _Nullable)operatorUserIds
                   customType:(NSString * _Nullable)customType
              progressHandler:(nullable void (^)(int64_t bytesSent, int64_t totalBytesSent, int64_t totalBytesExpectedToSend))progressHandler
            completionHandler:(nonnull void (^)(SBDOpenChannel * _Nullable channel, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/**
 *  Creates an open channel.
 *
 *  @param name              The name of the channel.
 *  @param channelUrl        The channel URL. If nil, channel url will be determined randomly.
 *  @param coverImageFilePath        The cover image file path of open channel.
 *  @param data              The data for channel.
 *  @param operatorUserIds   The operator user IDs of channel.
 *  @param customType        The custom type for channel.
 *  @param progressHandler   The handler block to monitor progression. `bytesSent` is the number of bytes sent since the last time this method was called. `totalBytesSent` is the total number of bytes sent so far. `totalBytesExpectedToSend` is the expected length of the body <span>data</span>. These parameters are the same to the declaration of [`URLSession:task:didSendBodyData:totalBytesSent:totalBytesExpectedToSend:`](https://developer.apple.com/reference/foundation/nsurlsessiontaskdelegate/1408299-urlsession?language=objc).
 *  @param completionHandler The handler block to execute. `channel` is the open channel instance which is created.
 *
 *  @deprecated 3.0.116. (Use `createChannelWithParams:progressHandler:completionHandler:` instead.)
 */
+ (void)createChannelWithName:(NSString * _Nullable)name
                   channelUrl:(NSString * _Nullable)channelUrl
           coverImageFilePath:(NSString * _Nonnull)coverImageFilePath
                         data:(NSString * _Nullable)data
              operatorUserIds:(NSArray<NSString *> * _Nullable)operatorUserIds
                   customType:(NSString * _Nullable)customType
              progressHandler:(nullable void (^)(int64_t bytesSent, int64_t totalBytesSent, int64_t totalBytesExpectedToSend))progressHandler
            completionHandler:(nonnull void (^)(SBDOpenChannel * _Nullable channel, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;


/**
 *  Updates an open channel with properties.
 *
 *  @param name              The name of the channel.
 *  @param coverImage        The cover image data of open channel.
 *  @param coverImageName    The cover image file name of open channel.
 *  @param data              The data for channel.
 *  @param operatorUsers     The operator users of channel.
 *  @param progressHandler   The handler block to monitor progression. `bytesSent` is the number of bytes sent since the last time this method was called. `totalBytesSent` is the total number of bytes sent so far. `totalBytesExpectedToSend` is the expected length of the body <span>data</span>. These parameters are the same to the declaration of [`URLSession:task:didSendBodyData:totalBytesSent:totalBytesExpectedToSend:`](https://developer.apple.com/reference/foundation/nsurlsessiontaskdelegate/1408299-urlsession?language=objc).
 *  @param completionHandler The handler block to execute. `channel` is the open channel instance which is created.
 *
 *  @deprecated 3.0.116. (Use `updateChannelWithParams:progressHandler:completionHandler:` instead.)
 */
- (void)updateChannelWithName:(NSString * _Nullable)name
                   coverImage:(NSData * _Nullable)coverImage
               coverImageName:(NSString * _Nullable)coverImageName
                         data:(NSString * _Nullable)data
                operatorUsers:(NSArray<SBDUser *> * _Nullable)operatorUsers
              progressHandler:(nullable void (^)(int64_t bytesSent, int64_t totalBytesSent, int64_t totalBytesExpectedToSend))progressHandler
            completionHandler:(nonnull void (^)(SBDOpenChannel * _Nullable channel, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/**
 *  Updates an open channel.
 *
 *  @param name              The name of the channel.
 *  @param coverUrl          The cover image URL.
 *  @param data              The data for channel.
 *  @param operatorUserIds   The operator user IDs of channel.
 *  @param completionHandler The handler block to execute. `channel` is the open channel instance which is created.
 *
 *  @deprecated 3.0.116. (Use `updateChannelWithParams:progressHandler:completionHandler:` instead.)
 */
- (void)updateChannelWithName:(NSString * _Nullable)name
                     coverUrl:(NSString * _Nullable)coverUrl
                         data:(NSString * _Nullable)data
              operatorUserIds:(NSArray<NSString *> * _Nullable)operatorUserIds
            completionHandler:(nonnull void (^)(SBDOpenChannel * _Nullable channel, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/**
 *  Updates an open channel.
 *
 *  @param name              The name of the channel.
 *  @param coverUrl          The cover image URL.
 *  @param data              The data for channel.
 *  @param operatorUserIds   The operator user IDs of channel.
 *  @param customType        The custom type for channel.
 *  @param completionHandler The handler block to execute. `channel` is the open channel instance which is created.
 *
 *  @deprecated 3.0.116. (Use `updateChannelWithParams:progressHandler:completionHandler:` instead.)
 */
- (void)updateChannelWithName:(NSString * _Nullable)name
                     coverUrl:(NSString * _Nullable)coverUrl
                         data:(NSString * _Nullable)data
              operatorUserIds:(NSArray<NSString *> * _Nullable)operatorUserIds
                   customType:(NSString * _Nullable)customType
            completionHandler:(nonnull void (^)(SBDOpenChannel * _Nullable channel, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;

/**
 *  Updates an open channel.
 *
 *  @param name              The name of the channel.
 *  @param coverImage        The cover image data of open channel.
 *  @param coverImageName    The cover image file name of open channel.
 *  @param data              The data for channel.
 *  @param operatorUserIds   The operator user IDs of channel.
 *  @param progressHandler   The handler block to monitor progression. `bytesSent` is the number of bytes sent since the last time this method was called. `totalBytesSent` is the total number of bytes sent so far. `totalBytesExpectedToSend` is the expected length of the body <span>data</span>. These parameters are the same to the declaration of [`URLSession:task:didSendBodyData:totalBytesSent:totalBytesExpectedToSend:`](https://developer.apple.com/reference/foundation/nsurlsessiontaskdelegate/1408299-urlsession?language=objc).
 *  @param completionHandler The handler block to execute. `channel` is the open channel instance which is created.
 *
 *  @deprecated 3.0.116. (Use `updateChannelWithParams:progressHandler:completionHandler:` instead.)
 */
- (void)updateChannelWithName:(NSString * _Nullable)name
                   coverImage:(NSData * _Nullable)coverImage
               coverImageName:(NSString * _Nullable)coverImageName
                         data:(NSString * _Nullable)data
              operatorUserIds:(NSArray<NSString *> * _Nullable)operatorUserIds
              progressHandler:(nullable void (^)(int64_t bytesSent, int64_t totalBytesSent, int64_t totalBytesExpectedToSend))progressHandler
            completionHandler:(nonnull void (^)(SBDOpenChannel * _Nullable channel, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;


/**
 *  Updates an open channel.
 *
 *  @param name              The name of the channel.
 *  @param coverImageFilePath        The cover image file path of open channel.
 *  @param data              The data for channel.
 *  @param operatorUserIds   The operator user IDs of channel.
 *  @param customType        The custom type for channel.
 *  @param progressHandler   The handler block to monitor progression. `bytesSent` is the number of bytes sent since the last time this method was called. `totalBytesSent` is the total number of bytes sent so far. `totalBytesExpectedToSend` is the expected length of the body <span>data</span>. These parameters are the same to the declaration of [`URLSession:task:didSendBodyData:totalBytesSent:totalBytesExpectedToSend:`](https://developer.apple.com/reference/foundation/nsurlsessiontaskdelegate/1408299-urlsession?language=objc).
 *  @param completionHandler The handler block to execute. `channel` is the open channel instance which is created.
 *
 *  @deprecated 3.0.116. (Use `updateChannelWithParams:progressHandler:completionHandler:` instead.)
 */
- (void)updateChannelWithName:(NSString * _Nullable)name
           coverImageFilePath:(NSString * _Nullable)coverImageFilePath
                         data:(NSString * _Nullable)data
              operatorUserIds:(NSArray<NSString *> * _Nullable)operatorUserIds
                   customType:(NSString * _Nullable)customType
              progressHandler:(nullable void (^)(int64_t bytesSent, int64_t totalBytesSent, int64_t totalBytesExpectedToSend))progressHandler
            completionHandler:(nonnull void (^)(SBDOpenChannel * _Nullable channel, SBDError * _Nullable error))completionHandler
DEPRECATED_ATTRIBUTE;


@end
