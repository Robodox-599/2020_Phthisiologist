// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/cGroupAutonomous.h"

#include "commands/command_ShooterFeedAndShoot.h"
#include "commands/command_IntakeRunIndexer.h"
#include "commands/command_WaitTime.h"
#include "commands/command_DriveByDistance.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
cGroupAutonomous::cGroupAutonomous(subsystem_Shooter* shooter, std::function<double()> feederPower, std::function<double()> flywheelVelocity, subsystem_Intake* intake, std::function<double()> left, std::function<double()> right, double time, subsystem_Drive *theDrive, int inches) {
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  AddCommands(command_ShooterFeedAndShoot(shooter, feederPower, flywheelVelocity), command_IntakeRunIndexer(intake, left, right), command_WaitTime(time), command_ShooterFeedAndShoot(shooter, [=] {return 0;}, [=] {return 0;}), command_IntakeRunIndexer(intake, [=] {return 0;}, [=] {return 0;}), command_DriveByDistance(theDrive, inches));
}
