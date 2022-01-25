//
//  SBDTypes.h
//  SendBirdSDK
//
//  Created by Jed Gyeong on 6/24/16.
//  Copyright © 2016 SENDBIRD.COM. All rights reserved.
//

#ifndef SBDTypes_h
#define SBDTypes_h

#define CHANNEL_TYPE_OPEN @"open"
#define CHANNEL_TYPE_GROUP @"group"

#define SBD_PUSH_TEMPLATE_DEFAULT @"default"
#define SBD_PUSH_TEMPLATE_ALTERNATIVE @"alternative"

/**
 *  The order type for `SBDGroupChannelListQuery`.
 */
typedef NS_ENUM(NSInteger, SBDGroupChannelListOrder) {
    /**
     *  Chronological order for group channel.
     */
    SBDGroupChannelListOrderChronological           = 0,
    /**
     *  Lastest last message order for group channel.
     */
    SBDGroupChannelListOrderLatestLastMessage       = 1,
    /**
     *  Alphabetical name order for group channel.
     */
    SBDGroupChannelListOrderChannelNameAlphabetical = 2,
    
    /**
     *  Alphabetical value order of a selected key in meta data for group channel.
     */
    SBDGroupChannelListOrderChannelMetaDataValueAlphabetical = 3,
};

/**
 *  The order type for `SBDPublicGroupChannelListQuery`.
 */
typedef NS_ENUM(NSUInteger, SBDPublicGroupChannelListOrder) {
    /**
     *  Chronological order for public group channel.
     */
    SBDPublicGroupChannelListOrderChronological           = 0,
    /**
     *  Alphabetical name order for public group channel.
     */
    SBDPublicGroupChannelListOrderChannelNameAlphabetical = 2,
    
    /**
     *  Alphabetical value order of a selected key in meta data for public group channel.
     */
    SBDPublicGroupChannelListOrderChannelMetaDataValueAlphabetical = 3,
};

/**
 *  Error types.
 */
