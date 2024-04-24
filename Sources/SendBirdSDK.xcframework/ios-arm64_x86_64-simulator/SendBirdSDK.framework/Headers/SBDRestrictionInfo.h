//
//  SBDRestrictionInfo.h
//  SendBirdSDK
//
//  Created by Celine Moon on 2021/09/28.
//  Copyright © 2021 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBDTypes.h"
#import "SBDMappable.h"

/**
 * Class to represent restriction information of muted, banned users.
 * @note This class is available from 3.0.236
 */
@interface SBDRestrictionInfo : NSObject <SBDMappable>

/**
 * Description about muting or banning.
 * @since 3.0.236
 */
@property (atomic) NSString *infoDescription;

/**
 * Timestamp when mute or ban will end.
 * @since 3.0.236
 */
@property (atomic, readonly) long long endAt;

/**
 * Type of restriction (mute or ban).
 * @since 3.0.236
 */
@property (atomic, readonly) SBDRestrictionType restrictionType; 


@end

