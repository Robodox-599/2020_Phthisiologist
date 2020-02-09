/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/subsystem_Drive.h"
#include "Constants.h"

subsystem_Drive::subsystem_Drive() : 
frontLeftMotor(DriveConstants::frontLeftMotorPort), rearLeftMotor(DriveConstants::rearLeftMotorPort), 
frontRightMotor(DriveConstants::frontRightMotorPort), rearRightMotor(DriveConstants::rearRightMotorPort),
pGyon(DriveConstants::pigeonPort)
{
    frontLeftMotor.SetInverted(true);
    rearLeftMotor.SetInverted(true);
    frontRightMotor.SetInverted(false);
    rearRightMotor.SetInverted(false);

    rearLeftMotor.SetSensorPhase(true);
    rearRightMotor.SetSensorPhase(false);

    // rearLeftMotor.ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 0);
    // rearRightMotor.ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 0);

    rearLeftMotor.SetSelectedSensorPosition(0, 0, 0);
    rearRightMotor.SetSelectedSensorPosition(0, 0, 0);

    pGyon.SetYaw(0, 0);
}

// This method will be called once per scheduler run
void subsystem_Drive::Periodic() {}

void subsystem_Drive::JoystickPercentDrive(double x, double y)
{
    double l;
	double r;

	if(y > 0.2)
	{
		y = (y-0.2)*1/.8;
	}
	else if(y < -0.2)
	{
		y = (y+0.2)*1/.8;
	}
	else
	{
		y = 0;
	}

	if(x > 0.2)
	{
		x = (x-0.2)*1/.8;
	}
	else if(x < -0.2)
	{
		x = (x+0.2)*1/.8;
	}
	else
	{
		x = 0;
	}

	l = y-x;
	r = y+x;

	frontLeftMotor.Set(ControlMode::PercentOutput, l);
	rearLeftMotor.Set(ControlMode::PercentOutput, l);
	frontRightMotor.Set(ControlMode::PercentOutput, r);
	rearRightMotor.Set(ControlMode::PercentOutput, r);   
}