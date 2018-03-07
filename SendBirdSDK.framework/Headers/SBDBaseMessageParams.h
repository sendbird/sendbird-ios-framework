//
//  SBDBaseMessageParams.h
//  SendBirdSDK
//
//  Created by sendbird-young on 2018. 3. 5..
//  Copyright © 2018년 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SBDUser;

/**
 *  The `SBDBaseMessageParams` class represents the base class which has parameters to create a channel or update a channel. The `SBDUserMessageParams`, the `SBDFileMessageParams` are derived from this class.
 */
@interface SBDBaseMessageParams : NSObject

/**
 *  Message data. The default value is nil.
 *
 *  @since 3.0.90
 */
@property (copy, nonatomic, nullable) NSString *data;

/**
 *  Customize message's type to filter. The default value is nil.
 *
 *  @since 3.0.90
 */
@property (copy, nonatomic, nullable) NSString *customType;

/**
 *  Can mention to specific users. If this field is set and send a message with this, the message will be arrived to mention users. The default value is nil.
 *
 *  @since 3.0.90
 */
@property (copy, nonatomic, nullable) NSArray <NSString *> *mentionedUserIds;

/**
 *  Can set mentioned users with a list of users.
 *
 *  @since 3.0.90
 */
- (void)setMentionedUsers:(nonnull NSArray <SBDUser *> *)mentionedUsers;

@end
