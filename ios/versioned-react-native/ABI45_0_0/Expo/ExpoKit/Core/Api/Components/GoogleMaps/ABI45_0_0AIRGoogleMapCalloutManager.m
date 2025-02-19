//
//  ABI45_0_0AIRGoogleMapCalloutManager.m
//  AirMaps
//
//  Created by Gil Birman on 9/6/16.
//
//

#ifdef ABI45_0_0HAVE_GOOGLE_MAPS

#import "ABI45_0_0AIRGoogleMapCalloutManager.h"
#import "ABI45_0_0AIRGoogleMapCallout.h"
#import <ABI45_0_0React/ABI45_0_0RCTView.h>

@implementation ABI45_0_0AIRGoogleMapCalloutManager
ABI45_0_0RCT_EXPORT_MODULE()

- (UIView *)view
{
  ABI45_0_0AIRGoogleMapCallout *callout = [ABI45_0_0AIRGoogleMapCallout new];
  return callout;
}

ABI45_0_0RCT_EXPORT_VIEW_PROPERTY(tooltip, BOOL)
ABI45_0_0RCT_EXPORT_VIEW_PROPERTY(onPress, ABI45_0_0RCTBubblingEventBlock)
ABI45_0_0RCT_EXPORT_VIEW_PROPERTY(alphaHitTest, BOOL)

@end

#endif
