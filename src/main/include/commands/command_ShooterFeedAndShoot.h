/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/subsystem_Shooter.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class command_ShooterFeedAndShoot
    : public frc2::CommandHelper<frc2::CommandBase, command_ShooterFeedAndShoot> {
 public:
  command_ShooterFeedAndShoot(subsystem_Shooter* shooter, std::function<double()> feederPower, std::function<double()> flywheelVelocity);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

private:  
  subsystem_Shooter* m_shooter;
  std::function<double()> m_feederPower;
  std::function<double()> m_flywheelVelocity;
};
