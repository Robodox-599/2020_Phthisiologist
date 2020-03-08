/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/subsystem_AimBot.h"
#include "subsystems/subsystem_Drive.h"
#include "frc/Timer.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class AimBotAutoAim
    : public frc2::CommandHelper<frc2::CommandBase, AimBotAutoAim> {
 public:
  AimBotAutoAim(subsystem_AimBot* aimBot, subsystem_Drive* drive);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
private:
  frc::Timer timer;
  subsystem_AimBot* m_aimBot;
  subsystem_Drive* m_drive;
  double m_yaw;
  double m_power;
  double m_kF;
  double m_kP;
  double m_kI;
  double i;
  double prevPosition;
  double nextPosition;
  bool linedUp;
};
