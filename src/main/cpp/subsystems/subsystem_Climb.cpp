/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/subsystem_Climb.h"
#include "Constants.h"

subsystem_Climb::subsystem_Climb() : m_leftWinchMotor(ClimbConstants::leftWinchMotorPort), m_rightWinchMotor(ClimbConstants::rightWinchMotorPort), m_slideMotor(ClimbConstants::antiTipMotorPort), m_climbArmMotor(ClimbConstants::armMotorPort), m_lockSolenoid(ClimbConstants::climbLockPistonL,ClimbConstants::climbLockPistonR) {
    m_leftWinchMotor.Set(ControlMode::PercentOutput, 0);
    m_rightWinchMotor.Set(ControlMode::PercentOutput, 0);
    m_rightWinchMotor.SetInverted(false);
    m_leftWinchMotor.SetInverted(false);
    m_rightWinchMotor.Follow(m_leftWinchMotor);

    m_slideMotor.Set(ControlMode::PercentOutput, 0);

    m_climbArmMotor.Set(ControlMode::PercentOutput, 0);
    m_climbArmMotor.SetInverted(true);

//    m_climbArmMotor.ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 0);

//    m_climbArmMotor.SetSensorPhase(false);

    // m_climbArmMotor.Config_kF(0, ClimbConstants::climbArmkF, 0);
    // m_climbArmMotor.Config_kP(0, ClimbConstants::climbArmkP, 0);
    // m_climbArmMotor.Config_kI(0, ClimbConstants::climbArmkI, 0);
    // m_climbArmMotor.Config_kD(0, ClimbConstants::climbArmkD, 0);

    // m_climbArmMotor.ConfigMotionCruiseVelocity(ClimbConstants::climbArmVelocity);
    // m_climbArmMotor.ConfigMotionAcceleration(ClimbConstants::climbArmAcceleration);

    // m_climbArmEncoderRange = ClimbConstants::climbArmEncoderMax-ClimbConstants::climbArmEncoderMin;

    // m_climbArmLimitOffset = (m_climbArmEncoderRange)*(ClimbConstants::climbArmEncoderLimitPercent/100);
    // m_climbArmLimitMax = ClimbConstants::climbArmEncoderMax - m_climbArmLimitOffset;
    // m_climbArmLimitMin = ClimbConstants::climbArmEncoderMin + m_climbArmLimitOffset;

    // m_climbArmMotor.ConfigForwardSoftLimitThreshold((int)round(m_climbArmLimitMax));
    // m_climbArmMotor.ConfigReverseSoftLimitThreshold((int)round(m_climbArmLimitMin));
    // m_climbArmMotor.ConfigForwardSoftLimitEnable(true);
    // m_climbArmMotor.ConfigReverseSoftLimitEnable(true); 

    //built_different

    LockClimb();
 }

void subsystem_Climb::SetWinchMotorPower(double power)
{
    m_leftWinchMotor.Set(ControlMode::PercentOutput, power);
}

void subsystem_Climb::LockClimb()
{
    m_lockSolenoid.Set(frc::DoubleSolenoid::kForward);
    m_isClimbLocked = true;
}

void subsystem_Climb::UnlockClimb()
{
    m_lockSolenoid.Set(frc::DoubleSolenoid::kReverse);
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

void subsystem_Climb::ClimbArmMovementByTicks(double ticks)
{
    frc::SmartDashboard::PutNumber("climb arm target in ticks", ticks);
    m_climbArmMotor.Set(ControlMode::MotionMagic, ticks);
}

void subsystem_Climb::ClimbArmMovementByDegrees(double degrees)
{
    double ticks = degrees * (m_climbArmEncoderRange/ClimbConstants::climbArmTotalDegrees);
    frc::SmartDashboard::PutNumber("climb arm target in degrees", degrees);
    frc::SmartDashboard::PutNumber("climb arm degrees to ticks", ticks);
    m_climbArmMotor.Set(ControlMode::MotionMagic, ticks);
}

double subsystem_Climb::ReturnClimbArmTicks()
{
    return m_climbArmMotor.GetSelectedSensorPosition();
}

// This method will be called once per scheduler run
void subsystem_Climb::Periodic() {}
