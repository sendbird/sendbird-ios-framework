//
//  SBDPollListQuery.h
//  SendBirdSDK
//
//  Created by Wooyoung Chung on 7/27/21.
//  Copyright © 2021 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SBDBaseChannel;
@class SBDUser, SBDError;
@class SBDPoll;

NS_ASSUME_NONNULL_BEGIN

/// A class representing query to retrieve list of `SBDPoll`s that matches a given query with given channelURL.
/// @since 3.0.232
@interface SBDPollListQuery : NSObject

/// The channel url related to query.
@property (strong, readonly) NSString *channelURL;

/// Sets the number of users per page.
@property (atomic) NSUInteger limit;

/// Shows if there is a next page
@property (atomic, readonly) BOOL hasNext;

- (nullable instancetype)init NS_UNAVAILABLE;

/// Shows if the query is loading.
///
/// @return Returns YES if the query is loading, otherwise returns NO.
- (BOOL)isLoading;

- (void)loadNextPageWithCompletionHandler:(nullable void (^)(NSArray<SBDPoll *> * _Nullable users,
                                                             SBDError *_Nullable error))completionHandler;

@end

NS_ASSUME_NONNULL_END
