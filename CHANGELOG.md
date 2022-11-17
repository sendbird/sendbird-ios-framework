# Changelog

## v3.1.34 (Nov 17, 2022)

### Improvements
- Fixed multiple concurrent connections issue

## v3.1.33 (Oct 27, 2022)

- Fixed metaArrays not being copied when copying a userMessage

## v3.1.32 (Oct 25, 2022)

### Improvements

* Fixed timer concurrency issue when reconnecting
* Fixed an issue that caused the main thread to slow down while using `SBDGroupChannelCollection`

## v3.1.29 (Oct 12, 2022)

* Improved stability

## v3.1.28 (Sep 28, 2022)
* Implemented synchronous initialization for SBDMain
* Improved stability when sending FILE messages
* Removed older implementation of polls from v3

## v3.1.27 (Sep 22, 2022)
* Resolved priority inversion warning

## v3.1.26 (Sep 14, 2022)
* Fixed duplicate message being returned in SBDMessageCollection's loadPrevious and loadNext

## v3.1.25 (Sep 5, 2022)
* Improved stability

## v3.1.24 (Aug 31, 2022)
* Added MessageSearchQuery's totalCount and made it public
* Implemented channel membership history where clients can retrieve whether users have joined or left the channel 
* Removed some logs to improve performance

## v3.1.23 (Aug 8, 2022)
* Fixed an error where the channel update event was not triggered when receiving a new message using the platform API
* Improved cleanup process on WebSocket reconnection

## v3.1.22 (Aug 3, 2022)
* Added Metadata key filter that was previously missing in belongsTo of SBDGroupChannelListQuery
* Disabled DB access if local caching is off
* Fixed WS connection being lost after switching from wifi to LTE

## v3.1.21 (Jul 22, 2022)
* Fixed objectEnumerator error when invoking channel change event

## v3.1.20 (Jul 20, 2022)
* Fixed error in console log when invoking channel change event

## v3.1.19 (Jul 19, 2022)
* Improved console logging when invoking channel change event

## v3.1.18 (May 31, 2022)
* Improved stability.

## v3.1.17 (May 27, 2022)
* Fixed a bug that returns the wrong token for changelogs in channel sync.

## v3.1.16 (May 19, 2022)
* Fixed crash in NSRunLoop.

## v3.1.15 (May 11, 2022)
* Improved stability.
* Fixed a bug for filtering public group channels in `SBDGroupChannelCollection`.
* Added `SBDChannelHiddenStateFilterAll`.
* Added mentioned users to pending messages.

## v3.1.14 (May 6, 2022)
* Removed Network.framework from Podspec.

## v3.1.13 (Apr 19, 2022)
* Fixed a crash bug.
* Fixed a bug that `belongsTo:` of `SBDMessageListParams` returns a wrong value. 

## v3.1.12 (Apr 5, 2022)
* Improved stability.

## v3.1.11 (Apr 4, 2022)
* Improved stability.

## v3.1.10 (Mar 28, 2022)
* Fixed error with infinite calls of SBDMain.connect completion.
* Fixed issue where cachedMetadata is not serialized (not stored in database).

## v3.1.9 (Mar 18, 2022)
* Fixed issue with `getCachedMetadata()` in message collection.

## v3.1.8 (Mar 17, 2022)
* Fixed issue with `getCachedMetadata()` in local caching.

## v3.1.7 (Mar 8, 2022)
* Add custom type and super mode filter to `getTotalUnreadChannelCount`.

## v3.1.6 (Mar 2, 2022)
* Fix issue with local caching where messages were loading slowly.

## v3.1.5 (Feb 24, 2022)
* Fixed a bug where ACK_TIMEOUT(800180) errors were incorrectly being sent.

## v3.1.4 (Feb 22, 2022)
* Fixed issue with channel sync where channels created in the background did not properly load.
* Deprecated `SBDAuthenticateDelegate` and `SBDConnectionManager`.

## v3.1.3 (Jan 25, 2022)
* Added `applyParentMessage:` method to update a parent message object in the child messages.
* Fixed a bug where child messages' parent message wasn’t being updated.
* Improved stability of session management.

## v3.1.2 (Jan 5, 2022)
* Improved stability.

## v3.1.1 (Dec 9, 2021)
* Fixed a bug that the reply message isn't received when the network is reconnected.
* Fixed a bug that some messages are disappeared.
* Improved stability

