/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"
#include "Constants.h"

RobotContainer::RobotContainer() : m_autonomousCommand(), m_mainController{0} {
  // Initialize all of your commands and subsystems here
  m_drive.SetDefaultCommand(command_DriveByJoystick(&m_drive, [this] {return m_mainController.GetRawAxis(ControllerConstants::xboxLYAxis);},
  [this] {return m_mainController.GetRawAxis(ControllerConstants::xboxRXAxis);}));

  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}
