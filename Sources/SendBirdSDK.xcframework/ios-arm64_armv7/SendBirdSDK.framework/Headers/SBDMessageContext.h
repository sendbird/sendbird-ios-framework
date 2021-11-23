//
//  SBDMessageContext.h
//  SendBirdSDK
//
//  Created by Jed Gyeong on 5/27/21.
//  Copyright © 2021 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SBDCollectionEventSource.h"
#import "SBDTypes.h"

NS_ASSUME_NONNULL_BEGIN

/// Represents what happened to the messages.
/// @since 3.1.0
@interface SBDMessageContext : NSObject

/// @since 3.1.0
@property (atomic) SBDCollectionEventSource source;

/// @since 3.1.0
@property (atomic) SBDMessageSendingStatus messageSendingStatus;

/// Checks whether the context is from an event or not.
/// @return If YES, the context is from an event.
/// @since 3.1.0
- (BOOL)isFromEvent;

@end

NS_ASSUME_NONNULL_END
