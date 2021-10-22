//
//  SBDPollOptionVoterResult.h
//  SendBirdSDK
//
//  Created by Wooyoung Chung on 7/8/21.
//  Copyright © 2021 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBDMappable.h"

@class SBDUser;

NS_ASSUME_NONNULL_BEGIN

/// Represents a voter result for an option
/// @since 3.0.232
@interface SBDPollOptionVoterResult : NSObject <SBDMappable>

/// Number of voter
@property (atomic, assign, readonly) NSUInteger voteCount;

/// First page Voters list - could be partial
@property (nonatomic, strong, readonly) NSArray<SBDUser *> *voters;

- (nonnull instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
