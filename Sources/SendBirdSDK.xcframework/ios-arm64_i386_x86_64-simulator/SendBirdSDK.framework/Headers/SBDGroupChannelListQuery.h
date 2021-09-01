//
//  SBDGroupChannelListQuery.h
//  SendBirdSDK
//
//  Created by Jed Gyeong on 5/25/16.
//  Copyright © 2016 SENDBIRD.COM. All rights reserved.
//

#import "SBDError.h"
#import "SBDTypes.h"
#import "SBDUser.h"
#import "SBDMappable.h"

@class SBDGroupChannel;
@class SBDUser;


/// The `SBDGroupChannelListQuery` class is a query class for getting the list of group channels.
/// The instance of this class is created by [`createMyGroupChannelListQuery`]
/// (../Classes/SBDGroupChannel.html#//api/name/createMyGroupChannelListQuery) in `SBDGroupChannel` class.
@interface SBDGroupChannelListQuery : NSObject <NSCopying, SBDMappable>

/// Sets the number of channels per page.
@property (atomic) NSUInteger limit;


/// If the value is YES, the channel list includes empty channel.
@property (atomic) BOOL includeEmptyChannel;


/// If the value is YES, the channel list includes frozen channel. Default is YES
/// @since 3.0.182
@property (atomic) BOOL includeFrozenChannel;


/// If the value is YES, the channel object of the list includes members list.
@property (atomic) BOOL includeMemberList;

/// If  the value is YES, the channel object of the list includes meta data property.
/// @since 3.0.216
@property (atomic) BOOL includeMetaData;

/// Sets the order of the list. The order is defined in `SBDGroupChannelListOrder`.
@property (atomic) SBDGroupChannelListOrder order;

/// Shows if there is a next page
@property (nonatomic, readonly) BOOL hasNext;


/// Sets query type for `includeMemberList`.
@property (atomic) SBDGroupChannelListQueryType queryType;

/// Sets the custom type filter.
///
/// @deprecated in 3.0.64. (Use `customTypesFilter` instead.)
@property (strong, nonatomic, nullable) NSString *customTypeFilter
DEPRECATED_ATTRIBUTE;

/// Sets the member state filter.
@property (nonatomic) SBDMemberStateFilter memberStateFilter;

/// Sets <code>SBDGroupChannel</code> URLs filter. <code>SBDGroupChannel</code> list containing
/// only and exactly the passed <code>SBDGroupChannel</code> URLs will be returned.
/// This does not cooperate with other filters.
@property (copy, nonatomic, nullable) NSArray<NSString *> *channelUrlsFilter;

/// Sets a filter to return only channels that contains the specified group channel name.
///
/// @deprecated 3.0.64. (Use `setChannelNameContainsFilter:` instead.)
@property (strong, nonatomic, nullable) NSString *channelNameFilter
DEPRECATED_ATTRIBUTE;

/// Sets to filter super channel.
/// 
/// SBDGroupChannelSuperChannelFilterAll by default.
@property (nonatomic) SBDGroupChannelSuperChannelFilter superChannelFilter;

/// Sets to filter public channel.
/// SBDGroupChannelSuperChannelFilterAll by default.
@property (nonatomic) SBDGroupChannelPublicChannelFilter publicChannelFilter;

/// Sets to filter channels by custom type that starts with.
/// @see Combined with `setCustomTypeStartsWithFilter:`.
@property (copy, nonatomic, nullable) NSString *customTypeStartsWithFilter;

/// Sets the custom types filter. The custom types to search.
/// @see Combined with `setCustomTypesFilter:`.
@property (copy, nonatomic, nullable) NSArray <NSString *> *customTypesFilter;

/// Sets the filter with nickname. The group channels which have the member that has nickname are returned by `loadNextPageWithCompletionHandler:`(LIKE search).
/// @see Combined with `setNicknameContainsFilter:`.
@property (copy, nonatomic, nullable) NSString *nicknameContainsFilter;

/// Sets the filter with user IDs. The group channels which have the members that contain user IDs are returned by `loadNextPageWithCompletionHandler:`.
/// @see Use `setUserIdsIncludeFilter:queryType:` to set the property.
@property (copy, nonatomic, readonly, nullable) NSArray <NSString *> *userIdsIncludeFilter;

/// Sets the filter with user IDs. The group channels which have the members that have user IDs are returned by `loadNextPageWithCompletionHandler:`. The channels have the `userIds` members only.
/// @see Combined with `setUserIdsExactFilter:`.
@property (copy, nonatomic, nullable) NSArray <NSString *> *userIdsExactFilter;

/// Sets a filter to return only channels that contains the specified group channel name.
/// The channel name to search. The query will return the channels include `channelName`.
/// @see Combined with `setChannelNameContainsFilter:`.
@property (copy, nonatomic, nullable) NSString *channelNameContainsFilter;

/// Sets to filter channels by the unread messages. The default value is `SBDUnreadChannelFilterAll`.
/// @since 3.0.113
@property (nonatomic) SBDUnreadChannelFilter unreadChannelFilter;

/// Sets a key for ordering by value in the metadata. This is valid when the `order` is `SBDGroupChannelListOrderChannelMetaDataValueAlphabetical` only.
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

