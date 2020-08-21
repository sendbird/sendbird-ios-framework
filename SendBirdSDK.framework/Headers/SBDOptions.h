//
//  SBDOptions.h
//  SendBirdSDK
//
//  Created by Wooyoung Chung on 5/6/20.
//  Copyright © 2020 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Represents operation options.
 */
@interface SBDOptions : NSObject

/**
 Gets the value whether the sender information of `sender` of `SBDUserMessage` or `SBDFileMessage` such as nickname and profile url will be returned as the latest user's or not.
 
 @return If YES, the sender is the latest information.
 */
+ (BOOL)useMemberAsMessageSender;

/**
 If set <code>YES</code>, the sender information of `sender` of `SBDUserMessage` or `SBDFileMessage` such as nickname and profile url will be returned as the latest user's. Otherwise, the information will be the value of the message creation time.
 
 @param tf <code>YES</code> or <code>NO</code>.
 */
+ (void)setUseMemberAsMessageSender:(BOOL)tf;


/**
 Sets the timeout for connection. If there is a timeout error frequently, set the longer timeout than default value. The default is 10 seconds.
 
 @param timeout The timeout for connection.
 */
+ (void)setConnectionTimeout:(NSInteger)timeout;

/**
 *  Sets a term of typing indicator throttling in group channel.
 *  After this throttling interval from typing indicator started (or ended), You can re-start (or re-end) typing indicator.
 *  If you call start (or end) again in this interval, the call will be ignored.
 *
 *  @param interval  A time interval that can renew typing indicator. can be RANGE from 1.0 to 9.0.
 *  @since 3.0.100
 */
+ (void)setTypingIndicatorThrottle:(NSTimeInterval)interval;

/**
 Sets the authentication timeout managed by `authenticateWithAuthInfoRequestHandler:completionHandler:` of `SBDConnectionManager`. The default value is 10 seconds.

 @param timeout Timeout in seconds. It must be greater than 0. Otherwise, the default value (10 seconds) will be set.
 @since 3.0.109
 */
+ (void)setAuthenticationTimeout:(NSTimeInterval)timeout;

/**
 Sets the timeout for file transfer. This value affects the methods that send a binary data including sending file messages, creating and updating channels.

 @param timeout Timeout in seconds. It must be greater than 0. Otherwise, the default value (60 seconds) will be set.
 @since 3.0.130
 */
+ (void)setFileTransferTimeout:(NSInteger)timeout;

/// Sets the websocket response timeout used in sending/receiving commmands by websocket.
/// The value should be between 5 seconds and 300 seconds (5 minutes).
/// The default value is 10 seconds.
/// @param timeout Timeout in seconds.
/// @since 3.0.199
+ (void)setWebSocketResponseTimeout:(NSInteger)timeout;

@end

