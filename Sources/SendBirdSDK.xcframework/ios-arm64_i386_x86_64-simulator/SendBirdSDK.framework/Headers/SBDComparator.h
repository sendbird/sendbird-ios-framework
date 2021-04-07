//
//  SBDComparator.h
//  SendBirdSDK
//
//  Created by Wooyoung Chung on 9/8/20.
//  Copyright © 2020 SENDBIRD.COM. All rights reserved.
//

#ifndef SBDComparator_h
#define SBDComparator_h

#import "SBDBaseMessage.h"
#import "SBDGroupChannel.h"
#import "SBDGroupChannelListQuery.h"

@class SBDBaseMessage;
@class SBDGroupChannel;
@class SBDGroupChannelListQuery;

typedef NSComparisonResult(^SBDObjectComparator)(id obj1, id obj2);

/// Protocol confirms to provide comparator that can be used to sort 
@protocol SBDComparator <NSObject>
- (SBDObjectComparator)comparator;
- (NSComparisonResult)orderBetweenObject:(id)obj1 andObject:(id)obj2;
@end

@interface SBDBaseMessage (Comparator) <SBDComparator>
@end

@interface SBDGroupChannel (Comparator) <SBDComparator>
@end

@interface SBDGroupChannelListQuery (Comparator) <SBDComparator>
@end

#endif
