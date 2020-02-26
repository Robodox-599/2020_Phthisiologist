/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/subsystem_Drive.h"

subsystem_Drive::subsystem_Drive() : frontLeftMotor(1), rearLeftMotor(2), frontRightMotor(3), rearRightMotor(4)
{
  frontRightMotor.SetInverted(true);
  rearRightMotor.SetInverted(true);
  frontLeftMotor.SetInverted(false);
  rearLeftMotor.SetInverted(false);
}


void subsystem_Drive::JoystickVelocityDrive(double x, double y)
{
  double l;
  double r;
  double leftOutput;
  double rightOutput;
  double increment = 600;

  if (y > 0.2)
  {
    y = (y - 0.2) * (1 / .8) * 3000 /**max velocity*/;
  }
  else if (y < -0.2)
  {
    y = (y + 0.2) * 1 / .8 * 3000 /**max velocity*/;
  }
  else
  {
    y = 0;
  }

  if (x > 0.2)
  {
    x = (x - 0.2) * 1 / .8 * 1500 /**max velocity/2*/;
  }
  else if (x < -0.2)
  {
    x = (x + 0.2) * 1 / .8 * 1500 /**max velocity/2*/;
  }
  else
  {
    x = 0;
  }

  l = -y + x;
  r = -y - x;

  if (l > rearLeftMotor.GetSelectedSensorVelocity(0) + increment)
  {
    leftOutput = rearLeftMotor.GetSelectedSensorVelocity(0) + increment;
  }
  else if (l < rearLeftMotor.GetSelectedSensorVelocity(0) - increment)
  {
    leftOutput = rearLeftMotor.GetSelectedSensorVelocity(0) - increment;
  }
  else
  {
    leftOutput = l;
  }

  if (r > rearRightMotor.GetSelectedSensorVelocity(0) + increment)
  {
    rightOutput = rearRightMotor.GetSelectedSensorVelocity(0) + increment;
  }
  else if (r < rearRightMotor.GetSelectedSensorVelocity(0) - increment)
  {
    rightOutput = rearRightMotor.GetSelectedSensorVelocity(0) - increment;
  }
  else
  {
    rightOutput = r;
  }

  frontLeftMotor.Set(ControlMode::Follower, 1);
  rearLeftMotor.Set(ControlMode::Velocity, leftOutput);
  frontRightMotor.Set(ControlMode::Follower, 3);
  rearRightMotor.Set(ControlMode::Velocity, rightOutput);
}

void subsystem_Drive::Periodic() {}


