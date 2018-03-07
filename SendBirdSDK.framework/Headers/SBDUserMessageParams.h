//
//  SBDUserMessageParams.h
//  SendBirdSDK
//
//  Created by sendbird-young on 2018. 3. 5..
//  Copyright © 2018년 SENDBIRD.COM. All rights reserved.
//

#import "SBDBaseMessageParams.h"

/**
 *  The `SBDUserMessageParams` class is used to send a user message in `SBDBaseChannel`. This is a child class of `SBDBaseMessageParams`.
 */
@interface SBDUserMessageParams : SBDBaseMessageParams

@property (copy, nonatomic, nonnull) NSString *message;

@property (copy, nonatomic, nullable) NSArray <NSString *> *targetLanguages;

- (nullable instancetype)init NS_UNAVAILABLE;
- (nullable instancetype)initWithMessage:(nonnull NSString *)message NS_DESIGNATED_INITIALIZER;

@end
