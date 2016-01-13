//
//  SendBirdAppUser.h
//  SendBirdSDK
//
//  Created by Jed Kyung on 1/12/16.
//  Copyright © 2016 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SendBirdAppUser : NSObject

/**
 *  Integer value ID asssigned to users
 */
@property long long userId;

/**
 *  User name
 */
@property (retain) NSString *nickname;

/**
 *  Profile iamge URL
 */
@property (retain) NSString *picture;

/**
 *  Unique identifier assigned to users
 */
@property (retain) NSString *guestId;

@property (retain) NSDictionary *jsonObj;

- (id) initWithDic:(NSDictionary *)dic;

@end
