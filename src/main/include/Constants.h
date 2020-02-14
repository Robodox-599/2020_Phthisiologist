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
    constexpr int frontLeftMotorPort = 1;
    constexpr int rearLeftMotorPort = 2;
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
    constexpr int xboxA = 1;
    constexpr int xboxB = 2;
    constexpr int xboxX = 3;
    constexpr int xboxY = 4;
}