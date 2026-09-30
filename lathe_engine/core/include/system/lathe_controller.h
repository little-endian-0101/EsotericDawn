// lathe_controller.h
#pragma once

// typedef struct {
//     bool current;
//     bool previous;
// } lathe_button_state;

typedef struct {
  float left_x;
  float left_y;

  float right_x;
  float right_y;

  float left_trigger;
  float right_trigger;

  bool a_button;
  bool b_button;
  bool x_button;
  bool y_button;

  bool dpad_up;
  bool dpad_down;
  bool dpad_left;
  bool dpad_right;
} lathe_controller_state;

bool controller_connected(void);
bool controller_disconnected(void);
bool controller_print_buttons(void); // Debug
lathe_controller_state controller_get_state(void);
