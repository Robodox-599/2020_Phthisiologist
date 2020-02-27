/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/subsystem_Shooter.h"
#include "ctre/Phoenix.h"
#include "frc/WPILib.h"
//dummy values
subsystem_Shooter::subsystem_Shooter(): LeftMotor(0), RightMotor(1), HoodMotor(2) {

    LeftMotor.SetInverted(true);
    RightMotor.SetInverted(false);

    RightMotor.SetSensorPhase(false);
    
    RightMotor.ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 0);
    HoodMotor.ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 0);

    RightMotor.SetSelectedSensorPosition(0, 0, 0);
    HoodMotor.SetSelectedSensorPosition(0, 0, 0);

    LeftMotor.Set(ControlMode::Follower, 1);

    HoodMotor.Config_kD = 0; //dummy values
    HoodMotor.Config_kF = 1; //dummy values
    HoodMotor.Config_kI = 0; //dummy values
    HoodMotor.Config_kP = 0; //dummy values
    HoodMotor.Config_IntegralZone = 0; //dummy values

    RightMotor.Config_kD = 0; //dummy values
    RightMotor.Config_kF = 1; //dummy values
    RightMotor.Config_kI = 0; //dummy values
    RightMotor.Config_kP = 0; //dummy values
    RightMotor.Config_IntegralZone = 0; //dummy values

}

void subsystem_Shooter::FlywheelSpin(double velocity)
{
    RightMotor.Set(ControlMode::Velocity, velocity);
}

void subsystem_Shooter::HoodMovement(double position)
{
    HoodMotor.Set(ControlMode::Position, position);
}

// This method will be called once per scheduler run
void subsystem_Shooter::Periodic() {}
