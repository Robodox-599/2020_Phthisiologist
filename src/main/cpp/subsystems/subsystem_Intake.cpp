/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/subsystem_Intake.h"

subsystem_Intake::subsystem_Intake()
: m_intakeMotor(IntakeConstants::intakeMotorPort), m_leftIndexerMotor(IntakeConstants::leftIndexerMotorPort),
m_rightIndexerMotor(IntakeConstants::rightIndexerMotorPort), m_intakePiston(IntakeConstants::intakePiston1,IntakeConstants::intakePiston2)
{
    m_intakeMotor.Set(ControlMode::PercentOutput, 0);
    m_leftIndexerMotor.Set(ControlMode::PercentOutput, 0);
    m_rightIndexerMotor.Set(ControlMode::PercentOutput, 0);
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

void subsystem_Intake::SetIntakeWheelsOn()
{
    m_intakeMotor.Set(ControlMode::PercentOutput, 1);
}


void subsystem_Intake::SetIntakeWheelsOff()
{
    m_intakeMotor.Set(ControlMode::PercentOutput, 0);
}

void subsystem_Intake::SetIndexerOn(double leftPower, double rightPower)
{
    m_leftIndexerMotor.Set(ControlMode::PercentOutput, leftPower);
    m_rightIndexerMotor.Set(ControlMode::PercentOutput, rightPower);
}

void subsystem_Intake::SetIndexerOff()
{
    m_leftIndexerMotor.Set(ControlMode::PercentOutput, 0);
    m_rightIndexerMotor.Set(ControlMode::PercentOutput, 0);
}

// This method will be called once per scheduler run
void subsystem_Intake::Periodic() {}
