//
//  SBDFileMessageParams.h
//  SendBirdSDK
//
//  Created by sendbird-young on 2018. 3. 5..
//  Copyright © 2018년 SENDBIRD.COM. All rights reserved.
//

#import "SBDBaseMessageParams.h"

@class SBDThumbnailSize;

/**
 *  The `SBDFileMessageParams` class is used to send a file message in `SBDBaseChannel`. This is a child class of `SBDBaseMessageParams`.
 */
@interface SBDFileMessageParams : SBDBaseMessageParams

@property (copy, nonatomic, nullable) NSData *file;

@property (copy, nonatomic, nullable) NSString *fileUrl;

@property (copy, nonatomic, nullable) NSArray <SBDThumbnailSize *> *thumbnailSizes;

@property (copy, nonatomic, nullable) NSString *fileName;

@property (copy, nonatomic, nullable) NSString *mimeType;

@property (nonatomic) NSUInteger fileSize;

- (nullable instancetype)init NS_UNAVAILABLE;
- (nullable instancetype)initWithFile:(nonnull NSData *)file;
- (nullable instancetype)initWithFileUrl:(nonnull NSString *)fileUrl;

@end
