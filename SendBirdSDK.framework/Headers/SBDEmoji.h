//
//  SBDEmoji.h
//  SendBirdSDK
//
//  Created by Wooyoung Chung on 5/8/20.
//  Copyright © 2020 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Class to represent emoji
 * @note This class is available from 3.0.180
 */
@interface SBDEmoji : NSObject

/**
 * Emoji's key
 * @since 3.0.180
 */
@property (strong, readonly) NSString *key;


/**
 * Emoji's url
 * @since 3.0.180
*/
@property (strong, readonly) NSString *url;

/**
 *  Initializes a emoji object.
 *
 *  @param dict Dictionary data for a Emoji.
 *  @return SBDEmoji object
 *  @since 3.0.180
 */
- (instancetype)initWithDictionary:(NSDictionary *)dict;
@end



/**
 * Class to represent emoji cateogry
 * @note This class is available from 3.0.180
 */
@interface SBDEmojiCategory : NSObject

/**
 * Emoji category's key
 * @since 3.0.180
 */
@property (assign, readonly) long long cid;

/**
 * Emoji category's name
 * @since 3.0.180
*/
@property (strong, readonly) NSString *name;

/**
 * Emoji category's url
 * @since 3.0.180
*/
@property (strong, readonly) NSString *url;

/**
 * Emoji list
 * @since 3.0.180
 */
@property (strong, readonly) NSArray<SBDEmoji *> *emojis;

/**
 *  Initializes a emoji category object.
 *
 *  @param dict Dictionary data for a Emoji category.
 *  @return SBDEmojiCategory object
 *  @since 3.0.180.
 */
- (instancetype)initWithDictionary:(NSDictionary *)dict;
@end

@interface SBDEmojiContainer : NSObject

/**
 * A hash value that represnts any changes on emojis
 * @since 3.0.180
 */

@property (strong, readonly) NSString *emojiHash;

/**
 * Emoji category list
 * @since 3.0.180
 */
@property (strong, readonly) NSArray<SBDEmojiCategory *> *categories;

/**
 *  Initializes a emoji container object.
 *
 *  @param dict Dictionary data for a Emoji container.
 *  @return SBDEmojiContainer object
 *  @since 3.0.180.
 */
- (instancetype)initWithDictionary:(NSDictionary *)dict;
@end

NS_ASSUME_NONNULL_END
