#include <Metal/Metal.h>
#include <MetalKit/MetalKit.h>

@interface MainRenderer : NSObject< MTKViewDelegate >
@end

@implementation MainRenderer
@end

MainRenderer CreateMainRenderer()
{
	MainRenderer* renderer = [MainRenderer new];
	
	return renderer;
}