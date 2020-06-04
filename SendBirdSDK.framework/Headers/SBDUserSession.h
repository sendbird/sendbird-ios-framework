//
//  SBDUserSession.h
//  SendBirdSDK
//
//  Created by Jed Gyeong on 5/21/20.
//  Copyright © 2020 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SBDUserSession : NSObject

@property (class, strong, nullable) NSString *sessionKey;
@property (class, strong, nullable) NSString *eKey;

+ (void)setUserId:(nonnull NSString *)aUserId;
+ (void)clearSessionKey;
+ (void)clearEKey;
+ (NSString * _Nullable)decryptedSessionKey;
+ (void)setEncryptedSessionKey:(nullable NSString *)sessionKey;

@end
