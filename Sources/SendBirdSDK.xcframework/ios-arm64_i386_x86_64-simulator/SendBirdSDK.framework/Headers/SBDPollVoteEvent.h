//
//  SBDPollVoteEvent.h
//  SendBirdSDK
//
//  Created by Wooyoung Chung on 5/24/21.
//  Copyright © 2021 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SBDMappable.h"
#import "SBDTypes.h"

NS_ASSUME_NONNULL_BEGIN

@class SBDUpdatedVoteCount;

/// Represents a vote event on a poll
/// @since 3.0.232
@interface SBDPollVoteEvent : NSObject <SBDMappable>

/// Poll id associated with this vote event
@property (atomic, assign, readonly) long long pollId;

/// Updated poll options
@property (nonatomic, strong, readonly) NSArray<SBDUpdatedVoteCount *> *updatedVoteCounts;

/// Timestamp for this vote event
@property (atomic, assign, readonly) long long timestamp;

- (nullable instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
