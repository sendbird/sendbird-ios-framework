//
//  SBDEmoji.h
//  SendBirdSDK
//
//  Created by Wooyoung Chung on 5/8/20.
//  Copyright © 2020 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import "SBDMappable.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Class to represent emoji
 * @note This class is available from 3.0.180
 */
@interface SBDEmoji : NSObject <SBDMappable>

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

@end



/**
 * Class to represent emoji cateogry
 * @note This class is available from 3.0.180
 */
@interface SBDEmojiCategory : NSObject <SBDMappable>

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

@end

@interface SBDEmojiContainer : NSObject <SBDMappable>

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

@end

NS_ASSUME_NONNULL_END
