//
//  SBDSessionDelegate.h
//  SendBirdSDK
//
//  Created by Jed Gyeong on 10/9/20.
//  Copyright © 2020 SENDBIRD.COM. All rights reserved.
//

#ifndef SBDSessionDelegate_h
#define SBDSessionDelegate_h

NS_ASSUME_NONNULL_BEGIN

@protocol SBDSessionDelegate <NSObject>

@required
/// App needs to fetch a new token.
/// Pass on the new (retrieved) token to SDK via `success(NEW_TOKEN)`
/// or `fail()` if fetch failed.
/// In case when app decides not to refresh the session for this user,
/// they should call `success(nil)`.
/// @param success Call this block method after retrieving a new token. In case when app decides not to refresh the session for this user, they should call this with `nil`.
/// @param fail Call this block method when failed to retrieve a new token.
/// @since 3.0.205
- (void)sessionTokenDidRequireWithSuccessCompletion:(void (^_Nonnull)(NSString * _Nullable sessionToken))success
                                     failCompletion:(void (^_Nonnull)(void))fail;

/// Called when the SDK can't refresh the session.
/// App should force a user to a login page to connect again.
/// @since 3.0.205
- (void)sessionWasClosed;

@optional
/// Called when session key is expired.
/// @since 3.0.205
/// @deprecated 3.0.236
- (void)sessionWasExpired
DEPRECATED_ATTRIBUTE;

/// Called when SDK refreshed the session key.
/// @since 3.0.205
- (void)sessionWasRefreshed;

/// Called when the SDK run into an error while refreshing the session key.
/// @param error Error object
/// @since 3.0.205
- (void)sessionDidHaveError:(nonnull SBDError *)error;

@end

NS_ASSUME_NONNULL_END

#endif /* SBDSessionDelegate_h */
