//
//  SBDGroupChannelMemberListQuery.h
//  SendBirdSDK
//
//  Created by sendbird-young on 2018. 1. 29..
//  Copyright © 2018년 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SBDMember, SBDError;

@interface SBDGroupChannelMemberListQuery : NSObject

- (nullable instancetype)init NS_UNAVAILABLE;

/**
 *  Sets the number of members per page.
 */
@property (atomic, readonly) NSUInteger limit;

/**
 *  Shows if there is a next page
 */
@property (atomic, readonly) BOOL hasNext;

/**
 *  Gets the list of member in group channel. If this method is repeatedly called, it will retrieve the following pages of the member list.
 *
 *  @param completionHandler The handler block to execute. The `users` is the array of `SBDUser` instances.
 */
- (void)loadNextPageWithCompletionHandler:(nullable void (^)(NSArray<SBDMember *> * _Nullable users, SBDError *_Nullable error))completionHandler;

@end
