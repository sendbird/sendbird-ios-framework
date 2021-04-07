//
//  SBDReaction.h
//  SendBirdSDK
//
//  Created by Jed Gyeong on 2/13/20.
//  Copyright © 2020 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>

/// Class to store the reaction info. The `SBDBaseMessage` object can have the `SBDReaction` object in `reactions` property.
/// @note This class is available in 3.0.169
@interface SBDReaction : NSObject

/// The reaction key.
/// @since 3.0.169
@property (strong, nonnull, readonly) NSString *key;

/// The users who add the reaction.
/// @since 3.0.169
@property (strong, nonnull, readonly, getter=getUserIds) NSArray<NSString *> *userIds;

/// The timestamp when the reaction is updated.
/// @since 3.0.169
@property (atomic, readonly) long long updatedAt;

@end
