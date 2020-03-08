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
  m_kF = 0.1;
  m_kP = 0.015;
  m_kI = 0.003;
}

// Called when the command is initially scheduled.
void AimBotAutoAim::Initialize() 
{
  timer.Stop();
  timer.Reset();
  linedUp = false;
  prevPosition = m_aimBot->AimBotYaw();  
}

// Called repeatedly when this Command is scheduled to run
void AimBotAutoAim::Execute() 
{
  m_yaw = m_aimBot->AimBotYaw();
  nextPosition = m_yaw - (prevPosition - m_yaw);
  if(nextPosition < 12 && nextPosition > -12)
  {
    double maxI = 65;
    i += nextPosition;
    if(i > maxI)
    {
      i = maxI;
    }
    else if(i < -maxI)
    {
      i = -maxI;
    }
  }
  else
  {
    i = 0;
  }
  
  if(nextPosition > 0)
  {
    m_power = m_kF + (m_yaw * m_kP) + (i * m_kI);
  }
  else
  {
    m_power = - m_kF + (m_yaw * m_kP) + (i * m_kI);
  }
  
  // printf("power: %f \n", m_power);
  // printf("yaw: %f \n", m_yaw);
  printf("i gain: %f \n", i);
  printf("next position value: %f \n", nextPosition);
  m_drive->JoystickPercentDrive(m_power, 0);
  if(nextPosition < 0.5 && nextPosition > -0.5)
  {
    i = 0;
    printf("in the if statement");
    timer.Start();
    printf("timer %f \n", timer.Get());
    if(timer.Get() > 0.2)
    {
      linedUp = true;
    }
  }
  else
  {
    timer.Stop();
    timer.Reset();
  }
  prevPosition = m_yaw;
}

// Called once the command ends or is interrupted.
void AimBotAutoAim::End(bool interrupted) {m_drive->JoystickPercentDrive(0, 0); printf("aim locked");}

// Returns true when the command should end.
bool AimBotAutoAim::IsFinished() { return linedUp; }
