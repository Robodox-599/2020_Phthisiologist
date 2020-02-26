/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/subsystem_Climb.h"

subsystem_Climb::subsystem_Climb() : m_LeftWinchMotor(0), m_RightWinchMotor(0), m_SlideMotor(0), m_ClimbArmMotor(0), m_LockSolenoid(0,0) {
    m_LeftWinchMotor.Set(ControlMode::PercentOutput, 0);
    m_RightWinchMotor.Set(ControlMode::PercentOutput, 0);
    m_RightWinchMotor.SetInverted(true);
    m_LeftWinchMotor.SetInverted(false);
    m_RightWinchMotor.Follow(m_LeftWinchMotor);

    m_SlideMotor.Set(ControlMode::PercentOutput, 0);

    m_ClimbArmMotor.Set(ControlMode::PercentOutput, 0);
}

void subsystem_Climb::SetWinchMotorPower(double power)
{
    m_LeftWinchMotor.Set(ControlMode::PercentOutput, power);
}

void subsystem_Climb::LockClimb()
{
    m_LockSolenoid.Set(frc::DoubleSolenoid::kReverse);
    m_isClimbLocked = true;
}

void subsystem_Climb::UnlockClimb()
{
    m_LockSolenoid.Set(frc::DoubleSolenoid::kForward);
    m_isClimbLocked = false;
}

bool subsystem_Climb::IsClimbLocked()
{
    return m_isClimbLocked;
}

void subsystem_Climb::SetSlideMotorPower(double power)
{
    m_SlideMotor.Set(ControlMode::PercentOutput, power);
}

void subsystem_Climb::SetClimbArmMotorPower(double power)
{
    m_ClimbArmMotor.Set(ControlMode::PercentOutput, power);
}

// This method will be called once per scheduler run
void subsystem_Climb::Periodic() {}
