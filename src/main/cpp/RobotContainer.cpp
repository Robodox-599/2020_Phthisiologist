/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"
#include "frc/smartdashboard/SmartDashboard.h"
#include "Constants.h"
#include "commands/command_DriveByJoystick.h"
#include "commands/command_ShooterShoot.h"
#include "commands/command_ShooterHoodAdjustmentTicks.h"
#include "commands/command_AimBotAutoAim.h"
#include "commands/command_AimBotCameraMode.h"
#include "commands/command_AimBotDefault.h"
#include "commands/command_IntakeRunIndexer.h"
#include "commands/command_ShooterFeedAndShoot.h"
#include "commands/command_IntakeRun.h"
#include "commands/command_IntakeMode.h"
#include "commands/command_ClimbArmByPosition.h"
#include "commands/command_ClimbArmByPower.h"
#include "commands/command_ClimbArmByPower.h"
#include "commands/command_ClimbLock.h"
#include "commands/command_ClimbUnlock.h"
#include "commands/command_ClimbWinchByPower.h"
#include "subsystems/subsystem_Climb.h"
// #include "stdio.h"
// #include "iostream"
// using namespace std;

RobotContainer::RobotContainer(){
  // m_chooser.SetDefaultOption("Middle Auto", &m_autonomousCommandMiddle);
  // m_chooser.AddOption("Left Auto", &m_autonomousCommandLeft);
  // m_chooser.AddOption("Right Auto", &m_autonomousCommandRight);
  // // Put the chooser on the dashboard
  // frc::SmartDashboard::PutData(&m_chooser);
  // Initialize all of your commands and subsystems here
  m_drive.SetDefaultCommand(command_DriveByJoystick(&m_drive, [this] {return xbox.GetRawAxis(ControllerConstants::xboxLYAxis);},
  [this] {return xbox.GetRawAxis(ControllerConstants::xboxRXAxis);}));
  m_aimBot.SetDefaultCommand(command_AimBotDefault(&m_aimBot));
  m_shooter.SetDefaultCommand(command_ShooterFeedAndShoot(&m_shooter, [=] {return 0;}, [=] {return 0;}));
  m_shooter.SetDefaultCommand(command_ShooterHoodAdjustmentTicks(&m_shooter, [=] {return 120*atk3.GetRawAxis(2)+322;}));
  m_intake.SetDefaultCommand(command_IntakeRun(&m_intake, [this] {return xbox.GetRawAxis(ControllerConstants::xboxLTAxis)*0.8;},
  [this] {return xbox.GetRawAxis(ControllerConstants::xboxRTAxis)*0.8;}));
//  m_climb.SetDefaultCommand(command_ClimbLock(&m_climb));
//  m_climb.SetDefaultCommand(command_ClimbArmByPower(&m_climb,[=] {return 0.0;}));

  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
  frc2::JoystickButton xboxA(&xbox, ControllerConstants::xboxA);
  frc2::JoystickButton xboxB(&xbox, ControllerConstants::xboxB);
  frc2::JoystickButton xboxX  (&xbox, ControllerConstants::xboxX);
  frc2::JoystickButton xboxY(&xbox, ControllerConstants::xboxY);
  frc2::JoystickButton xboxRB(&xbox, ControllerConstants::xboxRB);
  frc2::JoystickButton xboxLB(&xbox, ControllerConstants::xboxLB);
  frc2::JoystickButton atk3ArmUp(&atk3, ControllerConstants::atk3ArmUp);
  frc2::JoystickButton atk3ArmDown(&atk3, ControllerConstants::atk3ArmDown);
  frc2::JoystickButton atk3WinchUnlock(&atk3, ControllerConstants::atk3WinchUnlock);
  frc2::JoystickButton atk3WinchUp(&atk3, ControllerConstants::atk3WinchUp);
  frc2::JoystickButton atk3WinchDown(&atk3, ControllerConstants::atk3WinchDown);

//  frc2::JoystickButton xboxMenu(&xbox, ControllerConstants::xboxMenu); 

  
 xboxA.WhenPressed(command_ShooterFeedAndShoot(&m_shooter, [=] {return 0.8;}, [=] {return 30000;})); //revs up shooter and runs feeder
  // xboxA.WhenPressed(command_IntakeRunIndexer(&m_intake, [=] {return 0.3;}, [=] {return 0.3;}));
  xboxLB.WhenPressed(command_ShooterFeedAndShoot(&m_shooter, [=] {return 0;}, [=] {return 0;})); 
  xboxRB.WhenPressed(command_IntakeMode(&m_intake, &m_shooter));
  xboxX.WhenPressed(command_ShooterFeedAndShoot(&m_shooter, [=] {return 0;}, [=] {return 0;}));
  xboxX.WhenPressed(command_IntakeRunIndexer(&m_intake, [=] {return 0;}, [=] {return 0;}));
  xboxB.WhenPressed(command_IntakeRunIndexer(&m_intake, [=] {return -0.3;}, [=] {return 0.3;}));
  atk3ArmUp.WhenPressed(command_ClimbArmByPower(&m_climb, [=] {return 0.4;}));
  atk3ArmUp.WhenReleased(command_ClimbArmByPower(&m_climb, [=] {return 0.1;}));
  
  // danel additions:
  // atk3ArmDown.WhenPressed(command_ClimbArmByPower(&m_climb, [=] {return 0;}));
  // atk3WinchUnlock.WhenPressed(command_ClimbUnlock(&m_climb));
  // atk3WinchUnlock.WhenReleased(command_ClimbUnlock(&m_climb));
  // atk3WinchUp.WhenPressed(command_ClimbWinchByPower(&m_climb), power);//set power
  // atk3WinchUp.WhenReleased(command_ClimbWinchByPower(&m_climb), power);//set power


//  xboxB.WhenPressed(command_ClimbArmByPower(&m_climb, [=] {return 0.2;}));
//  xboxY.WhenPressed(command_ClimbUnlock(&m_climb));
// 


 // xboxY.WhenPressed(command_IntakeMode(&m_intake,&m_shooter));


  //xboxA.WhenPressed(command_AimBotCameraMode(&m_aimBot));
  //xboxB.WhenPressed(AimBotAutoAim(&m_aimBot, &m_drive));
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
return &m_autonomousCommand;
}
  

