/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"
#include "Constants.h"
#include "commands/command_DriveByJoystick.h"
#include "commands/command_ShooterShoot.h"
#include "commands/command_ShooterHoodAdjustmentTicks.h"
#include "commands/command_AimBotAutoAim.h"
#include "commands/command_AimBotCameraMode.h"
#include "frc/smartdashboard/SmartDashboard.h"
#include "commands/command_AimBotDefault.h"
#include "commands/command_IntakeRunIndexer.h"
#include "commands/command_ShooterFeedAndShoot.h"

RobotContainer::RobotContainer() : m_autonomousCommand() {
  // Initialize all of your commands and subsystems here
  m_drive.SetDefaultCommand(command_DriveByJoystick(&m_drive, [this] {return xbox.GetRawAxis(ControllerConstants::xboxLYAxis);},
  [this] {return xbox.GetRawAxis(ControllerConstants::xboxRXAxis);}));
  
  m_aimBot.SetDefaultCommand(command_AimBotDefault(&m_aimBot));
  m_shooter.SetDefaultCommand(command_ShooterFeedAndShoot(&m_shooter, [=] {return 0;}, [=] {return 0;}));
  // m_shooter.SetDefaultCommand(command_ShooterHoodAdjustmentTicks(&m_shooter, [=] {return 120*atk3.GetRawAxis(2)+322;}));
  m_intake.SetDefaultCommand(command_IntakeRunIndexer(&m_intake, [=] {return 0;}, [=] {return 0;}, [=] {return 0;}));
  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
  frc2::JoystickButton xboxA(&xbox, ControllerConstants::xboxA);
  frc2::JoystickButton xboxB(&xbox, ControllerConstants::xboxB);
  frc2::JoystickButton xboxX(&xbox, ControllerConstants::xboxX);
  frc2::JoystickButton xboxY(&xbox, ControllerConstants::xboxY);
  frc2::JoystickButton xboxRB(&xbox, ControllerConstants::xboxRB);
  frc2::JoystickButton xboxLB(&xbox, ControllerConstants::xboxLB);
  
  xboxA.WhenPressed(command_ShooterFeedAndShoot(&m_shooter, [=] {return 0.8;}, [=] {return 30000;}));
  xboxLB.WhenPressed(command_ShooterFeedAndShoot(&m_shooter, [=] {return 0;}, [=] {return 0;}));
  xboxB.WhenPressed(command_IntakeRunIndexer(&m_intake, [=] {return 0.3;}, [=] {return 0.3;}, [=] {return 0;}));
  xboxX.WhenPressed(command_IntakeRunIndexer(&m_intake, [=] {return -0.3;}, [=] {return 0.3;}, [=] {return 0;}));
  xboxY.WhenPressed(command_IntakeRunIndexer(&m_intake, [=] {return 0;}, [=] {return 0;}, [=] {return 0;}));
  xboxRB.WhenPressed(command_IntakeRunIndexer(&m_intake, [=] {return 0;}, [=] {return 0;}, [=] {return 0.6;}));


  //xboxA.WhenPressed(AimBotCameraMode(&m_aimBot));
  //xboxB.WhenPressed(AimBotAutoAim(&m_aimBot, &m_drive));
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}
