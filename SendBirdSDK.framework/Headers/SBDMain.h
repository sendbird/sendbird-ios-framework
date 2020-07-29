//
//  SBDMain.h
//  SendBirdSDK
//
//  Created by Jed Gyeong on 5/23/16.
//  Copyright © 2016 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBDUser.h"
#import "SBDBaseChannel.h"
#import "SBDEmoji.h"
#import "SBDGroupChannel.h"
#import "SBDGroupChannelChangeLogsParams.h"
#import "SBDOpenChannelListQuery.h"
#import "SBDGroupChannelListQuery.h"
#import "SBDTypes.h"
#import "SBDUserListQuery.h"
#import "SBDInternalTypes.h"
#import "SBDFriendListQuery.h"
#import "SBDApplicationUserListQuery.h"
#import "SBDBlockedUserListQuery.h"
#import "SBDAppInfo.h"

typedef void(^SBDBackgroundSessionBlock)(void);



/**
 *  An object that adopts the `SBDConnectionDelegate` protocol is responsible for managing the connection statuses. This delegate includes three statuses: reconnection start, reconnection succession, and reconnection failure. The `SBDConnectionDelegate` can be added by [`addConnectionDelegate:identifier:`](../Classes/SBDMain.html#//api/name/addConnectionDelegate:identifier:) in `SBDMain`. Every `SBDConnectionDelegate` method which is added is going to manage the statues.
 *
 *  @warning If the object that adopts the `SBDConnectionDelegate` protocol is invalid, the delegate has to be removed by the identifier via [`removeConnectionDelegateForIdentifier:`](../Classes/SBDMain.html#//api/name/removeConnectionDelegateForIdentifier:) in `SBDMain`. If you miss this, it will cause the crash.
 */
@protocol SBDConnectionDelegate <NSObject>

@optional

/**
 *  Invoked when reconnection starts.
 */
- (void)didStartReconnection;

/**
 *  Invoked when reconnection is succeeded.
 */
- (void)didSucceedReconnection;

/**
 *  Invoked when reconnection is failed.
 */
- (void)didFailReconnection;

/**
 *  Invoked when reconnection is cancelled.
 */
- (void)didCancelReconnection;

@end

/**
 *  The `SBDMain` is the core class for Sendbird. This class is singletone instance which is initialized by Application ID.
 *  This class provides the methods for overall. The methods include `SBDChannelDelegate` registration for receiving events are related to channels, `SBDConnectionDelegate` for managing the connection status, updating the current user's information, registration for APNS push notification and blocking other users.
 */
@interface SBDMain : NSObject

/**
 *  Shows the current log level.
 */
@property (atomic) SBDLogLevel logLevel;

/**
 *  Manages registered `SBDConnectionDelegate`.
 */
@property (nonatomic, strong, readonly, nullable) NSMapTable<NSString *, id<SBDConnectionDelegate>> *connectionDelegatesDictionary;

/**
 *  Manages registered `SBDChannelDelegate`.
 */
@property (nonatomic, strong, readonly, nullable) NSMapTable<NSString *, id<SBDChannelDelegate>> *channelDelegatesDictionary;

/**
 *  Manages registered `SBDUserEventlDelegate`.
 */
@property (nonatomic, strong, readonly, nullable) NSMapTable<NSString *, id<SBDUserEventDelegate>> *userEventDelegatesDictionary;

/**
 *  The completion handler of background session.
 */
@property (nonatomic, strong, nullable) SBDBackgroundSessionBlock backgroundSessionCompletionHandler;

/**
 *  The list of tasks in background.
 */
@property (strong, nonatomic, nonnull) NSMutableArray <SBDBackgroundSessionBlock> *backgroundTaskBlock;

/**
 *  The number of URLSessionDidFinishEventsForBackgroundURLSession.
 */
@property (atomic) int URLSessionDidFinishEventsForBackgroundURLSession;


/**
 *  Retrieves the SDK version.
 *
 *  @return The SDK version.
 */
+ (nonnull NSString *)getSDKVersion;

/**
 *  Retrieves the log level.
 *
 *  @return Log level.
 */
+ (SBDLogLevel)getLogLevel;

/**
 *  Gets the Application ID which was used for initialization.
 *
 *  @return The Application ID.
 */
+ (nullable NSString *)getApplicationId;

/**
 *  Sets the log level. The log level is defined by `SBDLogLevel`.
 *
 *  @param logLevel Log level.
 */
+ (void)setLogLevel:(SBDLogLevel)logLevel;

/**
 *  Gets the current debug mode.
 *
 *  @return If YES, this instance is debug mode.
 */
+ (BOOL)getDebugMode DEPRECATED_ATTRIBUTE;

/**
 *  Gets a singleton instance of `SBDMain`.
 *
 *  @return a singleton instance for `SBDMain`.
 */
+ (nonnull SBDMain *)sharedInstance;

/**
 *  Gets initializing state.
 *
 *  @return If YES, `SBDMain` instance is initialized.
 */
+ (BOOL)isInitialized;

/**
 *  Initializes `SBDMain` singleton instance with Sendbird Application ID. The Application ID is on Sendbird dashboard. This method has to be run first in order to user Sendbird.
 *
 *  @param applicationId The Applicatin ID of Sendbird. It can be founded on Sendbird Dashboard.
 *
 *  @return If YES, the applicationId is set.
 */
