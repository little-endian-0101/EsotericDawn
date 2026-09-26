#pragma once

#if defined(WIN32) || defined(_WIN32)
#define LATHE_WINDOWS 1
#elif defined(__APPLE__)
#include <TargetConditionals.h>
#if TARGET_OS_OSX
#define LATHE_OSX 1
#else
#error "Detected an Apple device, but not supported"
#endif
#elif defined(__linux__)
#define LATHE_LINUX 1
#else
#error "Detected Platform is not Apple,Windows, or Linux"
#endif
