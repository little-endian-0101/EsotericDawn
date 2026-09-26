#include "system/lathe_logger.h"

void term_set_background_color(color_t color, FILE *out) {
  out = (out == nullptr) ? stderr : out;
  fprintf(out, "\e[48;2;%d;%d;%dm", color.R, color.G, color.B);
}

void term_set_foreground_color(color_t color, FILE *out) {
  out = (out == nullptr) ? stderr : out;
  fprintf(out, "\e[38;2;%d;%d;%dm", color.R, color.G, color.B);
}
/**
 * @brief Sets the terminal text to be bold
 */
void term_set_bold(FILE *out) {
  out = (out == nullptr) ? stderr : out;
  fprintf(out, "\e[1m");
}

/**
 * @brief Sets the terminal text to not be bold
 */
void term_set_no_bold(FILE *out) {
  out = (out == nullptr) ? stderr : out;
  fprintf(out, "\e[22m");
}
/**
 * @brief Sets the terminal text to be underlined
 */
void term_set_underline(FILE *out) {
  out = (out == nullptr) ? stderr : out;
  fprintf(out, "\e[4m");
}

/**
 * @brief Sets the terminal text to be not underlined
 */
void term_set_no_underline(FILE *out) {
  out = (out == nullptr) ? stderr : out;
  fprintf(out, "\e[24m");
}

/**
 * @brief Resets any of the terminals features above
 */
void term_reset(FILE *out) {
  out = (out == nullptr) ? stderr : out;
  fprintf(out, "\e[0m");
}
/** @} */ // End of Terminal Coloring Utils

void log_lvl_to_str(lathe_log_level lvl, char *log_lvl_buf) {
  switch (lvl) {
  case LOG_LEVEL_FATAL:
    snprintf(log_lvl_buf, log_buffer_max, "%s", "[FATAL] \U00002757");
    break;
  case LOG_LEVEL_ERROR:
    snprintf(log_lvl_buf, log_buffer_max, "%s", "[ERROR] \U0000274C");
    break;
  case LOG_LEVEL_WARNING:
    snprintf(log_lvl_buf, log_buffer_max, "%s", "[WARNING] \U000026A0");
    break;
  case LOG_LEVEL_INFO:
    snprintf(log_lvl_buf, log_buffer_max, "%s", "[INFO] \U00002139");
    break;
  case LOG_LEVEL_DEBUG:
    snprintf(log_lvl_buf, log_buffer_max, "%s", "[DEBUG] \U0001F41B");
    break;
  case LOG_LEVEL_TRACE:
    snprintf(log_lvl_buf, log_buffer_max, "%s", "[TRACE] \U0001F50D");
    break;
  default:
    // may handle later
    break;
  }
}

/**
 * @brief Sets the log message to the provided output not to be used directly
 * @param lvl Provided color for this terminal function
 * @param out The output file/buffer
 * @param msg Message to be logged
 */
// LATHE_ERROR("This is an ERROR", stdout);
//  #define LATHE_FATAL(msg, out) \
//   _internal_log_mes(LOG_LEVEL_FATAL, out, __FILE__, __LINE__, __TIME__, msg);
void _internal_log_mes(lathe_log_level lvl, FILE *out, const char *file,
                       int line, const char *time, const char *msg) {
  out = (out == nullptr) ? stderr : out;
  char log_str[log_buffer_max];
  log_lvl_to_str(lvl, log_str);
  // add macro for time
  fprintf(out, "%s %s:%d %s ", log_str, file, line, msg);
}
