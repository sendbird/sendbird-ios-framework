//
//  SBDWebSocketEngine.h
//  SendBirdSDK
//
//  Created by Wooyoung Chung on 4/1/21.
//  Copyright © 2021 SENDBIRD.COM. All rights reserved.
//

#ifndef SBDWebSocketEngine_h
#define SBDWebSocketEngine_h

#import "SBDWebSocketTypes.h"

@protocol SBDWebSocketDelegate;

@protocol SBDWebSocketEngine <NSObject>
/// Sets delegate for socket
/// @param delegate SBDWebSocketDelegate instance
@optional
- (void)setDelegate:(nullable id<SBDWebSocketDelegate>)delegate;

/// Sets delegate for dispatch queue
/// @param queue dispatch_queue_t object
@optional
- (void)setDelegateDispatchQueue:(dispatch_queue_t _Nullable)queue;

/// Starts websocket communication with request
/// @param request URL object represents host
@optional
- (void)start:(nonnull NSURLRequest *)request;

/// Stops websocket communication
/// @param closeCode SBDWebSocketStatusCode to indicate close reason
@optional
- (void)stop:(SBDWebSocketStatusCode)closeCode;

/// Forces to stop websocket communication
@optional
- (void)forceStop;

/// Sends a data to the server
/// @param data Data object to be sent
@optional
- (void)sendData:(nullable NSData *)data
   completion:(nullable void (^)(NSError * _Nullable))completion;

/// Sends a string to the server
/// @param string String object to be sent
@optional
- (void)sendString:(nonnull NSString *)string
   completion:(nullable void (^)(NSError * _Nullable))completion;

/// Returns websocket state
/// @return SBDWebSocketState state
@optional
- (SBDWebSocketState)readyState;

/// Clear websocket
@optional
- (void)clear;

@end


#endif /* SBDWebSocketEngine_h */
