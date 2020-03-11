/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableInstance.h"

class subsystem_AimBot : public frc2::SubsystemBase {
 public:
  subsystem_AimBot();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();
  double AimBotYaw();
  void ConvertMode();
  bool AimBotIsLocked();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  nt::NetworkTableEntry yaw;
  bool driverMode;
  bool isLocked;
  nt::NetworkTableInstance table;
  std::shared_ptr<NetworkTable> cameraTable;
};
