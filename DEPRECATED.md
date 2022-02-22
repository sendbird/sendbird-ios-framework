# Deprecated classes, methods, properties

## v3.1.4
| Old class | Old property | New class | New property |
| --------- | ---------- | --------- | ---------- |
|SBDAuthenticateDelegate||*No Alternative*||
|SBDConnectionManager||*No Alternative*||

## v3.1.0
| Old class | Old property | New class | New property |
| --------- | ---------- | --------- | ---------- |
|`SBDBaseMessage`|`parentMessageText`|`SBDBaseMessage`|`parentMessage`|
|`SBDMessageListParams`|`includeReplies`|`SBDMessageListParams`|`replyType`|
|`SBDMessageChangeLogsParams`|`includeReplies`|`SBDMessageChangeLogsParams`|`replyType`|
|`SBDPreviousMessageListQuery`|`includeReplies`|`SBDPreviousMessageListQuery`|`replyType`|
|`SBDMessageListParams`|`includeParentMessageText`|`SBDMessageListParams`|`includeParentMessageInfo`|
|`SBDMessageChangeLogsParams`|`includeParentMessageText`|`SBDMessageChangeLogsParams`|`includeParentMessageInfo`|
|`SBDMessageRetrievalParams`|`includeParentMessageText`|`SBDPreviousMessageListQuery`|`includeParentMessageInfo`|
|`SBDPreviousMessageListQuery`|`includeParentMessageText`|`SBDPreviousMessageListQuery`|`includeParentMessageInfo`|


## v3.0.234
| Old class | Old method | New class | New method |
| --------- | ---------- | --------- | ---------- |
|`SBDGroupChannel`|`markAsRead`|`SBDGroupChannel`|`markAsReadWithCompletionHandler:`|

