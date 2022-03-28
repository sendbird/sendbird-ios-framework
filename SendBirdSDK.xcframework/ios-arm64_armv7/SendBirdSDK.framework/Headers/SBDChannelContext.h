//
//  SBDChannelContext.h
//  SendBirdSDK
//
//  Created by Jed Gyeong on 5/3/21.
//  Copyright © 2021 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SBDCollectionEventSource.h"

NS_ASSUME_NONNULL_BEGIN

/// Represents what happened to the channels.
/// @since 3.1.0
@interface SBDChannelContext : NSObject

/// @since 3.1.0
@property (atomic) SBDCollectionEventSource source;

/// Initializes with the channel source.
/// @param source Channel source.
/// @return SBDChannelContext object.
/// @since 3.1.0
- (instancetype)initWithChannelSource:(SBDCollectionEventSource)source;

/// Checks whether the context is from an event or not.
/// @return If YES, the context is from an event.
/// @since 3.1.0
- (BOOL)isFromEvent;

@end

NS_ASSUME_NONNULL_END
