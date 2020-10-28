
///////////////////////////////////
// SPAN SERVICES (HAP Chapter 8) //
///////////////////////////////////

// Macros to define vectors of required and optional characteristics for each Span Service structure

#define REQ(name) req.push_back(&homeSpan.chr.name)
#define OPT(name) opt.push_back(&homeSpan.chr.name)

namespace Service {

  struct AccessoryInformation : SpanService { AccessoryInformation() : SpanService{"3E","AccessoryInformation"}{
    REQ(FirmwareRevision);
    REQ(Identify);
    REQ(Manufacturer);
    REQ(Model);
    REQ(Name);
    REQ(SerialNumber);
    OPT(HardwareRevision);      
  }};

  struct AirPurifier : SpanService { AirPurifier() : SpanService{"BB","AirPurifier"}{
    REQ(Active);
    REQ(CurrentAirPurifierState);
    REQ(TargetAirPurifierState);
    OPT(Name);
    OPT(RotationSpeed);
    OPT(SwingMode);
    OPT(LockPhysicalControls);
  }};

  struct AirQualitySensor : SpanService { AirQualitySensor() : SpanService{"8D","AirQualitySensor"}{
    REQ(AirQuality);
    OPT(Name);
    OPT(OzoneDensity);
    OPT(NitrogenDioxideDensity);
    OPT(SulphurDioxideDensity);
    OPT(PM25Density);
    OPT(PM10Density);
    OPT(VOCDensity);
    OPT(StatusActive);
    OPT(StatusFault);
    OPT(StatusTampered);
    OPT(StatusLowBattery);
  }};

  struct BatteryService : SpanService { BatteryService() : SpanService{"96","BatteryService"}{
    REQ(BatteryLevel);
    REQ(ChargingState);
    REQ(StatusLowBattery);
    OPT(Name);
  }};

  struct CarbonDioxideSensor : SpanService { CarbonDioxideSensor() : SpanService{"97","CarbonDioxideSensor"}{
    REQ(CarbonDioxideDetected);
    OPT(Name);
    OPT(StatusActive);
    OPT(StatusFault);
    OPT(StatusTampered);
    OPT(StatusLowBattery);
    OPT(CarbonDioxideLevel);
    OPT(CarbonDioxidePeakLevel);
  }};

  struct CarbonMonoxideSensor : SpanService { CarbonMonoxideSensor() : SpanService{"7F","CarbonMonoxideSensor"}{
    REQ(CarbonMonoxideDetected);
    OPT(Name);
    OPT(StatusActive);
    OPT(StatusFault);
    OPT(StatusTampered);
    OPT(StatusLowBattery);
    OPT(CarbonMonoxideLevel);
    OPT(CarbonMonoxidePeakLevel);
    }};

  struct ContactSensor : SpanService { ContactSensor() : SpanService{"80","ContactSensor"}{
    REQ(ContactSensorState);
    OPT(Name);
    OPT(StatusActive);
    OPT(StatusFault);
    OPT(StatusTampered);
    OPT(StatusLowBattery);
  }};

  struct Door : SpanService { Door() : SpanService{"81","Door"}{
    REQ(CurrentPosition);
    REQ(TargetPosition);
    REQ(PositionState);
    OPT(Name);
    OPT(HoldPosition);
    OPT(ObstructionDetected);
  }};

  struct Doorbell : SpanService { Doorbell() : SpanService{"121","Doorbell"}{
    REQ(ProgrammableSwitchEvent);
    OPT(Name);
    OPT(Volume);
    OPT(Brightness);
  }};

  struct Fan : SpanService { Fan() : SpanService{"B7","Fan"}{
    REQ(Active);
    OPT(Name);
    OPT(CurrentFanState);
    OPT(TargetFanState);
    OPT(RotationDirection);
    OPT(RotationSpeed);
    OPT(SwingMode);
    OPT(LockPhysicalControls);
  }};

  struct Faucet : SpanService { Faucet() : SpanService{"D7","Faucet"}{
    REQ(Active);
    OPT(StatusFault);
    OPT(Name);
  }};

  struct FilterMaintenance : SpanService { FilterMaintenance() : SpanService{"BA","FilterMaintenance"}{
    REQ(FilterChangeIndication);
    OPT(Name);
    OPT(FilterLifeLevel);
    OPT(ResetFilterIndication);
  }};

  struct GarageDoorOpener : SpanService { GarageDoorOpener() : SpanService{"41","GarageDoorOpener"}{
    REQ(CurrentDoorState);
    REQ(TargetDoorState);
    REQ(ObstructionDetected);
    OPT(LockCurrentState);
    OPT(LockTargetState);
    OPT(Name);
  }};

  struct HAPProtocolInformation : SpanService { HAPProtocolInformation() : SpanService{"A2","HAPProtocolInformation"}{
    REQ(Version);
  }};

