//
//  SBDAppInfo.h
//  SendBirdSDK
//
//  Created by Tez Park on 08/05/2020.
//  Copyright © 2020 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * This class contains application information.
 * @note This class is available from 3.0.180
 */
@interface SBDAppInfo : NSObject

/**
 * This is the latest hash value for Emoji.

 * Default value is empty string.
 * @since 3.0.180
 */
@property (strong, nonatomic, readonly, nonnull) NSString *emojiHash;

/**
 * This is the uploadable file size limit. (The unit is bytes.)
 * @since 3.0.180
 */
@property (assign, atomic, readonly) long long uploadSizeLimit;

/**
 * This is the premium feature list using on your Application ID.
 * @since 3.0.180
 */
@property (strong, nonatomic, readonly, nullable) NSArray<NSString *> *premiumFeatureList;

/**
 * This is the state of using the reaction feature.
 * @since 3.0.180
 */
@property (assign, atomic, readonly) BOOL useReaction;

/**
 * This is the application attributes list using on your Application ID.
 * @since 3.0.198
 */
@property (strong, nonatomic, readonly, nullable) NSArray<NSString *> *applicationAttributes;

/**
 * This function can check if Emoji information needs to be updated to date.
 *
 * @param prevEmojiHash Emoji hash value in use
 * @since 3.0.180
 */
- (BOOL)isEmojiUpdateNeeded:(nonnull NSString *)prevEmojiHash;

@end