## v3.0.231
| Old class | Old method | New class | New method |
| --------- | ---------- | --------- | ---------- |
|`SBDBaseChannel`|`getNextMessagesByTimestamp:limit:reverse:messageType:customType:completionHandler:`|`SBDBaseChannel`|`getMessagesByTimestamp:params:completionHandler:`|
|`SBDBaseChannel`|`getNextMessagesByTimestamp:limit:reverse:messageType:customType:senderUserIds:completionHandler:`|`SBDBaseChannel`|`getMessagesByTimestamp:params:completionHandler:`|
|`SBDBaseChannel`|`getNextMessagesByTimestamp:limit:reverse:messageType:customType:senderUserIds:includeMetaArray:completionHandler:`|`SBDBaseChannel`|`getMessagesByTimestamp:params:completionHandler:`|
|`SBDBaseChannel`|`getNextMessagesByTimestamp:inclusiveTimestamp:limit:reverse:messageType:customType:senderUserIds:includeMetaArray:includeReactions:completionHandler:`|`SBDBaseChannel`|`getMessagesByTimestamp:params:completionHandler:`|
|`SBDBaseChannel`|`getPreviousMessagesByTimestamp:limit:reverse:messageType:customType:completionHandler:`|`SBDBaseChannel`|`getMessagesByTimestamp:params:completionHandler:`|
|`SBDBaseChannel`|`getPreviousMessagesByTimestamp:limit:reverse:messageType:customType:senderUserIds:completionHandler:`|`SBDBaseChannel`|`getMessagesByTimestamp:params:completionHandler:`|
|`SBDBaseChannel`|`getPreviousMessagesByTimestamp:limit:reverse:messageType:customType:senderUserIds:includeMetaArray:completionHandler:`|`SBDBaseChannel`|`getMessagesByTimestamp:params:completionHandler:`|
|`SBDBaseChannel`|`getPreviousMessagesByTimestamp:inclusiveTimestamp:limit:reverse:messageType:customType:senderUserIds:includeMetaArray:includeReactions:completionHandler:`|`SBDBaseChannel`|`getMessagesByTimestamp:params:completionHandler:`|
|`SBDBaseChannel`|`getPreviousAndNextMessagesByTimestamp:prevLimit:nextLimit:reverse:messageType:customType:completionHandler:`|`SBDBaseChannel`|`getMessagesByTimestamp:params:completionHandler:`|
|`SBDBaseChannel`|`getPreviousAndNextMessagesByTimestamp:prevLimit:nextLimit:reverse:messageType:customType:senderUserIds:completionHandler:`|`SBDBaseChannel`|`getMessagesByTimestamp:params:completionHandler:`|
|`SBDBaseChannel`|`getPreviousAndNextMessagesByTimestamp:prevLimit:nextLimit:reverse:messageType:customType:senderUserIds:includeMetaArray:includeReactions:completionHandler:`|`SBDBaseChannel`|`getMessagesByTimestamp:params:completionHandler:`|
|`SBDBaseChannel`|`getNextMessagesByMessageId:limit:reverse:messageType:customType:completionHandler:`|`SBDBaseChannel`|`getMessagesByMessageId:params:completionHandler:`|
|`SBDBaseChannel`|`getNextMessagesByMessageId:limit:reverse:messageType:customType:senderUserIds:completionHandler:`|`SBDBaseChannel`|`getMessagesByMessageId:params:completionHandler:`|
|`SBDBaseChannel`|`getNextMessagesByMessageId:inclusiveTimestamp:limit:reverse:messageType:customType:senderUserIds:includeMetaArray:includeReactions:completionHandler:`|`SBDBaseChannel`|`getMessagesByMessageId:params:completionHandler:`|
|`SBDBaseChannel`|`getPreviousMessagesByMessageId:limit:reverse:messageType:customType:completionHandler:`|`SBDBaseChannel`|`getMessagesByMessageId:params:completionHandler:`|
|`SBDBaseChannel`|`getPreviousMessagesByMessageId:limit:reverse:messageType:customType:senderUserIds:completionHandler:`|`SBDBaseChannel`|`getMessagesByMessageId:params:completionHandler:`|
|`SBDBaseChannel`|`getPreviousMessagesByMessageId:inclusiveTimestamp:limit:reverse:messageType:customType:senderUserIds:includeMetaArray:includeReactions:completionHandler:`|`SBDBaseChannel`|`getMessagesByMessageId:params:completionHandler:`|
|`SBDBaseChannel`|`getPreviousAndNextMessagesByMessageId:prevLimit:nextLimit:reverse:messageType:customType:completionHandler:`|`SBDBaseChannel`|`getMessagesByMessageId:params:completionHandler:`|
|`SBDBaseChannel`|`getPreviousAndNextMessagesByMessageId:prevLimit:nextLimit:reverse:messageType:customType:senderUserIds:completionHandler:`|`SBDBaseChannel`|`getMessagesByMessageId:params:completionHandler:`|
|`SBDBaseChannel`|`getPreviousAndNextMessagesByMessageId:prevLimit:nextLimit:reverse:messageType:customType:senderUserIds:includeMetaArray:includeReactions:completionHandler:`|`SBDBaseChannel`|`getMessagesByMessageId:params:completionHandler:`|
|`SBDBaseChannel`|`getMessageChangeLogsWithToken:completionHandler:`|`SBDBaseChannel`|`getMessageChangeLogsSinceToken:params:completionHandler:`|
|`SBDBaseChannel`|`getMessageChangeLogsWithToken:includeMetaArray:completionHandler:`|`SBDBaseChannel`|`getMessageChangeLogsSinceToken:params:completionHandler:`|
|`SBDBaseChannel`|`getMessageChangeLogsWithToken:includeMetaArray:includeReactions:completionHandler:`|`SBDBaseChannel`|`getMessageChangeLogsSinceToken:params:completionHandler:`|
|`SBDBaseChannel`|`getMessageChangeLogsByTimestamp:completionHandler:`|`SBDBaseChannel`|`getMessageChangeLogsSinceTimestamp:params:completionHandler:`|
|`SBDBaseChannel`|`getMessageChangeLogsByTimestamp:includeMetaArray:completionHandler:`|`SBDBaseChannel`|`getMessageChangeLogsSinceTimestamp: params:completionHandler:`|
|`SBDBaseChannel`|`getMessageChangeLogsByTimestamp:includeMetaArray:includeReactions:completionHandler:`|`SBDBaseChannel`|`getMessageChangeLogsSinceTimestamp: params:completionHandler:`|

