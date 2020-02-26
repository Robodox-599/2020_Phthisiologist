/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/subsystem_Intake.h"

subsystem_Intake::subsystem_Intake() : m_intakeMotor(0), m_intakePiston(0,0)
{
    m_intakeMotor.Set(ControlMode::PercentOutput, 0);
}

void subsystem_Intake::SetIntakeUp()
{
    m_intakePiston.Set(frc::DoubleSolenoid::kReverse);
    m_isIntakeDeployed = false;
}

void subsystem_Intake::SetIntakeDown()
{
    m_intakePiston.Set(frc::DoubleSolenoid::kForward);
    m_isIntakeDeployed = true;
}

bool subsystem_Intake::IsIntakeDeployed()
{
    return m_isIntakeDeployed;
}

void subsystem_Intake::SetIntakeRollersOn()
{
    m_intakeMotor.Set(ControlMode::PercentOutput, 1);
}

void subsystem_Intake::SetIntakeRollersOff()
{
    m_intakeMotor.Set(ControlMode::PercentOutput, 0);
}



// This method will be called once per scheduler run
void subsystem_Intake::Periodic() {}
