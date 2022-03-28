//
//  SBDGroupChannelMemberListQuery.h
//  SendBirdSDK
//
//  Created by sendbird-young on 2018. 1. 29..
//  Copyright © 2018년 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBDTypes.h"

@class SBDMember, SBDError;

/**
 *  The `SBDGroupChannelMemberListQuery` class is a query class for getting the list member in group channels. 
 *  The instance of this class is created by [`createMemberListQuery`](../Classes/SBDGroupChannel.html#//api/name/createMemberListQuery) in `SBDGroupChannel` class.
 */
@interface SBDGroupChannelMemberListQuery : NSObject <NSCopying>

/**
 *  Don't use this initializer. Use `createGroupChannelListQuery` of `SBDGroupChannel` instead.
 */
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wnullability"
- (nullable instancetype)init NS_UNAVAILABLE;
#pragma clang diagnostic pop

/**
 *  Sets the number of members per page.
 */
@property (atomic) NSUInteger limit;

/**
 *  Shows if there is a next page
 */
@property (atomic, readonly) BOOL hasNext;

/**
 *  Shows if the query is loading.
 *
 *  @return Returns YES if the query is loading, otherwise returns NO.
 *
 *  @since 3.0.94
 */
@property (atomic, readonly, getter=isLoading) BOOL loading;

/**
 *  Filters members of nickname that starts with.
 *
 *  @since 3.0.102
 */
@property (copy, atomic, nullable) NSString *nicknameStartsWithFilter;

/**
 *  Sets a filter to query operators. 
 *
 *  @since 3.0.89
 *  @see Combined with `setOperatorFilter:`.
 */
@property (nonatomic) SBDGroupChannelOperatorFilter operatorFilter;

/**
 *  Sets a filter to query muted member list.
 *
 *  @since 3.0.89
 *  @see Combined with `setMutedMemberFilter:`.
 */
@property (nonatomic) SBDGroupChannelMutedMemberFilter mutedMemberFilter;

/**
 * Sets a filter to query member list with member state.
 *
 *  @see Combined with `setMemberStateFilter:`.
 */
@property (nonatomic) SBDMemberStateFilter memberStateFilter;

/// Sets how the query result should be ordered. If the `order` is `SBDMemberListOrderNicknameAlphabetical`, the result will be ordered by the nickname in alphabetical order.
/// If the `order` is `SBDMemberListOrderOperatorThenMemberNicknameAlphabetical`, then the result will contain the operators first, and then the members. The two groups (operators and members) will be ordered by the nickname in alphabetical order. The default value is `SBDMemberListOrderNicknameAlphabetical`.
/// @since 3.0.198
@property (atomic) SBDMemberListOrder order;

/**
 *  Gets the list of member in group channel. If this method is repeatedly called, it will retrieve the following pages of the member list.
 *
 *  @param completionHandler The handler block to execute. The `users` is the array of `SBDUser` instances.
 */
- (void)loadNextPageWithCompletionHandler:(nullable void (^)(NSArray<SBDMember *> * _Nullable users, SBDError *_Nullable error))completionHandler;

@end
