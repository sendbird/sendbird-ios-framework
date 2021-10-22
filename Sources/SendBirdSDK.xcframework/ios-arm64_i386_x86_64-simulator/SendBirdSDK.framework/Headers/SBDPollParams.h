//
//  SBDPollParams.h
//  SendBirdSDK
//
//  Created by Wooyoung Chung on 4/28/21.
//  Copyright © 2021 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SBDPollOption;
@class SBDPollData;

NS_ASSUME_NONNULL_BEGIN

/// Represents a parameter object to create or update poll object
/// @since 3.0.232
@interface SBDPollParams : NSObject

/// Title of this poll
@property (nonatomic, strong) NSString *title;

/// An additional text to accompany the poll.
/// Can be used to provide explanations for incorrect quiz answers
@property (nonatomic, strong, nullable) NSString *text;

/// Possible options for which a user can vote
/// @note this property is only valid when creating a poll, ignored when updating a poll
@property (nonatomic, strong) NSArray<NSString *> *options;

/// Whether to make the votes anonymous. Default is NO
@property (atomic, assign) BOOL isAnonymous;

/// Whether to allow user-suggested options. Default is NO
@property (atomic, assign) BOOL allowUserSuggestion;

/// Whether to allow multiple vote casting. Default is NO
@property (atomic, assign) BOOL allowMutipleVotes;

/// Unix timestamp at which the poll has closed or will close (millisecond)
@property (atomic, assign) long long closeAt;

@end

NS_ASSUME_NONNULL_END
