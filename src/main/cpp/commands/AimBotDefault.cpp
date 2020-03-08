/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AimBotDefault.h"

AimBotDefault::AimBotDefault(subsystem_AimBot* aimbBot) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({aimbBot});
}

// Called when the command is initially scheduled.
void AimBotDefault::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void AimBotDefault::Execute() {m_subsystem.AimBotYaw();}

// Called once the command ends or is interrupted.
void AimBotDefault::End(bool interrupted) {}

// Returns true when the command should end.
bool AimBotDefault::IsFinished() { return false; }
