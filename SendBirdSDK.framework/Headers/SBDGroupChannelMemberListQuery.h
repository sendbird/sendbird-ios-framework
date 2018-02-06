//
//  SBDGroupChannelMemberListQuery.h
//  SendBirdSDK
//
//  Created by sendbird-young on 2018. 1. 29..
//  Copyright © 2018년 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SBDMember, SBDError;

/**
 *  The `SBDGroupChannelMemberListQuery` class is a query class for getting the list member in group channels. 
 *  The instance of this class is created by [`createMemberListQuery`](../Classes/SBDGroupChannel.html#//api/name/createMemberListQuery) in `SBDGroupChannel` class.
 */
@interface SBDGroupChannelMemberListQuery : NSObject

/**
 *  Initialize SBDGroupChannelMemberListQuery instance.
 *  This method is designated initializer.
 *
 *  @param  channelUrl      the channel url to get member list.
 *  @return SBDGroupChannelMemberListQuery  The instance of this class.
 */
- (nullable instancetype)initWithChannelUrl:(nonnull NSString *)channelUrl NS_DESIGNATED_INITIALIZER;

- (nullable instancetype)init NS_UNAVAILABLE;

/**
 *  Sets the number of members per page.
 */
@property (atomic) NSUInteger limit;

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
