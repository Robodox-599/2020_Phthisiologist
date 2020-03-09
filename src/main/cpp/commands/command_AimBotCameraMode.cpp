/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/command_AimBotCameraMode.h"

command_AimBotCameraMode::command_AimBotCameraMode(subsystem_AimBot* aimBot) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({aimBot});
}

// Called when the command is initially scheduled.
void command_AimBotCameraMode::Initialize() {m_subsystem.ConvertMode();}

// Called repeatedly when this Command is scheduled to run
void command_AimBotCameraMode::Execute() {}

// Called once the command ends or is interrupted.
void command_AimBotCameraMode::End(bool interrupted) {}

// Returns true when the command should end.
bool command_AimBotCameraMode::IsFinished() { return true; }
