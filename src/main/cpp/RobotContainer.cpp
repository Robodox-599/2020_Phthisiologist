/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"
#include "commands/AimBotDefault.h"
#include "commands/AimBotCameraMode.h"
#include "commands/AimBotAutoAim.h"

RobotContainer::RobotContainer() : m_autonomousCommand() {
  // Initialize all of your commands and subsystems here
  m_aimBot.SetDefaultCommand(AimBotDefault(&m_aimBot));
  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
  frc2::JoystickButton xboxA{&xbox, ControllerConstants::xboxA};
  frc2::JoystickButton xboxB{&xbox, ControllerConstants::xboxB};

  xboxA.WhenPressed(AimBotCameraMode(&m_aimBot));
  xboxB.WhenPressed(AimBotAutoAim(&m_aimBot, &m_drive));
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}
