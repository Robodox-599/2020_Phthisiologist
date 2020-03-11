/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/command_ShooterHoodAdjustmentDegrees.h"

command_ShooterHoodAdjustmentDegrees::command_ShooterHoodAdjustmentDegrees(subsystem_Shooter* shooter, std::function<double()> degrees) : m_shooterSubsystem{shooter}, m_degrees{degrees} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({shooter});
}

// Called when the command is initially scheduled.
void command_ShooterHoodAdjustmentDegrees::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void command_ShooterHoodAdjustmentDegrees::Execute() {m_shooterSubsystem->HoodMovementByDegrees(m_degrees());}

// Called once the command ends or is interrupted.
void command_ShooterHoodAdjustmentDegrees::End(bool interrupted) {}

// Returns true when the command should end.
bool command_ShooterHoodAdjustmentDegrees::IsFinished() { return false; }
