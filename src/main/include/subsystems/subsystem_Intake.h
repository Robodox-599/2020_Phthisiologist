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

class subsystem_Intake : public frc2::SubsystemBase {
 public:
  subsystem_Intake();

  void SetIntakeUp();
  void SetIntakeDown();
  bool IsIntakeDeployed();
  void SetIntakeWheelsOn(double power);
  void SetIntakeWheelsOff();
  void SetIndexerOn(double leftPower, double rightPower);
  void SetIndexerOff();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

 private:
  TalonSRX m_intakeMotor;
  TalonSRX m_leftIndexerMotor;
  TalonSRX m_rightIndexerMotor;
  frc::DoubleSolenoid m_intakePiston;
  bool m_isIntakeDeployed;
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
