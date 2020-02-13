/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/subsystem_AimBot.h"
#include "frc/smartdashboard/SmartDashboard.h"

subsystem_AimBot::subsystem_AimBot() 
{
    printf("aimbot init");
    table = nt::NetworkTableInstance::GetDefault();
    cameraTable = table.GetTable("chameleon-vision")->GetSubTable("Microsoft LifeCam HD-3000");
    yaw = cameraTable->GetEntry("targetYaw");
    cameraTable->PutBoolean("driverMode", true);
    driverMode = true;
}

// This method will be called once per scheduler run
void subsystem_AimBot::Periodic() {}

double subsystem_AimBot::AimBotYaw()
{
    //printf("yaw: %f\n", yaw.GetDouble(0));
    frc::SmartDashboard::PutNumber("yaw", yaw.GetDouble(0));
    return yaw.GetDouble(0);
}

void subsystem_AimBot::ConvertMode()
{
    if(driverMode == true)
    {
        cameraTable->PutBoolean("driverMode", false);
        table.Flush();
        driverMode = false;
    }
    else
    {
        cameraTable->PutBoolean("driverMode", true);
        table.Flush();
        driverMode = true;
    }
}
