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

    constexpr int atk3ArmUp = 6;
    constexpr int atk3ArmDown = 7;
    constexpr int atk3WinchUnlock = 8;
    constexpr int atk3WinchUp = 11;
    constexpr int atk3WinchDown = 12;
}

namespace ClimbConstants
{
    constexpr int leftWinchMotorPort = 7;
    constexpr int rightWinchMotorPort = 12;
    constexpr int armMotorPort = 9;
    constexpr int antiTipMotorPort = 6;
    
    constexpr int climbLockPistonL = 6;
    constexpr int climbLockPistonR = 7;

    constexpr double climbArmEncoderMax = 0;
    constexpr double climbArmEncoderMin = 0;
    constexpr double climbArmEncoderLimitPercent = 10;
    constexpr double climbArmTotalDegrees = 0;

    constexpr double climbArmkF = 0;
    constexpr double climbArmkP = 0;
    constexpr double climbArmkI = 0;
    constexpr double climbArmkD = 0;

    constexpr int climbArmVelocity = 280;
    constexpr int climbArmAcceleration = 100;    
}

namespace ShooterConstants
{
    constexpr int leftShooterMotorPort = 11;
    constexpr int rightShooterMotorPort = 5;
    constexpr int shooterEncoderPort = 5;
    
    constexpr double shooterkF = 0.0165;
    constexpr double shooterkP = 0.12;
    constexpr double shooterkD = 1;

    constexpr int feederMotorPort = 10;

    constexpr int hoodAdjustHoodPort = 13;
    constexpr int hoodPotentiometerPort = 13;

    constexpr double hoodPotMin = 316;
    constexpr double hoodPotMax = 447;
    constexpr double hoodPotLimitPercent = 2;
    constexpr double hoodTotalDegrees = 37;

    constexpr double hoodkF = 0;
    constexpr double hoodkP = 35;
    constexpr double hoodkI = 0;
    constexpr double hoodkD = 0;
    constexpr int hoodVelocity = 280;
    constexpr int hoodAcceleration = 100;
}

namespace IntakeConstants
{
    constexpr int intakeMotorPort = 14;
    
    constexpr int intakePistonL = 0;
    constexpr int intakePistonR = 1;
    
    constexpr int leftIndexerMotorPort  = 8;
    constexpr int rightIndexerMotorPort  = 15;
}