+ (BOOL)initWithApplicationId:(NSString * _Nonnull)applicationId;

/**
 *  Initialize `sharedContainerIdentifier` of NSURLSessionConfiguration to use background session.
 *  Important! If you use `App Extension` and use upload file message in extension, you MUST set thie field.
 *
 *  @param identifier   The identifier to set background session configuraion.
 */
+ (void)setSharedContainerIdentifier:(nonnull NSString *)identifier;

/**
 *  Performs a connection to Sendbird with the user ID.
 *
 *  @param userId            The user ID.
 *  @param completionHandler The handler block to execute. `user` is the object to represent the current user.
 */
+ (void)connectWithUserId:(NSString * _Nonnull)userId
        completionHandler:(nullable void (^)(SBDUser * _Nullable user, SBDError * _Nullable error))completionHandler;

/**
 *  Performs a connection to Sendbird with the user ID and the access token.
 *
 *  @param userId            The user ID.
 *  @param accessToken       The access token. If the user doesn't have access token, set nil.
 *  @param completionHandler The handler block to execute. `user` is the object to represent the current user.
 */
+ (void)connectWithUserId:(NSString * _Nonnull)userId
              accessToken:(NSString * _Nullable)accessToken
        completionHandler:(nullable void (^)(SBDUser * _Nullable user, SBDError * _Nullable error))completionHandler;

/**
 *  Performs a connection to Sendbird with the user ID and the access token.
 *
 *  @param userId userId
 *  @param accessToken accessToken
 *  @param apiHost apiHost
 *  @param wsHost wsHost
 *  @param completionHandler completionHandler
 *  @see -connectWithUserId:accessToken:completionHandler:
 *  @warning *Important*: DON'T use this method. This method will be unavailable.
 */
+ (void)connectWithUserId:(NSString * _Nonnull)userId
              accessToken:(NSString * _Nullable)accessToken
                  apiHost:(NSString * _Nullable)apiHost
                   wsHost:(NSString * _Nullable)wsHost
        completionHandler:(nullable void (^)(SBDUser * _Nullable user, SBDError * _Nullable error))completionHandler;

/**
 *  Gets the current user object. The object is valid when the connection succeeded.
 *
 *  @return The current user object.
 */
+ (nullable SBDUser *)getCurrentUser;

/**
 *  Gets the current user's latest connection millisecond time(UTC). If the connection state is not open, returns 0.
 *
 *  @return  latest connected millisecond time stamp.
 *
 *  @since 3.0.117
 */
+ (long long)getLastConnectedAt;

/**
 *  Disconnects from Sendbird. If this method is invoked, the current user will be invalidated.
 *
 *  @param completionHandler The handler block to execute.
 */
+ (void)disconnectWithCompletionHandler:(nullable void (^)(void))completionHandler;

/**
 *  Adds the `SBDConnectionDelegate`.
 *
 *  @param delegate   `SBDConnectionDelegate` delegate.
 *  @param identifier The identifier for the delegate.
 */
+ (void)addConnectionDelegate:(id<SBDConnectionDelegate> _Nonnull)delegate
                   identifier:(NSString * _Nonnull)identifier;

/**
 *  Removes the `SBDConnectionDelegate` by identifier.
 *
 *  @param identifier The identifier for the delegate to be removed.
 */
+ (void)removeConnectionDelegateForIdentifier:(NSString * _Nonnull)identifier;

/**
 *  Gets the delegate for connection by indentifer.
 *
 *  @param identifier The identifier for delegate.
 *
 *  @return `SBDConnectionDelegate` delegate.
 */
+ (nullable id<SBDConnectionDelegate>)connectionDelegateForIdentifier:(NSString * _Nonnull)identifier;

/**
 Removes all connection delegates;
 */
+ (void)removeAllConnectionDelegates;

/**
 *  Adds the `SBDChannelDelegate`.
 *
 *  @param delegate   `SBDChannelDelegate` delegate.
 *  @param identifier The identifier for delegate.
 */
+ (void)addChannelDelegate:(id<SBDChannelDelegate> _Nonnull)delegate
                identifier:(NSString * _Nonnull)identifier;

/**
 *  Removes the `SBDChannelDelegate` by identifier.
 *
 *  @param identifier The identifier for the delegate to be removed.
 */
+ (void)removeChannelDelegateForIdentifier:(NSString * _Nonnull)identifier;

/**
 *  Gets the delegate for channel by indentifer.
 *
 *  @param identifier The identifier for delegate.
 *
 *  @return `SBDChannelDelegate` delegate.
 */
+ (nullable id<SBDChannelDelegate>)channelDelegateForIdentifier:(NSString * _Nonnull)identifier;

/**
 Removes all channel delegates;
 */
+ (void)removeAllChannelDelegates;

/**
 *  Gets the WebSocket server connection state.
 *
 *  @return `SBDWebSocketConnectionState`
 *
 *  - `SBDWebSocketConnecting` - Connecting to the chat server
 *  - `SBDWebSocketOpen` - Connected to the chat server
 *  - `SBSWebSocketClosed` - Disconnected from the chat server
 */
+ (SBDWebSocketConnectionState)getConnectState;

/**
 Sets dispatch queue for every completion handler and delegate. Default queue is the main queue.
 
 @param queue Dispatch queue for every completion handler and delegate.
 */
+ (void)setCompletionHandlerDelegateQueue:(dispatch_queue_t _Nullable)queue;

