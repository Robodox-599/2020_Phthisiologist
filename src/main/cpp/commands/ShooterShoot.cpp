/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ShooterShoot.h"

ShooterShoot::ShooterShoot(subsystem_Shooter* shooter, std::function<double()> velocity): m_shooterSubsystem{shooter}, m_velocity{velocity} {
  AddRequirements({shooter});
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void ShooterShoot::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ShooterShoot::Execute() {
  m_shooterSubsystem->FlywheelSpin(m_velocity());
}

// Called once the command ends or is interrupted.
void ShooterShoot::End(bool interrupted) {}

// Returns true when the command should end.
bool ShooterShoot::IsFinished() { return false; }
