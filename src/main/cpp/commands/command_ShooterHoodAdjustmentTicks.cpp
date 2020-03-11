/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/command_ShooterHoodAdjustmentTicks.h"

command_ShooterHoodAdjustmentTicks::command_ShooterHoodAdjustmentTicks(subsystem_Shooter* shooter, std::function<double()> ticks) : m_shooterSubsystem{shooter}, m_ticks{ticks} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({shooter});
}

// Called when the command is initially scheduled.
void command_ShooterHoodAdjustmentTicks::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void command_ShooterHoodAdjustmentTicks::Execute() {m_shooterSubsystem->HoodMovementByTicks(m_ticks());}

// Called once the command ends or is interrupted.
void command_ShooterHoodAdjustmentTicks::End(bool interrupted) {}

// Returns true when the command should end.
bool command_ShooterHoodAdjustmentTicks::IsFinished() { return false; }
