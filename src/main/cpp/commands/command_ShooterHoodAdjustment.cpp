/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/command_ShooterHoodAdjustment.h"

command_ShooterHoodAdjustment::command_ShooterHoodAdjustment(subsystem_Shooter* shooter, std::function<double()> degrees) : m_shooterSubsystem{shooter}, m_degrees{degrees} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({shooter});
}

// Called when the command is initially scheduled.
void command_ShooterHoodAdjustment::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void command_ShooterHoodAdjustment::Execute() {m_shooterSubsystem->HoodMovement(m_degrees());}

// Called once the command ends or is interrupted.
void command_ShooterHoodAdjustment::End(bool interrupted) {}

// Returns true when the command should end.
bool command_ShooterHoodAdjustment::IsFinished() { return false; }