## v3.1.0 (Nov 23, 2021) 
* Local caching support. See [Local Caching](https://sendbird.com/docs/chat/v3/ios/guides/local-caching) for details.
  * Added `SBDMessageContext` class.
  * Added `SBDCollectionEventSource` enum.
  * Added `SBDMessageCollectionDelegate` protocol.
  * Added `SBDMessageCollection` class.
  * Added `SBDChannelContext` class.
  * Added `SBDGroupChannelCollection` class.
  * Added `SBDGroupChannelCollectionDelegate` protocol.
  * Added `SBDMessageCollectionInitPolicy` enum.
* Added Reply to Channel feature. 
  * Added enum `SBDReplyType` for loading messages with respect to message's reply messages.
  * Added `replyType` property in `SBDMessageListParams`, `SBDMessageChangeLogsParams` and `SBDPreviousMessageListQuery`.
  * Deprecated `includeReplies` in `SBDMessageListParams`, `SBDMessageChangeLogsParams` and `SBDPreviousMessageListQuery`.
  * Added `parentMessage` property in `SBDBaseMessage`
  * Deprecated `includeParentMessageText` in `SBDMessageListParams`, `SBDMessageChangeLogsParams`, `SBDMessageRetrievalParams` and `SBDPreviousMessageListQuery`.
  * Deprecated `parentMessageText` in `SBDBaseMessage`.
  * Added `isReplyToChannel` in `SBDBaseMessage`
  * Added `isReplyToChannel` property in `SBDBaseMessageParams` .
  * Added `belongsToMessageParams:` method in `SBDMessageListParams`.

## v3.0.238 (Nov 15, 2021)
* Removed excluded architecture. 

## v3.0.237 (Nov 10, 2021)
* Added `includeReactions` field in `SBDMessageRetrievalParams`.
* Fixed messageType not being copied in `SBDMessageListParams`.
* Fixed `SBDMessageListParams belongsTo:(message)`, `SBDMessageListParams belongsTo:(messageParams)`.

## v3.0.236 (Oct 26, 2021) 
* Added `SBDRestrictionInfo` which contains information for users who are either muted or banned. 
* Added `SBDRestrictedUser` for muted or banned users, which contains `SBDRestrictionInfo`. 
* `SBDMutedUserListQuery loadNextPageWithCompletionHandler:` and `SBDBannedUserListQuery loadNextPageWithCompletionHandler:` will give a `NSArray<SBDRestrictedUser *>`.
* `SBDChannelDelegate channel: userWasMuted:` and `SBDChannelDelegate channel: userWasBanned:` will give a `SBDRestrictedUser` object. 
* Added `restrictionInfo` property in `SBDMember`.

## v3.0.235 (Oct 22, 2021)
* Removed Network.framework and replaced it with legacy Reachability
* Improved stability 
 
## v3.0.234 (Sep 24, 2021)
* Added  `markAsReadWithCompletionHandler:`.
* Deprecated `markAsRead`.
* Fixed a bug that the result of  `getMyGroupChannelChangeLogsWithToken:byTimestamp:params:completionHandler:` didn't include the read receipt data.

## v3.0.233 (Sep 1, 2021)
* Fixed typo.

## v3.0.232 (Sep 1, 2021)
* Added `metaDataKeyFilter`, `metaDataValuesFilter`, `metaDataValueStartsWithFilter`, `setMetaDataFilterWithKey:values:` and `setMetaDataFilterWithKey:valueStartsWith:` in `SBDGroupChannelListQuery` and `SBDPublicGroupChannelListQuery` class.
* Fixed a bug on `belongsTo:` in `SBDMessageListParams` class.

## v3.0.231 (Aug 11, 2021)
* Deprecated methods. See [DEPRECATED.md](https://github.com/sendbird/sendbird-ios-framework/blob/master/DEPRECATED.md) for more details.
  *  `getMessagesByTimestamp:params:completionHandler:`
  * `getMessagesById:params:completionHandler:`
  * all `getMessageChangeLogsWithToken ...`
  * all `getMessageChangeLogsByTimestamp ...`

## v3.0.230 (Aug 6, 2021)
* Optimized Supergroup protocol handling to improve performance for specific use cases.

## v3.0.229 (Jul 23, 2021)
* Improved stability.

## v3.0.228 (Jul 15, 2021)
* Improved stability.

## v3.0.227 (Jul 7, 2021)
* Improved stability.

## v3.0.226 (Jun 25, 2021)
* Fixed cached meta data mutation issue
* Improved stability

## v3.0.225 (Jun 3, 2021)
* Added serialization for emoji class
* Fixed cached meta data eviction crash
* Changed native socket minimum requirement for iOS 14 and above due to Apple's Network framework bug in iOS 13
* Improved stability 

## v3.0.224 (May 7, 2021)
* Removed `sharedApplication` usage
* Set `Require only app-extension-safe api` flag to true
* Improved stability

## v3.0.223 (Apr 28, 2021)
* Added `nicknameStartsWithFilter` property in `SBDApplicationUserListQuery` 
* Exposed `initWithDictionary:` methods for SBD classes
* Improved stability 

## v3.0.222 (Apr 20, 2021)
* Used the native socket implementation NSURLSessionWebSocketTask by default for iOS 13 and above. The prior versions of SDK use SocketRocket implementation for websocket communication. We are moving to native framework due to better support. If there is a problem experienced with this release, please contact Sendbird support because this change can be overwritten by server side configuration. Sendbird support team will change the setting setting for you per application.
* Improved network latency issue
* Improved stability

## v3.0.221 (Apr 7, 2021)
* Supports xcframework and Swift Package Manager.
* Added new parameter for Apple Critical Alert to `SBDBaseMessageParams` class.

## v3.0.220 (Mar 23, 2021)
* Enabled bitcode.

## v3.0.219 (Mar 20, 2021)
* The minimum deployment target is 9.0.
* Added new delegates(`channelDidChangeMemberCount:` and `channelDidChangeParticipantCount:`) to `SBDChannelDelegate` to receive the events that the member count and the participant count have been changed.

## v3.0.218 (Mar 6, 2021)
* Improved stability

## v3.0.217 (Mar 5, 2021)
* Improved stability

## v3.0.216 (Feb 24, 2021)
* Added `getCachedMetaData` in `SBDBaseChannel`.
* Added `includeMetaData` in `SBDGroupChannelListQuery`, `SBDPublicGroupChannelListQuery`, `SBDOpenChannelListQuery`.
* Fixed a bug that the message object in the search result was `SBDBaseMessage` class and the `sender` of the message object was `nil`.
* Improved stability.

## v3.0.215 (Feb 8, 2021)
* Added the methods below to `SBDGroupChannel` class.
  * `createChannelWithParams:progressHandler:completionHandler:`
  * `createDistinctChannelIfNotExistWithParams:progressHandler:completionHandler:`
  * `updateChannelWithParams:progressHandler:completionHandler:`
* Fixed bug of `requestId` in `SBDBaseMessage` object.

## v3.0.214 (Jan 25, 2021)
* Fixed member count bug of group channel. 

## v3.0.213 (Jan 11, 2021)
* Improved stability 

## v3.0.212 (Dec 29, 2020)
* Improved stability 

## v3.0.211 (Dec 16, 2020)
* Fixed minor bug.

## v3.0.210 (Dec 15, 2020)
* Improved console logging.
* Generated an error for file size limit before sending file message.

## v3.0.208 (Dec 7, 2020)
* Fixed bug of setting the host for the connection.

## v3.0.207 (Dec 1, 2020)
* Deprecated `setPushPreferenceWithPushOn:completionHandler:`
* Fixed channel cover image bug.

## v3.0.206 (Nov 17, 2020)
* Fixed a bug of resending message.
* Added `SBDOpenChannelParams` class
* Added channel create and update functions with parameters in `SBDOpenChannel` class.
* Modified the openChannelParams related test codes.

## v3.0.205 (Oct 31, 2020)
* Added `setAllowFriendDiscovery:completionHandler:`
* Added `getAllowFriendDiscoveryWithCompletionHandler:`
* When sending a file message with binary data, SDK will calculate the file size internally.
* Improved stability.

## v3.0.204 (Oct 21, 2020)
* Improved stability.
* Added SubChannel related properties
  * `showSubChannelMessageOnly` property in `SBDMessageListParams` class
  * `showSubChannelMessageOnly` property in `SBDPreviousMessageListQuery` class

## v3.0.203 (Oct 8, 2020)
* Improved stability.
* Added `buildFromSerializedData:desiredState:` in `SBDBaseMessage`.

## v3.0.202 (Sep 15, 2020)
* Fixed a bug that the `isMuted` of a group channel member wasn't updated.
* Added `getTypingUsers` method in `SBDGroupChannel` class.
* Deprecated `getTypingMembers` method in `SBDGroupChannel` class.

## v3.0.201 (Sep 4, 2020)
* Fixed unread count bug.
* Improved stability.

## v3.0.200 (Aug 25, 2020)
* Fixed copying message bug
* Fixed `myMutedState` is always muted issue
* Improved stability

## v3.0.199 (Aug 21, 2020)
* Added `creator` property in `SBDBaseChannel`
* Added `setWebSocketResponseTimeout:` to `SBDOptions` class to set the response timeout value.

## v3.0.198 (Aug 14, 2020)
* Added `SBDMemberListOrder` for the member list query.
* Added `isMuted` property in `SBDMember` class
* Added `applicationAttributes` property in `SBDAppInfo` class
* Activated `operationFilter` in `SBDGroupChannelMemberListQuery`
* Improved stability

## v3.0.197 (Aug 8, 2020)
* Improved stability

## v3.0.196 (Aug 5, 2020)
* Fixed memory allocation bug

## v3.0.195 (Jul 30, 2020)
* Improved stability

## v3.0.194 (Jul 29, 2020)
* Improved stability

## v3.0.193 (Jul 22, 2020)
* Added open graph feature along with `SBDOGMetaData` and `SBDOGImage` class
* Added `ogMetaData` property in `SBDBaseMessage` 
* Fixed bug in `markAsDeliveredWithRemoteNotificationPayload:completion`
 
## v3.0.192 (Jul 18, 2020)
* Improved stability

## v3.0.191 (Jul 18, 2020)
* Improved stability

## v3.0.190 (Jul 14, 2020)
* Fixed delegate validation mismatched

## v3.0.189 (Jul 8, 2020)
* Added `addOperatorsWithUserIds:completionHandler:` to add operators to channel.
* Added `removeOperatorsWithUserIds:completionHandler:` and `removeAllOperatorsWithCompletionHandler:` to remove operators from channel.
* Improved stability
* Fixed minor bug

## v3.0.187 (Jun 30, 2020)
* Fixed `markAsRead` unreadMessageCount bug

## v3.0.186 (Jun 24, 2020)
* Refactored `SBDBaseMessage` properties that need common access
* Supported `NSCopying` protocol for common objects
* Improved stability

## v3.0.185 (Jun 18, 2020)
* Added functions that creates a `SBDMessageChangeLogsParams` object with `SBDPreviousMessageListQuery` and `SBDMessageListParams` information.
* Added a function that creates a `SBDGroupChannelChangeLogsParams` object with `SBDGroupChannelListQuery` information.
* Added `getUnreadMemberCount:` and `getUndeliveredMemberCount:`.
* Improved stability.
* Fixed reconnection issue.

## v3.0.184 (Jun 11, 2020)
* Improved stability 

## v3.0.183 (Jun 4, 2020)
* Improved delivery receipt

## v3.0.182 (May 29, 2020)
* Added `SBDGroupChannelChangeLogsParams`
* Added `getMyGroupChannelChangeLogsByToken:params:completionHandler:`
* Deprecated `getMyGroupChannelChangeLogsByToken:customType:completionHandler:` and `getMyGroupChannelChangeLogsByToken:customType:includeEmptyChannel:completionHandler`
* Added `includeFronzeChannel` in `SBDOpenChannelListQuery`
* Fixed meta data completion type

## v3.0.181 (May 20, 2020)
* Fixed reaction bug.

## v3.0.180 (May 19, 2020)
* Added `deleteChannel` method in open channel
* Added `AppInfo` class
* Added emoji feature with `Emoji`, `EmojiCategory`, `EmojiContainer` class 
* Fixed type comparison in init methods
* Fixed to add `errorCode` in message's init methods

## v3.0.179 (Apr 29, 2020)
* Added `deleteMessageWithMessageId:completionHandler:` in `SBDBaseChannel`
* Fixed push register/unregister when no connection
* Deprecated `metaArrayKeys` in `SBDBaseMessageParams`
* Added `metaArrays` in `SBDBaseMessageParams`


## v3.0.178 (Apr 21, 2020)
* Added `addExtension` for UIKit

## v3.0.177 (Apr 13, 2020)
* Added `show_delivery_receipt` parameters.
* `resendUserMessage()`, `resendFileMessage()` returns the corresponding messages with `PENDING` state.
* Fixed minor bug.
* Improved stability.

## v3.0.176 (Apr 1, 2020)
* Renamed an enum value.
  * `SBDErrorFileUploadCancelled` -> `SBDErrorFileUploadCanceled`
* Improved stability.

## v3.0.175 (Mar 23, 2020)
* Defined a few errors for the failed message as resendable errors.
  * `SBDErrorInternalServerError`(500901)
  * `SBDErrorRateLimitExceeded`(500910)
  * `SBDErrorMessagesRateLimitExceeded`(900200)
* Improved stability.
* Added new methods to get messages with message ID and inclusiveTimestamp option.

## v3.0.174 (Mar 17, 2020)
* Added `channelDidUpdateOperators:` in SBDChannelDelegate
* Added `role` in SBDMember
* Improved stability.

## v3.0.173 (Mar 12, 2020)
* Deprecated `requestState` of `SBDUserMessage` and `SBDFileMessage`.
* Deprecated `SBDMessageRequestState`.
* Added `sendingStatus` to `SBDUserMessage` and `SBDFileMessage`.
* Added `SBDMessageSendingStatus`.

## v3.0.172 (Mar 11, 2020)
* Fixed minor bug.

## v3.0.171 (Mar 5, 2020)
* Improved stability.

## v3.0.170 (Feb 27, 2020)
* Added missing headers.

## v3.0.169 (Feb 26, 2020)
* Added Reaction API.

## v3.0.168 (Feb 24, 2020)
* Fixed group channel update bug.

## v3.0.167 (Feb 7, 2020)
* Fixed bug about can't receive specific channelDelegate(leave, remove).
* Improved stability.

## v3.0.166 (Feb 4, 2020)
* Improved stability and fixed bug of webSocket

## v3.0.165 (Jan 15, 2020)
* Add forceUpdateLastMessage property to force set the message as the last message of a channel when true.
* Improved parsing stability.

## v3.0.164 (Jan 10, 2020)
* Added Message search feature.
  * added class `SBDMessageSearchQuery` to search messages and create query.
  * added builder class `SBDMessageSearchQueryBuilder` to build a `SBDMessageSearchQuery`.

## v3.0.163 (Jan 9, 2020)
* Modified increasing unread message count on super group channel.

## v3.0.162 (Dec 23, 2019)
* Added **Delivery receipt** feature.
  * added methods `markAsDelivered` in `SBDGroupChannel` and `markAsDeliveredWithChannelUrl:` in `SBDMain` to sending delivered state to channel.
  * added `channelDidUpdateDeliveryReceipt:` delegate to receive user’s message delivery confirms.
  * added `getDeliveryReceipt:` method to get undelivered member counts.

## v3.0.161 (Dec 4, 2019)
* Added a method `isResendable` in `SBDUserMessage` and `SBDFileMessage`.
  * `resendUserMessage` and `resendFileMessage` work only when `isResendable` is `true`.
* Added a property named `errorCode` in `SBDUserMessage` and `SBDFileMessage`.

## v3.0.160 (Nov 25, 2019)
* Fixed bug of lost items while copying files.

## v3.0.159 (Nov 12, 2019)
* Improved stability.

## v3.0.158 (Nov 8, 2019)
* Progress handler can be executed on the specific thread.

## v3.0.157 (Nov 4, 2019)
* New property `messageOffsetTimestamp` that tells the current user's message offset of `SBDGroupChannel`. 

## v3.0.156 (Oct 20, 2019)
* Improved stability.

## v3.0.155 (Oct 17, 2019)
* Improved connection stability.

## v3.0.154 (Oct 7, 2019)
* Reporting APIs.
  * `reportUser:reportCategory:reportDescription:completionHandler:`
  * `reportChannelWithCategory:reportDescription:completionHandler:`
  * `reportMessage:reportCategory:reportDescription:completionHandler:`
* New user event of `didUpdateTotalUnreadMessageCount:totalCountByCustomType:` to handle total unread message count.
* Improved stability.

## v3.0.153 (Oct 4, 2019)
* Improved stability.

## v3.0.152 (Oct 4, 2019) DEPRECATED
* Fixed bug of updating channel metadata.
* Improved stability.

## v3.0.151 (Oct 1, 2019)
* Improved stability.

## v3.0.150 (Sep 18, 2019)
* Fixed a bug of registering remote push token in iOS 13
* New method to resend a file message in channel.
  * `resendFileMessageWithMessage:binaryData:progressHandler:completionHandler:`
  *  `resendFileMessageWithMessage:binaryData:completionHandler:`
* New property to show requested mention user ids in user message, file message.
  * `requestedMentionUserIds`
* Improved connection stability.

## v3.0.149 (Aug 23, 2019)
* Improved connection stability.
* Fixed bug of thread management.

## v3.0.148 (Aug 16, 2019)
* On-demand translation that translate a text message into target languages.
* Improved `MetaArray` feature with `SBDMessageMetaArray` class.
  * Add/remove meta array with an array of `SBDMessageMetaArray`.
  * Message has new property `metaArrays` that consists of an array of `SBDMessageMetaArray`. 
* Enable to create group channel strictly. `SBDGroupChannelParams` has new property boolean type of `strict` that can cause an error if any of users is not valid when creating a channel.

## v3.0.147 (Aug 10, 2019)
* Fixed a bug of network reachability.

## v3.0.146 (Jul 22, 2019)
* Improved stability.

## v3.0.145 (Jul 17, 2019)
* Fixed minor bug.
* Improved connection stability.

## v3.0.144 (Jul 13, 2019)
* New filter `searchFilter` of `SBDGroupChannelListQuery`. When you want to query a string for `channel name` or `member nickname`, use this filter.
* Improved stability.

## v3.0.143 (Jun 27, 2019)
* Fixed a bug of internal timer.

## v3.0.142 (Jun 14, 2019)
* Added `resendUserMessage:completionHandler` to resend a failed message in `SBDBaseChannel`.
* New enum and property to represent message request state `SBDMessageRequestState` in `SBDUserMessage`, `SBDFileMessage`. Enum `SBDMessageRequestStateNone`, `SBDMessageRequestStatePending`, `SBDMessageRequestStateFailed`, `SBDMessageRequestStateMessage`.
* `SBDBaseMessage` conforms `NSCopying`.
* Improved connection stability.
* Fixed minor bug.

## v3.0.141 (Jun 13, 2019)
* Fixed minor bug.

## v3.0.140 (Jun 11, 2019)
* Message request API with `inclusiveTimestamp` in `SBDBaseChannel`
* Improved stability

## v3.0.139 (Jun 8, 2019)
* Added `myLastRead` property to `SBDGroupChannel`.

## v3.0.138 (May 31, 2019)
* Fixed the change of `invitedAt` of `SBDGroupChannel`.
* Bug fix and stability improvement of WebSocket module.

## v3.0.137 (May 17, 2019)
* Added `deleteChannelWithCompletionHandler:` in `SBDGroupChannel`.

## v3.0.136 (May 3, 2019)
* Added `discoverable` property to `SBDGroupChannel` and `SBDGroupChannelParams`.
  * if `discoverable` of a public group channel is set to false(NO), then the channel will not appear during querying with `SBDPublicGroupChannelListQuery`. The default value of `discoverable` is true(YES).

## v3.0.135 (Apr 11, 2019)
* Improved stability.
* Fixed connection minor issue.

## v3.0.134 (Apr 5, 2019)
* Improved stability.

## v3.0.133 (Mar 21, 2019)
* Improved stability.

## v3.0.132 (Mar 14, 2019)
* Fixed minor bug.

## v3.0.131 (Feb 22, 2019)
* Fixed minor bug.

## v3.0.130 (Jan 31, 2019)
* Added `setFileTransferTimeout:` in `SBDOptions` class to set timeout for file transfer.

## v3.0.129 (Jan 19, 2019)
* Removed LLVM instrumentation.

## v3.0.128 (Jan 17, 2019)
* Divide push options for the detail triggers.
  * New enum type of push trigger option, `SBDPushTriggerOption` and `SBDGroupChannelPushTriggerOption`.
  * Added `[SBDMain setPushTriggerOption:completionHandler:]` and `[SBDMain getPushTriggerOptionWithCompletionHandler:]` class methods to set/get whether the current user receives remote push notification in the whole group channel.
  * Added `setMyPushTriggerOption:completionHandler:` and `getMyPushTriggerOptionWithCompletionHandler:` instance methods in `SBDGroupChannel`. It sets/gets whether the current user receives remote push notification in the group channel.
* Snooze or Stop snooze remote push notification in specific duration.
  * Added `[SBDMain setSnoozePeriodEnable:startTimestamp:endTimestamp:completionHandler:]` class methods to start or stop snooze period.
  * Added `[SBDMain getSnoozePeriod:]` class methods to get snooze period.

## v3.0.127 (Jan 11, 2019)
* Fixed bug of connection.

## v3.0.126 (Dec 12, 2018)
* Bitcode support for Xcode 9.

## v3.0.125 (Dec 4, 2018)
* Fixed bug about unread message count subscription.

## v3.0.124 (Dec 3, 2018)
* Fixed bug that can't toggle distinct channel.

## v3.0.123 (Nov 30, 2018)
* Fixed bug that updates unchanged properties of channel or message.

## v3.0.122 (Nov 22, 2018)
* Added `createDistinctChannelIfNotExistWithParams:completionHandler:` method in `SBDGroupChannel`.
   * It creates distinct channel and gets the channel with `isCreated` in `completionHandler` which represents whether the channel is actually created or not.
* Added `getMessageChangeLogsByTimestamp:completionHandler:` method in `SBDBaseChannel`.
   * It retrieves message change logs since the given timestamp.
* Added `hiddenState` type of `SBDGroupChannelHiddenState` property in `SBDGroupChannel` to get channel's hidden state.
   * `SBDGroupChannelHiddenStateUnhidden`: It's not hidden channel.
   * `SBDGroupChannelHiddenStateHiddenAllowAutoUnhide`: It's hidden channel which is automatically unhidden when new message comes in.
   * `SBDGroupChannelHiddenStateHiddenPreventAutoUnhide`: It's hidden channel which is not unhidden when new message comes in.
 * Added `hideChannelWithHidePreviousMessages:allowAutoUnhide:completionHandler:` method to allow automatic unhide on new message in `SBDGroupChannel`.
 * Added `unhideChannelWithCompletionHandler:` method in `SBDGroupChannel` to unhide manually the channel.
 * Added `channelHiddenStateFilter` property type of `SBDChannelHiddenStateFilter` in `SBDGroupChannelListQuery` to filter by `hiddenState`.
   * `SBDChannelHiddenStateFilterUnhiddenOnly`: Get all unhidden channels. (default)
   * `SBDChannelHiddenStateFilterHiddenOnly`: Get all hidden channels which `hiddenState` is `SBDGroupChannelHiddenStateHiddenAllowAutoUnhide` or `SBDGroupChannelHiddenStateHiddenPreventAutoUnhide`.
   * `SBDChannelHiddenStateFilterHiddenAllowAutoUnhide`: Get channels which `hiddenState` is `SBDGroupChannelHiddenStateHiddenAllowAutoUnhide`.
   * `SBDChannelHiddenStateFilterHiddenPreventAutoUnhide`: Get channels which `hiddenState` is `SBDGroupChannelHiddenStateHiddenPreventAutoUnhide`.
  * `SBDGroupChannelParams` conforms `NSCopying`.
  * Minor bug fixed

## v3.0.121 (Nov 15, 2018)
* Changed type of `sender` property in `SBDUserMessage` and `SBDFileMessage` from `SBDUser` to a new class `SBDSender` which extends `SBDUser`.
  * `SBDSender` has `isBlockedByMe` property which indicates that the message sender is blocked by the current user (default: false).
  * `isBlockedByMe` is valid in `SBDGroupChannel` only.
  * Message from blocked users is delivered only when `block_mode` in `Application` is set to `explicit` mode. Otherwise, it's not visible nor delivered.
* Minor bug fixed.

## v3.0.120 (Nov 8, 2018)
* Separated `SBDUserListQuery` into the following query classes according to its specific role.
  * Added `SBDApplicationUserList` as a substitute for `SBDUserListQuery` (Recommended).
  * Added `SBDBlockedUserListQuery`, `SBDBannedUserListQuery`, `SBDMutedUserListQuery`, `SBDParticipantListQuery`.
  * Added properties of `metaDataKeyFilter`, `metaDataValuesFilter`, `userIdsFilter` in `SBDApplicationUserListQuery`.
* Guaranteed the order of sending `SBDFileMessage` regardless of bulk file messages or a single file message.
* Minor bug fixed

## v3.0.119 (Oct 31, 2018)
* Added `SBDScheduledUserMessage` feature to send `SBDUserMessage` at the time specified by a user.
  * Added `SBDScheduledUserMessage` that is a scheduled `SBDUserMessage`.
  * Added `SBDScheduledUserMessageParams` to be delivered as a parameter to register scheduled `SBDUserMessage`.
  * Added `registerScheduledUserMessageWithParams:completionHandler:` in `SBDGroupChannel` to register scheduled `SBDUserMessage`.
* Improved stability.
* Minor bug fixed

## v3.0.118 (Oct 26, 2018)
* Added duration and a description to user mute.
* Added an ordering group channel with meta data value of specific key.
* Minor bug fixed. 

## v3.0.117 (Oct 19, 2018)
* Added a getter `getLastConnectedAt` that returns the current user's latest connection time.

## v3.0.116 (Oct 11, 2018)
* Improved stability.

## v3.0.115 (Sep 21, 2018)
* Added a method `getReadStatusIncludingAllMembers:` that gets readStatus in the group channel.
* Added a method `getReadMembersWithMessage:includeAllMembers:` that returns a list of members who read the message in the group channel.   
* Added a method `getUnreadMembersWithMessage:includeAllMembers:` that returns a list of members who did not read the message in the group channel.  
* Enabled to use `isEqual:` in Channel classes (`SBDBaseChannel`, `SBDGroupChannel`, `SBDOpenChannel`), Message classes (`SBDBaseMessage`, `SBDUserMessage`, `SBDFileMessage`, `SBDAdminMessage`), User classes (`SBDUser`, `SBDMember`) to compare deep-equality with other instance.
* Fixed connection method (ex. `connectWithUserId:accessToken:completionHandler:`) so that can receive call-back with an error when `disconnectWithCompletionHandler:` was called while connecting to SendBird.
* Changed setters of filter in query class (`SBDGroupChannelListQuery`, `SBDGroupChannelMemberListQuery`, `SBDOpenChannelListQuery`, `SBDPreviousMessageListQuery`, `SBDPublicGroupChannelListQuery`, `SBDUserListQuery`) into properties.
* Minor bug fixed.  
* Deprecated some feature.  
  * Deprecated method `getReadMembersWithMessage:` in `SBDGroupChannel`.  
  * Deprecated method `getUnreadMembersWithMessage:` in `SBDGroupChannel`.  
  * Deprecated method `getReadStatus` in `SBDGroupChannel`.  
  * Deprecated enum `SBDWebSocketClosing` in `SBDWebSocketConnectionState`.

## v3.0.114 (Sep 14, 2018)
* Minor bug fixed.  

## v3.0.112 (Sep 10, 2018)
* From now, `useMemberAsMessageSender` option is YES by default.
* Fixed a bug previous messages not showing the senders' latest user metadata.

## v3.0.111 (Sep 5, 2018)
* Minor bug fixed.

## v3.0.110 (Aug 24, 2018)
* Added `updateUserMessageWithMessageId:userMessageParams:completionHandler:` with `SBDUserMessageParams` in `SBDBaseChannel`.
* Added `updateFileMessageWithMessageId:fileMessageParams:completionHandler:` with `SBDFileMessageParams` in `SBDBaseChannel`.
* Minor bug fixed.

## v3.0.109 (Aug 16, 2018)
 * Improved connection management.

## v3.0.107 (Aug 3, 2018)
 * Added `invitedAt` in `SBDGroupChannel`.

## v3.0.106 (Jul 13, 2018)
 * Added `loadWithCompletionHandler:`, `setMessageTypeFilter:`, `setCustomTypeFilter:`, `setSenderUserIdsFilter:` in `SBDPreviousMessageListQuery`.
 * Added `getNextMessagesByTimestamp:limit:reverse:messageType:customType:senderUserIds:completionHandler:`, `getPreviousMessagesByTimestamp:limit:reverse:messageType:customType:senderUserIds:completionHandler:`, `getPreviousAndNextMessagesByTimestamp:prevLimit:nextLimit:reverse:messageType:customType:senderUserIds:completionHandler:`, `getNextMessagesByMessageId:limit:reverse:messageType:customType:senderUserIds:completionHandler:`, `getPreviousMessagesByMessageId:limit:reverse:messageType:customType:senderUserIds:completionHandler:`, and `getPreviousAndNextMessagesByMessageId:prevLimit:nextLimit:reverse:messageType:customType:senderUserIds:completionHandler:` in `SBDBaseChannel`.

## v3.0.105 (Jul 6, 2018)
 * Disabled to put the current user into `mentionedUsers`, `mentionedUserIds` in `SBDUserMessageParams` and `SBDFileMessageParams`.
 * Changed not to increase `unreadMentionCount` and not to call `channel:didReceiveMention:` for CHANNEL mention by the current user  (i.e. the message sender is the current user).

## v3.0.104 (Jun 29, 2018)
* Added `unreadMentionCount` property in `SBDGroupChannel`.
* Added enum `SBDCountPreferenceUnreadMentionCountOnly` in `SBDCountPreference`.
* Added `SBDUnreadItemKeyNonSuperUnreadMentionCount`, `SBDUnreadItemKeySuperUnreadMentionCount`, SBDUnreadItemKeyGroupChannelUnreadMessageCount`, `SBDUnreadItemKeyGroupChannelUnreadMentionCount`, `SBDUnreadItemKeyGroupChannelInvitationCount` in `SBDUnreadItemKey`.
* Added mention type.
  * New enum type `SBDMentionType` that has `SBDMentionTypeUsers` and `SBDMentionTypeChannel`.
  * New property in `SBDBaseMessage`. 
* Deprecated instance method, `getUnreadItemCountWithKey:completionHandler:` in `SBDGroupChannel`.
  * Replaced with class method `getUnreadItemCountWithKey:completionHandler:` in `SBDGroupChannel` instead.
* Minor bug fixed.

## v3.0.102 (Jun 22, 2018)
 * Added `nicknameStartsWithFilter` in `SBDGroupChannelMemberListQuery`.
 * Added enum `SBDCountPreference`.
   * Enum has `SBDCountPreferenceAll`, `SBDCountPreferenceUnreadMessageCountOnly`, `SBDCountPreferenceOff`.
   * Added `myCountPreference` in `SBDGroupChannel` as a getter.
   * Added `setMyCountPreference:completionHandler:` in `SBDGroupChannel` as an aynchronous setter.
 * Fixed a bug that `myRole` is not updated in `SBDGroupChannel`.

## v3.0.101 (Jun 13, 2018)
 * Added `joinedMemberCount` to get count of member joined in `SBDGroupChannel`.
 * Added `myMutedState` to show whether the current user is muted or not in `SBDGroupChannel`.
 * Added an api of `getUnreadItemCountWithKey:completionHandler:` in `SBDGroupChannel`.
   * The api gets an instance of `SBDUnreadItemCount` that contains properties of `nonSuperUnreadMessageCount`, `superUnreadMessageCount`, `nonSuperInvitationCount`, `superInvitationCount`.
   * As a parameter, bitmask `SBDUnreadItemKey` is used. It has `SBDUnreadItemKeyNonSuperUnreadMessageCount`, `SBDUnreadItemKeySuperUnreadMessageCount`, `SBDUnreadItemKeyNonSuperInvitationCount`, `SBDUnreadItemKeySuperInvitationCount`.
 
## v3.0.100 (Jun 1, 2018)
 * Added a setter for typing indicator throttling interval.
 * Fixed a minor bug for `buildFromSerialize:`
 * Fixed a minor bug when uploading file in background.
 
## v3.0.99 (May 23, 2018)
 * Fixed a minor bug when uploading file in background.

## v3.0.98 (May 17, 2018)
 * Fixed an occasional member count mismatch in a super group channel.

## v3.0.97 (May 15, 2018)
 * Added a property named `myRole` in the `SBDGroupChannel` which is a role of current user in the group channel.
 * Added `SBDGroupChannelTotalUnreadMessageCountParams` class that is used to get total unread message count.

## v3.0.96 (May 3, 2018)
 * Ordered member list by nickname alphabetically.
 * Fixed a bug that an encrypted file url contains duplicated query keys.
 * Fixed minor bug.

## v3.0.95 (Apr 23, 2018)
 * Fixed minor bug.

## v3.0.94 (Apr 20, 2018)
 * Deprecated `SBDGroupChannelOperatorFilter` in `SBDGroupChannelMemberListQuery`.
 * Added `createOperatorListQuery` in `SBDBaseChannel` to query users who are operators in the channel.
 * Removed internal methods.
 * Changed code convention in headers.
 * Updated project build setting.
 * Minor bug fix.  

## v3.0.93 (Mar 30, 2018)
 * Added `SBDPushNotificationDeliveryOption` to determine how to deliver the push notification when sending a user or a file message.
 * Added a method that gets a unread message count with custom types of group channel.

## v3.0.92 (Mar 21, 2018)
 * Changed an ephemeral `SBDGroupChannel` to maintain fields of `lastMessage` and `unreadMessageCount` after connected.

## v3.0.91 (Mar 20, 2018)
 * Fixed a bug that can't send file message with a binary file.

## v3.0.90 (Mar 7, 2018)
 * Added **mentioning to specific user**.
   * added channel delegate, `channel:didReceiveMention:`, which is called when the current user is mentioned.
   * added a property named `mentionedUsers` which means the users received mention together. 
 * Added **ephemeral group channel**.
   * added a property named `isEphemeral` in `SBDBaseChannel`.
   * added a property named `isEphemeral` in `SBDGroupChannelParams`.
 * Added api that can **message with an instance of MessageParams** .
   * added `SBDUserMessageParams`, `SBDFileMessageParams` based on `SBDBaseMessageParams` to message.
   * added an api, `sendUserMessageWithParams:completionHandler:`, used to send user message with message params.
   * added apis, `sendFileMessageWithParams:completionHandler:` and `sendFileMessageWithParams:progressHandler:completionHandler:`, used to send file message with message params.
 * Added **member's state** in group channel.
   * added a property named `myMemberState` type of `SBDMemberState` which means state of member in `SBDGroupChannel`.
   * added `SBDMemberStateNone` type of enum SBDMemberState.
 * Added `setConnectionTimeout:` to configure websocket timeout.
 * Removed `SBDChannelEvent.h` and `SBDCommand.h`.

## v3.0.89 (Feb 22, 2018)
 * **Changed channel 6 delegates parameter type from `SBDOpenChannel` to `SBDBaseChannel`** 
   * changed from `channel:(SBDOpenChannel * _Nonnull)sender userWasMuted: (SBDUser * _Nonnull)user` to `channel:(SBDBaseChannel * _Nonnull)sender userWasMuted:(SBDUser * _Nonnull)user`
   * changed from `channel:(SBDOpenChannel * _Nonnull)sender userWasUnmuted:(SBDUser * _Nonnull)user` to `channel:(SBDBaseChannel * _Nonnull)sender userWasUnmuted:(SBDUser * _Nonnull)user`
   * changed from `channel:(SBDOpenChannel * _Nonnull)sender userWasBanned:(SBDUser * _Nonnull)user` to `channel:(SBDBaseChannel * _Nonnull)sender userWasBanned:(SBDUser * _Nonnull)user`
   * changed from `channel:(SBDOpenChannel * _Nonnull)sender userWasUnbanned:(SBDUser * _Nonnull)user` to `channel:(SBDBaseChannel * _Nonnull)sender userWasUnbanned:(SBDUser * _Nonnull)user`
   * changed from `channelWasFrozen:(SBDOpenChannel * _Nonnull)sender` to `channelWasFrozen:(SBDBaseChannel * _Nonnull)sender`
   * changed from `channelWasUnfrozen:(SBDOpenChannel * _Nonnull)sender` to `channelWasUnfrozen:(SBDBaseChannel * _Nonnull)sender`
 * Moved property named `isFrozen` from **SBDOpenChannel** to **SBDBaseChannel**
 * Fixed error enum type.
 * Removed warning signals.

## v3.0.88 (Feb 6, 2018)
 * Added `setSharedContainerIdentifier:` in `SBDMain` to set shared container identifier of background session configuration for App Extension
 * Added **PublicGroupChannel** features.
   * new **SBDPublicGroupChannelListQuery** class.
   * added `isPublic` in **SBDGroupChannel** to flag public group channel or private group channel. 
   * added `createPublicGroupChannelListQuery` in **SBDGroupChannel** to create public group channel list query.
   * added `joinWithCompletionHandler:` in **SBDGroupChannel** to join public group channel.
   * added filters `publicChannelFilter`, `customTypeStartsWithFilter` in **SBDPublicGroupChannelListQuery**.
   * added enum `SBDGroupChannelPublicChannelFilter` - `SBDGroupChannelPublicChannelFilterAll`, `SBDGroupChannelPublicChannelFilterPublic`, `SBDGroupChannelPublicChannelFilterPrivate`.
   * added enum `SBDPublicGroupChannelMembershipFilter` - `SBDPublicGroupChannelMembershipFilterAll`, `SBDPublicGroupChannelMembershipFilterJoined`.
 * Added `channelUrl` in **SBDGroupChannelParams** to create group channel with explicit channel url.
 * Added `SBDGroupChannelListOrderChannelNameAlphabetical` in `SBDGroupChannelListOrder` enum.
 * Added enum `SBDPublicGroupChannelListOrder` - `SBDPublicGroupChannelListOrderChronological`, `SBDPublicGroupChannelListOrderChannelNameAlphabetical`.
 * Removed `SBDLogLevelDebug` in log level.
 * Improved socket connection.

## v3.0.87 (Feb 5, 2018)
 * Added `setSharedContainerIdentifier:` in `SBDMain` to set shared container identifier of background session configuration for App Extension

## v3.0.86 (Jan 29, 2018)
 * Fixed **SBDGroupChannel** instance method name `getUnreadMemebersWithMessage:` to `getUnreadMembersWithMessage:`.
 * Fixed nullability of `init` in **SBDFriendListQuery**.
 * Deprecated **SBDGroupChannel** instance methods - `getLastSeenAtByUser:`, `getLastSeenAtByUserId:`.
 * Added **SBDGroupChannelParams** to create or update group channel.
   * added `createChannelWithParams:completionHandler:` in **SBDGroupChannel** to create group channel with params.
   * added `updateChannelWithParams:completionHandler:` in **SBDGroupChannel** to update group channel with params.
 * Added **SBDGroupChannelMemberListQuery** to query member list in group channel.
   * added `createMemberListQuery` in **SBDGroupChannel** to create member list query instance.
 * Added **SuperGroupChannel** features.
   * added `isSuper` in **SBDGroupChannel** to flag super group channel or not.
   * added enum `SBDGroupChannelSuperChannelFilter` - `SBDGroupChannelSuperChannelFilterAll`, `SBDGroupChannelSuperChannelFilterSuper`, `SBDGroupChannelSuperChannelFilterNonSuper`.
   * added `superChannelFilter` in **SBDGroupChannelListQuery** to filter super group channel.
 * Removed `coverImageName` in **SBDGroupChannelParams** 
 
## v3.0.85 (Jan 20, 2018)
 * Improved file upload.

## v3.0.84 (Jan 17, 2018)
 * Fixed a bug of updating channel.

## v3.0.83 (Jan 16, 2018)
 * Added dirty flag for cache in **SBDGroupChannel**, **SBDOpenChannel**.

## v3.0.82 (Jan 11, 2018)
 * Moved `markAsReadAllWithCompletionHandler:` from **SBDGroupChannel** to **SBDMain**.
 * Added `markAsReadWithChannelUrls:completionHandler:` in **SBDMain** to mark ad read some channels.
 * Added member state filter enum - `SBDMemberStateFilterInvitedByFriend`, `SBDMemberStatefilterInvitedByNonFriend`.
 * Changed notification key in **SBDReachability** not to conflict duplicate.
 * Changed callback parameters of `getFriendChangeLogsByToken:completionHandler:`. Combined `addedUsers` and `updatedUsers` to `updatedUsers`.
 * Change unread message count behavior.
 * Updated SocketRocket library.
 * Fixed SocketRocket library not working with 'MyDataManager' application.
 * Improved routing.
 
## v3.0.81 (Jan 10, 2018)
 * Improved socket connection.

## v3.0.80 (Jan 5, 2018)
 * Added `setCustomTypesFilter` in `SBDGroupChannelListQuery` to search group channels.  
 * Added `originalProfileUrl` in `SBDUser` for getting original profile image.  
 * Added **Friend** feature.
   * `addFriendsWithUserIds:completionHandler:` adds friends with friends' user IDs. 
   * `deleteFriendWithUserId:completionHandler:` deletes a friend with a friend's user ID.
   * `deleteFriendsWithUserIds:completionHandler:` deletes friends with friends' user IDs.  
   * `deleteFriendWithDiscovery:completionHandler:` deletes friend's discovery key.
   * `deleteFriendsWithDiscoveries:completionHandler:` deletes friends' discovery keys. 
   * `uploadFriendDiscoveries:completionHandler:` adds friend using discovery key. 
   * `getFriendChangeLogsByToken:completionHandler:` gets the logs about changing friend relation. 
   * `createFriendListQuery` creates a `SBDFriendListQuery` object for getting friend list. 
   * `addUserEventDelegate:identifier:` adds delegate for receiving user event. 
   * `removeUserEventDelegateForIdentifier:` removes user event delegate with identifier.
   * `removeAllUserEventDelegates` removes all user event delegate.
   * `SBDUserEventDelegate`: user event delegate. 
 * From now, even when you call `connectWithUserId:...` before the previous `connectWithUserId:...` finishes, all of them get called back for the connection establishment result at the same time. 

## v3.0.79 (Dec 19, 2017)
* Fixed file uploading bug.

## v3.0.78 (Dec 14, 2017)
* Fixed connection bug.

## v3.0.77 (Dec 8, 2017)
* Fixed `state` of `SBDMember` bug.

## v3.0.75 (Dec 8, 2017)
* Added `isActive` property to `SBDUser`.

## v3.0.74 (Nov 29, 2017)
* Fixed bug.

## v3.0.73 (Nov 13, 2017)
* Added `channelWasHidden:` delegate to `SBDChannelDelegate` for a channel hidden event.

## v3.0.72 (Nov 12, 2017)
* Added a group channel hidden event.

## v3.0.71 (Nov 7, 2017)
* Added `isHidden` property to a group channel.

## v3.0.70 (Oct 24, 2017)
* Fixed bug of file message's custom type.

## v3.0.69 (Oct 18, 2017)
* Turned off LLVM profiling and code coverage options.

## v3.0.68 (Oct 11, 2017)
* Bitcode support.

## v3.0.67 (Oct 6, 2017)
* **DO NOT USE THIS VERSION**
* Fixed reconnection bug.

## v3.0.66 (Sep 7, 2017)
* Fixed message parsing bug.

## v3.0.65 (Aug 28, 2017)
* Added a method to count my group channels.
* Added a method to reset the group channel history.

## v3.0.64 (Aug 21, 2017)
* Added user block flags to a member of group channels.
* Added a method to get message changelogs.
* Deprecated filters of channel list query as properties.
* Added methods for filters of channel list query.

## v3.0.63 (Aug 18, 2017)
* Added new option to the method to hide a group channel for hiding the previous messages when the channel was hidden.
* Added freeze state to open channel.
* Added user meta data.
* Added meta data filter to user list query.

## v3.0.62 (Aug 11, 2017)
* Set default value to channel data.
* Added conditions to avoid null value when channel instance is updated.
* Fixed URL encoding bug.
* Fixed memory leak.
* Added events for changing meta counters and meta data.

## v3.0.61 (Jul 25, 2017)
* Added channel url filter for group channel list query.

## v3.0.60 (Jul 19, 2017)
* Fixed serialization bug.

## v3.0.59 (Jul 17, 2017)
* Fixed serialization bug.

## v3.0.58 (Jul 15, 2017)
* Added methods to copy a user message and a file message to another channel.

## v3.0.57 (Jul 10, 2017)
* Added `SBDMember` class for an invitation.
* Changed member objects of `SBDGroupChannel` to `SBDMember` objects.
* Added the methods to accept and decline an invitation to `SBDGroupChannel` object.
* Added `SBDMemberStateFilter` for group channel list query.
* Added the methods to set and get the channel invitation preference for automatic acceptance.
* Added `channel:userDidJoin:inviter:` delegate for invitation acceptance.
* Added `channel:didReceiveInvitation:inviter:` delegate for an invitation.

## v3.0.56 (Jul 4, 2017)
* Added a setter and a getter for push sound.

## v3.0.55 (Jun 14, 2017)
* Added custom type filter to channel query.

## v3.0.54 (Jun 5, 2017)
* Fixed bug of participant count in open channel.
* Added a channel URL parameter to a method to create an open channel.

## v3.0.53 (May 19, 2017)
* Added methods to update a user message and a file message.
* Added a delegate to receive the event for message updating.
* Added a method to cancel uploading file message.

## v3.0.52 (Apr 24, 2017)
* Improved connection performance.

## v3.0.51 (Apr 19, 2017)
* **Only iOS 8.0 or later is supported from this version.** `Podfile` has to be updated for dynamic frameworks like this:
```
platform :ios, '8.0'
use_frameworks!

target YOUR_PROJECT_TARGET do
  pod 'SendBirdSDK'
end
```

## v3.0.50 (Apr 14, 2017)
* This is the biggest release since our initial v3 release. Some of changes should be carefully taken when you update the SDK.

* Now every completion handler/delegates in SDK is returned to **MAIN THREAD queue**.  It used to be inconsistent so some were returned to main thread and others to background thread.  **Be aware that you shouldn't call any blocking/long running job without using custom background queue in our completion handler/delegates!!!!**

For your convenience we added the methods to set default dispatch queue for every delegates and completion handlers. The queue can be changed like this:

```swift
[SBDMain setCompletionHandlerDelegateQueue:dispatch_get_main_queue()];
```
or
```swift
[SBDMain setCompletionHandlerDelegateQueue:dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0)];
```

* The auto reconnection is also triggered with network awareness. The default option is on but you might want to turn it off if you have manual network detection to call reconnect(). It can be turned on or off like this:
```swift
[SBDMain setNetworkAwarenessReconnection:YES];
```
or
```swift
[SBDMain setNetworkAwarenessReconnection:NO];
```
* Now we support file uploading in background so you can send very large files.

## v3.0.45 (Apr 8, 2017)
* Improved connection speed.

## v3.0.44 (Mar 13, 2017)
* Fixed serialization bug.

## v3.0.43 (Mar 9, 2017)
* Fixed unread message count bug.

## v3.0.42 (Mar 8, 2017)
* Fixed unread message count sync problem.
* Added a method to get total unread channel count.

## v3.0.41 (Mar 6, 2017)
* Added option for sync member in group channel and sender of message.
* Added accurate error.
* Fixed unread count bug of group channel.
* Added message type and custom type options for getting messages.

## v3.0.40 (Mar 2, 2017)
* Added serialization for SBDUser, SBDBaseChannel, and SBDBaseMessage object.

## v3.0.39 (Feb 25, 2017)
* Fixed bugs of send user message and file message.

## v3.0.38 (Feb 17, 2017)
* Added file encryption.
* Fixed connection bug.

## v3.0.37 (Feb 14, 2017)
* Fixed bug of updating meta counter of channel.

*Note that we don't return result objects anymore when there's an error in completion handlers starting from this version. Please make sure that you don't use a result object when an error occurs after updating SDK.*

## v3.0.36 (Jan 31, 2017)
* Fixed bug of thumbnail image in file message.

## v3.0.35 (Jan 30, 2017)
* Added a method to run reconnection.
* Improved unread message count management.
* Added error for uninitialized class.

## v3.0.33 (Jan 28, 2017)
* Improved usability of channel delegates and connection delegates.

## v3.0.32 (Jan 20, 2017)
* Modified network error code.

## v3.0.31 (Jan 19, 2017)
* Added error code for network error.

## v3.0.30 (Jan 18, 2017)
* More accurate connection state.

## v3.0.29 (Jan 17, 2017)
* Fixed the bug of unread message count in group channel.
* Added file name parameter to the message for sending file with URL.

## v3.0.28 (Jan 9, 2017)
* Added file path parameter to the methods which are for uploading file.

## v3.0.27 (Jan 4, 2017)
* Added the class to represent a thumbnail max size.

## v3.0.26 (Jan 3, 2017)
* Fixed the bug of the group channel's data.
* Added the feature for generating the thumbnail of the image file message.

## v3.0.25 (Dec 23, 2016)
* Added a feature that sets a push notification template.

## v3.0.24 (Dec 19, 2016)
* Fixed channel URL and user ID encoding bug.
* Fixed bug of creating group channel with distinct option.

## v3.0.22 (Dec 16, 2016)
* Added `unique` option to push registration.

## v3.0.21 (Dec 6, 2016)
* Fixed bug of unread message count of group channel.
* Added `isPushEnabled` property to `SBDGroupChannel` in order to represent the push notification configuration.
* Deprecated `getPushPreferenceWithCompletionHandler:` of `SBDGroupChannel`. 

## v3.0.20 (Dec 2, 2016)
* Fixed bug of unread message count and last message of group channel.

## v3.0.19 (Dec 1, 2016)
* Added user IDs filters and query type to `SBDGroupChannelListQuery`.
* Added channel custom type for `SBDOpenChannel` and `SBDGroupChannel`.
* Fixed to call `channelWasChanged:` delegate when unread message count or last message has been updated.
* Fixed bug of reconnection for `SBDOpenChannel`.

## v3.0.18 (Nov 23, 2016)
* Fixed bug of last message of group channels.

## v3.0.17 (Nov 4, 2016)
* Fixed connection bug.

## v3.0.16 (Nov 3, 2016)
* Added group channel list search by a member nickname. (Search by multiple nicknames option in v3.0.15 is no more supported.)
* Added auto-translating feature to SBDUserMessage.
* Improved connection performance.

## v3.0.15 (Oct 31, 2016)
* Added custom type to messages.
* Added group channel list search by member nicknames and user IDs.
* Added creating and updating channel cover image with binary file.

## v3.0.14 (Oct 11, 2016)
* Fixed URL encoding bug.
* Fixed minor bug.

## v3.0.13 (Oct 4, 2016)
* Support Base SDK 9.3
* Fixed bug of the channel type of messages.

## v3.0.12 (Sep 30, 2016)
* Support Carthage.
* Fixed unread message count bug.
* Fixed minor bugs.

## v3.0.11 (Sep 23, 2016)
* Fixed bug of disconnection and reconnection (APNS-related bug).

## v3.0.10 (Sep 13, 2016)
* Removed validation of sending a user message.
* Added a channel type to messages from a message query.

## v3.0.9 (Sep 6, 2016)
* Fixed bug of `data` of `SBDFileMessage`.
* Added a method to get user list with user IDs(`+ createUserListQueryWithUserIds:` of `SBDMain`).
* Added a method to register a APNS device token without login(`+ registerDevicePushToken:completionHandler:` of `SBDMain`).
* Added keywords for open channel name and URL search(`urlKeyword` and `nameKeyword` of `SBDOpenChannelListQuery`).
* Added a method to get a total unread message count(`+ getTotalUnreadMessageCountWithCompletionHandler:` of `SBDGroupChannel`).
* Added a method to get a last timestamp when a user read at the channel(`- getLastSeenAtByUser:` and `- getLastSeenAtByUserId:` of `SBDGroupChannel`).
* Added a method to get members who read the message(`- getReadMembersWithMessage:` of `SBDGroupChannel`).
* Added a method to get members who did not read the message(`- getUnreadMemebersWithMessage:` of `SBDGroupChannel`).
* Added a method to get the read status(`- getReadStatus` of `SBDGroupChannel`).
* Added methods to set push preference(`- setPushPreferenceWithPushOn:completionHandler:` and `- getPushPreferenceWithCompletionHandler:` of `SBDGroupChannel`. `+ setDoNotDisturbWithEnable:startHour:startMin:endHour:endMin:timezone:completionHandler:` and `+ getDoNotDisturbWithCompletionHandler:` of `SBDMain`).
* Deprecated `+ registerPushToken:completionHandler:` of `SBDMain`.

## v3.0.8 (Sep 1, 2016)
* Fixed group channel unread count bug.

## v3.0.7 (Sep 1, 2016)
* Fixed minor bug.

## v3.0.6 (Sep 1, 2016)
* Added URL encoding to API parameters.

## v3.0.5 (Sep 1, 2016)
* ** DO NOT USE THIS VERSION **

## v3.0.4 (Aug 30, 2016)
* Removed duplicated symbols.

## v3.0.3 (Aug 30, 2016)
* Removed duplicated symbol.

## v3.0.2 (Aug 26, 2016)
* Updated version.

## v3.0.1 (Aug 25, 2016)
* Fixed reconnection bug.

## v3.0.0 (Aug 12, 2016)
* First release.

