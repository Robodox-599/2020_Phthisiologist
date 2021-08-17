/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/command_ShooterShoot.h"

command_ShooterShoot::command_ShooterShoot(subsystem_Shooter* shooter, std::function<double()> velocity): m_shooterSubsystem{shooter}, m_velocity{velocity} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({m_shooterSubsystem});
}

// Called when the command is initially scheduled.
void command_ShooterShoot::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void command_ShooterShoot::Execute() {m_shooterSubsystem->FlywheelSpin(m_velocity());}

// Called once the command ends or is interrupted.
void command_ShooterShoot::End(bool interrupted) {}

// Returns true when the command should end.
bool command_ShooterShoot::IsFinished() { return false; }