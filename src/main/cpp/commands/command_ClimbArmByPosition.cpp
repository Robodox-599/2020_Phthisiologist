/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/command_ClimbArmByPosition.h"

command_ClimbArmByPosition::command_ClimbArmByPosition(subsystem_Climb *subsystem_Climb, double ticks)
: m_subsystem_Climb{subsystem_Climb}, m_ticks{ticks}
{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({m_subsystem_Climb});
}

// Called when the command is initially scheduled.
void command_ClimbArmByPosition::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void command_ClimbArmByPosition::Execute() {
  m_subsystem_Climb->ClimbArmMovementByTicks(m_ticks);
}

// Called once the command ends or is interrupted.
void command_ClimbArmByPosition::End(bool interrupted) {}

// Returns true when the command should end.
bool command_ClimbArmByPosition::IsFinished() { return true; }
