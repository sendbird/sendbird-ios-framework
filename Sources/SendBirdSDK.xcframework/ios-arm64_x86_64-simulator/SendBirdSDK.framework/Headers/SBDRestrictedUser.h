//
//  SBDRestrictedUser.h
//  SendBirdSDK
//
//  Created by Celine Moon on 2021/09/30.
//  Copyright © 2021 SENDBIRD.COM. All rights reserved.
//

#import "SBDUser.h"
#import "SBDRestrictionInfo.h"

/**
 * Class to represent a muted or banned user.
 * @note This class is available from 3.0.236
 */
@interface SBDRestrictedUser : SBDUser

/**
 * Restriction information of a muted member.
 * @since This class is available from 3.0.236
 */
@property (atomic) SBDRestrictionInfo *restrictionInfo;

@end
