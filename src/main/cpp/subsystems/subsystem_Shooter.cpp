/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/subsystem_Shooter.h"
#include "Constants.h"
//dummy values
subsystem_Shooter::subsystem_Shooter(): LeftMotor(ShooterConstants::leftShooterMotorPort), RightMotor(ShooterConstants::rightShooterMotorPort), HoodMotor(ShooterConstants::hoodAdjustHoodPort), FeederMotor(ShooterConstants::feederMotorPort)
{

    LeftMotor.SetInverted(true);
    RightMotor.SetInverted(false);
    FeederMotor.SetInverted(false);
    HoodMotor.SetInverted(false);

    RightMotor.SetSensorPhase(true);
    
    RightMotor.ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 0);

    RightMotor.SetSelectedSensorPosition(0, 0, 0);

    RightMotor.Config_kF(0, ShooterConstants::shooterkF, 0);
    RightMotor.Config_kP(0, ShooterConstants::shooterkP, 0);
    RightMotor.Config_kD(0, ShooterConstants::shooterkD, 0);


    HoodMotor.SetSelectedSensorPosition(0, 0, 0);
    HoodMotor.ConfigSelectedFeedbackSensor(FeedbackDevice::Analog, 0, 0);

    hoodLimitOffset = (ShooterConstants::hoodPotMax - ShooterConstants::hoodPotMin) * (ShooterConstants::hoodPotLimitPercent/100);
    hoodLimitMax = ShooterConstants::hoodPotMax - hoodLimitOffset;
    hoodLimitMin = ShooterConstants::hoodPotMin + hoodLimitOffset;
    HoodMotor.ConfigForwardSoftLimitThreshold(hoodLimitMax);
    HoodMotor.ConfigReverseSoftLimitThreshold(hoodLimitMin);
    HoodMotor.ConfigForwardSoftLimitEnable(true);
    HoodMotor.ConfigReverseSoftLimitEnable(true);

    HoodMotor.Config_kF(0, ShooterConstants::hoodkF, 0);
    HoodMotor.Config_kP(0, ShooterConstants::hoodkP, 0);
    HoodMotor.Config_kI(0, ShooterConstants::hoodkI, 0);
    HoodMotor.Config_kD(0, ShooterConstants::hoodkD, 0);
}

void subsystem_Shooter::FlywheelSpin(double velocity)
{
    RightMotor.Set(ControlMode::Velocity, velocity);
    LeftMotor.Set(ControlMode::Follower, ShooterConstants::rightShooterMotorPort);
}

void subsystem_Shooter::HoodMovement(double degrees)
{
    double ticks = degrees*((ShooterConstants::hoodPotMax-ShooterConstants::hoodPotMin)/ShooterConstants::hoodTotalDegrees);
    HoodMotor.Set(ControlMode::MotionMagic, ticks);
}

// This method will be called once per scheduler run
void subsystem_Shooter::Periodic() {}