/**
 Runs block in the dispatch queue that was set by `setCompletionHandlerDelegateQueue:`.
 
 @param block Block to run.
 */
+ (void)performCompletionHandlerDelegateQueueBlock:(dispatch_block_t _Nullable)block;

/**
 *  Creates `SBDUserListQuery` instance for getting a list of all users of this application.
 *
 *  @return `SBDUserListQuery` instance.
 *  @deprecated in 3.0.120. Use `createApplicationUserListQuery`.
 */
+ (nullable SBDUserListQuery *)createAllUserListQuery DEPRECATED_ATTRIBUTE;

/**
 *  Creates `SBDUserListQuery` instance for gettting a list of users of this application with user IDs.
 *
 *  @param userIds The user IDs to get user objects.
 *
 *  @return `SBDUserListQuery` instance.
 *  @deprecated in 3.0.120. Use `createApplicationUserListQuery` and `userIdsFilter` of `SBDApplicationUserListQuery`.
 */
+ (nullable SBDUserListQuery *)createUserListQueryWithUserIds:(NSArray<NSString *> * _Nonnull)userIds DEPRECATED_ATTRIBUTE;

/**
 Creates `SBDApplicationUserListQuery` instance for getting a list of all users of this application.

 @return `SBDApplicationUserListQuery` instance
 @since 3.0.120
 */
+ (nullable SBDApplicationUserListQuery *)createApplicationUserListQuery;

/**
 *  Creates `SBDBlockedUserListQuery` instance for getting a list of blocked users by the current user.
 *
 *  @return `SBDBlockedUserListQuery` instance.
 */
+ (nullable SBDBlockedUserListQuery *)createBlockedUserListQuery;

#pragma mark - For Current User
/**
 *  Updates the current user's information.
 *
 *  @param nickname          New nickname.
 *  @param profileUrl        New profile image url.
 *  @param completionHandler The handler block to execute.
 */
+ (void)updateCurrentUserInfoWithNickname:(NSString * _Nullable)nickname
                               profileUrl:(NSString * _Nullable)profileUrl
                        completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/**
 *  Updates the current user's information.
 *
 *  @param nickname          New nickname.
 *  @param profileImage      New profile image data.
 *  @param completionHandler The handler block to execute.
 */
+ (void)updateCurrentUserInfoWithNickname:(NSString * _Nullable)nickname
                             profileImage:(NSData * _Nullable)profileImage
                        completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/**
 *  Updates the current user's information.
 *
 *  @param nickname          New nickname.
 *  @param profileImage      New profile image data.
 *  @param progressHandler   The handler block to monitor progression. `bytesSent` is the number of bytes sent since the last time this method was called. `totalBytesSent` is the total number of bytes sent so far. `totalBytesExpectedToSend` is the expected length of the body data. These parameters are the same to the declaration of [`URLSession:task:didSendBodyData:totalBytesSent:totalBytesExpectedToSend:`](https://developer.apple.com/reference/foundation/nsurlsessiontaskdelegate/1408299-urlsession?language=objc).
 *  @param completionHandler The handler block to execute.
 */
+ (void)updateCurrentUserInfoWithNickname:(NSString * _Nullable)nickname
                             profileImage:(NSData * _Nullable)profileImage
                          progressHandler:(nullable void (^)(int64_t bytesSent, int64_t totalBytesSent, int64_t totalBytesExpectedToSend))progressHandler
                        completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/**
 *  Updates the current user's information.
 *
 *  @param nickname          New nickname.
 *  @param profileImageFilePath      New profile image file path.
 *  @param progressHandler   The handler block to monitor progression. `bytesSent` is the number of bytes sent since the last time this method was called. `totalBytesSent` is the total number of bytes sent so far. `totalBytesExpectedToSend` is the expected length of the body data. These parameters are the same to the declaration of [`URLSession:task:didSendBodyData:totalBytesSent:totalBytesExpectedToSend:`](https://developer.apple.com/reference/foundation/nsurlsessiontaskdelegate/1408299-urlsession?language=objc).
 *  @param completionHandler The handler block to execute.
 */
+ (void)updateCurrentUserInfoWithNickname:(NSString * _Nullable)nickname
                     profileImageFilePath:(NSString * _Nullable)profileImageFilePath
                          progressHandler:(nullable void (^)(int64_t bytesSent, int64_t totalBytesSent, int64_t totalBytesExpectedToSend))progressHandler
                        completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/**
 *  Updates the current user's preferred languages
 *
 *  @param preferredLanguages   New array of preferred languages
 *  @param completionHandler    The handler block to execute.
 */
+ (void)updateCurrentUserInfoWithPreferredLanguages:(nonnull NSArray<NSString *> *)preferredLanguages
                                  completionHandler:(nullable SBDErrorHandler)completionHandler;

#pragma mark - push token
/**
 *  Gets the pending push token.
 *
 *  @return Returns the pending push token.
 */
+ (nullable NSData *)getPendingPushToken;

/**
 *  Registers the current device token to Sendbird.
 *
 *  @param devToken          Device token for APNS.
 *  @param unique            If YES, register device token after removing exsiting all device tokens of the current user. If NO, just add the device token.
 *  @param completionHandler The handler block to execute. `status` is the status for push token registration. It is defined in `SBDPushTokenRegistrationStatus`. `SBDPushTokenRegistrationStatusSuccess` represents the `devToken` is registered. `SBDPushTokenRegistrationStatusPending` represents the `devToken` is not registered because the connection is not established, so this method has to be invoked with `getPendingPushToken` method after the connection. The `devToken` is retrived by `getPendingPushToken`. `SBDPushTokenRegistrationStatusError` represents the push token registration is failed.
 */
