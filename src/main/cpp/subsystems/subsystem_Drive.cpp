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

  m_rearLeftMotor.Follow(m_frontLeftMotor);
  m_rearRightMotor.Follow(m_frontRightMotor);
}

void subsystem_Drive::SetPositionControl()
{
  double kP = 0.1, kI = 0, kD = 0, kIz = 0, kFF = 0, kMaxOutput = 1, kMinOutput = -1;

  m_leftPidController.SetP(kP);
  m_leftPidController.SetI(kI);
  m_leftPidController.SetD(kD);
  m_leftPidController.SetIZone(kIz);
  m_leftPidController.SetFF(kFF);
  m_leftPidController.SetOutputRange(kMinOutput, kMaxOutput);

  m_rightPidController.SetD(kD);
  m_rightPidController.SetI(kI);
  m_rightPidController.SetP(kP);
  m_rightPidController.SetIZone(kIz);
  m_rightPidController.SetFF(kFF);
  m_rightPidController.SetOutputRange(kMinOutput, kMaxOutput);
}

void subsystem_Drive::DriveDistance(int inches)
{
  SetPositionControl();
  m_leftPidController.SetReference(ConvertInchesToRotations(inches), rev::ControlType::kPosition);
  m_rightPidController.SetReference(ConvertInchesToRotations(inches), rev::ControlType::kPosition);
}

double subsystem_Drive::GetPIDError(int inches)
{
  return m_leftEncoder.GetPosition() - ConvertInchesToRotations(inches);
}

int subsystem_Drive::ConvertInchesToRotations(int inches)
{
  double wheelDiameter = 6;
  double gearRatio = 10.45;

  return ((inches)/(wheelDiameter*3.14))*gearRatio;
}

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


  void subsystem_Drive::VelocityDrive(double x, double y)
{
  // double l;
  // double r;
  // double leftOutput;
  // double rightOutput;
  // double increment = 600;

  // if (y > 0.2)
  // {
  //   y = (y - 0.2) * (1 / .8) * 3000 /**max velocity*/;
  // }
  // else if (y < -0.2)
  // {
  //   y = (y + 0.2) * 1 / .8 * 3000 /**max velocity*/;
  // }
  // else
  // {
  //   y = 0;
  // }

  // if (x > 0.2)
  // {
  //   x = (x - 0.2) * 1 / .8 * 1500 /**max velocity/2*/;
  // }
  // else if (x < -0.2)
  // {
  //   x = (x + 0.2) * 1 / .8 * 1500 /**max velocity/2*/;
  // }
  // else
  // {
  //   x = 0;
  // }

  // l = -y + x;
  // r = -y - x;

  // if (l > m_rearLeftMotor.GetSelectedSensorVelocity(0) + increment)
  // {
  //   leftOutput = m_rearLeftMotor.GetSelectedSensorVelocity(0) + increment;
  // }
  // else if (l < m_rearLeftMotor.GetSelectedSensorVelocity(0) - increment)
  // {
  //   leftOutput = m_rearLeftMotor.GetSelectedSensorVelocity(0) - increment;
  // }
  // else
  // {
  //   leftOutput = l;
  // }

  // if (r > m_rearRightMotor.GetSelectedSensorVelocity(0) + increment)
  // {
  //   rightOutput = m_rearRightMotor.GetSelectedSensorVelocity(0) + increment;
  // }
  // else if (r < m_rearRightMotor.GetSelectedSensorVelocity(0) - increment)
  // {
  //   rightOutput = m-rearRightMotor.GetSelectedSensorVelocity(0) - increment;
  // }
  // else
  // {
  //   rightOutput = r;
  // }

  // m_frontLeftMotor.Set(ControlMode::Follower, 1);
  // m_rearLeftMotor.Set(ControlMode::Velocity, leftOutput);
  // m_frontRightMotor.Set(ControlMode::Follower, 3);
  // m_rearRightMotor.Set(ControlMode::Velocity, rightOutput);
}

// This method will be called once per scheduler run
void subsystem_Drive::Periodic() {}


