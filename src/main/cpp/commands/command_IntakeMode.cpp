/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/command_IntakeMode.h"

command_IntakeMode::command_IntakeMode(subsystem_Intake* intake, subsystem_Shooter* shooter) : m_intake{intake} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({intake, shooter});
}

// Called when the command is initially scheduled.
void command_IntakeMode::Initialize() 
{
  if(m_intake->IsIntakeDeployed())
  {
    m_intake->SetIntakeUp();
  }
  else
  {
    m_intake->SetIntakeDown();
  }
  
}

// Called repeatedly when this Command is scheduled to run
void command_IntakeMode::Execute() {}

// Called once the command ends or is interrupted.
void command_IntakeMode::End(bool interrupted) {}

// Returns true when the command should end.
bool command_IntakeMode::IsFinished() { return true; }
