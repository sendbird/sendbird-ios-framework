//
//   Copyright 2012 Square Inc.
//
//   Licensed under the Apache License, Version 2.0 (the "License");
//   you may not use this file except in compliance with the License.
//   You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
//   Unless required by applicable law or agreed to in writing, software
//   distributed under the License is distributed on an "AS IS" BASIS,
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permissions and
//   limitations under the License.
//

#import <Foundation/Foundation.h>
#import <Security/SecCertificate.h>

typedef NS_ENUM(NSInteger, SendBirdSRReadyState) {
    SENDBIRD_SR_CONNECTING   = 0,
    SENDBIRD_SR_OPEN         = 1,
    SENDBIRD_SR_CLOSING      = 2,
    SENDBIRD_SR_CLOSED       = 3,
};

typedef enum SendBirdSRStatusCode : NSInteger {
    SendBirdSRStatusCodeNormal = 1000,
    SendBirdSRStatusCodeGoingAway = 1001,
    SendBirdSRStatusCodeProtocolError = 1002,
    SendBirdSRStatusCodeUnhandledType = 1003,
    // 1004 reserved.
    SendBirdSRStatusNoStatusReceived = 1005,
    // 1004-1006 reserved.
    SendBirdSRStatusCodeInvalidUTF8 = 1007,
    SendBirdSRStatusCodePolicyViolated = 1008,
    SendBirdSRStatusCodeMessageTooBig = 1009,
} SendBirdSRStatusCode;

@class SendBirdSRWebSocket;

extern NSString *const SendBirdSRWebSocketErrorDomain;
extern NSString *const SendBirdSRHTTPResponseErrorKey;

#pragma mark - SendBirdSRWebSocketDelegate

@protocol SendBirdSRWebSocketDelegate;

#pragma mark - SendBirdSRWebSocket

@interface SendBirdSRWebSocket : NSObject <NSStreamDelegate>

@property (nonatomic, weak) id <SendBirdSRWebSocketDelegate> delegate;

@property (nonatomic, readonly) SendBirdSRReadyState readyState;
@property (nonatomic, readonly, retain) NSURL *url;


@property (nonatomic, readonly) CFHTTPMessageRef receivedHTTPHeaders;

// Optional array of cookies (NSHTTPCookie objects) to apply to the connections
@property (nonatomic, readwrite) NSArray * requestCookies;

// This returns the negotiated protocol.
// It will be nil until after the handshake completes.
@property (nonatomic, readonly, copy) NSString *protocol;

// Protocols should be an array of strings that turn into Sec-WebSocket-Protocol.
- (id)initWithURLRequest:(NSURLRequest *)request protocols:(NSArray *)protocols allowsUntrustedSSLCertificates:(BOOL)allowsUntrustedSSLCertificates;
- (id)initWithURLRequest:(NSURLRequest *)request protocols:(NSArray *)protocols;
- (id)initWithURLRequest:(NSURLRequest *)request;

// Some helper constructors.
- (id)initWithURL:(NSURL *)url protocols:(NSArray *)protocols allowsUntrustedSSLCertificates:(BOOL)allowsUntrustedSSLCertificates;
- (id)initWithURL:(NSURL *)url protocols:(NSArray *)protocols;
- (id)initWithURL:(NSURL *)url;

// Delegate queue will be dispatch_main_queue by default.
// You cannot set both OperationQueue and dispatch_queue.
- (void)setDelegateOperationQueue:(NSOperationQueue*) queue;
- (void)setDelegateDispatchQueue:(dispatch_queue_t) queue;

// By default, it will schedule itself on +[NSRunLoop SR_networkRunLoop] using defaultModes.
- (void)scheduleInRunLoop:(NSRunLoop *)aRunLoop forMode:(NSString *)mode;
- (void)unscheduleFromRunLoop:(NSRunLoop *)aRunLoop forMode:(NSString *)mode;

// SendBirdSRWebSockets are intended for one-time-use only.  Open should be called once and only once.
- (void)open;

- (void)close;
- (void)closeWithCode:(NSInteger)code reason:(NSString *)reason;

// Send a UTF8 String or Data.
- (void)send:(id)data;

// Send Data (can be nil) in a ping message.
- (void)sendPing:(NSData *)data;

@end

#pragma mark - SendBirdSRWebSocketDelegate

@protocol SendBirdSRWebSocketDelegate <NSObject>

// message will either be an NSString if the server is using text
// or NSData if the server is using binary.
- (void)webSocket:(SendBirdSRWebSocket *)webSocket didReceiveMessage:(id)message;

@optional

- (void)webSocketDidOpen:(SendBirdSRWebSocket *)webSocket;
- (void)webSocket:(SendBirdSRWebSocket *)webSocket didFailWithError:(NSError *)error;
- (void)webSocket:(SendBirdSRWebSocket *)webSocket didCloseWithCode:(NSInteger)code reason:(NSString *)reason wasClean:(BOOL)wasClean;
- (void)webSocket:(SendBirdSRWebSocket *)webSocket didReceivePong:(NSData *)pongPayload;

@end

#pragma mark - NSURLRequest (SendBirdCertificateAdditions)

@interface NSURLRequest (SendBirdCertificateAdditions)

@property (nonatomic, retain, readonly) NSArray *SR_SSLPinnedCertificates;

@end

#pragma mark - NSMutableURLRequest (SendBirdCertificateAdditions)

@interface NSMutableURLRequest (SendBirdCertificateAdditions)

@property (nonatomic, retain) NSArray *SR_SSLPinnedCertificates;

@end

#pragma mark - NSRunLoop (SendBirdSRWebSocket)

@interface NSRunLoop (SendBirdSRWebSocket)

+ (NSRunLoop *)SR_networkRunLoop;

@end
