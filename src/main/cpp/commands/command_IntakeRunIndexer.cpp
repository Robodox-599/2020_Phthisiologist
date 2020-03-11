/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/command_IntakeRunIndexer.h"

command_IntakeRunIndexer::command_IntakeRunIndexer(subsystem_Intake* intake, std::function<double()> left, std::function<double()> right, std::function<double()> intakePower) : m_intake{intake}, m_left{left}, m_right{right}, m_intakePower{intakePower} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({intake});
}

// Called when the command is initially scheduled.
void command_IntakeRunIndexer::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void command_IntakeRunIndexer::Execute() 
{
  m_intake->SetIndexerOn(m_left(), m_right());
  m_intake->SetIntakeWheelsOn(m_intakePower());
}

// Called once the command ends or is interrupted.
void command_IntakeRunIndexer::End(bool interrupted) {}

// Returns true when the command should end.
bool command_IntakeRunIndexer::IsFinished() { return false; }
