//
//  SBDMappable.h
//  SendBirdSDK
//
//  Created by Wooyoung Chung on 6/17/20.
//  Copyright © 2020 SENDBIRD.COM. All rights reserved.
//

#ifndef SBDMappable_h
#define SBDMappable_h

/// Confirms that an object can initialize from dictionary and convert to dictionary
@protocol SBDMappable <NSObject>
@required
- (nonnull instancetype)initWithDictionary:(nonnull NSDictionary *)dict;
@optional
- (nonnull NSDictionary *)_toDictionary;
+ (nonnull NSArray *)objectsFromJsonArray:(nullable NSArray *)array;
@end


#endif /* SBDMappable_h */
