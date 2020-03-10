/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/command_ShooterHoodandShoot.h"

command_ShooterHoodandShoot::command_ShooterHoodandShoot(subsystem_Shooter* shooter, std::function <double()> degrees) : m_shooterSubsystem{shooter}, m_degrees{degrees} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({shooter});
}

// Called when the command is initially scheduled.
void command_ShooterHoodandShoot::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void command_ShooterHoodandShoot::Execute() 
{
 
}

// Called once the command ends or is interrupted.
void command_ShooterHoodandShoot::End(bool interrupted) {}

// Returns true when the command should end.
bool command_ShooterHoodandShoot::IsFinished() { return false; }
