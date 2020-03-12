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
#include "Constants.h"
#include "frc/smartdashboard/SmartDashboard.h"

class subsystem_Climb : public frc2::SubsystemBase {
 public:
  subsystem_Climb();

  void SetWinchMotorPower(double power);
  void LockClimb();
  void UnlockClimb();
  bool IsClimbLocked();
  void SetSlideMotorPower(double power);
  void SetClimbArmMotorPower(double power);
  void ClimbArmMovementByTicks(double ticks);
  void ClimbArmMovementByDegrees(double degrees);
  double ReturnClimbArmTicks();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  TalonSRX m_leftWinchMotor;
  TalonSRX m_rightWinchMotor;
  TalonSRX m_slideMotor;
  TalonSRX m_climbArmMotor;
  frc::DoubleSolenoid m_lockSolenoid;
  bool m_isClimbLocked;
  int m_climbArmEncoderRange;
  int m_climbArmLimitOffset;
  int m_climbArmLimitMax;
  int m_climbArmLimitMin;
  
};
