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
    HoodMotor.SetInverted(true);

    RightMotor.SetSensorPhase(false);
    
    RightMotor.ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 0);

    RightMotor.SetSelectedSensorPosition(0, 0, 0);

    RightMotor.Config_kF(0, ShooterConstants::shooterkF, 0);
    RightMotor.Config_kP(0, ShooterConstants::shooterkP, 0);
    RightMotor.Config_kD(0, ShooterConstants::shooterkD, 0);


    HoodMotor.ConfigSelectedFeedbackSensor(FeedbackDevice::Analog, 0, 0);

    HoodMotor.SetSensorPhase(false);

    HoodMotor.Config_kF(0, ShooterConstants::hoodkF, 0);
    HoodMotor.Config_kP(0, ShooterConstants::hoodkP, 0);
    HoodMotor.Config_kI(0, ShooterConstants::hoodkI, 0);
    HoodMotor.Config_kD(0, ShooterConstants::hoodkD, 0);

    HoodMotor.ConfigMotionCruiseVelocity(ShooterConstants::hoodVelocity);
    HoodMotor.ConfigMotionAcceleration(ShooterConstants::hoodAcceleration);
}

void subsystem_Shooter::FlywheelSpin(double velocity)
{
    RightMotor.Set(ControlMode::Velocity, velocity);
    LeftMotor.Set(ControlMode::Follower, ShooterConstants::rightShooterMotorPort);
}

double subsystem_Shooter::ReturnFlywheelVelocity()
{
    return RightMotor.GetSelectedSensorVelocity();
}

void subsystem_Shooter::HoodMovement(double ticks)
{
    HoodMotor.Set(ControlMode::MotionMagic, ticks);
}

double subsystem_Shooter::ReturnHoodTicks()
{
    return HoodMotor.GetSelectedSensorPosition();
}

void subsystem_Shooter::Feed()
{
    FeederMotor.Set(ControlMode::PercentOutput, 0.8);
}

// This method will be called once per scheduler run
void subsystem_Shooter::Periodic() {}
