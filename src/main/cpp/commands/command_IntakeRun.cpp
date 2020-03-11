/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/command_IntakeRun.h"

command_IntakeRun::command_IntakeRun(subsystem_Intake* intake, std::function<double()> power) : m_intake{intake}, m_power{power} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({intake});
}

// Called when the command is initially scheduled.
void command_IntakeRun::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void command_IntakeRun::Execute() 
{
  m_intake->SetIntakeWheelsOn(m_power());
}

// Called once the command ends or is interrupted.
void command_IntakeRun::End(bool interrupted) {}

// Returns true when the command should end.
bool command_IntakeRun::IsFinished() { return false; }