typedef NS_ENUM(NSInteger, SBDErrorCode) {
    // RESTful API Errors
    SBDErrorInvalidParameterValueString = 400100,
    SBDErrorInvalidParameterValueNumber = 400101,
    SBDErrorInvalidParameterValueList = 400102,
    SBDErrorInvalidParameterValueJson = 400103,
    SBDErrorInvalidParameterValueBoolean = 400104,
    SBDErrorInvalidParameterValueRequired = 400105,
    SBDErrorInvalidParameterValuePositive = 400106,
    SBDErrorInvalidParameterValueNegative = 400107,
    SBDErrorNonAuthorized = 400108,
    SBDErrorTokenExpired = 400109,
    SBDErrorInvalidChannelUrl = 400110,
    SBDErrorInvalidParameterValue = 400111,
    SBDErrorUnusableCharacterIncluded = 400151,
    SBDErrorNotFoundInDatabase = 400201,
    SBDErrorDuplicatedData = 400202,
    SBDErrorReachedMaxCount = 400203,
    
    SBDErrorUserDeactivated = 400300,
    SBDErrorUserNotExist = 400301,
    SBDErrorAccessTokenNotValid = 400302,
    SBDErrorAuthUnknownError = 400303,
    SBDErrorAppIdNotValid = 400304,
    SBDErrorAuthUserIdTooLong = 400305,
    SBDErrorAuthPlanQuotaExceeded = 400306,
    SBDErrorSessionKeyExpired = 400309,
    SBDErrorSessionTokenRevoked = 400310,
    
    SBDErrorInvalidApiToken = 400401,
    SBDErrorParameterMissing = 400402,
    SBDErrorInvalidJsonBody = 400403,
    
    SBDErrorConflict = 409000,

    SBDErrorInternalServerError = 500901,
    SBDErrorRateLimitExceeded = 500910,
    SBDErrorServiceUnavailable = 503000,
    
    // SDK Internal Errors
    SBDErrorUnknownError = 800000,
    SBDErrorInvalidInitialization = 800100,
    SBDErrorConnectionRequired = 800101,
    SBDErrorConnectionCanceled = 800102,
    SBDErrorInvalidParameter = 800110,
    SBDErrorNetworkError = 800120,
    SBDErrorNetworkRoutingError = 800121,
    SBDErrorMalformedData = 800130,
    SBDErrorMalformedErrorData = 800140,
    SBDErrorWrongChannelType = 800150,
    SBDErrorMarkAsReadRateLimitExceeded = 800160,
    SBDErrorQueryInProgress = 800170,
    SBDErrorAckTimeout = 800180,
    SBDErrorLoginTimeout = 800190,
    SBDErrorWebSocketConnectionClosed = 800200,
    SBDErrorWebSocketConnectionFailed = 800210,
    SBDErrorRequestFailed = 800220,
    SBDErrorFileUploadCancelFailed = 800230,
    SBDErrorFileUploadCanceled = 800240,
    SBDErrorFileUploadTimeout = 800250,
    SBDErrorFileSizeLimitExceeded = 800260,
    SBDErrorTimerWasExpired = 800301,
    SBDErrorTimerWasAlreadyDone = 800302,
    SBDErrorPendingError = 800400,
    SBDErrorPassedInvalidAccessToken = 800500,
    SBDErrorSessionKeyRefreshSucceeded = 800501,
    SBDErrorSessionKeyRefreshFailed = 800502,
    SBDErrorLocalDatabase = 800700,
    
    // WS Error
    SBDErrorSocketLoginRequired = 900010,
    SBDErrorSocketUserNotMember = 900020,
    SBDErrorSocketUserDeactivated = 900021,
    SBDErrorSocketUserNotOwnerOfMessage = 900022,
    SBDErrorSocketUserSendMessageNotAllowed = 900023,
    SBDErrorSocketInvalidMentionForMessage = 900025,
    SBDErrorSocketInvalidPushOptionForMessage = 900026,
    SBDErrorSocketTooManyMetaKeyForMessage = 900027,
    SBDErrorSocketTooManyMetaValueForMessage = 900028,
    SBDErrorSocketTooManyMetaArrayForMessage = 900029,
    SBDErrorSocketGuestNotAllowed = 900030,
    SBDErrorSocketMutedUserInApplicationSendMessageNotAllowed = 900040,
    SBDErrorSocketMutedUserInChannelSendMessageNotAllowed = 900041,
    SBDErrorSocketChannelFrozen = 900050,
    SBDErrorSocketProfanityMessageBlocked = 900060,
    SBDErrorSocketBannedUrlsBlocked = 900061,
    SBDErrorSocketRestrictedDomainBlocked = 900065,
    SBDErrorSocketModeratedFileBlocked = 900066,
    SBDErrorSocketEnterDeletedChannel = 900070,
    SBDErrorSocketBlockedUserReceiveMessageNotAllowed = 900080,
    SBDErrorSocketDeactivatedUserReceiveMessageNotAllowed = 900081,
    SBDErrorSocketWrongChannelType = 900090,
    SBDErrorSocketBannedUserSendMessageNotAllowed = 900100,
    SBDErrorSocketTooManyMessages = 900200,
    SBDErrorSocketMessageNotFound = 900300,
    SBDErrorSocketTooManyParticipants = 900400,
    SBDErrorSocketChannelNotFound = 900500,
    SBDErrorSocketPollNotFound = 901200,
};

/**
 *  Connection state
 */
typedef NS_ENUM(NSUInteger, SBDWebSocketConnectionState) {
    /**
     *  Connecting
     */
    SBDWebSocketConnecting = 0,
    /**
     *  Open
     */
    SBDWebSocketOpen = 1,
    /**
     *  Closed
     */
    SBDWebSocketClosed = 3,
    /**
     *  Closing
     *  @deprecated 3.0.115. Has been replaced by SBDWebSocketClosed
     */
    SBDWebSocketClosing DEPRECATED_ATTRIBUTE = SBDWebSocketClosed,
};

