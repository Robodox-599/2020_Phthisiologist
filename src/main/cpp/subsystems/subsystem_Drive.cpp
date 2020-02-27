/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/subsystem_Drive.h"

subsystem_Drive::subsystem_Drive() :
  m_frontLeftMotor{DriveConstants::frontLeftMotorPort, rev::CANSparkMax::MotorType::kBrushless},
  m_frontRightMotor{DriveConstants::frontRightMotorPort, rev::CANSparkMax::MotorType::kBrushless},
  m_rearLeftMotor{DriveConstants::rearLeftMotorPort, rev::CANSparkMax::MotorType::kBrushless},
  m_rearRightMotor{DriveConstants::rearRightMotorPort, rev::CANSparkMax::MotorType::kBrushless}
{
  m_frontLeftMotor.SetInverted(false);
  m_frontRightMotor.SetInverted(true);
  m_rearLeftMotor.SetInverted(false);
  m_rearRightMotor.SetInverted(true);
}

// void subsystem_Drive::JoystickVelocityDrive(double x, double y)
// {
//   double l;
//   double r;
//   double leftOutput;
//   double rightOutput;
//   double increment = 600;

//   if (y > 0.2)
//   {
//     y = (y - 0.2) * (1 / .8) * 3000 /**max velocity*/;
//   }
//   else if (y < -0.2)
//   {
//     y = (y + 0.2) * 1 / .8 * 3000 /**max velocity*/;
//   }
//   else
//   {
//     y = 0;
//   }

//   if (x > 0.2)
//   {
//     x = (x - 0.2) * 1 / .8 * 1500 /**max velocity/2*/;
//   }
//   else if (x < -0.2)
//   {
//     x = (x + 0.2) * 1 / .8 * 1500 /**max velocity/2*/;
//   }
//   else
//   {
//     x = 0;
//   }

//   l = -y + x;
//   r = -y - x;

//   if (l > m_rearLeftMotor.GetSelectedSensorVelocity(0) + increment)
//   {
//     leftOutput = m_rearLeftMotor.GetSelectedSensorVelocity(0) + increment;
//   }
//   else if (l < m_rearLeftMotor.GetSelectedSensorVelocity(0) - increment)
//   {
//     leftOutput = m_rearLeftMotor.GetSelectedSensorVelocity(0) - increment;
//   }
//   else
//   {
//     leftOutput = l;
//   }

//   if (r > m_rearRightMotor.GetSelectedSensorVelocity(0) + increment)
//   {
//     rightOutput = m_rearRightMotor.GetSelectedSensorVelocity(0) + increment;
//   }
//   else if (r < m_rearRightMotor.GetSelectedSensorVelocity(0) - increment)
//   {
//     rightOutput = m_rearRightMotor.GetSelectedSensorVelocity(0) - increment;
//   }
//   else
//   {
//     rightOutput = r;
//   }

//   m_frontLeftMotor.Set(ControlMode::Follower, 1);
//   m_rearLeftMotor.Set(ControlMode::Velocity, leftOutput);
//   m_frontRightMotor.Set(ControlMode::Follower, 3);
//   m_rearRightMotor.Set(ControlMode::Velocity, rightOutput);
// }

void subsystem_Drive::JoystickPowerDrive(double x, double y)
{
  double l;
  double r;
  if (y > 0.2)
  {
    y = (y - 0.2  ) * 1 / .8;
  }
  else if (y < -0.2)
  {
    y = (y + 0.2) * 1 / .8;
  }
  else
  {
    y = 0;
  }
  if (x > 0.2)
  {
    x = (x - 0.2) * 1 / .8;
  }
  else if (x < -0.2)
  {
    x = (x + 0.2) * 1 / .8;
  }
  else
  {
    x = 0;
  }

  l = -y - x;
  r = -y + x;

  m_frontLeftMotor.Set(r);
  m_rearLeftMotor.Set(r);
  m_frontRightMotor.Set(l);
  m_rearRightMotor.Set(l);
}

// This method will be called once per scheduler run
void subsystem_Drive::Periodic() {}


