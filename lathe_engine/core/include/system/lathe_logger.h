//
//  lathe_logger.h
//  lathe_core
//
//  Created by Christopher Scott on 9/22/26.
//
//
#pragma once

#define LOG_WARNING_ENABLED 1
#define LOG_INFO_ENABLED 1
#define LOG_DEBUG_ENABLED 1
#define LOG_TRACE_ENABLED 1
#if _LATHERELEASE == 1
#define LOG_DEBUG_ENABLED 0
#define LOG_TRACE_ENABLED 0
#endif

#include <stdint.h>
#include <stdio.h>

constexpr size_t log_buffer_max = 16;

typedef enum : uint8_t {
  LOG_LEVEL_FATAL,
  LOG_LEVEL_ERROR,
  LOG_LEVEL_WARNING,
  LOG_LEVEL_INFO,
  LOG_LEVEL_DEBUG,
  LOG_LEVEL_TRACE,
  LOG_LEVEL_COUNT
} lathe_log_level;

typedef struct {
  uint8_t R;
  uint8_t G;
  uint8_t B;
} color_t;

#define WHITE ((color_t){255, 255, 255})
#define BLACK ((color_t){0, 0, 0})
#define LASER_RED ((color_t){240, 44, 44})
#define FIRE_BUSH ((color_t){236, 148, 44})
#define YELLOW_GLITTER ((color_t){249, 225, 84})
#define LIGHT_SEA_BLUE ((color_t){64, 166, 206})
#define TRUE_TURQUOISE ((color_t){54, 224, 224})
#define SOME_GREEN ((color_t){7, 168, 20})

/**
 * @defgroup Terminal Coloring Utils
 * @brief A collection of terminal codes for colors
 * @{
 */

/**
 * @brief Sets the outputs background to color provided
 * @param color color to be applied
 * @param out output file or buffer
 */
void term_set_background_color(color_t color, FILE *out);

/**
 * @brief Sets the terminal text to the provided color
 * @addtogroup color
 * @param color Provided color for this terminal function
 */
void term_set_foreground_color(color_t color, FILE *out);

/**
 * @brief Sets the terminal text to be bold
 */
void term_set_bold(FILE *out);

/**
 * @brief Sets the terminal text to not be bold
 */
void term_set_no_bold(FILE *out);
/**
 * @brief Sets the terminal text to be underlined
 */
void term_set_underline(FILE *out);

/**
 * @brief Sets the terminal text to be not underlined
 */
void term_set_no_underline(FILE *out);

/**
 * @brief Resets any of the terminals features above
 */
void term_reset(FILE *out);
/** @} */ // End of Terminal Coloring Utils



void log_lvl_to_str(lathe_log_level lvl, char *log_lvl_buf);

/**
 * @brief Sets the log message to the provided output not to be used directly
 * @param lvl Provided color for this terminal function
 * @param out The output file/buffer
 * @param msg Message to be logged
 */
void internal_log_mes(lathe_log_level lvl, FILE *out, const char *file,
                       int line, const char *time, const char *msg);

#define LATHE_FATAL(msg, out)                                                  \
  internal_log_mes(LOG_LEVEL_FATAL, out, __FILE__, __LINE__, __TIME__, msg);

#define LATHE_WARN(msg, out)                                                   \
  internal_log_mes(LOG_LEVEL_WARNING, out, __FILE__, __LINE__, __TIME__, msg);

#define LATHE_INFO(msg, out)                                                   \
  internal_log_mes(LOG_LEVEL_INFO, out, __FILE__, __LINE__, __TIME__, msg);

#define LATHE_DEBUG(msg, out)                                                  \
  internal_log_mes(LOG_LEVEL_DEBUG, out, __FILE__, __LINE__, __TIME__, msg);

#define LATHE_ERROR(msg, out)                                                  \
  internal_log_mes(LOG_LEVEL_ERROR, out, __FILE__, __LINE__, __TIME__, msg);

#define LATHE_TRACE(msg, out)                                                  \
  internal_log_mes(LOG_LEVEL_TRACE, out, __FILE__, __LINE__, __TIME__, msg);
