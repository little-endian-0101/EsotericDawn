
#include "system/lathe_controller.h"
#import <GameController/GameController.h>

bool controller_connected(void) {
  [[NSRunLoop currentRunLoop]
      runUntilDate:[NSDate dateWithTimeIntervalSinceNow:0.1]];
  return GCController.controllers.count > 0;
}

lathe_controller_state controller_get_state(void) {
  lathe_controller_state state = {0};

  GCController *controller = GCController.controllers.firstObject;

  if (controller == nil)
    return state;

  GCExtendedGamepad *pad = controller.extendedGamepad;

  if (pad == nil)
    return state;

  state.left_x = pad.leftThumbstick.xAxis.value;
  state.left_y = pad.leftThumbstick.yAxis.value;

  state.right_x = pad.rightThumbstick.xAxis.value;
  state.right_y = pad.rightThumbstick.yAxis.value;

  state.left_trigger = pad.leftTrigger.value;
  state.right_trigger = pad.rightTrigger.value;

  state.a = pad.buttonA.isPressed;
  state.b = pad.buttonB.isPressed;
  state.x = pad.buttonX.isPressed;
  state.y = pad.buttonY.isPressed;

  state.dpad_up = pad.dpad.up.isPressed;
  state.dpad_down = pad.dpad.down.isPressed;
  state.dpad_left = pad.dpad.left.isPressed;
  state.dpad_right = pad.dpad.right.isPressed;

  return state;
}

#ifdef LATHE_DEBUG_ENABLED
void controller_print_buttons(void) {
  [[NSRunLoop currentRunLoop]
      runUntilDate:[NSDate dateWithTimeIntervalSinceNow:0.01]];

  GCController *controller = GCController.controllers.firstObject;

  if (controller == nil)
    return;

  GCExtendedGamepad *pad = controller.extendedGamepad;

  if (pad == nil)
    return;

  if (pad.buttonA.isPressed)
    printf("A\n");
  if (pad.buttonB.isPressed)
    printf("B\n");
  if (pad.buttonX.isPressed)
    printf("X\n");
  if (pad.buttonY.isPressed)
    printf("Y\n");

  if (pad.leftShoulder.isPressed)
    printf("L1\n");
  if (pad.rightShoulder.isPressed)
    printf("R1\n");

  if (pad.leftTrigger.isPressed)
    printf("L2\n");
  if (pad.rightTrigger.isPressed)
    printf("R2\n");

  if (pad.dpad.up.isPressed)
    printf("D-Pad Up\n");
  if (pad.dpad.down.isPressed)
    printf("D-Pad Down\n");
  if (pad.dpad.left.isPressed)
    printf("D-Pad Left\n");
  if (pad.dpad.right.isPressed)
    printf("D-Pad Right\n");
}
#else
void controller_print_buttons(void) {}
#endif