/// Sets to filter channels by the hidden state. The default value is `SBDChannelHiddenStateFilterUnhiddenOnly`.
/// @since 3.0.122
@property (atomic) SBDChannelHiddenStateFilter channelHiddenStateFilter;

/// The query property of the query specified by `setSearchFilterQuery:fields:`
/// @since 3.0.144
@property (copy, nonatomic, nullable, readonly) NSString *searchQuery;

/// The fields properties of the query specified by `setSearchFilterQuery:fields:`
/// @since 3.0.144
@property (nonatomic, readonly) SBDGroupChannelListQuerySearchField searchFields;

/// DO NOT USE this initializer. Use `[SBDGroupChannel createMyGroupChannelListQuery]` instead.
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wnullability"
- (nullable instancetype)init NS_UNAVAILABLE;
#pragma clang diagnostic pop

/// Shows if the query is loading.
/// @return Returns YES if the query is loading, otherwise returns NO.
- (BOOL)isLoading;

/// Sets the filter with user IDs. 
///
/// The group channels which have the members that have user IDs are returned by `loadNextPageWithCompletionHandler:`.
/// @param userIds    User IDs to search.
/// @param exactMatch If YES, the group channels which have the `userIds` only are returned. If NO, the group channels which contain the `userIds` are returned.
/// @deprecated in 3.0.19
- (void)setUserIdsFilter:(NSArray<NSString *> * _Nonnull)userIds
              exactMatch:(BOOL)exactMatch DEPRECATED_ATTRIBUTE;

/// Sets the filter with user IDs. 
///
/// The group channels which have the members that contain user IDs are returned by `loadNextPageWithCompletionHandler:`.
/// @param userIds    User IDs to search.
/// @param queryType Logical condition applied to filter. If you pass `SBDGroupChannelListQueryTypeAnd` to `queryType` and A, B to `userIds`, the channels whose members containing A and B will be returned. If `SBDGroupChannelListQueryTypeOr` is set, the members of the queried channels will be A or B.
/// @see `userIdsIncludeFilter`, `queryType`.

- (void)setUserIdsIncludeFilter:(NSArray<NSString *>* _Nonnull)userIds
                      queryType:(SBDGroupChannelListQueryType)queryType;

/// Sets the custom type filter.
///
/// @param customType The custom type to search.
/// @deprecated in 3.0.79.
- (void)setCustomTypeFilter:(NSString * _Nullable)customType DEPRECATED_ATTRIBUTE;

/// Sets the search query and search fields of the query specified a given query and a given fields.
///
/// @param query  The query to request for `searchFields`.
/// @param fields  The fields to request query for `searchQuery` that MUST be `SBDGroupChannelListQuerySearchField`.
/// @see fields MUST be an array with 'SBDGroupChannelListQuerySearchField'.
/// @since 3.0.144
///
/// @code
/// SBDGroupChannelListQuery *query = [SBDGroupChannel createMyGroupChannelListQuery];
/// NSString *filter = @"sendbird";
/// SBDGroupChannelListQuerySearchField fields = SBDGroupChannelListQuerySearchFieldChannelName |
///                                              SBDGroupChannelListQuerySearchFieldMemberNickname;
/// [query setSearchFilter:filter fields:fields];
///
/// [query loadNextPageWithCompletionHandler:^(NSArray<SBDGroupChannel *> *channels, SBDError *error) {
///    if (error != nil) { handle error }
///    else { do something }
/// }];
/// @endcode
- (void)setSearchFilter:(nonnull NSString *)query fields:(SBDGroupChannelListQuerySearchField)fields;

/// Sets meta data filter.
///
/// @param key The key of the meta data to use for filter.
/// @param values The values of the meta data to use for filter.
/// @since 3.0.232
- (void)setMetaDataFilterWithKey:(nonnull NSString *)key
                          values:(nonnull NSArray<NSString *> *)values;

/// Sets meta data filter with startsWith.
///
/// @param key The key of the meta data to use for filter.
/// @param valueStartsWith The values of the meta data to use for filter.
/// @since 3.0.232
- (void)setMetaDataFilterWithKey:(nonnull NSString *)key
                 valueStartsWith:(nonnull NSString *)valueStartsWith;

/// Gets the list of channels. 
///
/// If this method is repeatedly called, it will retrieve the following pages of the channel list.
/// @param completionHandler The handler block to execute. The `channels` is the array of `SBDGroupChannel` instances.
- (void)loadNextPageWithCompletionHandler:(nullable void (^)(NSArray<SBDGroupChannel *> * _Nullable channels, SBDError *_Nullable error))completionHandler;

#pragma mark - serailzation

/// Returns my group channel list query from given binary data.
///
/// @param data The binary data from `serialize`. Must not be nil.
/// @return SBDGroupChannelListQuery The query instance from which to deserialized data. Can be nil if an internal error occurs.
+ (nullable instancetype)buildFromSerializedData:(NSData * _Nonnull)data;

/// Returns a serialized binary data from a query.
///
/// @return A serialized binary data from query, or nil if an internal error occurs.
- (nullable NSData *)serialize;

#pragma mark - Local Cache
/// Checks whether the channel belongs to this query or not.
/// @param channel Channel object.
/// @since 3.0.227
- (BOOL)belongsTo:(nonnull SBDGroupChannel *)channel;

@end