  struct HeaterCooler : SpanService { HeaterCooler() : SpanService{"BC","HeaterCooler"}{
    REQ(Active);
    REQ(CurrentTemperature);
    REQ(CurrentHeaterCoolerState);
    REQ(TargetHeaterCoolerState);
    OPT(Name);
    OPT(RotationSpeed);
    OPT(TemperatureDisplayUnits);
    OPT(SwingMode);
    OPT(CoolingThresholdTemperature);
    OPT(HeatingThresholdTemperature);
    OPT(LockPhysicalControls);
  }};

  struct HumidifierDehumidifier : SpanService { HumidifierDehumidifier() : SpanService{"BD","HumidifierDehumidifier"}{
    REQ(Active);
    REQ(CurrentRelativeHumidity);
    REQ(CurrentHumidifierDehumidifierState);
    REQ(TargetHumidifierDehumidifierState);
    OPT(Name);
    OPT(RelativeHumidityDehumidifierThreshold);
    OPT(RelativeHumidityHumidifierThreshold);
    OPT(RotationSpeed);
    OPT(SwingMode);
    OPT(WaterLevel);
    OPT(LockPhysicalControls);
  }};

  struct HumiditySensor : SpanService { HumiditySensor() : SpanService{"82","HumiditySensor"}{
    REQ(CurrentRelativeHumidity);
    OPT(Name);
    OPT(StatusActive);
    OPT(StatusFault);
    OPT(StatusTampered);
    OPT(StatusLowBattery);   
  }};

  struct IrrigationSystem : SpanService { IrrigationSystem() : SpanService{"CF","IrrigationSystem"}{
    REQ(Active);
    REQ(ProgramMode);
    REQ(InUse);
    OPT(RemainingDuration);
    OPT(Name);
    OPT(StatusFault);
  }};

  struct LeakSensor : SpanService { LeakSensor() : SpanService{"83","LeakSensor"}{
    REQ(LeakDetected);
    OPT(Name);
    OPT(StatusActive);
    OPT(StatusFault);
    OPT(StatusTampered);
    OPT(StatusLowBattery);       
  }};

  struct LightBulb : SpanService { LightBulb() : SpanService{"43","LightBulb"}{
    REQ(On);
    OPT(Brightness);
    OPT(Hue);
    OPT(Name);
    OPT(Saturation);
    OPT(ColorTemperature);
  }};

  struct LightSensor : SpanService { LightSensor() : SpanService{"84","LightSensor"}{
    REQ(CurrentAmbientLightLevel);
    OPT(Name);
    OPT(StatusActive);
    OPT(StatusFault);
    OPT(StatusTampered);
    OPT(StatusLowBattery);          
  }};

  struct MotionSensor : SpanService { MotionSensor() : SpanService{"85","MotionSensor"}{
    REQ(MotionDetected);
    OPT(Name);
    OPT(StatusActive);
    OPT(StatusFault);
    OPT(StatusTampered);
    OPT(StatusLowBattery);       
  }};

  struct OccupancySensor : SpanService { OccupancySensor() : SpanService{"86","OccupancySensor"}{
    REQ(OccupancyDetected);
    OPT(Name);
    OPT(StatusActive);
    OPT(StatusFault);
    OPT(StatusTampered);
    OPT(StatusLowBattery);         
  }};

  struct Outlet : SpanService { Outlet() : SpanService{"47","Outlet"}{
    REQ(On);
    REQ(OutletInUse);
    OPT(Name);
  }};

  struct ServiceLabel : SpanService { ServiceLabel() : SpanService{"47","ServiceLabel"}{
    REQ(ServiceLabelNamespace);
  }};  

  struct Slat : SpanService { Slat() : SpanService{"B9","Slat"}{
    REQ(CurrentSlatState);
    REQ(SlatType);
    OPT(Name);
    OPT(SwingMode);
    OPT(CurrentTiltAngle);
    OPT(TargetTiltAngle);
  }};

  struct SmokeSensor : SpanService { SmokeSensor() : SpanService{"87","SmokeSensor"}{
    REQ(SmokeDetected);
    OPT(Name);
    OPT(StatusActive);
    OPT(StatusFault);
    OPT(StatusTampered);
    OPT(StatusLowBattery);             
  }};

  struct StatelessProgrammableSwitch : SpanService { StatelessProgrammableSwitch() : SpanService{"89","StatelessProgrammableSwitch"}{
    REQ(ProgrammableSwitchEvent);
    OPT(Name);
    OPT(ServiceLabelIndex);
  }};

  struct Switch : SpanService { Switch() : SpanService{"49","Switch"}{
    REQ(On);
    OPT(Name);
  }};

  struct TemperatureSensor : SpanService { TemperatureSensor() : SpanService{"8A","TemperatureSensor"}{
    REQ(CurrentTemperature);
    OPT(Name);
    OPT(StatusActive);
    OPT(StatusFault);
    OPT(StatusTampered);
    OPT(StatusLowBattery);
  }};