## v3.0.207

### Methods

| Old class | Old method | New class | New method |
| --------- | ---------- | --------- | ---------- |
| `SBDGroupChannel` | `setPushPreferenceWithPushOn:completionHandler:` | `SBDGroupChannel` | `setMyPushTriggerOption:completionHandler:` |

## v3.0.202

### Methods

| Old class | Old method | New class | New method |
| --------- | ---------- | --------- | ---------- |
| `SBDGroupChannel` | `getTypingMembers` | `SBDGroupChannel` | `getTypingUsers` |

## v3.0.185

### Methods

| Old class | Old method | New class | New method |
| --------- | ---------- | --------- | ---------- |
| `SBDGroupChannel` | `markAsDelivered` | | *No Alternative* |
| `SBDGroupChannel` | `getReadReceiptOfMessage:` | `SBDGroupChannel` | `getUnreadMemberCount:` |
| `SBDGroupChannel` | `getDeliveryReceipt:` | `SBDGroupChannel` | `getUndeliveredMemberCount:` |
| `SBDMain` | `markAsDeliveredWithChannelUrl:` |  | *No Alternative* |

## v3.0.182

### Methods

| Old class | Old method | New class | New method |
| --------- | ---------- | --------- | ---------- |
| `SBDMain` | `getMyGroupChannelChangeLogsByToken:customTypes:completionHandler:` | `SBDMain` | `getMyGroupChannelChangeLogsByToken:params:completionHandler` |
| `SBDMain` | `getMyGroupChannelChangeLogsByToken:customTypes:includeEmptyChannel:completionHandler:` | `SBDMain` | `getMyGroupChannelChangeLogsByToken:params:completionHandler` |
| `SBDMain` | `getMyGroupChannelChangeLogsByTimestamp:customTypes:completionHandler:` | `SBDMain` | `getMyGroupChannelChangeLogsByTimestamp:params:completionHandler` |
| `SBDMain` | `getMyGroupChannelChangeLogsByTimestamp:customTypes:includeEmptyChannel:completionHandler:` | `SBDMain` | `getMyGroupChannelChangeLogsByTimestamp:params:completionHandler` |

## v3.0.175

### Methods

| Old class | Old method | New class | New method |
| --------- | ---------- | --------- | ---------- |
| `SBDBaseChannel` | `getNextMessagesByMessageId:limit:reverse:messageType:customType:senderUserIds:includeMetaArray:includeReactions:completionHandler:` | `SBDBaseChannel` | `getMessagesByMessageId:params:completionHandler:` |
| `SBDBaseChannel` | `getPreviousMessagesByMessageId:limit:reverse:messageType:customType:senderUserIds:includeMetaArray:includeReactions:completionHandler:` | `SBDBaseChannel` | `getMessagesByMessageId:params:completionHandler:` |

## v3.0.179

### Properties

| Old class | Old property | New class | New property |
| --------- | ------------ | --------- | ------------ |
| `SBDBaseMessageParams` | `metaArrayKeys` | `SBDBaseMessageParams` | `metaArrays` |

## v3.0.173

### Enum

| Old enum type | Old enum value | New enum type | New enum value |
| --------- | ---------- | --------- | ---------- |
| `SBDMessageRequestState` | `SBDMessageRequestStateNone` | `SBDMessageSendingStatus` | `SBDMessageSendingStatusNone` |
| `SBDMessageRequestState` | `SBDMessageRequestStatePending` | `SBDMessageSendingStatus` | `SBDMessageSendingStatusPending` |
| `SBDMessageRequestState` | `SBDMessageRequestStateFailed` | `SBDMessageSendingStatus` | `SBDMessageSendingStatusFailed` |
| `SBDMessageRequestState` | `SBDMessageRequestStateSucceeded` | `SBDMessageSendingStatus` | `SBDMessageSendingStatusSucceeded` |

### Properties

