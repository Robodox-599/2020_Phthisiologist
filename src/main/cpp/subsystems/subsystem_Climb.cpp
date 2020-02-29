/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/subsystem_Climb.h"

subsystem_Climb::subsystem_Climb() : m_leftWinchMotor(0), m_rightWinchMotor(0), m_slideMotor(0), m_climbArmMotor(0), m_lockSolenoid(0,0) {
    m_leftWinchMotor.Set(ControlMode::PercentOutput, 0);
    m_rightWinchMotor.Set(ControlMode::PercentOutput, 0);
    m_rightWinchMotor.SetInverted(true);
    m_leftWinchMotor.SetInverted(false);
    m_rightWinchMotor.Follow(m_leftWinchMotor);

    m_slideMotor.Set(ControlMode::PercentOutput, 0);

    m_climbArmMotor.Set(ControlMode::PercentOutput, 0);
}

void subsystem_Climb::SetWinchMotorPower(double power)
{
    m_leftWinchMotor.Set(ControlMode::PercentOutput, power);
}

void subsystem_Climb::LockClimb()
{
    m_lockSolenoid.Set(frc::DoubleSolenoid::kReverse);
    m_isClimbLocked = true;
}

void subsystem_Climb::UnlockClimb()
{
    m_lockSolenoid.Set(frc::DoubleSolenoid::kForward);
    m_isClimbLocked = false;
}

bool subsystem_Climb::IsClimbLocked()
{
    return m_isClimbLocked;
}

void subsystem_Climb::SetSlideMotorPower(double power)
{
    m_slideMotor.Set(ControlMode::PercentOutput, power);
}

void subsystem_Climb::SetClimbArmMotorPower(double power)
{
    m_climbArmMotor.Set(ControlMode::PercentOutput, power);
}

// This method will be called once per scheduler run
void subsystem_Climb::Periodic() {}