/**
 *  User connection statuses for `SBDUser`.
 */
typedef NS_ENUM(NSUInteger, SBDUserConnectionStatus) {
    /**
     *  For unavailable user.
     */
    SBDUserConnectionStatusNonAvailable = 0,
    /**
     *  For on-line user.
     */
    SBDUserConnectionStatusOnline = 1,
    /**
     *  For off-line user.
     */
    SBDUserConnectionStatusOffline = 2,
};

/**
 *  Channel types.
 */
typedef NS_ENUM(NSUInteger, SBDChannelType) {
    /**
     *  Open channel.
     */
    SBDChannelTypeOpen = 0,
    /**
     *  Group channel.
     */
    SBDChannelTypeGroup = 1,
};

/**
 *  Push token registration statuses
 */
typedef NS_ENUM(NSUInteger, SBDPushTokenRegistrationStatus) {
    /**
     *  Registration succeeded.
     */
    SBDPushTokenRegistrationStatusSuccess = 0,
    /**
     *  Registration is pending.
     */
    SBDPushTokenRegistrationStatusPending = 1,
    /**
     *  Registartion is failed.
     */
    SBDPushTokenRegistrationStatusError = 2,
};

/**
 *  The query type for `SBDGroupChannelListQuery`.
 */
typedef NS_ENUM(NSInteger, SBDGroupChannelListQueryType) {
    SBDGroupChannelListQueryTypeAnd = 0,
    SBDGroupChannelListQueryTypeOr = 1,
};


/**
 Message type for filtering
 */
typedef NS_ENUM(NSInteger, SBDMessageTypeFilter) {
    /**
     * Filter of all messages.
     */
    SBDMessageTypeFilterAll = 0,
    /**
     *  Filter of user message.
     */
    SBDMessageTypeFilterUser = 1,
    /**
     *  Filter of file message.
     */
    SBDMessageTypeFilterFile = 2,
    /**
     *  Filter of admin message.
     */
    SBDMessageTypeFilterAdmin = 3,
};


/**
 Member state filter for group channel list query and group channel count
 */
typedef NS_ENUM(NSInteger, SBDMemberStateFilter) {
    /**
     * Filter of all member states.
     */
    SBDMemberStateFilterAll                 = 0,
    /**
     * Filter of joined state only.
     */
    SBDMemberStateFilterJoinedOnly          = 1,
    /**
     * Filter of invited state only. This contains SBDMemberStateFilterByFriend, SBDMemberStateFilterByNonFriend.
     */
    SBDMemberStateFilterInvitedOnly         = 2,
    /**
     * Filter of invited by friend state only.
     */
    SBDMemberStateFilterInvitedByFriend     = 3,
    /**
     * Filter of invited by non-friend state only.
     */
    SBDMemberStatefilterInvitedByNonFriend  = 4
};


/**
 Member state in group channel.
 */
typedef NS_ENUM(NSInteger, SBDMemberState) {
    /**
     * Filter of joined members in a group channel.
     */
    SBDMemberStateJoined = 0,
    /**
     * Filter of invited members in a group channel.
     */
    SBDMemberStateInvited = 1,
    /**
     * Filter of members neither joined or invited in a group channel.
     */
    SBDMemberStateNone = 2,
};

/**
 *  Channel filter for super mode in group channels.
 */
typedef NS_ENUM(NSUInteger, SBDGroupChannelSuperChannelFilter) {
    /**
     * Without filter
     */
    SBDGroupChannelSuperChannelFilterAll       = 0,
    /**
     * Filter super group channel.
     */
    SBDGroupChannelSuperChannelFilterSuper     = 1,
    /**
     * Filter non-super group channel.
     */
    SBDGroupChannelSuperChannelFilterNonSuper  = 2,
    /**
     * Filter only broadcast group channel.
     */
    SBDGroupChannelSuperChannelFilterBroadcastOnly = 3,
};

/**
 *  Filter public group channel or private one in group channels.
 */
