//
//  SBDPollData.h
//  SendBirdSDK
//
//  Created by Wooyoung Chung on 6/22/21.
//  Copyright © 2021 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBDMappable.h"

NS_ASSUME_NONNULL_BEGIN

/// Represents a poll data
/// @since 3.0.232
@interface SBDPollData : NSObject <SBDMappable, NSCopying>

/// Text representation
@property (nonatomic, strong, readonly) NSString *text;

- (nonnull instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
