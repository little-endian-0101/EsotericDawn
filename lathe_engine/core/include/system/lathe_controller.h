// lathe_controller.h
#pragma once

typedef struct {
  float left_x;
  float left_y;

  float right_x;
  float right_y;

  float left_trigger;
  float right_trigger;

  bool a;
  bool b;
  bool x;
  bool y;

  bool dpad_up;
  bool dpad_down;
  bool dpad_left;
  bool dpad_right;
} lathe_controller_state;

bool controller_connected(void);
bool controller_disconnected(void);
void controller_print_buttons(void); // Debug
lathe_controller_state controller_get_state(void);
