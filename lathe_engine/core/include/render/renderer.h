// lathe_renderer.h

#pragma once 

#include <stdint.h>

typedef enum {
    RENDERER_OPENGL,
    RENDERER_METAL,
    RENDERER_VULKAN,
    RENDERER_D3D12,
} renderer_api;

typedef struct {
    void *internal_state;
} renderer;

bool renderer_start(
    renderer *r,
    renderer_api api,
    void *platform_window
);

void renderer_begin_frame(renderer *r);

void renderer_clear(
    renderer *r,
    float red,
    float green,
    float blue,
    float alpha
);

void renderer_end_frame(renderer *r);

void renderer_shutdown(renderer *r);
