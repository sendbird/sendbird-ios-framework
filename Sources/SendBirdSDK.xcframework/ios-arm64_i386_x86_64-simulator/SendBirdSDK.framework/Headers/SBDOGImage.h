//
//  SBDOGImage.h
//  SendBirdSDK
//
//  Created by Wooyoung Chung on 6/18/20.
//  Copyright © 2020 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBDOGMetaData.h"
#import "SBDOGProtocol.h"

NS_ASSUME_NONNULL_BEGIN

/// Represents OpenGraph Image information
/// @since 3.0.193
@interface SBDOGImage : NSObject <SBDOGMedia, SBDOGDisplayableMedia>

/// An image url
@property (nonatomic, copy, readonly, nullable) NSString *url;

/// An alternate url to use if the webpage requires HTTPS
@property (nonatomic, copy, readonly, nullable) NSString *secureURL;

/// A MIME type for this image
@property (nonatomic, copy, readonly, nullable) NSString *type;

/// A description of what is in the image (not a caption). If the page specifies an og:image it should specify this property
@property (nonatomic, copy, readonly, nullable) NSString *alt;

/// The number of pixels wide
@property (atomic, assign, readonly) NSInteger width;

/// The number of pixels high
@property (atomic, assign, readonly) NSInteger height;

@end

NS_ASSUME_NONNULL_END