typedef NS_ENUM(NSUInteger, SBDGroupChannelPublicChannelFilter) {
    /**
     * Without filter
     */
    SBDGroupChannelPublicChannelFilterAll       = 0,
    /**
     * Filter public group channel.
     */
    SBDGroupChannelPublicChannelFilterPublic    = 1,
    /**
     * Filter private group channel.
     */
    SBDGroupChannelPublicChannelFilterPrivate   = 2,
};

/**
 *  Filter my channels or all ones in public group channels.
 */
typedef NS_ENUM(NSUInteger, SBDPublicGroupChannelMembershipFilter) {
    /**
     * Without filter.
     */
    SBDPublicGroupChannelMembershipFilterAll      = 0,
    /**
     * Filter public group channel the current user joined in.
     */
    SBDPublicGroupChannelMembershipFilterJoined   = 1,
};

/**
 *  Filter operators in group channels.
 */
typedef NS_ENUM(NSUInteger, SBDGroupChannelOperatorFilter) {
    /**
     * Without filter.
     */
    SBDGroupChannelOperatorFilterAll            = 0,
    /**
     * Filter operators.
     */
    SBDGroupChannelOperatorFilterOperator      = 1,
    /**
     * Filter members except operators.
     */
    SBDGroupChannelOperatorFilterNonOperator   = 2,
};

/**
 *  Filter operators in group channels.
 */
typedef NS_ENUM(NSUInteger, SBDGroupChannelMutedMemberFilter) {
    /**
     * Without filter.
     */
    SBDGroupChannelMutedMemberFilterAll     = 0,
    /**
     * Filter muted members.
     */
    SBDGroupChannelMutedMemberFilterMuted   = 1,
    /**
     * Filter members not muted.
     */
    SBDGroupChannelMutedMemberFilterUnmuted = 2,
};


/**
 *  The push option that determines how to deliver the push notification when sending a user or a file message.
 */
typedef NS_ENUM(NSUInteger, SBDPushNotificationDeliveryOption) {
    /**
     *  The push notification will be delivered by the opposite user's setting.
     */
    SBDPushNotificationDeliveryOptionDefault = 0,
    /**
     *  The push notification will never be delivered.
     */
    SBDPushNotificationDeliveryOptionSuppress = 1,
};

/**
 *  The users's role which gives different behaviors, permisions to user.
 */
typedef NS_ENUM(NSUInteger, SBDRole) {
    /**
     *  The default role that means nothing.
     */
    SBDRoleNone = 0,
    /**
     *  The role of operator.
     */
    SBDRoleOperator = 1,
};

/**
 The current user's muted state type.

 - SBDMutedStateUnmuted: The current user is unmuted in the group channel.
 - SBDMutedStateMuted: The current user is muted in the group channel.
 */
typedef NS_ENUM(NSInteger, SBDMutedState) {
    
    SBDMutedStateUnmuted = 0,
    SBDMutedStateMuted = 1,
};

/**
 *  The bitmask keys of count about unread messages or invitation.
 */
typedef NS_OPTIONS(NSUInteger, SBDUnreadItemKey) {
    /**
     *  The bitmask key for unread message count of non super channel.
     */
    SBDUnreadItemKeyNonSuperUnreadMessageCount      = (1 << 0),
    /**
     *  The bitmask key for unread message count of super channel.
     */
    SBDUnreadItemKeySuperUnreadMessageCount         = (1 << 1),
    /**
     *  The bitmask key for invitation count of non super channel.
     */
    SBDUnreadItemKeyNonSuperInvitationCount         = (1 << 2),
    /**
     *  The bitmask key for invitation count of super channel.
     */
    SBDUnreadItemKeySuperInvitationCount            = (1 << 3),
    /**
     *  The bitmask key for unread mention count of non super channel.
     */
    SBDUnreadItemKeyNonSuperUnreadMentionCount      = (1 << 4),
    /**
     *  The bitmask key for unread mention count of non super channel.
     */
    SBDUnreadItemKeySuperUnreadMentionCount         = (1 << 5),
    
    
    /**
     *  The bitmask key for unread message count of group channel(super and non-super).
     */
    SBDUnreadItemKeyGroupChannelUnreadMessageCount  = (1 << 10),
    /**
     *  The bitmask key for unread mention count of group channel(super and non-super).
     */
    SBDUnreadItemKeyGroupChannelUnreadMentionCount  = (1 << 11),
    /**
     *  The bitmask key for invitation count of group channel(super and non-super).
     */
    SBDUnreadItemKeyGroupChannelInvitationCount     = (1 << 12),
};

