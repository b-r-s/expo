#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class ABI46_0_0REANodesManager;

typedef NSNumber *ABI46_0_0REANodeID;

@protocol ABI46_0_0REAFinalNode

- (void)update;

@end

@interface ABI46_0_0REAUpdateContext : NSObject
@property (nonatomic) NSString *callID;
@end

@interface ABI46_0_0REANode : NSObject

+ (void)runPropUpdates:(nonnull ABI46_0_0REAUpdateContext *)context;

- (instancetype)initWithID:(ABI46_0_0REANodeID)nodeID config:(NSDictionary<NSString *, id> *)config NS_DESIGNATED_INITIALIZER;

@property (nonatomic, weak, nullable) ABI46_0_0REANodesManager *nodesManager;
@property (nonatomic, nullable) ABI46_0_0REAUpdateContext *updateContext;
@property (nonatomic, readonly, nonnull) ABI46_0_0REANodeID nodeID;

- (_Nullable id)evaluate;
- (_Nullable id)value;
- (void)markUpdated;

- (void)addChild:(ABI46_0_0REANode *)child NS_REQUIRES_SUPER;
- (void)removeChild:(ABI46_0_0REANode *)child NS_REQUIRES_SUPER;

- (void)dangerouslyRescheduleEvaluate;
- (void)forceUpdateMemoizedValue:(id)value;

- (void)onDrop;

@end
