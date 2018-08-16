//
//  SBDConnectionManager.h
//  SendBirdSDK
//
//  Created by Jed Gyeong on 6/26/18.
//  Copyright © 2018 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBDUser.h"
#import "SBDError.h"
#import "SBDTypes.h"


/**
 Network delegate.
 To add or remove this delegate, use `addNetworkDelegate:identifier:`, `removeNetworkDelegateForIdentifier:`, and `removeAllNetworkDelegates`.
 @since 3.0.109
 */
@protocol SBDNetworkDelegate <NSObject>

@required

/**
 A delegate method for when connection is reestablished.
 */
- (void)didReconnect;

@end

/**
 @since 3.0.109
 */
@interface SBDAuthInfoRequestHandler : NSObject

@property (nonatomic, copy, nullable) void (^userAuthenticationWithHostInfoBlock)(void (^ _Nullable completionHandler)(NSString * _Nullable userId, NSString * _Nullable accessToken, NSString * _Nullable apiHost, NSString * _Nullable wsHost));
@property (nonatomic, copy, nullable) void (^userAuthenticationBlock)(void (^ _Nullable completionHandler)(NSString * _Nullable userId, NSString * _Nullable accessToken));

- (nullable instancetype)init;

@end

@interface SBDConnectionManager : NSObject

/**
 Authenticate must be invoked before authentication timeout. To set the timeout, use `setAuthenticationTimeout:` of `SBDOptions`.

 @param authInfoRequestHandler SBDAuthInfoRequestHandler handler.
 @param completionHandler completion handler.
 @since 3.0.109
 */
+ (void)authenticateWithAuthInfoRequestHandler:(SBDAuthInfoRequestHandler * _Nullable)authInfoRequestHandler
                      completionHandler:(nullable void (^)(SBDUser * _Nullable user, SBDError * _Nullable error))completionHandler;

/**
 Adds a network delegate. All added delegates will be notified when events occurs.

 @param delegate Delegate to be added.
 @param identifier ID of delegate to be added.
 @since 3.0.109
 */
+ (void)addNetworkDelegate:(id<SBDNetworkDelegate> _Nonnull)delegate
                identifier:(NSString * _Nonnull)identifier;

/**
 Removes a network delegate. The deleted delegate no longer be notified.

 @param identifier ID of delegate to be removed.
 @since 3.0.109
 */
+ (void)removeNetworkDelegateForIdentifier:(NSString * _Nonnull)identifier;

/**
 Removes all network delegates added by `addNetworkDelegate:identifier:`.
 @since 3.0.109
 */
+ (void)removeAllNetworkDelegates;

@end
