//
//  SBDThreadInfo.h
//  SendBirdSDK
//
//  Created by Jed Gyeong on 3/16/20.
//  Copyright © 2020 SENDBIRD.COM. All rights reserved.
//

#import "SBDError.h"
#import "SBDTypes.h"
#import "SBDUser.h"
#import "SBDThreadedMessageListParams.h"

/// An object that represents the information about threaded messages, whose properties show how many replies the thread has received, who left the replies, and when the last reply was added.
/// @note This class is available from 3.0.181
@interface SBDThreadInfo : NSObject

/// The total number of replies in a specific thread. A value of 0 indicates there is no reply in the thread.
/// @since 3.0.181
@property (nonatomic, readonly) NSInteger replyCount;

/// Users who left most replies in the thread. The order of users is based on the number of replies they made in the thread and the maximum size of the array can be adjusted per request.
/// @since 3.0.181
@property (nonatomic, nonnull, strong, readonly) NSArray<SBDUser *> *mostRepliedUsers;

/// The time that the last reply was created, in Unix milliseconds format. A value of 0 indicates there is no reply in the thread.
/// @since 3.0.181
@property (nonatomic, readonly) long long lastRepliedAt;

@end
