#include "autonSelector.h"

int selectedAuton = 1;
const int NUM_OF_AUTONS = 8;
const int FIRST_AUTON = 1;

void autonSelector(){
    bool previousPressed = false;




    while(!Controller.ButtonUp.pressing()){
        if (Controller.ButtonRight.pressing() && !previousPressed < NUM_OF_AUTONS){
            selectedAuton++;
            previousPressed = true;
        }
        else if (Controller.ButtonLeft.pressing() && !previousPressed){
            selectedAuton--;
            previousPressed = true;
        }
        else if(previousPressed == true && (!Controller.ButtonRight.pressing() && !Controller.ButtonLeft.pressing())){
            previousPressed = false;
        }

        Controller.Screen.setCursor(3, 1);
        Controller.Screen.setCursor(3, 1);
        Controller.Screen.print("Auton number:" + selectedAuton);
        wait(20, msec);
    }
    
    
    Controller.Screen.clearScreen();
    Controller.Screen.setCursor(3, 1);
    Controller.Screen.print("Auton number:" + selectedAuton);
}