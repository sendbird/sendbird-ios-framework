//
//  SBDAdminMessage.h
//  SendBirdSDK
//
//  Created by Jed Gyeong on 5/23/16.
//  Copyright © 2016 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBDBaseMessage.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  The `SBDAdminMessage` class represents a <span>message</span> which is sent by an admin via [Platform API](https://docs.sendbird.com/platform). The admin <span>message</span> doesn't have a sender. This <span>message</span> is sutable for a notice to inform the members in a group channel or the participants in an open channel. If you would like to know about the Platform API for the <span>message</span>, see [Send a message](https://docs.sendbird.com/platform#messages_3_send).
 */
@interface SBDAdminMessage : SBDBaseMessage <NSCopying>

@end

NS_ASSUME_NONNULL_END