| Old class | Old property | New class | New property |
| --------- | ------------ | --------- | ------------ |
| `SBDUserMessage` | `requestState` | `SBDUserMessage` | `sendingStatus` |
| `SBDFileMessage` | `requestState` | `SBDFileMessage` | `sendingStatus` |

## v3.0.169

### Methods

| Old class | Old method | New class | New method |
| --------- | ---------- | --------- | ---------- |
| `SBDBaseChannel` | `getNextMessagesByTimestamp:inclusiveTimestamp:limit:reverse:messageType:customType:senderUserIds:includeMetaArray:completionHandler:` | `SBDBaseChannel` | `getMessagesByTimestamp:params:completionHandler:` |
| `SBDBaseChannel` | `getPreviousMessagesByTimestamp:inclusiveTimestamp:limit:reverse:messageType:customType:senderUserIds:includeMetaArray:completionHandler:` | `SBDBaseChannel` | `getMessagesByTimestamp:params:completionHandler:` |
| `SBDBaseChannel` | `getNextMessagesByMessageId:limit:reverse:messageType:customType:senderUserIds:includeMetaArray:completionHandler:` | `SBDBaseChannel` | `getMessagesByMessageId:params:completionHandler:` |
| `SBDBaseChannel` | `getPreviousMessagesByMessageId:limit:reverse:messageType:customType:senderUserIds:includeMetaArray:completionHandler:` | `SBDBaseChannel` | `getMessagesByMessageId:params:completionHandler:` |
| `SBDBaseChannel` | `getPreviousAndNextMessagesByMessageId:prevLimit:nextLimit:reverse:messageType:customType:senderUserIds:includeMetaArray:completionHandler:` | `SBDBaseChannel` | `getMessagesByMessageId:params:completionHandler:` |

## v3.0.148

### Properties

| Old class | Old property | New class | New property |
| --------- | ------------ | --------- | ------------ |
| `SBDBaseMessage` | `metaArray` | `SBDBaseMessage` | `metaArrays` |
| `SBDScheduledUserMessage` | `metaArray` | `SBDScheduledUserMessage` | `metaArrays` |

### Methods

| Old class | Old method | New class | New method |
| --------- | ---------- | --------- | ---------- |
| `SBDBaseMessage` | `getMetaArrayWithKeys:` | `SBDBaseMessage` | `metaArraysWithKeys:` |
| `SBDScheduledUserMessage` | `getMetaArrayWithKeys:` | `SBDScheduledUserMessage` | `metaArraysWithKeys:` |

## v3.0.128

### Properties

| Old class | Old property | New class | New property |
| --------- | ------------ | --------- | ------------ |
| `SBDGroupChannel` | `isPushEnabled` | `SBDGroupChannel` | `myPushTriggerOption` |

## v3.0.120

### Properties

| Old class | Old property | New class | New property |
| --------- | ------------ | --------- | ------------ |
| `SBDUserListQuery` | `metaDataKey` | `SBDApplicationUserListQuery` | `setMetaDataFilterWithKey:values:` |
| `SBDUserListQuery` | `metaDataValues` | `SBDApplicationUserListQuery` | `setMetaDataFilterWithKey:values:` |

### Methods

| Old class | Old method | New class | New method |
| --------- | ---------- | --------- | ---------- |
| `SBDUserListQuery` | `setMetaDataFilterWithKey:values:` | `SBDApplicationUserListQuery` | `setMetaDataFilterWithKey:values:` |
| `SBDMain` | `createAllUserListQuery` | `SBDMain` | `createApplicationUserListQuery` |
| `SBDMain` | `createUserListQueryWithUserIds:` | `SBDApplicationUserListQuery` | `userIdsFilter` |


## v3.0.116

### Methods

