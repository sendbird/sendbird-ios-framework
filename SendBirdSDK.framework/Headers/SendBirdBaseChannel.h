//
//  SendBirdBaseChannel.h
//  SendBirdSDK
//
//  Created by Jed Kyung on 2/27/16.
//  Copyright © 2016 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SendBirdBaseChannel : NSObject

/**
 *  Channel ID
 */
@property long long channelId;

/**
 *  Members count for the channel
 */
@property int memberCount;

/**
 *  Channel URL
 */
@property (retain) NSString *url;

/**
 *  Channel Topic
 */
@property (retain) NSString *name;

/**
 *  Cover image URL
 */
@property (retain) NSString *coverUrl;

/**
 *  Channel creation timestamp (UTC)
 */
@property long long createdAt;

/**
 *  Returns Channel URL without the Namespace. Channel URL is comprised of a unique Namespace along with the channel identifier string. Use this method to retrieve the identifier part of the URL without the Namespace.
 *
 *  @return Channel URL without the Namespace
 */
- (NSString *) getUrlWithoutAppPrefix;

@property (retain) NSDictionary *jsonObj;

- (id) initWithDic:(NSDictionary *)dic;

- (NSString *) toJson;

@end
