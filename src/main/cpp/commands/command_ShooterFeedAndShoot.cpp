/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/command_ShooterFeedAndShoot.h"

command_ShooterFeedAndShoot::command_ShooterFeedAndShoot(subsystem_Shooter* shooter, std::function<double()> feederPower, std::function<double()> flywheelVelocity) : m_shooter{shooter}, m_feederPower{feederPower}, m_flywheelVelocity{flywheelVelocity} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({shooter});
}

// Called when the command is initially scheduled.
void command_ShooterFeedAndShoot::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void command_ShooterFeedAndShoot::Execute() 
{
  m_shooter->FlywheelSpin(m_flywheelVelocity());
  // m_shooter->HoodMovementByTicks(280);
  if(m_shooter->ReturnFlywheelVelocity() > 0.95*m_flywheelVelocity())
  {
    m_shooter->Feed(m_feederPower());
  }
  else
  {
    m_shooter->Feed(0);
  }
}

// Called once the command ends or is interrupted.
void command_ShooterFeedAndShoot::End(bool interrupted) 
{
  m_shooter->FlywheelSpin(0);
}

// Returns true when the command should end.
bool command_ShooterFeedAndShoot::IsFinished() { return false; }
