//
//  SBDMessageMetaArray.h
//  SendBirdSDK
//
//  Created by sendbird-young on 05/08/2019.
//  Copyright © 2019 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 The `SBDMessageMetaArray` instance has a string type of key and an array type of value.
 The value consists of a string.
 It usually can be used for 'vote' or 'reaction' for the message.
 */
@interface SBDMessageMetaArray : NSObject <NSCopying>

/**
 A string type of key.
 @since 3.0.148
 */
@property (copy, atomic, readonly, nonnull) NSString *key;

/**
 The value consists of a string.
 The value guarantees de-duplicated string.
 @since 3.0.148
 */
@property (strong, atomic, readonly, nonnull) NSArray<NSString *> *value;

/**
 Initializes an message meta array with the given key and an empty array of the value.
 @param key  A string type of key.
 @return Message meta array instance.
 @since 3.0.148
 
 @code
 SBDMessageMetaArray *metaArray = [[SBDMessageMetaArray alloc] initWithKey:string_key];
 @endcode
 */
- (nonnull instancetype)initWithKey:(nonnull NSString *)key;

/**
 Initializes an message meta array with the given key and the given value.
 @param key  A string type of key.
 @param value  The value consists of a string.
 @return Message meta array instance.
 @since 3.0.148
 
 @code
 SBDMessageMetaArray *metaArray = [[SBDMessageMetaArray alloc] initWithKey:string_key value:array_value];
 @endcode
 */
- (nonnull instancetype)initWithKey:(nonnull NSString *)key
                              value:(nullable NSArray<NSString *> *)value
NS_DESIGNATED_INITIALIZER;

/**
 *  DO NOT USE this initializer. Use `initWithKey:value:` instead.
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 Adds an set type of the value to the receiver’s value field.
 @param value  The value consists of a string.
 @since 3.0.148
 
 @code
 [metaArray addValue:set_value];
 @endcode
 */
- (void)addValue:(nonnull NSSet<NSString *> *)value;

/**
 Adds an array type of the value to the receiver’s value field.
 @param array  The array consists of a string.
 @since 3.0.148

 @code
 [metaArray addValueWithArray:array_value];
 @endcode
 */
- (void)addValueWithArray:(nonnull NSArray<NSString *> *)array;

/**
 Removes an set type of the value from the receiver’s value field.
 @param value  The value consists of a string.
 @discussion Nonexistent string value are not ignored.
 @since 3.0.148

 @code
 [metaArray removeValue:set_value];
 @endcode
 */
- (void)removeValue:(nonnull NSSet<NSString *> *)value;

/**
 Removes an array type of the value from the receiver’s value field.
 @param array  The value consists of a string.
 @discussion Nonexistent string value are not ignored.
 @since 3.0.148

 @code
 [metaArray removeValueWithArray:array_value];
 @endcode
 */
- (void)removeValueWithArray:(nonnull NSArray<NSString *> *)array;

@end
