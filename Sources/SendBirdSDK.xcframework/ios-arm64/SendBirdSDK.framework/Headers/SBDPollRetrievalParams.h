//
//  SBDPollRetrievalParams.h
//  SendBirdSDK
//
//  Created by Wooyoung Chung on 7/22/21.
//  Copyright © 2021 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Represents a object to retrieve poll object
/// @since 3.0.232
@interface SBDPollRetrievalParams : NSObject

/// Channel url where the poll exists in
@property (nonatomic, strong) NSString *channelUrl;

/// Poll id
@property (atomic, assign) long long pollId;

/// Shows limited users on each option in this poll. Default is false
@property (atomic, assign) BOOL showPartialVoters;

@end

NS_ASSUME_NONNULL_END