+ (void)registerDevicePushToken:(NSData * _Nonnull)devToken
                         unique:(BOOL)unique
              completionHandler:(nullable void (^)(SBDPushTokenRegistrationStatus status, SBDError * _Nullable error))completionHandler;

/**
 *  Registers the current device token to Sendbird.
 *
 *  @param devToken          Device token for APNS.
 *  @param completionHandler The handler block to execute. `status` is the status for push token registration. It is defined in `SBDPushTokenRegistrationStatus`. `SBDPushTokenRegistrationStatusSuccess` represents the `devToken` is registered. `SBDPushTokenRegistrationStatusPending` represents the `devToken` is not registered because the connection is not established, so this method has to be invoked with `getPendingPushToken` method after the connection. The `devToken` is retrived by `getPendingPushToken`. `SBDPushTokenRegistrationStatusError` represents the push token registration is failed.
 *
 *  @deprecated in 3.0.22
 */
+ (void)registerDevicePushToken:(NSData * _Nonnull)devToken
              completionHandler:(nullable void (^)(SBDPushTokenRegistrationStatus status, SBDError * _Nullable error))completionHandler DEPRECATED_ATTRIBUTE;

/**
 *  Registers the current device token to Sendbird.
 *
 *  @param devToken          Device token for APNS.
 *  @param completionHandler The handler block to execute.
 *
 *  @deprecated in 3.0.9
 */
+ (void)registerPushToken:(NSData * _Nonnull)devToken
        completionHandler:(nullable void (^)(NSDictionary * _Nullable response, SBDError * _Nullable error))completionHandler DEPRECATED_ATTRIBUTE;

/**
 *  Unregisters the current device token from Sendbird.
 *
 *  @param devToken          Device token for APNS.
 *  @param completionHandler The handler block to execute.
 */
+ (void)unregisterPushToken:(NSData * _Nonnull)devToken
          completionHandler:(nullable void (^)(NSDictionary * _Nullable response, SBDError * _Nullable error))completionHandler;

/**
 *  Unregisters all device tokens for the current user from Sendbird.
 *
 *  @param completionHandler The handler block to execute.
 */
+ (void)unregisterAllPushTokenWithCompletionHandler:(nullable void (^)(NSDictionary * _Nullable response, SBDError * _Nullable error))completionHandler;

/**
 *  Gets the pending push token for PushKit.
 *
 *  @return Returns the pending push token for PushKit.
 *
 *  @since 3.0.132
 */
+ (nullable NSData *)getPendingPushKitToken;

/**
 *  Registers the current device token for PushKit to Sendbird.
 *
 *  @param devToken          Device token for PushKit.
 *  @param unique            If YES, register device token after removing exsiting all device tokens of the current user. If NO, just add the device token.
 *  @param completionHandler The handler block to execute. `status` is the status for push token registration. It is defined in `SBDPushTokenRegistrationStatus`. `SBDPushTokenRegistrationStatusSuccess` represents the `devToken` is registered. `SBDPushTokenRegistrationStatusPending` represents the `devToken` is not registered because the connection is not established, so this method has to be invoked with `getPendingPushToken` method after the connection. The `devToken` is retrived by `getPendingPushToken`. `SBDPushTokenRegistrationStatusError` represents the push token registration is failed.
 *  @since 3.0.132
 */
+ (void)registerDevicePushKitToken:(NSData * _Nonnull)devToken
                            unique:(BOOL)unique
                 completionHandler:(nullable void (^)(SBDPushTokenRegistrationStatus status, SBDError * _Nullable error))completionHandler;

/**
*  Unregisters the current device token for PushKit from Sendbird.
*
*  @param devToken          Device token for PushKit.
*  @param completionHandler The handler block to execute.
*
*  @since 3.0.132
*/
+ (void)unregisterPushKitToken:(NSData * _Nonnull)devToken
             completionHandler:(nullable void (^)(NSDictionary * _Nullable response, SBDError * _Nullable error))completionHandler;

/**
 *  Unregisters all device tokens for PushKit for the current user from Sendbird.
 *
 *  @param completionHandler The handler block to execute.
 *
 *  @since 3.0.132
 */
+ (void)unregisterAllPushKitTokenWithCompletionHandler:(nullable void (^)(NSDictionary * _Nullable response, SBDError * _Nullable error))completionHandler;

/**
 *  Requests device push tokens list of current user after the token.
 *
 *  @param token  The token used to get next pagination of deive push tokens.
 *  @param pushTokenType  The enum type to represent the type of push token.
 *  @param completionHandler  The handler block to be executed after requests. This block has no return value and takes 5 arguments that are device push token list, push token type you are requesting, boolean that indicates having next pagination, token to be used next pagination and error.
 *
 *  @since 3.0.134
 */
+ (void)getMyPushTokensByToken:(nullable NSString *)token
                 pushTokenType:(SBDPushTokenType)pushTokenType
             completionHandler:(nonnull SBDGetPushTokensHandler)completionHandler;

