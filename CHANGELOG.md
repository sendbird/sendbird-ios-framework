# Change Log

### v3.0.25(Dec 23, 2016)
* Added a feature that sets a push notification template.

### v3.0.24(Dec 19, 2016)
* Fixed channel URL and user ID encoding bug.
* Fixed bug of creating group channel with distinct option.

### v3.0.22(Dec 16, 2016)
* Added `unique` option to push registration.

### v3.0.21(Dec 6, 2016)
* Fixed bug of unread message count of group channel.
* Added `isPushEnabled` property to `SBDGroupChannel` in order to represent the push notification configuration.
* Deprecated `getPushPreferenceWithCompletionHandler:` of `SBDGroupChannel`. 

### v3.0.20(Dec 2, 2016)
* Fixed bug of unread message count and last message of group channel.

### v3.0.19(Dec 1, 2016)
* Added user IDs filters and query type to `SBDGroupChannelListQuery`.
* Added channel custom type for `SBDOpenChannel` and `SBDGroupChannel`.
* Fixed to call `channelWasChanged:` delegate when unread message count or last message has been updated.
* Fixed bug of reconnection for `SBDOpenChannel`.

### v3.0.18(Nov 23, 2016)
* Fixed bug of last message of group channels.

### v3.0.17(Nov 4, 2016)
* Fixed connection bug.

### v3.0.16(Nov 3, 2016)
* Added group channel list search by a member nickname. (Search by multiple nicknames option in v3.0.15 is no more supported.)
* Added auto-translating feature to SBDUserMessage.
* Improved connection performance.

### v3.0.15(Oct 31, 2016)
* Added custom type to messages.
* Added group channel list search by member nicknames and user IDs.
* Added creating and updating channel cover image with binary file.

### v3.0.14(Oct 11, 2016)
* Fixed URL encoding bug.
* Fixed minor bug.

### v3.0.13(Oct 4, 2016)
* Support Base SDK 9.3
* Fixed bug of the channel type of messages.

### v3.0.12(Sep 30, 2016)
* Support Carthage.
* Fixed unread message count bug.
* Fixed minor bugs.

### v3.0.11(Sep 23, 2016)
* Fixed bug of disconnection and reconnection(APNS-related bug).

### v3.0.10(Sep 13, 2016)
* Removed validation of sending a user message.
* Added a channel type to messages from a message query.

### v3.0.9(Sep 6, 2016)
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

### v3.0.8(Sep 1, 2016)
* Fixed group channel unread count bug.

### v3.0.7(Sep 1, 2016)
* Fixed minor bug.

### v3.0.6(Sep 1, 2016)
* Added URL encoding to API parameters.

### v3.0.5(Sep 1, 2016)
* ** DO NOT USE THIS VERSION **

### v3.0.4(Aug 30, 2016)
* Removed duplicated symbols.

### v3.0.3(Aug 30, 2016)
* Removed duplicated symbol.

### v3.0.2(Aug 26, 2016)
* Updated version.

### v3.0.1(Aug 25, 2016)
* Fixed reconnection bug.

### v3.0.0(Aug 12, 2016)
* First release.

