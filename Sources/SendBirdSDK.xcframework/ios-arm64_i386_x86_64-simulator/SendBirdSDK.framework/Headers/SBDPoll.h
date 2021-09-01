//
//  SBDPoll.h
//  SendBirdSDK
//
//  Created by Wooyoung Chung on 4/28/21.
//  Copyright © 2021 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SBDConstants.h"
#import "SBDMappable.h"

@class SBDPollOption;
@class SBDPollParams;
@class SBDPollDetails;
@class SBDPollOptionVoterResult;
@class SBDPollUpdateEvent, SBDPollVoteEvent;
@class SBDPollRetrievalParams;

NS_ASSUME_NONNULL_BEGIN

/// Represents a poll that users can vote
/// @since 3.0.232
@interface SBDPoll : NSObject <SBDMappable, NSCopying>

/// Poll id
@property (atomic, assign, readonly) long long pollId;

/// Title of this poll
@property (nonatomic, strong, readonly) NSString *title;

/// Detail information of this poll
/// @note this property can be nil if `includePollDetails` option is NO when fetching message list
@property (nonatomic, strong, readonly, nullable) SBDPollDetails *details;

- (nullable instancetype)init NS_UNAVAILABLE;

/// Creates a poll with given params
/// @param completionHandler completion block
+ (void)createWithParams:(SBDPollParams *)params
       completionHandler:(SBDPollHandler)completionHandler
NS_SWIFT_NAME(create(params:completionHandler:));

/// Gets a poll
/// @param params `SBDPollRetrievalParams` object
/// @param completionHandler completion block
+ (void)getWithParams:(SBDPollRetrievalParams *)params
    completionHandler:(SBDPollHandler)completionHandler
NS_SWIFT_NAME(get(params:completionHandler:));

/// Updates this poll with params
/// @param params SBDPollParams object to update the poll
/// @param completionHandler completion block
- (void)updateWithParams:(SBDPollParams *)params
       completionHandler:(SBDPollHandler)completionHandler
NS_SWIFT_NAME(update(params:completionHandler:));

/// Closes this poll
/// @param completionHandler completion block
- (void)closeWithCompletionHandler:(SBDPollHandler)completionHandler
NS_SWIFT_NAME(close(completionHandler:));

/// Deletes this poll
/// @param completionHandler completion block
- (void)deleteWithCompletionHandler:(nullable SBDErrorHandler)completionHandler
NS_SWIFT_NAME(delete(completionHandler:));

/// Adds an option to this poll
/// @param text option text
/// @param channelUrl channel url where this poll is included
/// @param completionHandler completion block
- (void)addOptionWithText:(NSString *)text
               channelUrl:(NSString *)channelUrl
        completionHandler:(SBDPollHandler)completionHandler
NS_SWIFT_NAME(addOption(text:channelUrl:completionHandler:));

/// Votes on this poll
/// @param optionIds number array that contains option ids
/// @param completionHandler completion block
- (void)voteWithOptionIds:(NSArray<NSNumber *> *)optionIds
               channelUrl:(NSString *)channelUrl
        completionHandler:(SBDPollHandler)completionHandler
NS_SWIFT_NAME(vote(optionIds:channelUrl:completionHandler:));

@end

NS_ASSUME_NONNULL_END
