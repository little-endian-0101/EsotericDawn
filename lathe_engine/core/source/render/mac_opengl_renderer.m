#define GL_SILENCE_DEPRECATION //sigh 2026... RIP my sweet summer child

#import <Cocoa/Cocoa.h>
#import <OpenGL/gl3.h>

#include "render/renderer.h"

#include <mach/mach_time.h>
#include "system/lathe_logger.h"

typedef struct MacPlatformState {
    NSApplication *application;
    NSWindow *window;
    mach_timebase_info_data_t timebase;
    uint64_t start_time;
} MacPlatformState;

//TODO move into renderer internal state
static NSOpenGLView *gl_view = nil;
static NSOpenGLContext *gl_context = nil;

bool renderer_start(PlatformState *state){
    if (state == nullptr || state->internal_state == nullptr) {
        return false;
    }

    MacPlatformState *mac = (MacPlatformState *)state->internal_state;

    if (mac->window == nil) {
        return false;
    }

    NSOpenGLPixelFormatAttribute attrs[] = {
        NSOpenGLPFAOpenGLProfile,
        NSOpenGLProfileVersion3_2Core,

        NSOpenGLPFADoubleBuffer,
        NSOpenGLPFAAccelerated,

        NSOpenGLPFAColorSize, 24,
        NSOpenGLPFAAlphaSize, 8,
        NSOpenGLPFADepthSize, 24,

        0
    };

    NSOpenGLPixelFormat *format = [[NSOpenGLPixelFormat alloc] initWithAttributes:attrs];

    if (format == nil) {
        LATHE_FATAL("Failed to create OpenGL pixel format!", nullptr);
        return false;
    }

 
    gl_view = [[NSOpenGLView alloc] initWithFrame:mac->window.contentView.bounds 
                                    pixelFormat:format];

    if (gl_view == nil) {
        LATHE_FATAL("Failed to create NSOpenGLView!", nullptr);
        return false;
    }


    gl_view.autoresizingMask = NSViewWidthSizable | NSViewHeightSizable;

    [mac->window setContentView:gl_view];

   
    gl_context = [gl_view openGLContext];

    if (gl_context == nil) {
        LATHE_FATAL("Failed to create OpenGL context!", nullptr);
        return false;
    }

    [gl_context makeCurrentContext];

    const GLubyte *version = glGetString(GL_VERSION);

    if (version != NULL) {
        printf("OpenGL Version: %s\n", (const char *)version);
        LATHE_INFO("OpenGL Version fix the logger....", nullptr);
    }

    return true;
}

void renderer_begin_frame(){
    [gl_context makeCurrentContext];
}

void renderer_clear(float red, float green, float blue, float alpha){
    glClearColor(red, green, blue, alpha);
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void renderer_end_frame(){
    [gl_context flushBuffer];
}

void renderer_shutdown(){
    [NSOpenGLContext clearCurrentContext];
    gl_context = nil;
    gl_view = nil;
}