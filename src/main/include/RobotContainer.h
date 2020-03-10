/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/Command.h>
#include <frc/Joystick.h>

#include "commands/placeHolder.h"
#include "commands/command_DriveByJoystick.h"
#include "subsystems/subsystem_Climb.h"
#include "subsystems/subsystem_Drive.h"
#include "subsystems/subsystem_Intake.h"
#include "subsystems/subsystem_Shooter.h"
#include "subsystems/subsystem_AimBot.h"
#include "frc/XboxController.h"
#include "frc2/command/button/JoystickButton.h"
#include "Constants.h"


/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();

 private:
  // The robot's subsystems and commands are defined here...
  subsystem_Climb m_climb;
  subsystem_Drive m_drive;
  subsystem_Intake m_intake;
  subsystem_Shooter m_shooter;
  subsystem_AimBot m_aimBot;
  placeHolder m_autonomousCommand;
  frc::Joystick atk3{1};

  frc::XboxController xbox{ControllerConstants::xboxPort};

  void ConfigureButtonBindings();
};
