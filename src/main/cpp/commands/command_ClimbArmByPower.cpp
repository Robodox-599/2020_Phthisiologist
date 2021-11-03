/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/command_ClimbArmByPower.h"

command_ClimbArmByPower::command_ClimbArmByPower(subsystem_Climb *subsystem_Climb, std::function<double()> power)
: m_subsystem_Climb{subsystem_Climb}, m_power{power}
{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({m_subsystem_Climb});
}

// Called when the command is initially scheduled.
void command_ClimbArmByPower::Initialize() {
    m_subsystem_Climb->SetClimbArmMotorPower(m_power());
    printf("climb arm power\n");
}

// Called repeatedly when this Command is scheduled to run
void command_ClimbArmByPower::Execute() {
    printf("climb arm by power execute \n");
}

// Called once the command ends or is interrupted.
void command_ClimbArmByPower::End(bool interrupted) {}

// Returns true when the command should end.
bool command_ClimbArmByPower::IsFinished() { return true; }
