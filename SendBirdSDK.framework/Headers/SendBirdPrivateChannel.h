//
//  SendBirdPrivateChannel.h
//  SendBirdSDK
//
//  Created by Jed Kyung on 2/27/16.
//  Copyright © 2016 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SendBirdMessage.h"
#import "SendBirdMemberInMessagingChannel.h"
#import "SendBirdCommand.h"
#import "SendBirdBaseChannel.h"
#import "SendBirdUser.h"

/**
 *  Class used for private messaging channel. This contains information such as: users within the channel, timestamp of each users' most recent read receipts, unread message counts for the current user, last message within the channel, new messages created after the current user joined the channel, channel type (1-on-1 or group), etc.
 */
@interface SendBirdPrivateChannel : SendBirdBaseChannel

/**
 *  List of members participating in the Messaging/Group messaging channel
 */
@property (retain) NSMutableArray *members DEPRECATED_ATTRIBUTE;

@property (retain) NSMutableArray<SendBirdUser *> *channelMembers;

/**
 *  List of the recent read receipts of members in the Messaging/Group messaging channel
 */
@property (retain) NSMutableDictionary *readStatus;

/**
 *  Unread message count of the current user in the Messaging channel
 */
@property int unreadMessageCount;

/**
 *  Last message within Messaging/Group messaging channel
 */
@property (retain) SendBirdMessage *lastMessage;

/**
 *  Number of new messages created after the current user has joined the Messaging/Group messaging channel. If this value is 0, then it means no new messages were created within the channel after joining.
 */
@property int messageCountSinceJoined;

/**
 *  Messaging channel type. 1 on 1 = 5, Group messaging = 6
 */
@property int channelType;

- (id) initWithDic:(NSDictionary *) dic;

/**
 *  Get the timestamp of the last read receipt for the target user
 *
 *  @param userID User ID. Same as [`SendBirdUser guestID`](./SendBirdUser.html#//api/name/guestId)
 *
 *  @return UTC timestamp of the last read receipt for that user
 */
- (long long) getLastReadMillisWithUserID:(NSString *)userID;

- (long long) getLastReadMillis:(NSString *)userId DEPRECATED_ATTRIBUTE;

/**
 *  Check if the channel is a Group messaging channel
 *
 *  @return Returns YES if the type is a Group messaging channel, otherwise returns NO
 */
- (BOOL) isGroupMessagingChannel;

/**
 *  Check if the channel is a Messaging channel
 *
 *  @return Returns YES if the type is a Messaging channel, otherwise returns NO
 */
- (BOOL) isMessagingChannel;

/**
 *  Returns Channel URL without the Namespace. Channel URL is comprised of a unique Namespace along with the channel identifier string. Use this method to retrieve the identifier part of the URL without the Namespace.
 *
 *  @return Channel URL without the Namespace
 */
- (NSString *) getUrlWithoutAppPrefix;

/**
 *  Get the number of members in the channel
 *
 *  @return Number of members
 */
- (unsigned long) getPrivateChannelMemberCount;

/**
 *  Check if there was a last message in the channel
 *
 *  @return Returns YES if there is a last message, otherwise returns NO
 */
- (BOOL) hasLastMessage;

/**
 *  Get the UTC timestamp of the last message in the channel
 *
 *  @return UTC Timestamp of the last mesage
 */
- (long long) getLastMessageTimestamp;

/**
 *  Update the last message in the channel
 *
 *  @param messageJson Message body
 */
- (void) updateLastMessage:(NSString *) messageJson;

/**
 *  Update unread message count
 *
 *  @param count Unread message count
 */
- (void) updateUnreadMessageCount:(int) count;

@end
