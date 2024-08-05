/* *******************************************************************************
 *       @file              Devices.h
 *       @expl              Truma EBL
 *       @author            Andres Rivas
 *       @coauthor
 *       @Date:             15-02-2024
 *       @copyright         Arvimarine Control Systems SL "ARVIKON"
 *       @Programming mode  Survival Mode
 ********************************************************************************/
 
#ifndef _DEVICES_H_
#define _DEVICES_H_

#include <stdint.h>
#include "Enums.h"

enum DeviceType {
    ACSocket1_Type = 1,
    AESFridge_Type,
    AirConditioner1_Type,
    AuxGrC_Type,
    AuxGrD_Type,
    AuxOutPut_Type,
    Boiler_Type,
    Charger1_Type,
    DCDCBooster_Type,
    DFuses_Type,
    DoorStep_Type,
    DPlusOutputs_Type,
    DrainValve_Type,
    EmptyingValve_Type,
    EnergySpliter_Type,
    EngineBattery1_Type,
    ExternalLigths_Type,
    ExternalLigths2_Type,
    ExtraAuxGrC_Type,
    ExtraAuxGrH_Type,
    Fan_Type,
    FloorHeating_Type,
    FreshWater1_Type,
    Fridge_Type,
    Fuses_Type,
    GasAlarm1_Type,
    GasPiezo_Type,
    GrayTankHeating_Type,
    GrayWater1_Type,
    Heater_Type,
    HomeAlarm1_Type,
    IBSSensor1_Type,
    IBSSensor2_Type,
    InternalLigths_Type,
    Inverter_Type,
    LeisureBattery1_Type,
    Ligths1_Type,
    Ligths2_Type,
    Ligths3_Type,
    Ligths4_Type,
    Ligths5_Type,
    Ligths6_Type,
    Ligths7_Type,
    Ligths8_Type,
    Ligths9_Type,
    Ligths10_Type,
    Ligths11_Type,
    Ligths12_Type,
    LigthsGrA_Type,
    LigthsGrB_Type,
    LigthsGrC_Type,
    LigthsGrD_Type,
    LigthsGrE_Type,
    LigthsGrF_Type,
    LigthsGrH_Type,
    LigthsGrG_Type,
    MainSwitch_Type,
    Multimedia_Type,
    RoofVent1_Type,
    Sat_Type,
    SolarRegulator1_Type,
    TPMSSensor_Type,
    WaterPump_Type
};

class Devices
{
private:
    short idTopic;
public:
    Devices(short _idTopic);

    short getIdTopic();
    virtual void setOn() = 0;
    virtual void setOff() = 0;
    virtual void topicReceived(uint8_t* topic) = 0;
		virtual int getTopicState() = 0;
};

#endif /* _DEVICES_H_*/