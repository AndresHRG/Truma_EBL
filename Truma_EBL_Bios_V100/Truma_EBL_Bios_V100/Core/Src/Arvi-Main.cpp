#include <stdint.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include "Truma_EBL_Bios_V100.h"
#include "Lin.h"
#include "LinMaster.h"
#include "TopicsList.h"
#include "ErrorManager.h"
#include "Utils.h"
#include "Comm.h"

/****cabeceras de todos los topics****/
#include "EmptyingValve.h"
#include "EngineBattery1.h"
#include "ExternalLigths.h"
#include "FloorHeating.h"
#include "FreshWater_1.h"
#include "Fridge.h"
#include "Fuses.h"
#include "GrayWater_1.h"
#include "InternalLigths.h"
#include "Inverter.h"
#include "Multimedia.h"
#include "LeisureBattery1.h"
#include "Ligths_1.h"
#include "SolarRegulator1.h"
#include "WaterPump.h"
#include "GasBottle.h"
#include "EisExMode.h"


//COMMUNICATIONS
Lin* linInstance;
LinMaster* linMasterInstance;

//battery instance
LeisureBattery1* batteryInstance;
EngineBattery1* eBatteryIntance;

uint64_t updateTimeInfoFrames = 0;
uint64_t  checkVariantTime = 0;
uint8_t variant;


std::vector<SystemDevices*> devices;

void initCommunications()
{
	linInstance = new Lin();
	linMasterInstance = new LinMaster();
}

void initTopics()
{
	/***************************************/
	EngineBattery1* eBattery = new EngineBattery1(EngineBattery1_Type);
	
	if(eBattery!= NULL)
	{
		devices.push_back(eBattery);
		linInstance->addClients(eBattery);
		eBatteryIntance = eBattery;
	}
	/***************************************/
	
	FreshWater1* freshWater = new FreshWater1(FreshWater1_Type);
	
	if(freshWater!= NULL)
	{
		devices.push_back(freshWater);
		linInstance->addClients(freshWater);
	}
	
	/***************************************/
	
	Fuses* fuse = new Fuses(Fuses_Type);
	
	if(fuse != NULL)
	{
		devices.push_back(fuse);
		linInstance->addClients(fuse);
	}
	/***************************************/
	
	GrayWater1* grayWater = new GrayWater1(GrayWater1_Type);
	
	if(grayWater  != NULL)
	{
		devices.push_back(grayWater);
		linInstance->addClients(grayWater);
	}
	/***************************************/
	
	InternalLigths* iLights = new InternalLigths(InternalLigths_Type);
	
	if(iLights != NULL)
	{
		devices.push_back(iLights);
		linInstance->addClients(iLights);
	}
	/***************************************/
	
	ExternalLigths* eLights = new ExternalLigths(ExternalLigths_Type);
	
	if(eLights != NULL)
	{
		devices.push_back(eLights);
		linInstance->addClients(eLights);
	}
	/***************************************/
	
	Ligths1* nLights = new Ligths1(Ligths1_Type);
	
	if(nLights != NULL)
	{
		devices.push_back(nLights);
		linInstance->addClients(nLights);
	}
	/***************************************/
	
	Inverter* inverter = new Inverter(Inverter_Type);
	
	if(inverter != NULL)
	{
		devices.push_back(inverter);
		linInstance->addClients(inverter);
		linMasterInstance->addClient(inverter);
	}
	/***************************************/
	
	Multimedia* multimedia = new Multimedia(Multimedia_Type);
	
	if(multimedia  != NULL)
	{
		devices.push_back(multimedia );
		linInstance->addClients(multimedia);
	}
	/***************************************/
	
	LeisureBattery1* leisureBatt = new LeisureBattery1(LeisureBattery1_Type);
	
	if(leisureBatt != NULL)
	{
		batteryInstance = leisureBatt;
		devices.push_back(leisureBatt);
		linInstance->addClients(leisureBatt);
		linMasterInstance->addClient(leisureBatt);
	}
	/***************************************/
	
	FloorHeating* floorHeating = new FloorHeating(FloorHeating_Type);
	
	if(floorHeating != NULL)
	{
		devices.push_back(floorHeating);
		linInstance->addClients(floorHeating);
	}
	/***************************************/
	
	Fridge* fridge = new Fridge(Fridge_Type);
	
	if(fridge != NULL)
	{
		devices.push_back(fridge);
		linInstance->addClients(fridge);
	}
	/***************************************/
	
	EmptyingValve* emptyValve = new EmptyingValve(EmptyingValve_Type);
	
	if(emptyValve != NULL)
	{
		devices.push_back(emptyValve);
		linInstance->addClients(emptyValve);
	}
	
	/***************************************/
	SolarRegulator1* solar = new SolarRegulator1(SolarRegulator1_Type);
	
	if(solar != NULL)
	{
		devices.push_back(solar);
		linInstance->addClients(solar);
		linMasterInstance->addClient(solar);
	}	
	
	/***************************************/
	WaterPump* waterPump = new WaterPump(WaterPump_Type);
	
	if(waterPump != NULL)
	{
		devices.push_back(waterPump);
		linInstance->addClients(waterPump);
	}
	/***************************************/
	GasBottle* gasBottle = new GasBottle(GasBottle_Type);
	
	if(gasBottle != NULL)
	{
		devices.push_back(gasBottle);
		linInstance->addClients(gasBottle);
	}
	/***************************************/
	EisExMode* eisExMode = new EisExMode(EisExMode_Type);
	
	if(eisExMode != NULL)
	{
		devices.push_back(eisExMode);
		linInstance->addClients(eisExMode);
	}
}

void checkVariant()
{
	variant = 1;
	ScanMultiplexores();
	
	if(ArviGet_AD(BLK5_6) >  255)// usamos de forma provisional esta entrada para cambio de variante 2.
		variant = 2;
	
	if(ArviGet_AD(BLK5_5) >  255)// usamos de forma provisional esta entrada para cambio de variante 3.
		variant = 3;
	
	if(ArviGet_AD(BLK5_1) >  255)// usamos de forma provisional esta entrada para cambio de variante 4.
		variant = 4;
}

void Arvi_Setup(void)
{
	initCommunications();
	checkVariant();
	initTopics();
}

void devicesState()
{
	for(const auto& device : devices)
	{
		device->updateState();
	}
}

void Arvi_Main(void)
{
	if((updateTimeInfoFrames < GetMilliSec()))
	{
		linInstance->updateInfoFrames();
		updateTimeInfoFrames = GetMilliSec() + 50;
	}
	
	if(checkVariantTime < GetMilliSec())
	{
		checkVariant();
		checkVariantTime = GetMilliSec() + 1000;
	}
	
	devicesState();
}

