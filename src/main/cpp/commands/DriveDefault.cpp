/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DriveDefault.h"

DriveDefault::DriveDefault(subsystem_Drive* drive, std::function<double()> rotation, std::function<double()> forward) 
              : m_subsystem{drive}, m_rotation{rotation}, m_forward{forward}
{
  AddRequirements({drive});
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void DriveDefault::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void DriveDefault::Execute()
{
  m_subsystem->JoystickPercentDrive(m_forward(), m_rotation());
}

// Called once the command ends or is interrupted.
void DriveDefault::End(bool interrupted) {}

// Returns true when the command should end.
bool DriveDefault::IsFinished() { return false; }
