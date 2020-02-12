/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AimBotCameraMode.h"

AimBotCameraMode::AimBotCameraMode(subsystem_AimBot* aimBot) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({aimBot});
}

// Called when the command is initially scheduled.
void AimBotCameraMode::Initialize() {m_subsystem.ConvertMode();}

// Called repeatedly when this Command is scheduled to run
void AimBotCameraMode::Execute() {}

// Called once the command ends or is interrupted.
void AimBotCameraMode::End(bool interrupted) {}

// Returns true when the command should end.
bool AimBotCameraMode::IsFinished() { return true; }
