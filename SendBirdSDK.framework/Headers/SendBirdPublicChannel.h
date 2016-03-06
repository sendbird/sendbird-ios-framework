//
//  SendBirdPublicChannel.h
//  SendBirdSDK
//
//  Created by Jed Kyung on 2/27/16.
//  Copyright © 2016 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SendBirdBaseChannel.h"

/**
 *  SendBird Public Channel Class - This class includes Channel ID, Number of members within the channel, Channel URL, Channel Topic, Cover image URL, Channel creation timestamp
 */
@interface SendBirdPublicChannel : SendBirdBaseChannel

- (id) initWithDic:(NSDictionary *)dic;

- (NSString *) toJson;

@end