#pragma mark - block
/**
 *  Blocks the specified user.
 *
 *  @param userId            The user ID to be blocked.
 *  @param completionHandler The handler block to execute. `blockedUser` is the blocked user by the current user.
 */
+ (void)blockUserId:(NSString * _Nonnull)userId
  completionHandler:(nullable void (^)(SBDUser * _Nullable blockedUser, SBDError * _Nullable error))completionHandler;

/**
 *  Blocks the specified user.
 *
 *  @param user              The user to be blocked.
 *  @param completionHandler The handler block to execute. `blockedUser` is the blocked user by the current user.
 */
+ (void)blockUser:(SBDUser * _Nonnull)user completionHandler:(nullable void (^)(SBDUser * _Nullable blockedUser, SBDError * _Nullable error))completionHandler;

/**
 *  Unblocks the specified user.
 *
 *  @param userId            The user ID which was blocked.
 *  @param completionHandler The handler block to execute.
 */
+ (void)unblockUserId:(NSString * _Nonnull)userId
    completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/**
 *  Unblocks the specified user.
 *
 *  @param user              The user who was blocked.
 *  @param completionHandler The handler block to execute.
 */
+ (void)unblockUser:(SBDUser * _Nonnull)user
  completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

#pragma mark - push preference
/**
 *  Sets Do-not-disturb.
 *  This method make snooze(or stop snooze) repeatedly.
 *  If you want to snooze specific period, use `setSnoozePeriodEnable:startTimestamp:endTimestamp:completionHandler:]`.
 *
 *  @param enable            Enables or not.
 *  @param startHour         Start hour.
 *  @param startMin          Start minute.
 *  @param endHour           End hour.
 *  @param endMin            End minute.
 *  @param timezone          Sets timezone.
 *  @param completionHandler The handler block to execute.
 */
+ (void)setDoNotDisturbWithEnable:(BOOL)enable
                        startHour:(int)startHour
                         startMin:(int)startMin
                          endHour:(int)endHour
                           endMin:(int)endMin
                         timezone:(NSString * _Nonnull)timezone
                completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/**
 *  Gets Do-not-disturb.
 *
 *  @param completionHandler The handler block to execute.
 */
+ (void)getDoNotDisturbWithCompletionHandler:(nullable void (^)(BOOL isDoNotDisturbOn, int startHour, int startMin, int endHour, int endMin, NSString * _Nonnull timezone, SBDError * _Nullable error))completionHandler;

/**
 *  Makes a current user snooze/receive remote push notification in specific duration.
 *  If you use `[SBDMain setDoNotDisturbWithEnable:startHour:startMin:endHour:endMin:timezone:completionHandler:]` method as well, both methods are applied together.
 *  Keep in mind snoozing(or stop snoozing) is applied from this method *only once*, not repeatedly.
 *  If you want to snooze(do not disturb) repeatedly, use `[SBDMain setDoNotDisturbWithEnable:startHour:startMin:endHour:endMin:timezone:completionHandler:]`.
 *
 *  @param enabled  Enabled means snooze remote push notification in duration. If set to disabled, current user can receive remote push notification.
 *  @param startTimestamp Unix timestamp to start snooze.
 *  @param endTimestamp  Unix timestamp to end snooze.
 *  @param completionHandler  The handler block to execute when setting notification snoozed is complete.
 *
 *  @since 3.0.128
 */
+ (void)setSnoozePeriodEnable:(BOOL)enabled
               startTimestamp:(long long)startTimestamp
                 endTimestamp:(long long)endTimestamp
            completionHandler:(nullable SBDErrorHandler)completionHandler;

/**
 *  Requests whether the current user snooze remote push notification.
 *
 *  @param completionHandler  The handler block to execute when setting notification snoozed is complete.
 *
 *  @since 3.0.128
 */
+ (void)getSnoozePeriod:(nonnull SBDSnoozePeriodHandler)completionHandler;

/**
 *  Changes a setting that decides which push notification for the current user to receive in all of the group channel.
 *
 *  @param pushTriggerOption  The options to choose which push notification for the current user to receive.
 *  @param completionHandler  The handler block to execute when setting a push trigger option of the current user is completed.
 *
 *  @since 3.0.128
 */
+ (void)setPushTriggerOption:(SBDPushTriggerOption)pushTriggerOption
           completionHandler:(nullable SBDErrorHandler)completionHandler;

/**
 *  Requests a setting that decides which push notification for the current user to receive in all of the group channel.
 *
 *  @param completionHandler  The handler block to execute when getting a push trigger of the current user is completed.
 *
 *  @since 3.0.128
 */
+ (void)getPushTriggerOptionWithCompletionHandler:(nonnull SBDPushTriggerOptionHandler)completionHandler;

/**
 Sets push sound
 
 @param sound Push sound
 @param completionHandler The handler block to be executed after set push sound. This block has no return value and takes an argument that is an error made when there is something wrong to set it.
 */
+ (void)setPushSound:(NSString * _Nonnull)sound
   completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;


/**
 Gets push shound
 
 @param completionHandler The handler block to execute.
 */
+ (void)getPushSoundWithCompletionHandler:(nullable void (^)(NSString * _Nullable sound, SBDError * _Nullable error))completionHandler;


/**
 Sets a push template of the current user.
 
 @param name The name of push template. It can be `SBD_PUSH_TEMPLATE_DEFAULT` or `SBD_PUSH_TEMPLATE_ALTERNATIVE`.
 @param completionHandler The handler block to execute.
 */
