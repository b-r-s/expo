#import <UIKit/UIKit.h>

#import "ABI46_0_0RNCSafeAreaViewEdges.h"
#import "ABI46_0_0RNCSafeAreaViewMode.h"

NS_ASSUME_NONNULL_BEGIN

@interface ABI46_0_0RNCSafeAreaViewLocalData : NSObject

- (instancetype)initWithInsets:(UIEdgeInsets)insets mode:(ABI46_0_0RNCSafeAreaViewMode)mode edges:(ABI46_0_0RNCSafeAreaViewEdges)edges;

@property (atomic, readonly) UIEdgeInsets insets;
@property (atomic, readonly) ABI46_0_0RNCSafeAreaViewMode mode;
@property (atomic, readonly) ABI46_0_0RNCSafeAreaViewEdges edges;

@end

NS_ASSUME_NONNULL_END
