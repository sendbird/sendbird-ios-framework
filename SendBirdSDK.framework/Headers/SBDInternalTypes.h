//
//  SBDInternalTypes.h
//  SendBirdSDK
//
//  Created by Jed Gyeong on 8/18/16.
//  Copyright © 2016 SENDBIRD.COM. All rights reserved.
//

#ifndef SBDInternalTypes_h
#define SBDInternalTypes_h

typedef NS_ENUM(NSInteger, SBDChannelMetaCountersUpdateMode) {
    SBDChannelUpdateModeSet = 0,
    SBDChannelUpdateModeIncrease = 1,
    SBDChannelUpdateModeDecrease = 2,
};

typedef NS_ENUM(NSInteger, SBDChannelEventCategory) {
    SBDChannelEventCategoryNone = 0,
    SBDChannelEventCategoryChannelJoin = 10000,
    SBDChannelEventCategoryChannelLeave = 10001,
    SBDChannelEventCategoryUpdateOperator = 10002,
    
    SBDChannelEventCategoryChannelInvite = 10020,
    SBDChannelEventCategoryChannelDeclineInvite = 10022,
    
    SBDChannelEventCategoryChannelEnter = 10102,
    SBDChannelEventCategoryChannelExit = 10103,
    
    SBDChannelEventCategoryChannelMute = 10201,
    SBDChannelEventCategoryChannelUnmute = 10200,
    
    SBDChannelEventCategoryChannelBan = 10601,
    SBDChannelEventCategoryChannelUnban = 10600,
    
    SBDChannelEventCategoryChannelFrozen = 10701,
    SBDChannelEventCategoryChannelUnfrozen = 10700,
    
    SBDChannelEventCategoryTypingStart = 10900,
    SBDChannelEventCategoryTypingEnd = 10901,
    
    SBDChannelEventCategoryChannelPropChanged = 11000,
    SBDChannelEventCategoryChannelDeleted = 12000,
    
    SBDChannelEventCategoryMetaDataChanged = 11100,
    SBDChannelEventCategoryMetaCounterChanged = 11200,
    
    SBDChannelEventCategoryChannelHidden = 13000,
    SBDChannelEventCategoryChannelUnhidden = 13001,
};

typedef NS_ENUM(NSInteger, SBDUserEventCategory) {
    SBDUserEventCategoryUserUnblock = 20000,
    SBDUserEventCategoryUserBlock = 20001,
    SBDUserEventCategoryUserFriendDiscoveryReady = 20900,
};

typedef NS_ENUM(NSUInteger, SBDUserListQueryType) {
    SBDUserListQueryTypeAllUser = 1,
    SBDUserListQueryTypeBlockedUsers = 2,
    SBDUserListQueryTypeOpenChannelParticipants = 3,
    SBDUserListQueryTypeOpenChannelMutedUsers = 4,
    SBDUserListQueryTypeOpenChannelBannedUsers = 5,
    SBDUserListQueryTypeFilteredUsers = 6,
};

typedef NS_ENUM(NSInteger, SBDLogLevel) {
    SBDLogLevelNone = 0,
    SBDLogLevelError = 1,
    SBDLogLevelWarning = 2,
    SBDLogLevelInfo = 3,
};

typedef NS_OPTIONS(NSUInteger, SBDChannelQueryIncludeOption) {
    SBDChannelQueryIncludeOptionNone                    = (1 << 0),
    SBDChannelQueryIncludeOptionEmptyChannel            = (1 << 1),
    SBDChannelQueryIncludeOptionMemberList              = (1 << 2),
    SBDChannelQueryIncludeOptionFrozenChannel           = (1 << 3),
    SBDChannelQueryIncludeOptionReadReceipt             = (1 << 4),
    SBDChannelQueryIncludeOptionDeliveryReceipt         = (1 << 5)
};

typedef NS_OPTIONS(NSUInteger, SBDMessageQueryIncludeOption) {
    SBDMessageQueryIncludeOptionNone                    = (1 << 0),
    SBDMessageQueryIncludeOptionMetaArray               = (1 << 1),
    SBDMessageQueryIncludeOptionReaction                = (1 << 2),
    SBDMessageQueryIncludeOptionReplies                 = (1 << 3),
    SBDMessageQueryIncludeOptionParentMessageText       = (1 << 4),
    SBDMessageQueryIncludeOptionThreadInfo              = (1 << 5)
};

typedef NS_ENUM(NSInteger, SBDApiRequestType) {
    SBDApiRequestTypePassive = 0,
    SBDApiRequestTypeActive = 1,
};

#endif /* SBDInternalTypes_h */