/**
 *  The enum type to represent various kinds of counts.
 */
typedef NS_ENUM(NSUInteger, SBDCountPreference) {
    /**
     *  The channel of this preference has all of count.
     */
    SBDCountPreferenceAll = 0,
    /**
     *  The channel of this preference has only unread message count.
     */
    SBDCountPreferenceUnreadMessageCountOnly = 1,
    /**
     *  The channel of this preference has only unread mention count.
     */
    SBDCountPreferenceUnreadMentionCountOnly = 2,
    /**
     *  The channel of this preference does not get any count.
     */
    SBDCountPreferenceOff = 3,
};

/**
 *  The enum type to represent target type of mention.
 */
typedef NS_ENUM(NSUInteger, SBDMentionType) {
    SBDMentionTypeUsers = 0,
    SBDMentionTypeChannel = 1,
};

/**
 The enum type to filter my group channels.

 - SBDUnreadChannelFilterAll: Shows all my group channels.
 - SBDUnreadChannelFilterUnreadMessage: Shows my group channels that have unread messages.
 
 @since 3.0.113
 */
typedef NS_ENUM(NSUInteger, SBDUnreadChannelFilter) {
    SBDUnreadChannelFilterAll = 0,
    SBDUnreadChannelFilterUnreadMessage = 1,
};

typedef NS_ENUM(NSUInteger, SBDScheduledUserMessageStatus) {
    SBDScheduledUserMessageStatusScheduled = 0,
    SBDScheduledUserMessageStatusSent = 1,
    SBDScheduledUserMessageStatusCanceled = 2,
    SBDScheduledUserMessageStatusFailed = 3,
};

/**
 The enum type for the hidden state of a group channel.

 - SBDGroupChannelHiddenStateUnhidden: Shows the channel is unhidden.
 - SBDGroupChannelHiddenStateHiddenAllowAutoUnhide: Shows the channel will be unhidden automatically when there is a new message in the channel.
 - SBDGroupChannelHiddenStateHiddenPreventAutoUnhide: Shows the channel will not be unhidden automatically.
 
 @since 3.0.122
 */
typedef NS_ENUM(NSUInteger, SBDGroupChannelHiddenState) {
    SBDGroupChannelHiddenStateUnhidden = 0,
    SBDGroupChannelHiddenStateHiddenAllowAutoUnhide   = 1,
    SBDGroupChannelHiddenStateHiddenPreventAutoUnhide = 2,
};

/**
 The enum type to filter my group channels with the hidden state.
 
 - SBDChannelHiddenStateFilterUnhiddenOnly: Shows the unhidden channels only.
 - SBDChannelHiddenStateFilterHiddenOnly: Shows the hidden channels only.
 - SBDChannelHiddenStateFilterHiddenAllowAutoUnhide: Shows the channels will be unhidden automatically when there is a new message in the channel.
 - SBDChannelHiddenStateFilterHiddenPreventAutoUnhide: Shows the channels will not be unhidden automatically.
 
 @since 3.0.122
 */
typedef NS_ENUM(NSUInteger, SBDChannelHiddenStateFilter) {
    SBDChannelHiddenStateFilterUnhiddenOnly = 0,
    SBDChannelHiddenStateFilterHiddenOnly   = 1,
    SBDChannelHiddenStateFilterHiddenAllowAutoUnhide = 2,
    SBDChannelHiddenStateFilterHiddenPreventAutoUnhide = 3,
};

