//
//  SBDWebSocketEngineProtocol.h
//  SendBirdSDK
//
//  Created by Wooyoung Chung on 8/26/20.
//  Copyright © 2020 SENDBIRD.COM. All rights reserved.
//

#ifndef SBDWebSocketDelegate_h
#define SBDWebSocketDelegate_h

#import "SBDWebSocketTypes.h"

NS_ASSUME_NONNULL_BEGIN

@protocol SBDWebSocketEngine;

@protocol SBDWebSocketDelegate <NSObject>
@optional
/// Called when any message was received from a web socket.
/// This method is suboptimal and might be deprecated in a future release.
/// @param engine An instance of `SendBird_SRWebSocket` that received a message.
/// @param message   Received message. Either a `String` or `NSData`.
- (void)webSocket:(id<SBDWebSocketEngine>)engine didReceiveMessage:(id)message;

/// Called when a frame was received from a web socket.
/// @param engine An instance of `SendBird_SRWebSocket` that received a message.
/// @param string    Received text in a form of UTF-8 `String`.
- (void)webSocket:(id<SBDWebSocketEngine>)engine didReceiveMessageWithString:(NSString *)string;

/// Called when a frame was received from a web socket.
/// @param engine An instance of `SendBird_SRWebSocket` that received a message.
/// @param data      Received data in a form of `NSData`.
- (void)webSocket:(id<SBDWebSocketEngine>)engine didReceiveMessageWithData:(NSData *)data;

#pragma mark Status & Connection

/// Called when a given web socket was open and authenticated.
/// @param engine An instance of `SendBird_SRWebSocket` that was open.
- (void)webSocketDidOpen:(id<SBDWebSocketEngine>)engine;

/// Called when a given web socket encountered an error.
/// @param engine An instance of `SendBird_SRWebSocket` that failed with an error.
/// @param error     An instance of `NSError`.
- (void)webSocket:(id<SBDWebSocketEngine>)engine didFailWithError:(NSError *)error;

/// Called when a given web socket was closed.
/// @param engine An instance of `SendBird_SRWebSocket` that was closed.
/// @param code      Code reported by the server.
/// @param reason    Reason in a form of a String that was reported by the server or `nil`.
/// @param wasClean  Boolean value indicating whether a socket was closed in a clean state.
- (void)webSocket:(id<SBDWebSocketEngine>)engine
 didCloseWithCode:(SBDWebSocketStatusCode)code
           reason:(nullable NSString *)reason
         wasClean:(BOOL)wasClean;

/// Called on receive of a ping message from the server
/// @param engine An instance of `SendBird_SRWebSocket` that received a ping frame.
/// @param data      Payload that was received or `nil` if there was no payload.
- (void)webSocket:(id<SBDWebSocketEngine>)engine didReceivePingWithData:(nullable NSData *)data;

/// Called when a pong data was received in response to ping.
/// @param engine An instance of `SendBird_SRWebSocket` that received a pong frame.
/// @param pongData  Payload that was received or `nil` if there was no payload.
- (void)webSocket:(id<SBDWebSocketEngine>)engine didReceivePong:(nullable NSData *)pongData;

/// Sent before reporting a text frame to be able to configure if it shuold be convert to a UTF-8 String or passed as `NSData`.
/// If the method is not implemented - it will always convert text frames to String.
/// @param engine An instance of `SendBird_SRWebSocket` that received a text frame.
/// @return `YES` if text frame should be converted to UTF-8 String, otherwise - `NO`. Default: `YES`.
- (BOOL)webSocketShouldConvertTextFrameToString:(id<SBDWebSocketEngine>)engine;

@end


NS_ASSUME_NONNULL_END

#endif