+ (void)setPushTemplateWithName:(NSString * _Nonnull)name
              completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;


/**
 Gets a push template of the current user.
 
 @param completionHandler The handler block to execute. The `name` is the current user's push template.
 */
+ (void)getPushTemplateWithCompletionHandler:(nullable void (^)(NSString * _Nullable name, SBDError * _Nullable error))completionHandler;


/**
 Starts reconnection explictly. The `SBDConnectionDelegate` delegates will be invoked by the reconnection process.
 
 @return Returns YES if there is the data to be used for reconnection.
 */
+ (BOOL)reconnect;

/**
 Gets mime type of file.
 
 @param file File to get mime type.
 @return Returns mime type of the file.
 */
+ (nullable NSString *)getMimeType:(NSData * _Nullable)file;


/**
 Turns on or off the reconnection by network awareness.
 
 @param onOff If YES, the reconnection by network Awareness is turned.
 */
+ (void)setNetworkAwarenessReconnection:(BOOL)onOff;

/**
 Sets group channel invitation preference for auto acceptance.
 
 @param autoAccept If YES, the current user will accept the group channel invitation automatically.
 @param completionHandler The handler block to execute.
 */
+ (void)setChannelInvitationPreferenceAutoAccept:(BOOL)autoAccept
                               completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;


/**
 Gets group channel inviation preference for auto acceptance.
 
 @param completionHandler The handler block to execute.
 */
+ (void)getChannelInvitationPreferenceAutoAcceptWithCompletionHandler:(nullable void (^)(BOOL autoAccept, SBDError * _Nullable error))completionHandler;

#pragma mark - User Event
+ (nullable id<SBDUserEventDelegate>)userEventDelegateForIdentifier:(NSString * _Nonnull)identifier;

+ (void)addUserEventDelegate:(id<SBDUserEventDelegate> _Nonnull)delegate
                  identifier:(NSString * _Nonnull)identifier;

+ (void)removeUserEventDelegateForIdentifier:(NSString * _Nonnull)identifier;

+ (void)removeAllUserEventDelegates;

#pragma mark - Friend List
+ (nullable SBDFriendListQuery *)createFriendListQuery;

+ (void)addFriendsWithUserIds:(NSArray<NSString *> * _Nonnull)userIds
            completionHandler:(nullable void (^)(NSArray<SBDUser *> * _Nullable users, SBDError * _Nullable error))completionHandler;

+ (void)deleteFriendWithUserId:(NSString * _Nonnull)userId
             completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

+ (void)deleteFriendsWithUserIds:(NSArray<NSString *> * _Nonnull)userIds
               completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

+ (void)deleteFriendWithDiscovery:(NSString * _Nonnull)discoveryKey
                completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

+ (void)deleteFriendsWithDiscoveries:(NSArray<NSString *> * _Nonnull)discoveryKeys
                   completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

+ (void)uploadFriendDiscoveries:(NSDictionary<NSString *, NSString *> * _Nonnull)discoveryKeyAndNames
              completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

+ (void)getFriendChangeLogsByToken:(NSString * _Nullable)token
                 completionHandler:(nullable void (^)(NSArray<SBDUser *> * _Nullable updatedUsers, NSArray<NSString *> * _Nullable deletedUserIds, BOOL hasMore, NSString * _Nullable token, SBDError * _Nullable error))completionHandler;

#pragma mark - Channel List
/**
 *  Marks as read all group channels of the current user.
 *
 *  @param completionHandler The handler block to execute.
 */
+ (void)markAsReadAllWithCompletionHandler:(nullable void (^)(SBDError *_Nullable error))completionHandler;

/**
 *  Marks as read some group channels of the current user.
 *
 *  @param channelUrls The array list with channel urls to be marked as read.
 *  @param completionHandler The handler block to execute.
 */
+ (void)markAsReadWithChannelUrls:(NSArray <NSString *> * _Nonnull)channelUrls
                completionHandler:(nullable void (^)(SBDError *_Nullable error))completionHandler;

#pragma mark - Group Channel
/**
 *  Gets the number of group channel with the filter.
 *
 *  @param memberStateFilter The member state of the current user in the channels that are counted.
 *  @param completionHandler The handler block to execute.
 *
 *  @since 3.0.116
 */
+ (void)getChannelCountWithMemberStateFilter:(SBDMemberStateFilter)memberStateFilter
                           completionHandler:(nonnull void (^)(NSUInteger groupChannelCount, SBDError * _Nullable error))completionHandler;

/**
 *  Gets the total unread channel count of all group channels.
 *
 *  @param completionHandler The handler block to execute. The `unreadCount` is the total count of unread channels in all of group channel which the current is a member.
 *
 *  @since 3.0.116
 */
+ (void)getTotalUnreadChannelCountWithCompletionHandler:(nonnull void (^)(NSUInteger unreadCount, SBDError * _Nullable error))completionHandler;

/**
 *  Gets the number of unread messages in group channels.
 *
 *  @param completionHandler The handler block to execute. The `unreadCount` is the total count of unread messages in all of group channel which the current is a member.
 *
 *  @since 3.0.116
 */
+ (void)getTotalUnreadMessageCountWithCompletionHandler:(nullable void (^)(NSUInteger unreadCount, SBDError * _Nullable error))completionHandler;

