#include "PID.h"
#include "vex.h"

void PID(double target, double maxIntegral, double tolerance){
  double error = target;

  double derivative = 0;
  double integral = 0;
  double lastError = error;
  double total = 0;
  double kP = 7;
  double kI = 0.5;
  double kD = 0.05;
  inertialSensor.setRotation(0, degrees);
  const double gearRatio = 5.0/3;
  const double wheelDiameter = 3.25;
  const double deltaT  = 0.015;
  double wheelRotation = M_PI*wheelDiameter;
  //Main loop, when the robot is more than the desired distance from the target
  while(fabs(error) > tolerance){

    
    //Calculate how far the robot is from the target
    double sensorValue = (inertialSensor.rotation(degrees) / 360) * wheelRotation / gearRatio;
    error = target - sensorValue;
    //Find integral value
    integral += error * deltaT;
    
    //Prevent integral windup by capping the maximum integral value
    if (integral > maxIntegral){
      integral = maxIntegral;
    }
    else if (integral < -maxIntegral){

    }


    //Find derivative value
    derivative = (error-lastError)/ deltaT;
    lastError = error;
    
    
    
    //Calculate the target speed for the drivetrain
    total = kP*error + kI*integral + kD* derivative;
    //Spin drivetrain at the target speed
    LeftBack.spin(forward, total, percent);
    RightBack.spin(reverse, total, percent);
    LeftFront.spin(forward, total, percent);
    RightFront.spin(reverse, total, percent);
    LeftMiddle.spin(forward, total, percent);
    RightMiddle.spin(reverse, total, percent);


    //Short wait to save resources

    wait(15, msec); 
  }
  //Brake motors after driving is finished
  LeftBack.stop(brake);
  RightBack.stop(brake);
  RightFront.stop(brake);
  LeftFront.stop(brake);
  LeftMiddle.stop(brake);
  RightMiddle.stop(brake);
  //Short delay to come to a full stop
  wait(50, msec);
}