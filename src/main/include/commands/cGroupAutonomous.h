// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "subsystems/subsystem_Shooter.h"
#include "subsystems/subsystem_Intake.h"
#include "subsystems/subsystem_Drive.h"

class cGroupAutonomous
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 cGroupAutonomous> {
 public:
  cGroupAutonomous(subsystem_Shooter* shooter, std::function<double()> feederPower, std::function<double()> flywheelVelocity, subsystem_Intake* intake, std::function<double()> left, std::function<double()> right, double time, subsystem_Drive *theDrive, int inches);
};
