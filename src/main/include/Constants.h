/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

namespace DriveConstants
{
    constexpr int frontLeftMotorPort = 2;
    constexpr int rearLeftMotorPort = 1;
    constexpr int frontRightMotorPort = 3;
    constexpr int rearRightMotorPort = 4;

    constexpr int leftEncoderPort = 1;
    constexpr int rightEncoderPort = 3;

    constexpr int pigeonPort = 0;
}

namespace ControllerConstants
{
    constexpr int xboxPort = 0;
    constexpr int joystickPort = 1;

    constexpr int xboxLXAxis = 0;
    constexpr int xboxLYAxis = 1;
    constexpr int xboxRXAxis = 4;
    constexpr int xboxRYAxis = 5;

    constexpr int xboxLTAxis = 2;
    constexpr int xboxRTAxis = 3;

    constexpr int xboxA = 1;
    constexpr int xboxB = 2;
    constexpr int xboxX = 3;
    constexpr int xboxY = 4;
    constexpr int xboxLB = 5;
    constexpr int xboxRB = 6;
    constexpr int xboxView = 7;
    constexpr int xboxMenu = 8;
    constexpr int xboxLeftJoyPress = 9;
    constexpr int xboxRightJoyPress = 10;
}

namespace ClimbConstants
{
    constexpr int leftWinchMotorPort = 10;
    constexpr int rightWinchMotorPort = 6;
    constexpr int armMotorPort = 7;
    constexpr int antiTipMotorPort = 8;
    
    constexpr int climbLockPistonL = 2;
    constexpr int climbLockPistonR = 3;
}

namespace ShooterConstants
{
    constexpr int leftShooterMotorPort = 11;
    constexpr int rightShooterMotorPort = 5;
    constexpr int shooterEncoderPort = 5;

    constexpr double shooterkF = 0.0165;
    constexpr double shooterkP = 0.12;
    constexpr double shooterkD = 1;

    constexpr int feederMotorPort = 13;
    
    constexpr int hoodAdjustHoodPort = 11;
    constexpr int hoodPotentiometerPort = 11;

    constexpr double hoodPotMax = 444;
    constexpr double hoodPotMin = 314;
    constexpr double hoodPotLimitPercent = 10;
    constexpr double hoodTotalDegrees = 37;

    constexpr double hoodkF = 0;
    constexpr double hoodkP = 0;
    constexpr double hoodkI = 0;
    constexpr double hoodkD = 0;
}

namespace IntakeConstants
{
    constexpr int intakeMotorPort = 12;

    constexpr int leftIndexerMotorPort = 13;
    constexpr int rightIndexerMotorPort = 14;
    
    constexpr int intakePistonL = 0;
    constexpr int intakePistonR = 1;
}
