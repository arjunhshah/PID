#include "PID.h"
#include "vex.h"

void PID(double target, double maxIntegral, double tolerance){
  
  //Initialize remaining variables
  double error = target;

  double derivative = 0;
  double integral = 0;
  double lastError = error;
  double total = 0;

  double kP = 0;
  double kI = 0;
  double kD = 0;

  //Main loop, when the robot is more than the desired distance from the target
  while(/*Condition here*/){

    //Calculate how far the robot is from the target
    


    //Find integral value

    
    //Prevent integral windup by capping the maximum integral value


    //Find derivative value

    
    //Calculate the target speed for the drivetrain
    

    //Spin drivetrain at the target speed
    /*
    LeftBack.spin();
    RightBack.spin();
    LeftFront.spin();
    RightFront.spin();
    LeftMiddle.spin();
    RightMiddle.spin();
    */


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