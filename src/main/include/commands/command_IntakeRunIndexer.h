/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/subsystem_Intake.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class command_IntakeRunIndexer
    : public frc2::CommandHelper<frc2::CommandBase, command_IntakeRunIndexer> {
 public:
  command_IntakeRunIndexer(subsystem_Intake* intake, std::function<double()> left, std::function<double()> right, std::function<double()> intakePower);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

private:
  subsystem_Intake* m_intake;
  std::function<double()> m_left;
  std::function<double()> m_right;
  std::function<double()> m_intakePower;
};
