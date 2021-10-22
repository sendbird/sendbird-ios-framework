//
//  SBDPollOption.h
//  SendBirdSDK
//
//  Created by Wooyoung Chung on 4/28/21.
//  Copyright © 2021 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBDMappable.h"
#import "SBDConstants.h"

NS_ASSUME_NONNULL_BEGIN

/// Represents an option for poll
/// @since 3.0.232
@interface SBDPollOption : NSObject <SBDMappable, NSCopying>

/// Poll id
@property (atomic, assign, readonly) long long pollId;

/// Option id
@property (atomic, assign, readonly) long long optionId;

/// The text to represent the option
@property (nonatomic, strong, readonly) NSString *text;

/// Number of votes casted on the option
@property (atomic, assign, readonly) NSInteger voteCount;

/// ID of the user who has created the option
@property (nonatomic, strong, readonly) NSString *createdBy;

/// Unix timestamp at which the option is created (millisecond)
@property (atomic, assign, readonly) long long createdAt;

/// Unix timestamp at which the option is updated (millisecond)
@property (atomic, assign, readonly) long long updatedAt;

/// Unix timestamp at which last vote occurs either cast or cancel (millisecond)
@property (atomic, assign, readonly) long long lastVotedAt;

/// Users who casted the vote on this option, this field is only available when you fetch poll with `showPartialVoters` option
@property (nonatomic, strong, nullable, readonly) NSArray<SBDUser *> *partialVoters;

- (nonnull instancetype)init NS_UNAVAILABLE;

/// Gets an option with id
/// @param pollId poll id
/// @param optionId option id
/// @param channelUrl channelUrl that poll is belonged to
/// @param completionHandler completion block
+ (void)getWithPollId:(long long)pollId
             optionId:(long long)optionId
           channelUrl:(NSString *)channelUrl
    completionHandler:(SBDPollOptionHandler)completionHandler
NS_SWIFT_NAME(get(pollId:optionId:channelUrl:completionHandler:));

/// Update this option with text
/// @param text option text
/// @param completionHandler completion block
- (void)updateWithText:(NSString *)text
     completionHandler:(SBDPollHandler)completionHandler
NS_SWIFT_NAME(update(text:completionHandler:));

/// Deletes this option
/// @param completionHandler completion block
- (void)deleteWithCompletionHandler:(nullable SBDErrorHandler)completionHandler
NS_SWIFT_NAME(delete(completionHandler:));

@end

NS_ASSUME_NONNULL_END
