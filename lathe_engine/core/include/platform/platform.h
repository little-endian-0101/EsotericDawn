#pragma once
#include "lathe_logger.h"

typedef struct PlatformState {
  void *internal_state; // Opoque ptr to memory
} PlatformState;

typedef struct platform_window_cfg {
  int32_t position_x;
  int32_t position_y;
  uint32_t width;
  uint32_t height;
  const char *title;
  const char *name;
} platform_window_cfg;

// ### State Transitions ###
bool platform_start(PlatformState *state, const char *application_name,
                    int32_t x, int32_t y, int32_t width, int32_t height);
void platform_shutdown(PlatformState *state);
bool platform_handle_os_events(PlatformState *state);
// ### State Transitions ###

// ### Memory - [ESSENTIAL] ###
// DEV-NOTICE: If the platform mem adjustments are not set code will seg-fault!
void *platform_alloc(uint64_t size, bool aligned);
void *platform_zero_alloc(uint64_t size, bool aligned);
void platform_free(void *block, bool aligned);
void *platform_zero_mem(void *block, uint64_t size);
void *platform_copy_mem(void *dest, const void *src, uint64_t size);
void *platform_set_mem(void *dest, uint64_t val, uint64_t size);
// ### Memory ###

// ### Console Output ###
void platform_console_write(const char *msg, lathe_log_level lvl);
// ### Console Output ###

// ### Threading ###
double platform_get_time();
void platform_sleep(uint64_t ms);
// ### Threading ###
