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
#include "commands/command_DriveByDistance.h"
#include "commands/cGroupAutonomous.h"
#include "commands/command_ShooterFeedAndShoot.h"
#include "subsystems/subsystem_Climb.h"
#include "subsystems/subsystem_Drive.h"
#include "subsystems/subsystem_Intake.h"
#include "subsystems/subsystem_Shooter.h"
#include "subsystems/subsystem_AimBot.h"
#include "frc/XboxController.h"
#include "frc2/command/button/JoystickButton.h"
#include "Constants.h"
// #include <frc/smartdashboard/SendableChooser.h>

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


//  placeHolder m_autonomousCommand;
  cGroupAutonomous m_autonomousCommand {&m_shooter, [=] {return 0.8;}, [=] {return 30000;}, &m_intake, [=] {return -0.3;}, [=] {return 0.3;}, 3, &m_drive, -30};
  //robot starts directly in front of goal
  // cGroupAutonomous m_autonomousCommandMiddle {&m_shooter, [=] {return 0.8;}, [=] {return 30000;}, &m_intake, [=] {return -0.3;}, [=] {return 0.3;}, 5, &m_drive, -30};
  //cGroupAutonomousDrive m_autonomousCommand {&m_drive, 50, &m_drive2, -11};
  //robot starts to the left of the goal
  // cGroupAutonomous m_autonomousCommandLeft {&m_shooter, [=] {return 0.8;}, [=] {return 15000;}, &m_intake, [=] {return -0.3;}, [=] {return 0.3;}, 5, &m_drive, -30};
  //robot starts to the right of the goal
  // cGroupAutonomous m_autonomousCommandRight {&m_shooter, [=] {return 0.8;}, [=] {return 15000;}, &m_intake, [=] {return -0.3;}, [=] {return 0.3;}, 5, &m_drive, -30};
  //can create numerous versions for various positions on the field (i.e. commands for topmost, middle, bottommost position to create more variety :) 
  frc::Joystick atk3{ControllerConstants::joystickPort};

  frc::XboxController xbox{ControllerConstants::xboxPort};

  void ConfigureButtonBindings();

  // frc::SendableChooser<frc2::Command*> m_chooser;
};