/**
 The options to choose which push notification for the current user to receive.
 
 - SBDPushTriggerOptionAll: Receive all of remote push notification.
 - SBDPushTriggerOptionOff: Do NOT receive any remote push notification.
 - SBDPushTriggerOptionMentionOnly: Receive only mentioned messages's notification.
 
 @since 3.0.128
 */
typedef NS_ENUM(NSUInteger, SBDPushTriggerOption) {
    SBDPushTriggerOptionAll = 0,
    SBDPushTriggerOptionOff,
    SBDPushTriggerOptionMentionOnly,
};

/**
 The options to choose which push notification for the current user to receive in a group channel.
 
 - SBDGroupChannelPushTriggerOptionDefault: Follow the push trigger of current user. See `SBDPushTriggerOption`.
 - SBDGroupChannelPushTriggerOptionAll: Receive all of remote push notification.
 - SBDGroupChannelPushTriggerOptionOff: Do NOT receive any remote push notification.
 - SBDGroupChannelPushTriggerOptionMentionOnly: Receive only mentioned messages's notification.
 
 @since 3.0.128
 */
typedef NS_ENUM(NSUInteger, SBDGroupChannelPushTriggerOption) {
    SBDGroupChannelPushTriggerOptionDefault = 0,
    SBDGroupChannelPushTriggerOptionAll,
    SBDGroupChannelPushTriggerOptionOff,
    SBDGroupChannelPushTriggerOptionMentionOnly
};

/**
 Constants of type for device push token.
 
 - SBDPushTokenTypeNone: No type.
 - SBDPushTokenTypeGCM: Token from Android device.
 - SBDPushTokenTypeAPNS: Normal Token from iOS device.
 - SBDPushTokenTypeAPNSVoIP: Token used for VoIP from iOS device.
 
 @since 3.0.134
 */
typedef NS_ENUM(NSUInteger, SBDPushTokenType) {
    SBDPushTokenTypeNone = 0,
    SBDPushTokenTypeGCM,
    SBDPushTokenTypeAPNS,
    SBDPushTokenTypeAPNSVoIP,
};

/**
 Constants of type to describe message's request state
 
 - SBDMessageRequestStateNone: MUST NOT BE. If you got a message instance from SDK, the message can't have this value.
 - SBDMessageRequestStatePending: Indicates the state of the message returned when trying to send a message. The message with the pending state means that is not dispatched completely to the Sendbird server. The pending message should be replaced with a message (failed or succeeded) from the callback.
 - SBDMessageRequestStateFailed: Indicates the state of the message that failed to send the message.
 - SBDMessageRequestStateSucceeded: Indicates the state of the message that success to send the message.
 
 @since 3.0.141
 @deprecated 3.0.173. Use `SBDMessageSendingStatus` instead.
 */
typedef NS_ENUM(NSUInteger, SBDMessageRequestState) {
    SBDMessageRequestStateNone = 0,
    SBDMessageRequestStatePending,
    SBDMessageRequestStateFailed,
    SBDMessageRequestStateSucceeded,
};

/**
 Constants of type to describe message's sending status.
 
 - SBDMessageSendingStatusNone: MUST NOT BE. If you got a message instance from SDK, the message can't have this value.
 - SBDMessageSendingStatusPending: Indicates the status of the message returned when trying to send a message. The message with the pending status means that is not dispatched completely to the Sendbird server. The pending message should be replaced with a message (failed or succeeded) from the callback.
 - SBDMessageSendingStatusFailed: Indicates the status of the message that failed to send the message.
 - SBDMessageSendingStatusSucceeded: Indicates the status of the message that success to send the message.
 - SBDMessageSendingStatusCanceled: Indicates the status of the message that is canceled.
 
 @since 3.0.173
 */
typedef NS_ENUM(NSUInteger, SBDMessageSendingStatus) {
    SBDMessageSendingStatusNone = 0,
    SBDMessageSendingStatusPending,
    SBDMessageSendingStatusFailed,
    SBDMessageSendingStatusSucceeded,
    SBDMessageSendingStatusCanceled,
};