| Old class | Old method | New class | New method |
| --------- | ---------- | --------- | ---------- |
| `SBDBaseChannel` | `sendUserMessage:targetLanguages:completionHandler:` | `SBDBaseChannel` | `sendUserMessageWithParams:completionHandler:` |
| `SBDBaseChannel` | `sendUserMessage:data:completionHandler` | `SBDBaseChannel` | `sendUserMessageWithParams:completionHandler:` |
| `SBDBaseChannel` | `sendUserMessage:data:targetLanguages:completionHandler:` | `SBDBaseChannel` | `sendUserMessageWithParams:completionHandler:` |
| `SBDBaseChannel`| `sendUserMessage:data:customType:completionHandler:` | `SBDBaseChannel` | `sendUserMessageWithParams:completionHandler:` |
| `SBDBaseChannel`| `sendUserMessage:data:customType:targetLanguages:completionHandler:` | `SBDBaseChannel` | `sendUserMessageWithParams:completionHandler:` |
| `SBDBaseChannel`| `sendFileMessageWithBinaryData:filename:type:size:data:customType:completionHandler:` | `SBDBaseChannel` | `sendFileMessageWithParams:progressHandler:completionHandler:` |
| `SBDBaseChannel`| `sendFileMessageWithBinaryData:filename:type:size:data:progressHandler:completionHandler:` | `SBDBaseChannel` | `sendFileMessageWithParams:progressHandler:completionHandler:` |
| `SBDBaseChannel`| `sendFileMessageWithBinaryData:filename:type:size:data:customType:progressHandler:completionHandler:` | `SBDBaseChannel` | `sendFileMessageWithParams:progressHandler:completionHandler:` |
| `SBDGroupChannel`| `createChannelWithName:users:coverUrl:data:completionHandler:` | `SBDGroupChannel` | `createChannelWithParams:progressHandler:completionHandler:` |
| `SBDGroupChannel`| `createChannelWithName:users:coverImage:coverImageName:data:progressHandler:completionHandler:` | `SBDGroupChannel` | `createChannelWithParams:progressHandler:completionHandler:` |
| `SBDGroupChannel`| `createChannelWithName:userIds:coverUrl:data:completionHandler:` | `SBDGroupChannel` | `createChannelWithParams:progressHandler:completionHandler:` |
| `SBDGroupChannel`| `createChannelWithName:userIds:coverImage:coverImageName:data:progressHandler:completionHandler:` | `SBDGroupChannel` | `createChannelWithParams:progressHandler:completionHandler:` |
| `SBDGroupChannel`| `createChannelWithName:isDistinct:users:coverUrl:data:completionHandler:` | `SBDGroupChannel` | `createChannelWithParams:progressHandler:completionHandler:` |
| `SBDGroupChannel`| `createChannelWithName:isDistinct:users:coverImage:coverImageName:data:progressHandler:completionHandler:` | `SBDGroupChannel` | `createChannelWithParams:progressHandler:completionHandler:` |
| `SBDGroupChannel` | `createChannelWithName:isDistinct:userIds:coverUrl:data:completionHandler:` | `SBDGroupChannel` | `createChannelWithParams:progressHandler:completionHandler:` |
| `SBDGroupChannel` | `createChannelWithName:isDistinct:userIds:coverUrl:data:customType:completionHandler:` | `SBDGroupChannel` | `createChannelWithParams:progressHandler:completionHandler:` |
| `SBDGroupChannel` | `updateChannelWithName:isDistinct:coverUrl:data:completionHandler:` | `SBDGroupChannel` | `updateChannelWithParams:progressHandler:completionHandler:` |
| `SBDGroupChannel` | `updateChannelWithName:isDistinct:coverUrl:data:customType:completionHandler:` | `SBDGroupChannel` | `updateChannelWithParams:progressHandler:completionHandler:` |
| `SBDGroupChannel` | `updateChannelWithName:coverUrl:data:completionHandler:` | `SBDGroupChannel` | `updateChannelWithParams:progressHandler:completionHandler:` |
| `SBDGroupChannel` | `createChannelWithName:isDistinct:userIds:coverImage:coverImageName:data:progressHandler:completionHandler:` | `SBDGroupChannel` | `createChannelWithParams:progressHandler:completionHandler:` |
| `SBDGroupChannel` | `createChannelWithName:isDistinct:userIds:coverImageFilePath:data:customType:progressHandler:completionHandler:` | `SBDGroupChannel` | `createChannelWithParams:progressHandler:completionHandler:` |
| `SBDGroupChannel` | `updateChannelWithName:isDistinct:coverImage:coverImageName:data:progressHandler:completionHandler:` | `SBDGroupChannel` | `updateChannelWithParams:progressHandler:completionHandler:` |
| `SBDGroupChannel` | `updateChannelWithName:isDistinct:coverImageFilePath:data:customType:progressHandler:completionHandler:` | `SBDGroupChannel` | `updateChannelWithParams:progressHandler:completionHandler:` |
| `SBDGroupChannel` | `updateChannelWithName:coverImage:coverImageName:data:progressHandler:completionHandler:` | `SBDGroupChannel` | `updateChannelWithParams:progressHandler:completionHandler:` |
| `SBDGroupChannel` | `getChannelWithoutCache:completionHandler:` | | *No Alternative* |
| `SBDGroupChannel` | `getChannelFromCacheWithChannelUrl:` | | *No Alternative* |
| `SBDGroupChannel` | `getTotalUnreadMessageCountWithCompletionHandler:` | `SBDMain` | `getTotalUnreadMessageCountWithCompletionHandler:` |
| `SBDGroupChannel` | `getTotalUnreadChannelCountWithCompletionHandler:` | `SBDMain` | `getTotalUnreadChannelCountWithCompletionHandler:` |
| `SBDGroupChannel` | `getTotalUnreadMessageCountWithChannelCustomTypes:completionHandler:`	| `SBDMain` | `getTotalUnreadMessageCountWithParams:completionHandler:` |
| `SBDGroupChannel` | `getTotalUnreadMessageCountWithParams:completionHandler:` | `SBDMain` | `getTotalUnreadMessageCountWithParams:completionHandler:` |
| `SBDGroupChannel` | `hasChannelInCache:` | | | *No Alternative* |
| `SBDGroupChannel` | `getChannelCountWithMemberStateFilter:completionHandler:` | `SBDMain` | `getChannelCountWithMemberStateFilter:completionHandler:` |
| `SBDGroupChannel` | `getUnreadItemCountWithKey:completionHandler:` | `SBDMain` | `getUnreadItemCountWithKey:completionHandler:` |
| `SBDOpenChannel` | `createChannelWithName:coverUrl:data:operatorUsers:completionHandler:` | `SBDOpenChannel` | `createChannelWithParams:progressHandler:completionHandler:` |
| `SBDOpenChannel` | `createChannelWithName:coverImage:coverImageName:data:operatorUsers:progressHandler:completionHandler:` | `SBDOpenChannel` | `createChannelWithParams:progressHandler:completionHandler:` |
| `SBDOpenChannel` | `createChannelWithName:coverUrl:data:operatorUserIds:completionHandler:` | `SBDOpenChannel` | `createChannelWithParams:progressHandler:completionHandler:` |
| `SBDOpenChannel` | `createChannelWithName:coverUrl:data:operatorUserIds:customType:completionHandler:` | `SBDOpenChannel` | `createChannelWithParams:progressHandler:completionHandler:` |
| `SBDOpenChannel` | `createChannelWithName:coverImage:coverImageName:data:operatorUserIds:progressHandler:completionHandler:` | `SBDOpenChannel` | `createChannelWithParams:progressHandler:completionHandler:` |
| `SBDOpenChannel` | `createChannelWithName:coverImage:coverImageName:data:operatorUserIds:customType:progressHandler:completionHandler:` | `SBDOpenChannel` | `createChannelWithParams:progressHandler:completionHandler:` |
| `SBDOpenChannel` | `createChannelWithName:coverImageFilePath:data:operatorUserIds:customType:progressHandler:completionHandler:` | `SBDOpenChannel` | `createChannelWithParams:progressHandler:completionHandler:` |
| `SBDOpenChannel` | `createChannelWithName:channelUrl:coverImageFilePath:data:operatorUserIds:customType:progressHandler:completionHandler:` | `SBDOpenChannel` | `createChannelWithParams:progressHandler:completionHandler:` |
| `SBDOpenChannel` | `updateChannelWithName:coverImage:coverImageName:data:operatorUsers:progressHandler:completionHandler:` | `SBDOpenChannel` | `updateChannelWithParams:progressHandler:completionHandler:` |
| `SBDOpenChannel` | `updateChannelWithName:coverUrl:data:operatorUserIds:completionHandler:` | `SBDOpenChannel` | `updateChannelWithParams:progressHandler:completionHandler:` |
| `SBDOpenChannel` | `updateChannelWithName:coverUrl:data:operatorUserIds:customType:completionHandler:` | `SBDOpenChannel` | `updateChannelWithParams:progressHandler:completionHandler:` |
| `SBDOpenChannel` | `updateChannelWithName:coverImage:coverImageName:data:operatorUserIds:progressHandler:completionHandler:` | `SBDOpenChannel` | `updateChannelWithParams:progressHandler:completionHandler:` |
| `SBDOpenChannel` | `updateChannelWithName:coverImageFilePath:data:operatorUserIds:customType:progressHandler:completionHandler:` | `SBDOpenChannel` | `updateChannelWithParams:progressHandler:completionHandler:` |
| `SBDFileMessage` | `buildWithFileUrl:name:size:type:data:requestId:sender:channel:customType:` | | *No Alternative* |
| `SBDFileMessage` | `buildWithFileUrl:name:size:type:data:requestId:sender:channel:customType:thumbnailSizes:` | | *No Alternative* |

