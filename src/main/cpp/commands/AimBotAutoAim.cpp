/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AimBotAutoAim.h"

AimBotAutoAim::AimBotAutoAim(subsystem_AimBot* aimBot, subsystem_Drive* drive) : m_aimBot{aimBot}, m_drive{drive} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({aimBot, drive});
  m_power = 0;
  m_kF = 0.0;
  m_kP = 0.0;
}

// Called when the command is initially scheduled.
void AimBotAutoAim::Initialize() {timer.Stop(); timer.Reset(); linedUp = false;}

// Called repeatedly when this Command is scheduled to run
void AimBotAutoAim::Execute() 
{
  m_yaw = m_aimBot->AimBotYaw();
  m_power = m_kF + (m_yaw * m_kP);
  printf("power: %f \n", m_power);
  printf("yaw: %f \n", m_yaw);
  // m_drive->JoystickPercentDrive(0, m_power);
  if(m_yaw < 0.5 && m_yaw > -0.5)
  {
    printf("in the if statement");
    timer.Start();
    printf("timer %f \n", timer.Get());
    if(timer.Get() > 0.5)
    {
      linedUp = true;
    }
  }
  else
  {
    timer.Stop();
    timer.Reset();
  }
  
}

// Called once the command ends or is interrupted.
void AimBotAutoAim::End(bool interrupted) {m_drive->JoystickPercentDrive(0, 0); printf("aim locked");}

// Returns true when the command should end.
bool AimBotAutoAim::IsFinished() { return linedUp; }
