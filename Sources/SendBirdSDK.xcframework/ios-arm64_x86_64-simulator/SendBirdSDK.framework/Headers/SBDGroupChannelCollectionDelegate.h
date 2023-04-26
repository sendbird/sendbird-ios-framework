//
//  SBDGroupChannelCollectionDelegate.h
//  SendBirdSDK
//
//  Created by Jed Gyeong on 5/3/21.
//  Copyright © 2021 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SBDGroupChannelCollection.h"
#import "SBDChannelContext.h"
#import "SBDGroupChannel.h"

@class SBDGroupChannelCollection;
@class SBDChannelContext;
@class SBDGroupChannel;

NS_ASSUME_NONNULL_BEGIN

/// Methods that are invoked when the event of the channel collection occurs.
/// @since 3.1.0
@protocol SBDGroupChannelCollectionDelegate <NSObject>

@optional
/// A callback when the channels are added.
/// @param collection The collection object.
/// @param context The context that represents the reason why the delegate is invoked.
/// @param channels The channels that are added.
/// @since 3.1.0
- (void)channelCollection:(SBDGroupChannelCollection *)collection
                  context:(SBDChannelContext *)context
            addedChannels:(NSArray<SBDGroupChannel *> *)channels;

/// A callback when the channels are updated.
/// @param collection The collection object.
/// @param context The context that represents the reason why the delegate is invoked.
/// @param channels The channels that are updated.
/// @since 3.1.0
- (void)channelCollection:(SBDGroupChannelCollection *)collection
                  context:(SBDChannelContext *)context
          updatedChannels:(NSArray<SBDGroupChannel *> *)channels;

/// A callback when the channels are deleted.
/// @param collection The collection object.
/// @param context The context that represents the reason why the delegate is invoked.
/// @param deletedChannelUrls The channels that are deleted.
/// @since 3.1.0
- (void)channelCollection:(SBDGroupChannelCollection *)collection
                  context:(SBDChannelContext *)context
       deletedChannelUrls:(NSArray<NSString *> *)deletedChannelUrls;

@end

NS_ASSUME_NONNULL_END
