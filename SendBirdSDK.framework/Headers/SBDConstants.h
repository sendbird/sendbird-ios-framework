//
//  SBDConstants.h
//  SendBirdSDK
//
//  Created by sendbird-young on 12/10/2018.
//  Copyright © 2018 SENDBIRD.COM. All rights reserved.
//

#ifndef SBDConstants_h
#define SBDConstants_h

#import <Foundation/Foundation.h>

@class SBDOpenChannel, SBDFileMessage, SBDError;

typedef void (^SBDOpenChannelHandler)(SBDOpenChannel * _Nullable channel, SBDError * _Nullable error);
typedef void (^SBDFileMessageHandler)(SBDFileMessage * _Nullable message, SBDError * _Nullable error);
typedef void (^SBDBinaryProgressHandler)(int64_t bytesSent, int64_t totalBytesSent, int64_t totalBytesExpectedToSend);

#endif /* SBDConstants_h */
