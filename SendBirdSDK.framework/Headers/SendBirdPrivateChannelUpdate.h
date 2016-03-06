//
//  SendBirdPrivateChannelUpdate.h
//  SendBirdSDK
//
//  Created by Jed Kyung on 2/28/16.
//  Copyright © 2016 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SendBirdPrivateChannelUpdate : NSObject

@property NSDictionary *jsonObj;
@property long long channelId;
@property BOOL messageUpdate;

- (id) initWithDic:(NSDictionary *) dic;
- (NSString *) toJson;
- (BOOL) isMessageUpdate;


@end
