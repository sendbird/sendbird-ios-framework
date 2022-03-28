//
//  SBDCollectionEventSource.h
//  SendBirdSDK
//
//  Created by Jed Gyeong on 5/3/21.
//  Copyright © 2021 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>

/// Channel sources that represents where the channel object comes from.
/// @since 3.1.0
typedef NS_ENUM(NSUInteger, SBDCollectionEventSource) {
    SBDCollectionEventSourceMessageChangelog = 0,
    SBDCollectionEventSourceMessageFill = 1,
    SBDCollectionEventSourceChannelChangelog = 2,
    SBDCollectionEventSourceLocalMessagePendingCreated = 3,
    SBDCollectionEventSourceLocalMessageFailed = 4,
    SBDCollectionEventSourceLocalMessageCanceled = 5,
    SBDCollectionEventSourceLocalMessageResendStarted = 6,
    SBDCollectionEventSourceEventMessageSent = 100,
    SBDCollectionEventSourceEventMessageReceived = 101,
    SBDCollectionEventSourceEventMessageUpdated = 102,
    SBDCollectionEventSourceEventMessageDeleted = 103,
    SBDCollectionEventSourceEventReactionUpdated = 104,
    SBDCollectionEventSourceEventThreadInfoUpdated = 105,
    SBDCollectionEventSourceEventMention = 106,
    SBDCollectionEventSourceEventChannelChanged = 107,
    SBDCollectionEventSourceEventChannelMemberCountChanged = 108,
    SBDCollectionEventSourceEventChannelFrozen = 109,
    SBDCollectionEventSourceEventChannelUnfrozen = 110,
    SBDCollectionEventSourceEventChannelHidden = 111,
    SBDCollectionEventSourceEventChannelDeleted = 112,
    SBDCollectionEventSourceEventOperatorUpdated = 113,
    SBDCollectionEventSourceEventTypingStatusUpdated = 114,
    SBDCollectionEventSourceEventDeliveryReceiptUpdated = 115,
    SBDCollectionEventSourceEventReadReceiptUpdated = 116,
    SBDCollectionEventSourceEventUserReceivedInvitation = 117,
    SBDCollectionEventSourceEventUserDeclinedInvitation = 118,
    SBDCollectionEventSourceEventUserJoined = 119,
    SBDCollectionEventSourceEventUserMuted = 120,
    SBDCollectionEventSourceEventUserUnmuted = 121,
    SBDCollectionEventSourceEventUserLeft = 122,
    SBDCollectionEventSourceEventUserBanned = 123,
    SBDCollectionEventSourceEventUserUnbanned = 124,
    SBDCollectionEventSourceEventMetaDataCreated = 125,
    SBDCollectionEventSourceEventMetaDataUpdated = 126,
    SBDCollectionEventSourceEventMetaDataDeleted = 127,
    SBDCollectionEventSourceEventMetaCounterCreated = 128,
    SBDCollectionEventSourceEventMetaCounterUpdated = 129,
    SBDCollectionEventSourceEventMetaCounterDeleted = 130,
};
