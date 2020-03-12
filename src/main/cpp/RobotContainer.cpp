/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"

RobotContainer::RobotContainer() : m_autonomousCommand(), m_mainController{0} {
  // Initialize all of your commands and subsystems here
  // m_drive.SetDefaultCommand(command_DriveByJoystick(&m_drive, [this] {return m_mainController.GetRawAxis(4);},
  // [this] {return m_mainController.GetRawAxis(1);}));

  // m_climb.SetDefaultCommand(command_ClimbArmByPower(&m_climb, [this] {return m_mainController.GetRawAxis(4);}));

  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
  frc2::JoystickButton xboxA(&m_mainController, ControllerConstants::xboxA);
  xboxA.WhenPressed(command_ClimbLock(&m_climb));

  frc2::JoystickButton xboxB(&m_mainController, ControllerConstants::xboxB);
  xboxA.WhenPressed(command_ClimbUnlock(&m_climb));

  frc2::JoystickButton xboxX(&m_mainController, ControllerConstants::xboxX);
  xboxX.WhenPressed(command_ClimbArmByPosition(&m_climb, (ClimbConstants::climbArmEncoderMax-ClimbConstants::climbArmEncoderMin)/2));
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}
