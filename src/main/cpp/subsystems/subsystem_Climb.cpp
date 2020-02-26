/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/subsystem_Climb.h"

subsystem_Climb::subsystem_Climb() : m_LeftClimbMotor(0), m_RightClimbMotor(0), m_SlideMotor(0), m_ClimbArmMotor(0), m_RightLockSolenoid(0,0), m_LeftLockSolenoid(0,0) {
    m_LeftClimbMotor.Set(ControlMode::PercentOutput, 0);
    m_RightClimbMotor.Set(ControlMode::PercentOutput, 0);
    m_RightClimbMotor.SetInverted(true);
    m_LeftClimbMotor.SetInverted(false);
    m_RightClimbMotor.Follow(m_LeftClimbMotor);

    m_SlideMotor.Set(ControlMode::PercentOutput, 0);

    m_ClimbArmMotor.Set(ControlMode::PercentOutput, 0);
}

void subsystem_Climb::DriveClimbArm(double power, bool up) 
{
    m_LeftClimbMotor.Set(ControlMode::PercentOutput, up ? power : -power);
}

void subsystem_Climb::OperateLock(bool extend)
{
    m_RightLockSolenoid.Set(extend ? frc::DoubleSolenoid::kForward : frc::DoubleSolenoid::kReverse);
    m_LeftLockSolenoid.Set(extend ? frc::DoubleSolenoid::kForward : frc::DoubleSolenoid::kReverse);
}

// This method will be called once per scheduler run
void subsystem_Climb::Periodic() {}
