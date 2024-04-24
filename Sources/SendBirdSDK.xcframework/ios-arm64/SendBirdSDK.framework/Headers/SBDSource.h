//
//  SBDSource.h
//  SendBirdSDK
//
//  Created by Jed Gyeong on 5/3/21.
//  Copyright © 2021 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>

/// Channel sources that represents where the channel object comes from.
/// @since 3.0.227
typedef NS_ENUM(NSUInteger, SBDSource) {
    SBDSourceMessageChangelog = 0,
    SBDSourceMessageFill = 1,
    SBDSourceChannelChangelog = 2,
    SBDSourceChannelFill = 3,
    SBDSourceEventMessageSent = 4,
    SBDSourceEventMessageReceived = 5,
    SBDSourceEventMessageUpdated = 6,
    SBDSourceEventMessageDeleted = 7,
    SBDSourceEventReactionUpdated = 8,
    SBDSourceEventThreadInfoUpdated = 9,
    SBDSourceEventMention = 10,
    SBDSourceEventChannelChanged = 11,
    SBDSourceEventChannelMemberCountChanged = 12,
    SBDSourceEventChannelFrozen = 13,
    SBDSourceEventChannelUnfrozen = 14,
    SBDSourceEventChannelHidden = 15,
    SBDSourceEventChannelDeleted = 16,
    SBDSourceEventOperatorUpdated = 17,
    SBDSourceEventTypingStatusUpdated = 18,
    SBDSourceEventDeliveryReceiptUpdated = 19,
    SBDSourceEventReadReceiptUpdated = 20,
    SBDSourceEventUserReceivedInvitation = 21,
    SBDSourceEventUserDeclinedInvitation = 22,
    SBDSourceEventUserJoined = 23,
    SBDSourceEventUserMuted = 24,
    SBDSourceEventUserUnmuted = 25,
    SBDSourceEventUserLeft = 26,
    SBDSourceEventUserBanned = 27,
    SBDSourceEventUserUnbanned = 28,
};
