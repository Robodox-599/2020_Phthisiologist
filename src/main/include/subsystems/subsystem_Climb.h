/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "ctre/Phoenix.h"
#include "frc/DoubleSolenoid.h"

class subsystem_Climb : public frc2::SubsystemBase {
 public:
  subsystem_Climb();

  void DriveClimbArm(double power, bool up);
  void OperateLock(bool extend);

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

 private:
  TalonSRX m_LeftClimbMotor;
  TalonSRX m_RightClimbMotor;
  TalonSRX m_SlideMotor;
  TalonSRX m_ClimbArmMotor;
  frc::DoubleSolenoid m_LeftLockSolenoid;
  frc::DoubleSolenoid m_RightLockSolenoid;
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
