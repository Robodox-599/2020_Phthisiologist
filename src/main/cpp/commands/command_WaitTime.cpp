// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/command_WaitTime.h"

command_WaitTime::command_WaitTime(double time) : m_time{time} {
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void command_WaitTime::Initialize() {m_timer.Reset(); m_timer.Start();}

// Called repeatedly when this Command is scheduled to run
void command_WaitTime::Execute() {}

// Called once the command ends or is interrupted.
void command_WaitTime::End(bool interrupted) {}

// Returns true when the command should end.
bool command_WaitTime::IsFinished() {
  return m_timer.Get() >= m_time;
}
