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

/**
 *  Message text.
 *
 *  @since 3.0.90
 */
@property (copy, nonatomic, nonnull) NSString *message;

/**
 *  The target languages that the message will be translated into.
 *
 *  @since 3.0.90
 */
@property (copy, nonatomic, nullable) NSArray <NSString *> *targetLanguages;

/// Links a poll with message, to unlink set it -1l
/// @since 3.0.232
@property (atomic, assign) long long pollId;

/// The template for the message that has the mentioned users.
/// @since 3.1.11
@property (strong, nullable) NSString *mentionedMessageTemplate;

/**
 *  Don't use this initializer.
 *  Initializes an instance of a user message params.
 *
 *  @see -initWithMessage:
 *  @return nil as this method is unavailable.
 *  @since 3.0.90
 */
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wnullability"
- (nonnull instancetype)init NS_UNAVAILABLE;
#pragma clang diagnostic pop
    
/**
 *  Initializes an instance of a user message params with message.
 *
 *  @param message The message to text.
 *  @return An initialized user message params, used to send user message.
 *  @since 3.0.90
 */
- (nullable instancetype)initWithMessage:(nonnull NSString *)message;

@end
