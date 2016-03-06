//
//  SendBirdAdminMessage.h
//  SendBirdSDK
//
//  Created by Jed Kyung on 2/29/16.
//  Copyright © 2016 SENDBIRD.COM. All rights reserved.
//

#import <SendBirdSDK/SendBirdSDK.h>
#import "SendBirdMessageModel.h"

/**
 *  Class for admin messages. This class is comprised of message and additional data.
 */
@interface SendBirdAdminMessage : SendBirdMessageModel

/**
 *  Admin message
 */
@property (retain) NSString *message;

@property (retain) NSDictionary *jsonObj;

/**
 *  Additional data
 */
@property (retain) NSString *data;

- (id) initWithDic:(NSDictionary *)dic inPresent:(BOOL)present;

- (NSString *) toJson;

@end
