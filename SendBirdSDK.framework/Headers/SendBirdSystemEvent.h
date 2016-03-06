//
//  SendBirdSystemEvent.h
//  SendBirdSDK
//
//  Created by Jed Kyung on 2/29/16.
//  Copyright © 2016 SENDBIRD.COM. All rights reserved.
//

#import <SendBirdSDK/SendBirdSDK.h>
#import "SendBirdMessageModel.h"

#define kSendBirdSystemEventCategoryNone 0
#define kSendBirdSystemEventCategoryChannelJoin 10100
#define kSendBirdSystemEventCategoryChannelLeave 10101
#define kSendBirdSystemEventCategoryChannelInvite 10102
#define kSendBirdSystemEventCategoryTooManyMessages 10200
#define kSendBirdSystemEventCategoryMessagingUserBlocked 10300
#define kSendBirdSystemEventCategoryMessagingUserDeactivated 10400

/**
 *  Class used for system events.
 */
@interface SendBirdSystemEvent : SendBirdMessageModel

/**
 *  Message body
 */
@property (retain) NSString *message;

@property (retain) NSDictionary *jsonObj;

/**
 *  Message type
 *
 *  - Joined the channel  - 10100
 *  - Left the channel - 10101
 *  - Invited to the channel - 10102
 *  - Muted - 10500
 */
@property long long category;

- (id) initWithDic:(NSDictionary *)dic inPresent:(BOOL)present;
- (NSString *) toJson;

@end