/**
 *  Gets the total unread message count of the channels with filters of params.
 *
 *  @param params             The instance of parameters to filter.
 *  @param completionHandler  The handler block to be executed after getting total unread message count. This block has no return value and takes two argument, the one is the number of unread message and the other is error.
 *
 *  @since 3.0.116
 */
+ (void)getTotalUnreadMessageCountWithParams:(nonnull SBDGroupChannelTotalUnreadMessageCountParams *)params
                           completionHandler:(nonnull void (^)(NSUInteger unreadCount, SBDError * _Nullable error))completionHandler;

/**
 *  Get unread counts of message and invitation counts in super and non_super channels.
 *
 *  @param key  bitmask key composed of super/non_super unread message count, super/non_super invitation count.
 *  @param completionHandler  The handler block to be executed after getting unread item count. This block has no return value and takes two argument. the one is type of SBDUnreadItemCount that contains unsinged interger for count you requested. the other is an error made when there is something wrong to response.
 *
 *  @since 3.0.116
 */
+ (void)getUnreadItemCountWithKey:(SBDUnreadItemKey)key
                completionHandler:(nonnull void(^)(SBDUnreadItemCount * _Nullable count, SBDError * _Nullable error))completionHandler;

+ (NSInteger)getSubscribedTotalUnreadMessageCount;
+ (NSInteger)getSubscribedCustomTypeTotalUnreadMessageCount;
+ (NSInteger)getSubscribedCustomTypeUnreadMessageCountWithCustomType:(nonnull NSString *)customType;

/// Marks as delivered a group channel of the current user.
/// @param channelUrl The channel URL.
/// @since 3.0.162
/// @deprecated 3.0.185
/// @note The client doesn't have to call this method any longer.
+ (void)markAsDeliveredWithChannelUrl:(nonnull NSString *)channelUrl
DEPRECATED_ATTRIBUTE;

#pragma mark - channel change logs
/**
 *  Requests updated channels and deleted channel URLs since a certain time. A certain time is decided by a token. And the results contain empty channels.
 *
 *  @param token  The token used to get next pagination of changelogs.
 *  @param customTypes  The list of custom types to request. If not set, requests my group channels regardless of custom type.
 *  @param completionHandler  The handler type of `SBDChannelChangeLogsHandler` block to execute. The `updatedChannels` is the channels that were updated. The `deletedChannelUrls` is the list of the deleted channel URLs. If there are more changelogs that are not returned yet, the `hasMore` is YES. The `token` can be used to get more changedlogs.
 *
 *  @since 3.0.123
 *  @deprecated in 3.0.182 Use `getMyGroupChannelChangeLogsByToken:params:completionHandler` instead
 */
+ (void)getMyGroupChannelChangeLogsByToken:(nullable NSString *)token
                               customTypes:(nullable NSArray <NSString *> *)customTypes
                         completionHandler:(nonnull SBDChannelChangeLogsHandler)completionHandler DEPRECATED_ATTRIBUTE;

/**
 *  Requests updated channels and deleted channel URLs since a certain time. A certain time is decided by a token.
 *
 *  @param token  The token used to get next pagination of changelogs.
 *  @param customTypes  The list of custom types to request. If not set, requests my group channels regardless of custom type.
 *  @param includeEmptyChannel  Bool value that filters a result whether include empty channels, not contained any messages.
 *  @param completionHandler  The handler type of `SBDChannelChangeLogsHandler` block to execute. The `updatedChannels` is the channels that were updated. The `deletedChannelUrls` is the list of the deleted channel URLs. If there are more changelogs that are not returned yet, the `hasMore` is YES. The `token` can be used to get more changedlogs.
 *
 *  @since 3.0.131
 *  @deprecated in 3.0.182 Use `getMyGroupChannelChangeLogsByToken:params:completionHandler` instead
 */
+ (void)getMyGroupChannelChangeLogsByToken:(nullable NSString *)token
                               customTypes:(nullable NSArray<NSString *> *)customTypes
                       includeEmptyChannel:(BOOL)includeEmptyChannel
                         completionHandler:(nonnull SBDChannelChangeLogsHandler)completionHandler DEPRECATED_ATTRIBUTE;

/**
 *  Requests updated channels and deleted channel URLs since a certain time. A certain time is decided by a token.
 *
 *  @param token  The token used to get next pagination of changelogs.
 *  @param params  the parameter object that filters a result. See `SBDGroupChannelChangeLogsParams` for more detail
 *  @param completionHandler  The handler type of `SBDChannelChangeLogsHandler` block to execute. The `updatedChannels` is the channels that were updated. The `deletedChannelUrls` is the list of the deleted channel URLs. If there are more changelogs that are not returned yet, the `hasMore` is YES. The `token` can be used to get more changedlogs.
 *
 *  @since 3.0.182
 */
+ (void)getMyGroupChannelChangeLogsByToken:(nullable NSString *)token
                                    params:(nullable SBDGroupChannelChangeLogsParams *)params
                         completionHandler:(nonnull SBDChannelChangeLogsHandler)completionHandler;

