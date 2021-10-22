//
//  SBDUpdatedVoteCount.h
//  SendBirdSDK
//
//  Created by Wooyoung Chung on 7/20/21.
//  Copyright © 2021 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBDMappable.h"
NS_ASSUME_NONNULL_BEGIN

@interface SBDUpdatedVoteCount : NSObject <SBDMappable>
@property (atomic, assign, readonly) long long optionId;
@property (atomic, assign, readonly) NSUInteger voteCount;

- (nonnull instancetype)init NS_UNAVAILABLE;
@end

NS_ASSUME_NONNULL_END
