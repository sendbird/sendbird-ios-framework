# Change Log

### v3.0.84(Jan 17, 2018)
 * Fixed a bug of updating channel.

### v3.0.83(Jan 16, 2018)

### v3.0.82(Jan 11, 2018)

### v3.0.81(Jan 10, 2018)

### v3.0.80(Jan 5, 2018)
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

### v3.0.79(Dec 19, 2017)
* Fixed file uploading bug.

### v3.0.78(Dec 14, 2017)
* Fixed connection bug.

### v3.0.77(Dec 8, 2017)
* Fixed `state` of `SBDMember` bug.

### v3.0.75(Dec 8, 2017)
* Added `isActive` property to `SBDUser`.

### v3.0.74(Nov 29, 2017)
* Fixed bug.

### v3.0.73(Nov 13, 2017)
* Added `channelWasHidden:` delegate to `SBDChannelDelegate` for a channel hidden event.

### v3.0.72(Nov 12, 2017)
* Added a group channel hidden event.

### v3.0.71(Nov 7, 2017)
* Added `isHidden` property to a group channel.

### v3.0.70(Oct 24, 2017)
* Fixed bug of file message's custom type.

### v3.0.69(Oct 18, 2017)
* Turned off LLVM profiling and code coverage options.

### v3.0.68(Oct 11, 2017)
* Bitcode support.

### v3.0.67(Oct 6, 2017)
* **DO NOT USE THIS VERSION**
* Fixed reconnection bug.

### v3.0.66(Sep 7, 2017)
* Fixed message parsing bug.

### v3.0.65(Aug 28, 2017)
* Added a method to count my group channels.
* Added a method to reset the group channel history.

### v3.0.64(Aug 21, 2017)
* Added user block flags to a member of group channels.
* Added a method to get message changelogs.
* Deprecated filters of channel list query as properties.
* Added methods for filters of channel list query.

### v3.0.63(Aug 18, 2017)
* Added new option to the method to hide a group channel for hiding the previous messages when the channel was hidden.
* Added freeze state to open channel.
* Added user meta data.
* Added meta data filter to user list query.

### v3.0.62(Aug 11, 2017)
* Set default value to channel data.
* Added conditions to avoid null value when channel instance is updated.
* Fixed URL encoding bug.
* Fixed memory leak.
* Added events for changing meta counters and meta data.

### v3.0.61(Jul 25, 2017)
* Added channel url filter for group channel list query.

### v3.0.60(Jul 19, 2017)
* Fixed serialization bug.

### v3.0.59(Jul 17, 2017)
* Fixed serialization bug.

### v3.0.58(Jul 15, 2017)
* Added methods to copy a user message and a file message to another channel.

### v3.0.57(Jul 10, 2017)
* Added `SBDMember` class for an invitation.
* Changed member objects of `SBDGroupChannel` to `SBDMember` objects.
* Added the methods to accept and decline an invitation to `SBDGroupChannel` object.
* Added `SBDMemberStateFilter` for group channel list query.
* Added the methods to set and get the channel invitation preference for automatic acceptance.
* Added `channel:userDidJoin:inviter:` delegate for invitation acceptance.
* Added `channel:didReceiveInvitation:inviter:` delegate for an invitation.

### v3.0.56(Jul 4, 2017)
* Added a setter and a getter for push sound.

### v3.0.55(Jun 14, 2017)
* Added custom type filter to channel query.

### v3.0.54(Jun 5, 2017)
* Fixed bug of participant count in open channel.
* Added a channel URL parameter to a method to create an open channel.

### v3.0.53(May 19, 2017)
* Added methods to update a user message and a file message.
* Added a delegate to receive the event for message updating.
* Added a method to cancel uploading file message.

### v3.0.52(Apr 24, 2017)
* Improved connection performance.

### v3.0.51(Apr 19, 2017)
* **Only iOS 8.0 or later is supported from this version.** `Podfile` has to be updated for dynamic frameworks like this:
```
platform :ios, '8.0'
use_frameworks!

target YOUR_PROJECT_TARGET do
  pod 'SendBirdSDK'
end
```

### v3.0.50(Apr 14, 2017)
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

### v3.0.45(Apr 8, 2017)
* Improved connection speed.

### v3.0.44(Mar 13, 2017)
* Fixed serialization bug.

### v3.0.43(Mar 9, 2017)
* Fixed unread message count bug.

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

