#include "vex.h"

void default_constants()
{
  chassis.set_drive_constants(10, 1.5, 0, 10, 0);
  chassis.set_heading_constants(6, .4, 0, 1, 0);
  chassis.set_turn_constants(12, .4, .03, 3, 15);
  chassis.set_swing_constants(12, .3, .001, 2, 15);
  chassis.set_drive_exit_conditions(1.5, 300, 5000);
  chassis.set_turn_exit_conditions(1, 300, 3000);
  chassis.set_swing_exit_conditions(1, 300, 3000);
}

void odom_constants()
{
  default_constants();
  chassis.drive_max_voltage = 8;
  chassis.drive_settle_error = 3;
}


void auton_offensive()
{
  // when using right_swing_to_angle/left_swing_to_angle: use these values: (angle, speed, 2, 0, 1000, 2.2, 0, 4.2, 0).
  //  when want desired value, -/+10. eg: 90 degree turn, input 80
  chassis.drive_distance(58, 0, 12, 12);
  chassis.turn_to_angle(90, 12);
  rollerMotor.spin(reverse, 100, percent);
  chassis.drive_distance(28, 90, 12, 12, 2, 500, 1000, 1.75, 0, 1.6, 0, 1.75, 0, 1.6, 0);
  rollerMotor.stop();
  chassis.drive_distance(-10, 90, 12, 12);
  chassis.turn_to_angle(270, 12);
  chassis.drive_distance(18, 270, 12, 12);
  wall_solenoid.set(true);
  chassis.drive_distance(-20, 270, 12, 12);
  chassis.right_swing_to_angle(230, 8, 2, 0, 1000, 2.2, 0, 4.2, 0);
  rollerMotor.spin(forward, 100, percent);
  chassis.drive_distance(26, 245, 12, 12);
  chassis.drive_distance(-25, 245, 12, 12);
  chassis.turn_to_angle(80, 12);
  rollerMotor.stop();
  rollerMotor.spin(reverse, 100, percent);
  chassis.drive_distance(35, 90, 12, 12, 2, 500, 1000, 1.75, 0, 1.6, 0, 1.75, 0, 1.6, 0);
  rollerMotor.stop();
  chassis.drive_distance(-10, 90, 0, 0);
  Brain.Screen.printAt(100, 50, "inertial sensor heading: %f", inertialSensor.heading());
}

void skillsAuton()
{
  // when using right_swing_to_angle/left_swing_to_angle: use these values: (angle, speed, 2, 0, 1000, 2.2, 0, 4.2, 0).
  //  when want desired value, -/+10. eg: 90 degree turn, input 80

  // move foward to get both alliance triballs into the goal
  chassis.drive_distance(10, 0, 12, 12);
  chassis.turn_to_angle(-45, 12);
  chassis.drive_distance(28, -45, 12, 12);
  rollerMotor.spin(reverse, 100, percent);
  chassis.drive_distance(8, 0, 12, 12, 2, 500, 1000, 1.75, 0, 1.6, 0, 1.75, 0, 1.6, 0);
  chassis.drive_distance(-5, 0, 12, 12);
  chassis.drive_distance(5, 0, 12, 12, 2, 500, 1000, 1.75, 0, 1.6, 0, 1.75, 0, 1.6, 0);
  rollerMotor.stop();
  // return to alliance bar for matchload
  chassis.drive_distance(-12, 0, 12, 12, 2, 500, 600, 1.75, 0, 1.6, 0, 1.75, 0, 1.6, 0);
  chassis.turn_to_angle(-135, 12);
  chassis.drive_distance(14, -135, 12, 12, 2, 500, 800, 1.75, 0, 1.6, 0, 1.75, 0, 1.6, 0);
  chassis.right_swing_to_angle(-122, 2, 2, 0, 1000, 2.2, 0, 4.2, 0);
  chassis.drive_distance(2, -122, 12, 12);
  wait(2000, msec);
  // cata matchload code (make sure rotation times is correct)
  for (int i = 0; i < 5; i++) {
    cataMotor.spinFor(500, rotationUnits::deg);
  };
  // go to otherside to push balls in
  chassis.right_swing_to_angle(-45, 2, 2, 0, 1000, 2.2, 0, 4.2, 0);
  chassis.drive_distance(-20, -45, 12, 12);
  chassis.turn_to_angle(-90, 12);
  chassis.drive_distance(-80, -90, 12, 12);
  wait(1000, msec);
  chassis.turn_to_angle(-135, 12);
  wait(1000, msec);
  chassis.drive_distance(-25, -135, 12, 12);
  chassis.drive_distance(-17, -180, 12, 12, 2, 500, 1000, 1.75, 0, 1.6, 0, 1.75, 0, 1.6, 0);
  chassis.drive_distance(5, -180, 12, 12);
  chassis.drive_distance(-8, -180, 12, 12, 2, 500, 1000, 1.75, 0, 1.6, 0, 1.75, 0, 1.6, 0);
  chassis.drive_distance(5, -180, 12, 12);
  chassis.turn_to_angle(90, 12);
  chassis.drive_distance(-45, 90, 12, 12);
  chassis.right_swing_to_angle(270, 12, 2, 0, 1000, 2.2, 0, 4.2, 0);
  wall_solenoid.set(true);
  chassis.drive_distance(-30, 270, 12, 12, 2, 500, 800, 1.75, 0, 1.6, 0, 1.75, 0, 1.6, 0);
  chassis.drive_distance(15, 270, 12, 12);
  chassis.drive_distance(-20, 270, 12, 12, 2, 500, 800, 1.75, 0, 1.6, 0, 1.75, 0, 1.6, 0);
  Brain.Screen.printAt(100, 50, "inertial sensor heading: %f", inertialSensor.heading());
}

void turn_test()
{
  chassis.turn_to_angle(5);
  chassis.turn_to_angle(30);
  chassis.turn_to_angle(90);
  chassis.turn_to_angle(225);
  chassis.turn_to_angle(0);
}

void swing_test()
{
  chassis.left_swing_to_angle(90);
  chassis.right_swing_to_angle(0);
}

void full_test()
{
  chassis.drive_distance(24);
  chassis.turn_to_angle(-45);
  chassis.drive_distance(-36);
  chassis.right_swing_to_angle(-90);
  chassis.drive_distance(24);
  chassis.turn_to_angle(0);
}

void odom_test()
{
  chassis.set_coordinates(0, 0, 0);
  while (1)
  {
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(0, 50, "X: %f", chassis.get_X_position());
    Brain.Screen.printAt(0, 70, "Y: %f", chassis.get_Y_position());
    Brain.Screen.printAt(0, 90, "Heading: %f", chassis.get_absolute_heading());
    Brain.Screen.printAt(0, 110, "ForwardTracker: %f", chassis.get_ForwardTracker_position());
    Brain.Screen.printAt(0, 130, "SidewaysTracker: %f", chassis.get_SidewaysTracker_position());
    task::sleep(20);
  }
}

void tank_odom_test()
{
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.turn_to_point(24, 24);
  chassis.drive_to_point(24, 24);
  chassis.drive_to_point(0, 0);
  chassis.turn_to_angle(0);
}

void holonomic_odom_test()
{
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.holonomic_drive_to_point(0, 18, 90);
  chassis.holonomic_drive_to_point(18, 0, 180);
  chassis.holonomic_drive_to_point(0, 18, 270);
  chassis.holonomic_drive_to_point(0, 0, 0);
}