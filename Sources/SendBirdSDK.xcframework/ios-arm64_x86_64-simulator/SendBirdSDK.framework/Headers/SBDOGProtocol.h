//
//  SBDOGProtocol.h
//  SendBirdSDK
//
//  Created by Wooyoung Chung on 6/18/20.
//  Copyright © 2020 SENDBIRD.COM. All rights reserved.
//

#ifndef SBDOGProtocol_h
#define SBDOGProtocol_h

@protocol SBDOGMedia <NSObject>
@required
@property (nonatomic, copy, readonly) NSString *secureURL;
@property (nonatomic, copy, readonly) NSString *type;
@end

@protocol SBDOGDisplayableMedia <NSObject>
@required
@property (atomic, assign, readonly) NSInteger width;
@property (atomic, assign, readonly) NSInteger height;
@end

#endif /* SBDOGProtocol_h */
