#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;

motor LeftFront = motor(PORT1, ratio6_1, true);
motor LeftMiddle = motor(PORT2, ratio6_1, true);
motor LeftBack = motor(PORT3, ratio6_1, true);

motor RightFront = motor(PORT4, ratio6_1, false);
motor RightMiddle = motor(PORT5, ratio6_1, false);
motor RightBack = motor(PORT6, ratio6_1, false);

controller Controller = controller(primary);

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  // Nothing to initialize
}