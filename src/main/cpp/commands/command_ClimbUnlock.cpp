/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/command_ClimbUnlock.h"

command_ClimbUnlock::command_ClimbUnlock(subsystem_Climb *subsystem_Climb)
: m_subsystem_Climb{subsystem_Climb} 
{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({m_subsystem_Climb});
}

// Called when the command is initially scheduled.
void command_ClimbUnlock::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void command_ClimbUnlock::Execute() {
  m_subsystem_Climb->UnlockClimb();
}

// Called once the command ends or is interrupted.
void command_ClimbUnlock::End(bool interrupted) {}

// Returns true when the command should end.
bool command_ClimbUnlock::IsFinished() { return true; }
