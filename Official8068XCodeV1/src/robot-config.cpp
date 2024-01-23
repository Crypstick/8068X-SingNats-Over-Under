#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor rightFrontMotor = motor(PORT6, ratio6_1, false);
motor rightMiddleMotor = motor(PORT7, ratio6_1, false);
motor rightBackMotor = motor(PORT8, ratio6_1, false);
motor leftFrontMotor = motor(PORT5, ratio6_1, true);
motor leftMiddleMotor = motor(PORT4, ratio6_1, true);
motor leftBackMotor = motor(PORT3, ratio6_1, true);

motor rollerMotor = motor(PORT11, ratio6_1, true);
motor cataMotor = motor(PORT12, ratio6_1, false);

digital_out wall_solenoid = digital_out(Brain.ThreeWirePort.H);
digital_out endgame_solenoid = digital_out(Brain.ThreeWirePort.G);
inertial inertialSensor = inertial(PORT19);
rotation cataRotationSensor = rotation(PORT20, false); // to change port number and reverse boolean accordingly 

controller Remote = controller(primary);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools inkkkkkkkkkddkkkkkkk VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  rightFrontMotor.setBrake(coast);
  rightMiddleMotor.setBrake(coast);
  rightBackMotor.setBrake(coast);
  leftFrontMotor.setBrake(coast);
  leftMiddleMotor.setBrake(coast);
  leftBackMotor.setBrake(coast);
  inertialSensor.calibrate();
  cataRotationSensor.resetPosition();
}