## v3.0.115

### Methods

| Old class | Old method | New class | New method |
| --------- | ---------- | --------- | ---------- |
| `SBDGroupChannel` | `getReadMembersWithMessage:` | `SBDGroupChannel` | `getReadMembersWithMessage:includeAllMembers:` |
| `SBDGroupChannel` | `getUnreadMembersWithMessage:` | `SBDGroupChannel` | `getUnreadMembersWithMessage:includeAllMembers:` |
| `SBDGroupChannel` | `getReadStatus` | `SBDGroupChannel` | `getReadStatusIncludingAllMembers:` |

### Enum

| Old enum type | Old enum value | New enum type | New enum value |
| --------- | ---------- | --------- | ---------- |
| `SBDWebSocketConnectionState` | `SBDWebSocketClosing` | `SBDWebSocketConnectionState` | `SBDWebSocketClosed` |

## v3.0.103

### Methods

| Old class | Old method | New class | New method |
| --------- | ---------- | --------- | ---------- |
| `SBDGroupChannel` | `getUnreadItemCountWithKey:completionHandler:` | `SBDGroupChannel` | `getUnreadItemCountWithKey:completionHandler:` |

## v3.0.94

### Methods

| Old class | Old method | New class | New method |
| --------- | ---------- | --------- | ---------- |
| `SBDGroupChannel` | `markAsReadAllWithCompletionHandler:` | `SBDMain` | `markAsReadAllWithCompletionHandler:` |

