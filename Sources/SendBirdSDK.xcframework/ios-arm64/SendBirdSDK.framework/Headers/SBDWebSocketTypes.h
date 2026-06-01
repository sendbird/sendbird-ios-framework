//
//  SBDWebSocketTypes.h
//  SendBirdSDK
//
//  Created by Wooyoung Chung on 4/1/21.
//  Copyright © 2021 SENDBIRD.COM. All rights reserved.
//

#ifndef SBDWebSocketTypes_h
#define SBDWebSocketTypes_h

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, SBDWebSocketStatusCode) {
    // 0-999: Reserved and not used.
    SBDWebSocketStatusCodeNormal = 1000,
    SBDWebSocketStatusCodeGoingAway = 1001,
    SBDWebSocketStatusCodeProtocolError = 1002,
    SBDWebSocketStatusCodeUnhandledType = 1003,
    // 1004 reserved.
    SBDWebSocketStatusCodeNoStatusReceived = 1005,
    SBDWebSocketStatusCodeAbnormal = 1006,
    SBDWebSocketStatusCodeInvalidUTF8 = 1007,
    SBDWebSocketStatusCodePolicyViolated = 1008,
    SBDWebSocketStatusCodeMessageTooBig = 1009,
    SBDWebSocketStatusCodeMissingExtension = 1010,
    SBDWebSocketStatusCodeInternalError = 1011,
    SBDWebSocketStatusCodeServiceRestart = 1012,
    SBDWebSocketStatusCodeTryAgainLater = 1013,
    // 1014: Reserved for future use by the WebSocket standard.
    SBDWebSocketStatusCodeTLSHandshake = 1015,
    // 1016-1999: Reserved for future use by the WebSocket standard.
    // 2000-2999: Reserved for use by WebSocket extensions.
    // 3000-3999: Available for use by libraries and frameworks. May not be used by applications. Available for registration at the IANA via first-come, first-serve.
    // 4000-4999: Available for use by applications.
};

typedef NS_ENUM(NSUInteger, SBDFrameOpCode) {
    SBDFrameOpCodeContinueFrame = 0x0,
    SBDFrameOpCodeTextFrame = 0x1,
    SBDFrameOpCodeBinaryFrame = 0x2,
    SBDFrameOpCodeConnectionClose = 0x8,
    SBDFrameOpCodePing = 0x9,
    SBDFrameOpCodePong = 0xA,
    SBDFrameOpCodeUnknown = 100
};

typedef NS_ENUM(NSInteger, SBDWebSocketState) {
    SBDWebSocketStateConnecting   = 0,
    SBDWebSocketStateOpen         = 1,
    SBDWebSocketStateClosing      = 2,
    SBDWebSocketStateClosed       = 3,
};


#endif /* SBDWebSocketTypes_h */
