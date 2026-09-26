//
//  lathe_memory.h
//  lathe_core
//
//  Created by Christopher Scott on 9/22/26.
//  Inspired the following sites:
//  https://www.gingerbill.org/series/memory-allocation-strategies/
//  https://en.wikipedia.org/wiki/Region-based_memory_management
//  https://github.com/EasyMem/easy_memory/blob/main/easy_memory.h
//  https://www.aussieai.com/blog/poisoning-memory-safety
//  https://github.com/travisvroman/kohi/blob/main/kohi.core/src/memory/allocators/linear_allocator.c
//

#pragma once
// Arena Allocator / Linear Allocator

// Depending on if 32bit ->4 byte or 64bit ->8byte
// Memory is read at word size, unaligned is slower if allowed
// The amount of bytes that something must be aliged]med is power of 2

#include <stdio.h>

constexpr size_t LATHE_1KB = 1024;
constexpr size_t LATHE_1MB = 1024 * LATHE_1KB;
constexpr size_t LATHE_1GB = 1024 * LATHE_1MB;
constexpr size_t LATHE_ALIGNMENT = (2 * sizeof(void *));

// As of now, does not own memory...
typedef struct {
  unsigned char *buf;
  size_t buf_len;
  size_t prev_offset;
  size_t curr_offset;
} lathe_arena;

void arena_init(lathe_arena *arena, void *backing_buf, size_t backing_capacity);
// Must ensure that the data is aligned
uintptr_t align_foward(uintptr_t ptr, size_t align);

void *arena_alloced_align(lathe_arena *arena, size_t size, size_t align);
void *arena_allocate(lathe_arena *arena, size_t size);
// arena_resize //hmmm
void arena_free_all(lathe_arena *arena);
