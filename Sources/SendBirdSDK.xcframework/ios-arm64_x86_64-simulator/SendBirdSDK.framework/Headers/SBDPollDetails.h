//
//  SBDPollDetails.h
//  SendBirdSDK
//
//  Created by Wooyoung Chung on 5/27/21.
//  Copyright © 2021 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBDMappable.h"
#import "SBDTypes.h"

@class SBDPollOption, SBDPollData;

NS_ASSUME_NONNULL_BEGIN

/// Represents a poll details information
/// @since 3.0.232
@interface SBDPollDetails : NSObject <SBDMappable, NSCopying>

/// An additional data to accompany the poll.
@property (nonatomic, strong, readonly, nullable) SBDPollData *data;

/// Number of voters who casted a vote on the poll
@property (atomic, assign, readonly) NSInteger voterCount;

/// Possible options for which a user can vote
@property (nonatomic, strong, readonly) NSArray<SBDPollOption *> *options;

/// Current user's voted option list
@property (nonatomic, strong, readonly) NSArray<NSNumber *> *votedOptionIds;

/// User id who creates this poll
@property (nonatomic, strong, readonly, nullable) NSString *createdBy;

/// Whether to make the votes anonymous
@property (atomic, assign, readonly) BOOL isAnonymous;

/// Whether to allow user-suggested options
@property (atomic, assign, readonly) BOOL allowUserSuggestion;

/// Whether to allow multiple vote casting
@property (atomic, assign, readonly) BOOL allowMutipleVotes;

/// Unix timestamp at which the poll is created (millisecond)
@property (atomic, assign, readonly) long long createdAt;

/// Unix timestamp at which the poll is updated (millisecond)
@property (atomic, assign, readonly) long long updatedAt;

/// Unix timestamp at which the poll has closed or will close (second)
@property (atomic, assign, readonly) long long closeAt;

/// Whether the poll is closed
@property (nonatomic, assign, readonly) SBDPollStatus status;

- (nonnull instancetype)init NS_UNAVAILABLE;

- (void)overwriteWithDetail:(nonnull SBDPollDetails *)otherDetails;

@end

NS_ASSUME_NONNULL_END
