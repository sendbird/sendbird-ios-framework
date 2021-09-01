//
//  SBDPublicGroupChannelListQuery.h
//  SendBirdSDK
//
//  Created by sendbird-young on 2018. 1. 31..
//  Copyright © 2018년 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBDTypes.h"

@class SBDGroupChannel, SBDError;

/// The `SBDPublicGroupChannelListQuery` class is a query class for getting the list of public group channels.
/// The instance of this class is created by [`createPublicGroupChannelListQuery`](../Classes/SBDGroupChannel.html#//api/name/createPublicGroupChannelListQuery) in `SBDGroupChannel` class.
@interface SBDPublicGroupChannelListQuery : NSObject <NSCopying>


/// Sets the number of channels per page.
@property (atomic) NSUInteger limit;

/// Shows if there is a next page
@property (atomic, readonly) BOOL hasNext;

/// Shows if the query is loading.
/// YES if the query is loading, otherwise returns NO.
@property (atomic, readonly, getter=isLoading) BOOL loading;

/// If the value is YES, the channel list includes empty channel.
/// The property determines if including an empty channel, or not.
/// @see Combined with `setIncludeEmptyChannel:`.
@property (nonatomic) BOOL includeEmptyChannel;


/// If the value is YES, the channel list includes frozen channel. Default is YES
/// @since 3.0.182
@property (atomic) BOOL includeFrozenChannel;

/// If the value is YES, the channel list includes their members.
/// The property determines including channel's members.
/// @see Combined with `setIncludeMemberList:`.
@property (atomic) BOOL includeMemberList;

/// If  the value is YES, the channel object of the list includes meta data property.
/// @since 3.0.216
@property (atomic) BOOL includeMetaData;

/// Sets the order of the list. The order is defined in `SBDPublicGroupChannelListOrder`.
/// SBDPublicGroupChannelListOrderChronological by default.
/// @see Combined with `setOrder:`.
@property (nonatomic) SBDPublicGroupChannelListOrder order;

/// Sets to filter super channel.
/// SBDGroupChannelSuperChannelFilterAll by default.
/// The property filters super group channels.
/// @see Combined with `setSuperChannelFilter:`.
@property (nonatomic) SBDGroupChannelSuperChannelFilter superChannelFilter;

/// Sets <code>SBDGroupChannel</code> URLs filter.
/// <code>SBDGroupChannel</code> list containing only and exactly the passed <code>SBDGroupChannel</code> URLs will be returned.
/// This does not cooperate with other filters.
/// @see Combined with `setPublicMembershipFilter:`.
@property (nonatomic) SBDPublicGroupChannelMembershipFilter publicMembershipFilter;

/// Sets the custom types filter.
/// The property filters channels which have one of custom types.
/// @see Combined with `setCustomTypesFilter:`.
@property (copy, nonatomic, nullable) NSArray <NSString *> *customTypesFilter;


/// Sets to filter channels by custom type that starts with.
/// The property filters custom type that starts with this string.
/// @see Combined with `setCustomTypeStartsWithFilter:`.
@property (copy, nonatomic, nullable) NSString *customTypeStartsWithFilter;

/// Sets <code>SBDGroupChannel</code> URLs filter.
/// <code>SBDGroupChannel</code> list containing only and exactly the passed <code>SBDGroupChannel</code> URLs will be returned.
/// This does not cooperate with other filters.
/// @see Combined with `setChannelUrlsFilter:`.
@property (copy, nonatomic, nullable) NSArray <NSString *> *channelUrlsFilter;

/// Sets <code>SBDGroupChannel</code> names filter.
/// <code>SBDGroupChannel</code> list containing only and exactly the passed <code>SBDGroupChannel</code> name will be returned.
/// This does not cooperate with other filters.
/// The property filters channel name that contains this string.
/// @see Combined with `setChannelNameContainsFilter:`.
@property (copy, nonatomic, nullable) NSString *channelNameContainsFilter;


/// Sets a key for ordering by value in the metadata. This is valid when the `order` is `SBDPublicGroupChannelListOrderChannelMetaDataValueAlphabetical` only.
/// @since 3.0.118
@property (copy, nonatomic, nullable) NSString *metaDataOrderKeyFilter;

/// Searches for group channels with metadata containing an item with the specified value as its key
/// @since 3.0.232
@property (copy, nonatomic, nullable) NSString *metaDataKeyFilter;

/// Searches for group channels with metadata containing an item with the key specified by the metaDataKey
/// @since 3.0.232
@property (copy, nonatomic, nullable) NSArray<NSString *> *metaDataValuesFilter;

/// Searches for group channels with metadata containing an item with the key specified by the metaDataKey
/// and the values of that item start with the specified value
/// @since 3.0.232
@property (copy, nonatomic, nullable) NSString *metaDataValueStartsWithFilter;

/// Sets meta data filter.
///
/// @param key The key of the meta data to use for filter.
/// @param values The values of the meta data to use for filter.
- (void)setMetaDataFilterWithKey:(nonnull NSString *)key
                          values:(nonnull NSArray<NSString *> *)values;

/// Sets meta data filter with startsWith.
///
/// @param key The key of the meta data to use for filter.
/// @param valueStartsWith The values of the meta data to use for filter.
- (void)setMetaDataFilterWithKey:(nonnull NSString *)key
                 valueStartsWith:(nonnull NSString *)valueStartsWith;

/// Gets the list of channels. If this method is repeatedly called, it will retrieve the following pages of the channel list.
/// @param completionHandler The handler block to execute. The `channels` is the array of `SBDGroupChannel` instances.
- (void)loadNextPageWithCompletionHandler:(nullable void (^)(NSArray<SBDGroupChannel *> * _Nullable channels, SBDError *_Nullable error))completionHandler;

@end
