#pragma once

#include "vex.h"
#include "robot-config.h"

void PID (double target, double maxIntegral = 500, double tolerance = 0.5);