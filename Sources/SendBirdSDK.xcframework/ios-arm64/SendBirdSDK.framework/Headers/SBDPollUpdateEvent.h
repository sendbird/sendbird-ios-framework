//
//  SBDPollUpdateEvent.h
//  SendBirdSDK
//
//  Created by Wooyoung Chung on 5/24/21.
//  Copyright © 2021 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBDMappable.h"
#import "SBDTypes.h"

NS_ASSUME_NONNULL_BEGIN

@class SBDPoll;

/// Represents an poll update event
/// @since 3.0.232
@interface SBDPollUpdateEvent : NSObject <SBDMappable, NSCopying>

/// Updated poll
@property (nonatomic, strong, readonly) SBDPoll *poll;

/// Poll status 
@property (atomic, readonly) SBDPollStatus status;

/// Timestamps when this event occurs 
@property (atomic, assign, readonly) long long timestamp;

- (nonnull instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
