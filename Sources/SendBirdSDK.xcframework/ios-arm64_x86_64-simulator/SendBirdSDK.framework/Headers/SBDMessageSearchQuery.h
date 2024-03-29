//
//  SBDMessageSearchQuery.h
//  SendBirdSDK
//
//  Created by Tez Park on 02/12/2019.
//  Copyright © 2019 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBDTypes.h"
#import "SBDMappable.h"

@class SBDBaseMessage, SBDError;

/// A Builder class to build a SBDMessageSearchQuery
/// @since 3.0.162
@interface SBDMessageSearchQueryBuilder : NSObject

/// Keyword to search for.
@property (nonatomic, copy, nullable) NSString *keyword;


/// Channel url of the channel you want to set as a scope for the search.
@property (nonatomic, copy, nullable) NSString *channelUrl;

/// Channel custom type you want to set as a scope for the search.
@property (nonatomic, copy, nullable) NSString *channelCustomType;


/// Should reverse the queried result list.
/// Default is false
@property (nonatomic, assign) BOOL reverse;


/// Should search as a complete, exact phrase.
/// Default is false
@property (nonatomic, assign) BOOL exactMatch;


/// The maximum number of `SBDBaseMessage`s per queried page.
/// Default is 20, maximum is 999 (<1000)
@property (nonatomic, assign) NSUInteger limit;


/// Starting timestamp to search from.
/// Default is 0
@property (nonatomic, assign) long long messageTimestampFrom;


/// Ending timestamp to search to
/// Default is 0
@property (nonatomic, assign) long long messageTimestampTo;


/// The order method for the search.
/// It is defined in `SBDMessageSearchQueryOrder`.
@property (nonatomic, assign) SBDMessageSearchQueryOrder order;

/// Whether treat keyword field as advanced query or not
/// @since 3.0.222
@property (nonatomic, assign) BOOL advancedQuery;

/// Array of  target fields in message's data that will be searched with keyword
/// @since 3.0.222
@property (nonatomic, strong, nullable) NSArray<NSString *> *targetFields;
@end


/// A class representing query to retrieve list of `SBDBaseMessage`s that matches a given query with given filters.
/// `SBDMessageSearchQuery` can be generated by using `SBDMessageSearchQueryBuilder`
/// @since 3.0.162
@interface SBDMessageSearchQuery : NSObject <SBDMappable>

/// Create this query instance with default values.
/// @return The instance of query.
+ (nonnull instancetype)create;

/// Create query instance with block.
///
/// It is used builder pattern.
/// @param updateBlock Update Block to initialize with.
/// @return The instance of query.
+ (nonnull instancetype)createWithBuilder:(nonnull void (^)(SBDMessageSearchQueryBuilder * _Nonnull builder))updateBlock;

/// Gets the list of searched messages.
///
/// If this method is repeatedly called, it will retrieve the following pages of the searched messages.
/// @param completionHandler The handler block to execute. The `messages` is the array of `SBDBaseMessage` instances.
- (void)loadNextPageWithCompletionHandler:(nonnull void (^)(NSArray <SBDBaseMessage *> * _Nullable messages, SBDError *_Nullable error))completionHandler;

/// Shows if the query is loading.
/// @return Returns YES if the query is loading, otherwise returns NO.
- (BOOL)isLoading;

/// Shows if there is a next page.
/// @return Returns YES if the query has next, otherwise returns NO.
- (BOOL)hasNext;

/// Shows the total count of results that match the given search.
/// @return Returns the total count of results that match the given search.
/// @since 3.1.24
@property (atomic, readonly) NSInteger totalCount;

#pragma mark - serailzation

/// Returns message search query from given binary data.
/// @param data The binary data from `serialize`. Must not be nil.
/// @return `SBDMessageSearchQuery` The query instance from which to deserialized data. Can be nil if an internal error occurs.
+ (nullable instancetype)buildFromSerializedData:(NSData * _Nonnull)data;

/// Returns a serialized binary data from a query.
/// @return A serialized binary data from query, or nil if an internal error occurs.
- (nullable NSData *)serialize;

@end
