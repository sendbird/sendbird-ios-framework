# Change Log

### v3.0.42(Mar 8, 2017)
* Fixed unread message count sync problem.
* Added a method to get total unread channel count.

### v3.0.41(Mar 6, 2017)
* Added option for sync member in group channel and sender of message.
* Added accurate error.
* Fixed unread count bug of group channel.
* Added message type and custom type options for getting messages.

### v3.0.40(Mar 2, 2017)
* Added serialization for SBDUser, SBDBaseChannel, and SBDBaseMessage object.

### v3.0.39(Feb 25, 2017)
* Fixed bugs of send user message and file message.

### v3.0.38(Feb 17, 2017)
* Added file encryption.
* Fixed connection bug.

### v3.0.37(Feb 14, 2017)
* Fixed bug of updating meta counter of channel.

*Note that we don't return result objects anymore when there's an error in completion handlers starting from this version. Please make sure that you don't use a result object when an error occurs after updating SDK.*

### v3.0.36(Jan 31, 2017)
* Fixed bug of thumbnail image in file message.

### v3.0.35(Jan 30, 2017)
* Added a method to run reconnection.
* Improved unread message count management.
* Added error for uninitialized class.

### v3.0.33(Jan 28, 2017)
* Improved usability of channel delegates and connection delegates.

### v3.0.32(Jan 20, 2017)
* Modified network error code.

### v3.0.31(Jan 19, 2017)
* Added error code for network error.

### v3.0.30(Jan 18, 2017)
* More accurate connection state.

### v3.0.29(Jan 17, 2017)
* Fixed the bug of unread message count in group channel.
* Added file name parameter to the message for sending file with URL.

### v3.0.28(Jan 9, 2017)
* Added file path parameter to the methods which are for uploading file.

### v3.0.27(Jan 4, 2017)
* Added the class to represent a thumbnail max size.

### v3.0.26(Jan 3, 2017)
* Fixed the bug of the group channel's data.
* Added the feature for generating the thumbnail of the image file message.

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

