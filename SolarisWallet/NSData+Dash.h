//
//  NSData+Dash.h
//  BreadWallet
//
//  Created by Sam Westrich on 1/31/17.
//  Copyright © 2017 Dash Foundation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IntTypes.h"

@interface NSData (Dash)

-(UInt256)XEVAN;

+ (NSData *)dataFromHexString:(NSString *)string;

@end
