// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/command_ClimbSlide.h"

command_ClimbSlide::command_ClimbSlide(subsystem_Climb* climb, std::function<double()> power):m_climb{climb}, m_power{power} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({climb});
}

// Called when the command is initially scheduled.
void command_ClimbSlide::Initialize() {m_climb->SetSlideMotorPower(m_power());}

// Called repeatedly when this Command is scheduled to run
void command_ClimbSlide::Execute() {}

// Called once the command ends or is interrupted.
void command_ClimbSlide::End(bool interrupted) {}

// Returns true when the command should end.
bool command_ClimbSlide::IsFinished() {
  return true;
}
