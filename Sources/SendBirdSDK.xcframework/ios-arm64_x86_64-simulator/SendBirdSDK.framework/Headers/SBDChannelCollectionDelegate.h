//
//  SBDChannelCollectionDelegate.h
//  SendBirdSDK
//
//  Created by Jed Gyeong on 5/3/21.
//  Copyright © 2021 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SBDChannelCollection.h"
#import "SBDChannelContext.h"
#import "SBDGroupChannel.h"

@class SBDChannelCollection;
@class SBDChannelContext;
@class SBDGroupChannel;

NS_ASSUME_NONNULL_BEGIN

/// Methods that are invoked when the event of the channel collection occurs.
/// @since 3.0.227
@protocol SBDChannelCollectionDelegate <NSObject>

@optional
/// A callback when the channels are added and updated.
/// @param collection The collection object.
/// @param context The context that represents the reason why the delegate is invoked.
/// @param channels The channels that are added and updated.
- (void)channelCollection:(SBDChannelCollection *)collection
                  context:(SBDChannelContext *)context
          changedChannels:(NSArray<SBDGroupChannel *> *)channels;

/// A callback when the channels are deleted.
/// @param collection The collection object.
/// @param context The context that represents the reason why the delegate is invoked.
/// @param deletedChannelUrls The channels that are deleted.
- (void)channelCollection:(SBDChannelCollection *)collection
                  context:(SBDChannelContext *)context
       deletedChannelUrls:(NSArray<NSString *> *)deletedChannelUrls;

@end

NS_ASSUME_NONNULL_END
