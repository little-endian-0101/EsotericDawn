// lathe_renderer.h

#pragma once 

#include <stdint.h>
#include "platform/platform.h"

typedef enum {
    RENDERER_OPENGL,
    RENDERER_METAL,
    RENDERER_VULKAN,
    RENDERER_D3D12,
} renderer_api;

typedef struct {
    void *internal_state;
} renderer;

bool renderer_start(PlatformState *state);

void renderer_begin_frame();

void renderer_clear(
    float red,
    float green,
    float blue,
    float alpha
);

void renderer_end_frame();

void renderer_shutdown();