  struct Thermostat : SpanService { Thermostat() : SpanService{"4A","Thermostat"}{
    REQ(CurrentHeatingCoolingState);
    REQ(TargetHeatingCoolingState);
    REQ(CurrentTemperature);
    REQ(TargetTemperature);
    REQ(TemperatureDisplayUnits);
    OPT(CoolingThresholdTemperature);
    OPT(CurrentRelativeHumidity);
    OPT(HeatingThresholdTemperature);
    OPT(Name);
    OPT(TargetRelativeHumidity);
  }};

  struct Valve : SpanService { Valve() : SpanService{"D0","Valve"}{
    REQ(Active);
    REQ(InUse);
    REQ(ValveType);
    OPT(SetDuration);
    OPT(RemainingDuration);
    OPT(IsConfigured);
    OPT(ServiceLabelIndex);
    OPT(StatusFault);
    OPT(Name);
  }};

  struct Window : SpanService { Window() : SpanService{"8B","Window"}{
    REQ(CurrentPosition);
    REQ(TargetPosition);
    REQ(PositionState);
    OPT(Name);
    OPT(HoldPosition);
    OPT(ObstructionDetected);
  }};

  struct WindowCovering : SpanService { WindowCovering() : SpanService{"8C","WindowCovering"}{
    REQ(CurrentPosition);
    REQ(TargetPosition);
    REQ(PositionState);
    OPT(Name);
    OPT(HoldPosition);
    OPT(CurrentHorizontalTiltAngle);
    OPT(TargetHorizontalTiltAngle);
    OPT(CurrentVerticalTiltAngle);
    OPT(TargetVerticalTiltAngle);
    OPT(ObstructionDetected);
  }};

}

//////////////////////////////////////////
// SPAN CHARACTERISTICS (HAP Chapter 9) //
//////////////////////////////////////////

// Macro to define Span Characteristic structures based on name of HAP Characteristic (see HAPConstants.h), its type (e.g. int, double) and its default value

#define CREATE_CHAR(CHR,TYPE,DEFVAL) struct CHR : SpanCharacteristic { CHR(TYPE value=DEFVAL) : SpanCharacteristic{homeSpan.chr.CHR.id, homeSpan.chr.CHR.perms,(TYPE)value, homeSpan.chr.CHR.name}{} }

namespace Characteristic {
  
  CREATE_CHAR(Active,uint8_t,0);
  CREATE_CHAR(AirQuality,uint8_t,0);
  CREATE_CHAR(Brightness,int,0);
  CREATE_CHAR(ColorTemperature,uint32_t,50);
  CREATE_CHAR(CurrentDoorState,uint8_t,1);
  CREATE_CHAR(CurrentPosition,uint8_t,0);
  CREATE_CHAR(CurrentTemperature,double,0);
  CREATE_CHAR(FirmwareRevision,char *,"");
  CREATE_CHAR(HoldPosition,boolean,false);
  CREATE_CHAR(Hue,double,0);
  CREATE_CHAR(Identify,boolean,false);
  CREATE_CHAR(Manufacturer,char *,"");
  CREATE_CHAR(Model,char *,"");
  CREATE_CHAR(Name,char *,"");
  CREATE_CHAR(NitrogenDioxideDensity,double,0);
  CREATE_CHAR(ObstructionDetected,boolean,false);
  CREATE_CHAR(On,boolean,false);
  CREATE_CHAR(OutletInUse,boolean,false);
  CREATE_CHAR(OzoneDensity,double,0);
  CREATE_CHAR(PM10Density,double,0);
  CREATE_CHAR(PM25Density,double,0);
  CREATE_CHAR(PositionState,uint8_t,2);
  CREATE_CHAR(RotationDirection,int,0);
  CREATE_CHAR(RotationSpeed,double,0);
  CREATE_CHAR(Saturation,double,0);
  CREATE_CHAR(SerialNumber,char *,"");
  CREATE_CHAR(SlatType,uint8_t,0);
  CREATE_CHAR(SmokeDetected,uint8_t,0);
  CREATE_CHAR(StatusActive,boolean,true);
  CREATE_CHAR(StatusFault,uint8_t,0);
  CREATE_CHAR(StatusJammed,uint8_t,0);
  CREATE_CHAR(StatusLowBattery,uint8_t,0);
  CREATE_CHAR(StatusTampered,uint8_t,0);
  CREATE_CHAR(SulphurDioxideDensity,double,0);
  CREATE_CHAR(SwingMode,uint8_t,0);
  CREATE_CHAR(TargetDoorState,uint8_t,1);
  CREATE_CHAR(TargetPosition,uint8_t,0);
  CREATE_CHAR(TemperatureDisplayUnits,uint8_t,0);
  CREATE_CHAR(Version,char *,"");
  CREATE_CHAR(VOCDensity,double,0);

}
