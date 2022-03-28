//
//  SBDPollVoterListQuery.h
//  SendBirdSDK
//
//  Created by Wooyoung Chung on 7/27/21.
//  Copyright © 2021 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SBDUser, SBDError;

NS_ASSUME_NONNULL_BEGIN

/// A class representing query to retrieve list of `SBDUser`s who vote on given parameters
/// @since 3.0.232
@interface SBDPollVoterListQuery : NSObject

/// Poll id
@property (atomic, readonly) long long pollId;

/// Option id
@property (atomic, readonly) long long optionId;

/// The channel url related to the poll.
@property (strong, readonly) NSString *channelURL;

/// Sets the number of users per page.
@property (atomic) NSUInteger limit;

/// Shows if there is a next page
@property (atomic, readonly) BOOL hasNext;

- (instancetype)init NS_UNAVAILABLE;

/// Shows if the query is loading.
///
/// @return Returns YES if the query is loading, otherwise returns NO.
- (BOOL)isLoading;

/// Gets the list of voters.
///
/// If this method is repeatedly called, it will retrieve the following pages of the voters
/// @param completionHandler The handler block to execute. The `messages` is the array of `SBDUser` and total vote count.
- (void)loadNextPageWithCompletionHandler:(void (^)(NSArray<SBDUser *> * _Nullable,
                                                    int voteCount,
                                                    SBDError * _Nullable))completionHandler;

@end

NS_ASSUME_NONNULL_END
