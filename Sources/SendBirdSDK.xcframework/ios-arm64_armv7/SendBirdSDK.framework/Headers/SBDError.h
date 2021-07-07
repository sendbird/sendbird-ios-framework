//
//  SBDError.h
//  SendBirdSDK
//
//  Created by Jed Gyeong on 5/22/16.
//  Copyright © 2016 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SBDTypes.h"

/**
 *  Sendbird error class.
 */
@interface SBDError : NSError

/**
 *  Creates error object with NSDictionary.
 *
 *  @param dict Error data.
 *
 *  @return SBDError object.
 */
+ (nonnull SBDError *)errorWithDictionary:(NSDictionary * _Nonnull)dict;

/**
 *  Creates error object with NSError object.
 *
 *  @param error NSError object.
 *
 *  @return SBDError object.
 */
+ (nonnull SBDError *)errorWithNSError:(NSError * _Nonnull)error;

@end