## 3.0.86

### Methods

| Old class | Old method | New class | New method |
| --------- | ---------- | --------- | ---------- |
| `SBDGroupChannel` | `getLastSeenAtByUser:` | `SBDGroupChannel` | `getReadMembersWithMessage:includeAllMembers:` |
| `SBDGroupChannel` | `getLastSeenAtByUserId:` |  `SBDGroupChannel` | `getReadMembersWithMessage:includeAllMembers:` |

## 3.0.79

### Methods

| Old class | Old method | New class | New method |
| --------- | ---------- | --------- | ---------- |
| `SBDGroupChannelListQuery` | `setCustomTypeFilter:` | `SBDGroupChannelListQuery` | `customTypesFilter:` |

## v3.0.64

### Properties

| Old class | Old property | New class | New property |
| --------- | ------------ | --------- | ------------ |
| `SBDOpenChannelListQuery` | `urlKeyword` | `SBDOpenChannelListQuery` | `channelUrlFilter` |
| `SBDOpenChannelListQuery` | `nameKeyword` | `SBDOpenChannelListQuery` | `channelNameFilter` |
| `SBDGroupChannelListQuery` | `customTypeFilter` | `SBDGroupChannelListQuery` | `customTypesFilter` |
| `SBDGroupChannelListQuery` | `channelNameFilter` | `SBDGroupChannelListQuery` | `channelNameContainsFilter` |

