//
//  SBDAppleCriticalAlertOptions.h
//  SendBirdSDK
//
//  Created by Jed Gyeong on 3/18/21.
//  Copyright © 2021 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SBDMappable.h"

NS_ASSUME_NONNULL_BEGIN

/// Represents the options for the Apple Critical Alert.
/// The `SBDBaseMessageParams` object may have the `SBDAppleCriticalAlertOptions` object as an `appleCriticalAlertOptions` property.
/// When the message that has this options is received by the iOS device, the message is displayed as a critical alert.
/// See the [`Generating a Remote Notification`](https://developer.apple.com/documentation/usernotifications/setting_up_a_remote_notification_server/generating_a_remote_notification) for the details.
/// @since 3.0.221
@interface SBDAppleCriticalAlertOptions : NSObject<SBDMappable>

/// The name of a sound file in the iOS app. The default value is `default`.
/// @since 3.0.221
@property (strong, nullable) NSString *name;

/// The volume for the critical alert's sound.
/// Set this to a value between 0.0 (silent) and 1.0 (full volume).
/// The default value is `1.0`.
/// @since 3.0.221
@property (atomic) float volume;

@end

NS_ASSUME_NONNULL_END
