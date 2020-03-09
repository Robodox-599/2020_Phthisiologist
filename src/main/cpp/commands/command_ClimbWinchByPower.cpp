  /*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/command_ClimbWinchByPower.h"

command_ClimbWinchByPower::command_ClimbWinchByPower(subsystem_Climb *subsystem_Climb, double power)
: m_subsystem_Climb{subsystem_Climb}, m_power{power} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(m_subsystem_Climb);
}

// Called when the command is initially scheduled.
void command_ClimbWinchByPower::Initialize() {
  m_subsystem_Climb->SetWinchMotorPower(m_power);
}

// Called repeatedly when this Command is scheduled to run
void command_ClimbWinchByPower::Execute() {}

// Called once the command ends or is interrupted.
void command_ClimbWinchByPower::End(bool interrupted) {}

// Returns true when the command should end.
bool command_ClimbWinchByPower::IsFinished() { return true; }
