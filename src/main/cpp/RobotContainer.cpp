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
#include "commands/command_AimBotAutoAim.h"
#include "commands/command_AimBotCameraMode.h"
#include "commands/command_AimBotDefault.h"
#include "commands/command_ShooterHoodandShoot.h"

RobotContainer::RobotContainer() : m_autonomousCommand() {
  // Initialize all of your commands and subsystems here
  m_drive.SetDefaultCommand(command_DriveByJoystick(&m_drive, [this] {return xbox.GetRawAxis(ControllerConstants::xboxLYAxis);},
  [this] {return xbox.GetRawAxis(ControllerConstants::xboxRXAxis);}));
  
 // m_aimBot.SetDefaultCommand(AimBotDefault(&m_aimBot));
  // m_drive.SetDefaultCommand(DriveDefault(&m_drive, [this] {return xbox.GetRawAxis(1);}, [this] {return xbox.GetRawAxis(4);}));
  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
  frc2::JoystickButton xboxA(&xbox, ControllerConstants::xboxA);
  frc2::JoystickButton xboxB(&xbox, ControllerConstants::xboxB);
  

  xboxA.WhenPressed(command_ShooterShoot(&m_shooter, [=] {return 30000;}));
  xboxB.WhenPressed(command_ShooterShoot(&m_shooter, [=] {return 0;}));

  //xboxA.WhenPressed(AimBotCameraMode(&m_aimBot));
  //xboxB.WhenPressed(AimBotAutoAim(&m_aimBot, &m_drive));
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}
