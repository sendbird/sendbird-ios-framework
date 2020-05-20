//
//  SBDThreadInfoUpdateEvent.h
//  SendBirdSDK
//
//  Created by Jed Gyeong on 4/29/20.
//  Copyright © 2020 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SBDThreadInfo.h"
#import "SBDTypes.h"

/// An object that is returned through the event handler when a threaded reply is added or deleted. This object should be applied to the parent message.
/// @note This class is available from 3.0.181
@interface SBDThreadInfoUpdateEvent : NSObject

/// An object that has the information about threaded messages.
/// @since 3.0.181
@property (strong, readonly, nonnull) SBDThreadInfo *threadInfo;

/// The unique ID of the message that contains thread information.
/// @since 3.0.181
@property (atomic, readonly) long long targetMessageId;

/// The unique URL of the channel where threaded messages belong.
/// @since 3.0.181
@property (strong, readonly, nonnull) NSString *channelUrl;

/// The type of the channel where threaded messages belong.
/// @since 3.0.181
@property (atomic, readonly) SBDChannelType channelType;

@end
