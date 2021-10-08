/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/command_ClimbLock.h"

command_ClimbLock::command_ClimbLock(subsystem_Climb *subsystem_Climb) 
: m_subsystem_Climb{subsystem_Climb}
{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({m_subsystem_Climb});
}

// Called when the command is initially scheduled.
void command_ClimbLock::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void command_ClimbLock::Execute() {
  m_subsystem_Climb->LockClimb();
}

// Called once the command ends or is interrupted.
void command_ClimbLock::End(bool interrupted) {}

// Returns true when the command should end.
bool command_ClimbLock::IsFinished() { return true; }