/**
 *  Requests updated channels and deleted channel URLs since the timestamp. And the results contain empty channels.
 *
 *  @param timestamp  The number of milli-seconds(msec). Requests changelogs from that time. This value must not be negative.
 *  @param customTypes  The list of custom types to request. If not set, requests all of my group channels.
 *  @param completionHandler  The handler type of `SBDChannelChangeLogsHandler` block to execute. The `updatedChannels` is the channels that were updated. The `deletedChannelUrls` is the list of the deleted channel URLs. If there are more changelogs that are not returned yet, the `hasMore` is YES. The `token` can be used to get more changedlogs.
 *
 *  @since 3.0.123
 *  @deprecated in 3.0.182 Use `getMyGroupChannelChangeLogsByTimestamp:params:completionHandler` instead
 */
+ (void)getMyGroupChannelChangeLogsByTimestamp:(long long)timestamp
                                   customTypes:(nullable NSArray <NSString *> *)customTypes
                             completionHandler:(nonnull SBDChannelChangeLogsHandler)completionHandler DEPRECATED_ATTRIBUTE;

/**
 *  Requests updated channels and deleted channel URLs since the timestamp.
 *
 *  @param timestamp  The number of milli-seconds(msec). Requests changelogs from that time. This value must not be negative.
 *  @param customTypes  The list of custom types to request. If not set, requests all of my group channels.
 *  @param includeEmptyChannel  Bool value that filters a result whether include empty channels, not contained any messages.
 *  @param completionHandler  The handler type of `SBDChannelChangeLogsHandler` block to execute. The `updatedChannels` is the channels that were updated. The `deletedChannelUrls` is the list of the deleted channel URLs. If there are more changelogs that are not returned yet, the `hasMore` is YES. The `token` can be used to get more changedlogs.
 *
 *  @since 3.0.131
 *  @deprecated in 3.0.182 Use `getMyGroupChannelChangeLogsByTimestamp:params:completionHandler` instead
 */
+ (void)getMyGroupChannelChangeLogsByTimestamp:(long long)timestamp
                                   customTypes:(nullable NSArray <NSString *> *)customTypes
                           includeEmptyChannel:(BOOL)includeEmptyChannel
                             completionHandler:(nonnull SBDChannelChangeLogsHandler)completionHandler DEPRECATED_ATTRIBUTE;

/**
 *  Requests updated channels and deleted channel URLs since the timestamp.
 *
 *  @param timestamp  The number of milli-seconds(msec). Requests changelogs from that time. This value must not be negative.
 *  @param params  the parameter object that filters a result. See `SBDGroupChannelChangeLogsParams` for more detail
 *  @param completionHandler  The handler type of `SBDChannelChangeLogsHandler` block to execute. The `updatedChannels` is the channels that were updated. The `deletedChannelUrls` is the list of the deleted channel URLs. If there are more changelogs that are not returned yet, the `hasMore` is YES. The `token` can be used to get more changedlogs.
 *
 *  @since 3.0.182
 */
+ (void)getMyGroupChannelChangeLogsByTimestamp:(long long)timestamp
                                        params:(nullable SBDGroupChannelChangeLogsParams *)params
                             completionHandler:(nonnull SBDChannelChangeLogsHandler)completionHandler;

#pragma mark - Emoji

/**
 *  Requests a emoji container which contains hash and list of emoji category.
 *
 *  @param completionHandler The handler block to execute after request is completed
 *
 *  @since 3.0.180
 */
+ (void)getAllEmojis:(nullable void (^)(SBDEmojiContainer * _Nullable container, SBDError * _Nullable error))completionHandler;

/**
 *  Requests updated channels and deleted channel URLs since the timestamp.
 *
 *  @param emojiKey The emoji key
 *  @param completionHandler The handler block to execute after request is completed
 *
 *  @since 3.0.180
 */
+ (void)getEmoji:(nonnull NSString *)emojiKey
completionHandler:(nullable void (^)(SBDEmoji * _Nullable emoji, SBDError * _Nullable error))completionHandler;

/**
 *  Requests updated channels and deleted channel URLs since the timestamp.
 *
 *  @param categoryId The category id
 *  @param completionHandler The handler block to execute after request is completed
 *
 *  @since 3.0.180
*/
+ (void)getEmojiCategory:(long long)categoryId
       completionHandler:(nullable void (^)(SBDEmojiCategory * _Nullable category, SBDError * _Nullable error))completionHandler;

#pragma mark - For Extension SDK

/**
 * Sendbird user agent information getter.
 */
+ (nonnull NSString *)getSBUserAgent;

/**
 * Used to set the version information of the Sendbird SDK extension.
 *
 * @param key Extension sdk's hidden key
 * @param version Extension sdk's version string
 */
+ (void)addExtension:(nonnull NSString *)key version:(nonnull NSString *)version;


#pragma mark - Application Info
/**
 * Gets information set in the Application.
 *
 * @since 3.0.180
 */
+ (nullable SBDAppInfo *)getAppInfo;

#pragma mark - App Group Support.
/// Sets the app group.
/// @param appGroup The app group.
/// @since 3.0.183
+ (void)setAppGroup:(nonnull NSString *)appGroup;

/// Marks as delivered with the payload of the remote notification.
/// @param payload The remote notification payload
/// @param completionHandler The handler block to execute
/// @since 3.0.183
+ (void)markAsDeliveredWithRemoteNotificationPayload:(nonnull NSDictionary *)payload
                                   completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

#pragma mark - Key for file encryption
/// Gets the key to authenticate the file URL. This has to be put into the HTTP header when the client needs to access it.
/// @return The key to authenticate the file URL
/// @since 3.0.194
+ (nullable NSString *)ekey;

@end