## v3.0.63

### Methods

| Old class | Old method | New class | New method |
| --------- | ---------- | --------- | ---------- |
| `SBDGroupChannel` | `hideChannelWithCompletionHandler:` | `SBDGroupChannel` | `hideChannelWithHidePreviousMessages:completionHandler:` |

## v3.0.42

### Properties

| Old class | Old property | New class | New property |
| --------- | ------------ | --------- | ------------ |
| `SBDGroupChannel` | `sendMarkAsReadEnable` | | *No Alternative* |

## v3.0.40

### Methods

| Old class | Old method | New class | New method |
| --------- | ---------- | --------- | ---------- |
| `SBDBaseChannel` | `getNextMessagesByTimestamp:limit:reverse:completionHandler` | `SBDBaseChannel` | `getMessagesByTimestamp:params:completionHandler:` |
| `SBDBaseChannel` | `getPreviousMessagesByTimestamp:limit:reverse:completionHandler` | `SBDBaseChannel` | `getMessagesByTimestamp:params:completionHandler:` |
| `SBDBaseChannel` | `getPreviousAndNextMessagesByTimestamp:prevLimit:nextLimit:reverse:completionHandler` | `SBDBaseChannel` | `getMessagesByTimestamp:params:completionHandler:` |
| `SBDBaseChannel` | `getNextMessagesByMessageId:limit:reverse:completionHandler` | `SBDBaseChannel` | `getMessagesByMessageId:params:completionHandler:` |
| `SBDBaseChannel` | `getPreviousMessagesByMessageId:limit:reverse:completionHandler:` | `SBDBaseChannel` | `getMessagesByMessageId:params:completionHandler:` |
| `SBDBaseChannel` | `getPreviousAndNextMessagesByMessageId:prevLimit:nextLimit:reverse:completionHandler:` | `SBDBaseChannel` | `getMessagesByMessageId:params:completionHandler:` |

## v3.0.29

### Methods

| Old class | Old method | New class | New method |
| --------- | ---------- | --------- | ---------- |
| `SBDBaseChannel` | `createMessageListQuery` | `SBDBaseChannel` | `createPreviousMessageListQuery`, `getMessagesByTimestamp:params:completionHandler:`, `getMessagesByMessageId:params:completionHandler:` |

## v3.0.28

### Classes

| Old class | New class |
| --------- | --------- |
| `SBDMessageListQuery` | N/A |

### Methods

| Old class | Old method | New class | New method |
| --------- | ---------- | --------- | ---------- |
| `SBDBaseChannel` | `sendFileMessageWithUrl:size:type:data:completionHandler:` | `SBDBaseChannel` | `sendFileMessageWithParams:progressHandler:completionHandler:` |

## v3.0.22

### Methods

| Old class | Old method | New class | New method |
| --------- | ---------- | --------- | ---------- |
| `SBDMain` | `registerDevicePushToken:completionHandler:` | `SBDMain` | `registerDevicePushToken:unique:completionHandler:` |

## v3.0.21

### Methods

| Old class | Old method | New class | New method |
| --------- | ---------- | --------- | ---------- |
| `SBDGroupChannel` | `getPushPreferenceWithCompletionHandler:` | `SBDGroupChannel` | `myPushTriggerOption` |

## v3.0.19

### Properties

| Old class | Old property | New class | New property |
| --------- | ------------ | --------- | ------------ |
| `SBDGroupChannelListQuery` | `setUserIdsFilter:exactMatch:` | `SBDGroupChannelListQuery` | `setUserIdsIncludeFilter:queryType:` |

## v3.0.9

### Methods

| Old class | Old method | New class | New method |
| --------- | ---------- | --------- | ---------- |
| `SBDMain` | `registerPushToken:completionHandler:` | `SBDMain` | `registerDevicePushToken:unique:completionHandler:` |
