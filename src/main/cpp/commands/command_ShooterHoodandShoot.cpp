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
  m_shooterSubsystem->HoodMovement(m_degrees()*37);
  m_shooterSubsystem->FlywheelSpin(30000);
  if(m_shooterSubsystem->ReturnHoodTicks() < m_shooterSubsystem->HoodTarget(m_degrees()*37) + 2 && m_shooterSubsystem->ReturnHoodTicks() > m_shooterSubsystem->HoodTarget(m_degrees()*37) - 2)
  {
    if(m_shooterSubsystem->ReturnFlywheelVelocity > 28000)
    {
      m_shooterSubsystem->Feed();
    }
  }
}

// Called once the command ends or is interrupted.
void command_ShooterHoodandShoot::End(bool interrupted) {}

// Returns true when the command should end.
bool command_ShooterHoodandShoot::IsFinished() { return false; }