/**
 Filter types to query with `SBDGroupChannelListQuery`. You can combine search fields to query.
 @see used for -setSearchFilter:fields: of `SBDGroupChannelListQuery`
 @since 3.0.144
 */
typedef NS_OPTIONS(NSUInteger, SBDGroupChannelListQuerySearchField) {
    /* filter type to query for member nickname */
    SBDGroupChannelListQuerySearchFieldMemberNickname   = (1 << 0),
    /* filter type to query for member nickname */
    SBDGroupChannelListQuerySearchFieldChannelName      = (1 << 1),
};

/**
 Categories of reporting reasons
 
 - SBDReportCategorySuspicious: Report suspicious content
 - SBDReportCategoryHarassing: Report harassing content.
 - SBDReportCategorySpam: Report spam content
 - SBDReportCategoryInappropriate: Report inappropriate content
 
 @since 3.0.154
 */
typedef NS_ENUM(NSUInteger, SBDReportCategory) {
    SBDReportCategorySuspicious = 0,
    SBDReportCategoryHarassing,
    SBDReportCategorySpam,
    SBDReportCategoryInappropriate,
};

/**
 The order type for `SBDMessageSearchQuery`.
 
 - SBDMessageSearchQueryOrderScore: Score type returns the result as by their matching score.
 - SBDMessageSearchQueryOrderTimeStamp: Timestamp type returns the result as by `SBDBaseMessage`'s timestamp.
 @since 3.0.162
 */
typedef NS_ENUM(NSUInteger, SBDMessageSearchQueryOrder) {
    SBDMessageSearchQueryOrderScore = 0,
    SBDMessageSearchQueryOrderTimeStamp,
};

#pragma mark - Reactions

/**
 The SBDReactionEvent action state.

 @since 3.0.169
*/
typedef NS_ENUM(NSUInteger, SBDReactionEventAction) {
    SBDReactionEventActionAdd = 0,
    SBDReactionEventActionDelete = 1,
};

/**
 The order type for member list query.

 @since 3.0.198
*/
typedef NS_ENUM(NSUInteger, SBDMemberListOrder) {
    SBDMemberListOrderNicknameAlphabetical = 0,
    SBDMemberListOrderOperatorThenMemberNicknameAlphabetical = 1,
};

typedef NS_OPTIONS(NSInteger, SBDLogLevel) {
    SBDLogLevelNone         = 0,
    SBDLogLevelError        = (1 << 0),
    SBDLogLevelWarning      = (1 << 1),
    SBDLogLevelInfo         = (1 << 2),
};

/// Poll action type
/// @since 3.0.232
typedef NS_ENUM(NSUInteger, SBDPollVoteAction) {
    SBDPollVoteActionCast,
    SBDPollVoteActionCancel
};

/// Poll status
/// @since 3.0.232
typedef NS_ENUM(NSUInteger, SBDPollStatus) {
    SBDPollStatusOpen,
    SBDPollStatusClosed,
    SBDPollStatusRemoved
};

/// The policy for the message collection initialization.
/// @since 3.0.227
typedef NS_ENUM(NSUInteger, SBDMessageCollectionInitPolicy) {
    SBDMessageCollectionInitPolicyCacheAndReplaceByApi = 0,
};

/// Restriction type of SBDRestrictionInfo.
/// @since 3.0.236
typedef NS_ENUM(NSUInteger, SBDRestrictionType) {
    SBDRestrictionTypeMuted = 0,
    SBDRestrictionTypeBanned = 1,
};

/// Filter for deciding which reply types to include in a result.
/// @since 3.0.236
typedef NS_ENUM(NSUInteger, SBDReplyType) {
    SBDReplyTypeNone = 0,
    SBDReplyTypeAll = 1,
    SBDReplyTypeOnlyReplyToChannel = 2,
};

#endif /* SBDTypes_h */
