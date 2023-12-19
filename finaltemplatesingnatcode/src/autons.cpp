#include "vex.h"

void default_constants(){
  chassis.set_drive_constants(10, 1.5, 0, 10, 0);
  chassis.set_heading_constants(6, .4, 0, 1, 0);
  chassis.set_turn_constants(12, .4, .03, 3, 15);
  chassis.set_swing_constants(12, .3, .001, 2, 15);
  chassis.set_drive_exit_conditions(1.5, 300, 5000);
  chassis.set_turn_exit_conditions(1, 300, 3000);
  chassis.set_swing_exit_conditions(1, 300, 3000);
}

void odom_constants(){
  default_constants();
  chassis.drive_max_voltage = 8;
  chassis.drive_settle_error = 3;
}

void goStraight(double speed, double distance) {
  leftFrontMotor.spinFor(fwd, distance, degrees, speed, rpm, false);
  leftMiddleMotor.spinFor(fwd, distance, degrees, speed, rpm, false);
  leftBackMotor.spinFor(fwd, distance, degrees, speed, rpm, false);
  rightFrontMotor.spinFor(fwd, distance, degrees, speed, rpm, false);
  rightMiddleMotor.spinFor(fwd, distance, degrees, speed, rpm, false);
  rightBackMotor.spinFor(fwd, distance, degrees, speed, rpm, true);
  wait(200, msec);
}

void auton_offensive(){
  chassis.drive_distance(15, 0);
  
  //reminder: when using right_swing_to, add/minus 5 degrees
  //chassis.drive_distance(54, 0, 12, 12);
  //chassis.turn_to_angle(90, 12);
  //chassis.drive_distance(15.5, 90, 12, 12);
  //chassis.drive_distance(-10, 90, 12, 12);
  //chassis.turn_to_angle(270, 12);
  //chassis.drive_distance(13, 270, 12, 12);
  //wall_solenoid.set(true);
  //chassis.drive_distance(-15, 270, 12, 12);
  //chassis.right_swing_to_angle(240);
  //rollerMotor.spin(forward, 100, percent);
  //chassis.drive_distance(30, 245, 12, 12);
  //chassis.drive_distance(-25, 245, 12, 12);
  //chassis.turn_to_angle(150, 12);
  //goStraight(1000, 300);
  Brain.Screen.printAt(100, 50, "inertial sensor heading: %f", inertialSensor.heading());
}

void skillsAuton(){
  //move foward to get both alliance triballs into the goal
  chassis.drive_distance(20, 0, 12, 12);
  chassis.turn_to_angle(90, 12);
  rollerMotor.spin(reverse, 100, percent);
  goStraight(1000, 100);
  //return to alliance bar for matchload
  chassis.drive_distance(-10, 0, 12, 12);
  chassis.right_swing_to_angle(45);
  goStraight(100, 100);
  for (int i = 0; i < 46;)
  {
    //rotation sensor cata code
  }
  //go to otherside to push balls in
  chassis.drive_distance(-5, 0, 12, 12);
  chassis.right_swing_to_angle(270);
  chassis.drive_distance(80, 0, 12, 12);
  chassis.right_swing_to_angle(120);
  chassis.drive_distance(50, 120, 12, 12);
  chassis.left_swing_to_angle(60);
  //wall_solenoid.set(true)
  goStraight(1000, 500);
  chassis.drive_distance(-15, 0, 12, 12);
  goStraight(1000, 500);
}

void turn_test(){
  chassis.turn_to_angle(5);
  chassis.turn_to_angle(30);
  chassis.turn_to_angle(90);
  chassis.turn_to_angle(225);
  chassis.turn_to_angle(0);
}

void swing_test(){
  chassis.left_swing_to_angle(90);
  chassis.right_swing_to_angle(0);
}

void full_test(){
  chassis.drive_distance(24);
  chassis.turn_to_angle(-45);
  chassis.drive_distance(-36);
  chassis.right_swing_to_angle(-90);
  chassis.drive_distance(24);
  chassis.turn_to_angle(0);
}

void odom_test(){
  chassis.set_coordinates(0, 0, 0);
  while(1){
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(0,50, "X: %f", chassis.get_X_position());
    Brain.Screen.printAt(0,70, "Y: %f", chassis.get_Y_position());
    Brain.Screen.printAt(0,90, "Heading: %f", chassis.get_absolute_heading());
    Brain.Screen.printAt(0,110, "ForwardTracker: %f", chassis.get_ForwardTracker_position());
    Brain.Screen.printAt(0,130, "SidewaysTracker: %f", chassis.get_SidewaysTracker_position());
    task::sleep(20);
  }
}

void tank_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.turn_to_point(24, 24);
  chassis.drive_to_point(24,24);
  chassis.drive_to_point(0,0);
  chassis.turn_to_angle(0);
}

void holonomic_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.holonomic_drive_to_point(0, 18, 90);
  chassis.holonomic_drive_to_point(18, 0, 180);
  chassis.holonomic_drive_to_point(0, 18, 270);
  chassis.holonomic_drive_to_point(0, 0, 0);
}