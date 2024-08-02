#include "Lin.h"
#include "Truma_EBL_Bios_V100.h"
#include "string.h"
#include "Utils.h"
#include "Init.h"
#include "Enums.h"
#include "ErrorManager.h"
#include "LeisureBattery1.h"
#include "EngineBattery1.h"

extern LeisureBattery1* batteryInstance;
extern EngineBattery1* eBatteryIntance;

byte errorState[] = {0x7D, 0x7F, 0x06, 0xF2, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00};
byte identifier[] = {0x7D, 0x7F, 0x06, 0xF2, 0x17, 0x46, 0x00, 0x09, 0x00, 0x00};
byte firmware[] = {0x7D, 0x7F, 0x06, 0xF2, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00};

bool sendError = false;
short counterErrors = 1;

Lin::Lin(): CommunicationManager()
{
		Enable_LIN1	// HABILITAMOS DRV
		maxReceiveSize = 9;
		pReceive = 1;
		linstate = linHeader;
		eState = false;
		vFirmware = false;
		uint8_t readByte = 0;
		HAL_UART_Receive_IT(&huart1, &readByte, 1);
}

void Lin::composeMsgLin(unsigned char caracter) 
{
	switch (linstate) 
	{
		case linHeader:
		{
			if(caracter == BYTE_INICIO_LIN)// comprobar si el caracter es 0x55
			{
				memset(linBuffer, 0, SIZE_BUFFER_LIN);
				linstate = messageId;
			}
			else
				linstate = linHeader;
			
			break;
		}
	  case messageId:
		{
			linBuffer[0] = caracter;
			linstate = payLoad;
			verifyInfoFrame(caracter);
		  break;
		}
		case payLoad:
		{
			// ACUMULA EN EL LINBUFFER
			linBuffer[pReceive] = caracter;
		  pReceive++;
			
		  if (pReceive >= maxReceiveSize) 
			{
				pReceive = 1;
				linstate = crcLoad;
			}
			break;
		}
	  case crcLoad:
		{
			linstate = linHeader;	
			traslate2Topic(linBuffer);
			
			break;
		}
		default:
		{
			linstate = linHeader;	
			break;
		}
	}
	
}

void Lin::verifyInfoFrame(unsigned char caracter) 
{
	byte data[SIZE_BUFFER_LIN];
	
	switch(caracter)
	{
		case info_switchs:
		{
			memcpy(data, infoSwitch, SIZE_BUFFER_LIN);
			break;
		}
		case info_waterMng:
		{
			memcpy(data, infoWaterMng, SIZE_BUFFER_LIN);
			break;
		}
		case info_battMng:
		{
			memcpy(data, infoBatteryMng, SIZE_BUFFER_LIN);
			break;
		}
		case info_vehicleBatt :
		{
			memcpy(data, infoVehicleBatt, SIZE_BUFFER_LIN);
			break;
		}
		case info_leisure_batt1:
		{
			memcpy(data, infoLeisure1Batt, SIZE_BUFFER_LIN);
			break;
		}
		case info_leisure_batt2:
		{
			memcpy(data, infoLeisure2Batt, SIZE_BUFFER_LIN);
			break;
		}
		case info_controller:
		{
			if(eState)
			{
				memcpy(data, errorState, SIZE_BUFFER_LIN);
				eState = false;
				
				if(Errors::getNumErrors() > 0)
					sendError = true;
			}
			else if(sendError)
			{
				errors error = Errors::getError();
				
				errorState[2] = 0x20 + counterErrors;
				errorState[3] = error.classId;
				errorState[4] = error.code;
				errorState[5] = 0xFF;
				errorState[6] = 0xFF;
				errorState[7] = 0xFF;
				errorState[8] = 0xFF;
				
				memcpy(data, errorState, SIZE_BUFFER_LIN);
				counterErrors++;
				
				if(counterErrors > Errors::getNumErrors())
					counterErrors = 1;

			}
			else if(vFirmware)
			{
				memcpy(data, firmware, SIZE_BUFFER_LIN);
			}
			else
			{
				memcpy(data, identifier, SIZE_BUFFER_LIN);
			}
		
			data[9] = this->calculateCheckSum(data, 8); // crc
			break;
		}
		default:
		{
			linstate = payLoad;
			return;
		}
	}
	linstate = linHeader;
	this->sendFrame(data);
}

void Lin::traslate2Topic(unsigned char* frame)
{
	uint8_t topic[2] = {0,0};
	
	switch(frame[0])
	{
		case controller:
		{
			eState = false;
			vFirmware = false;
			
			if(frame[4] == 0x20)
			{
				vFirmware = true;
			}
			else if(frame[4] == 0x23) //comprobamos si el frame es de error o identificacion
			{
				eState = true;
				
				if(Errors::getNumErrors() > 0)
				{
					errorState[2] = 0x10;
					errorState[3] = 0x17;
					errorState[4] = 0xF2;
					errorState[5] = 0x03;//Format
					errorState[6] = Errors::getNumErrors();
					errorState[7] = 0xFF;
					errorState[8] = 0xFF;
				}
				else
				{
					sendError = false;
					errorState[2] = 0x06;
					errorState[3] = 0xF2;
					errorState[4] = 0x02;//Format
					errorState[5] = 0x00;
					errorState[6] = 0x00; 
					errorState[7] = 0x00;
					errorState[8] = 0x00;
					errorState[9] = 0x00;
				}
			}
			
			break;
		}
		case ctrl_switchs :
		{
			uint8_t iLigths = (frame[1] & 0xC0) >> 6;
			uint8_t eLigths = (frame[2] & 0x03);
			uint8_t nligths = (frame[2] &0x0C) >> 2;
			uint8_t eligths2 = (frame[2] & 0x30) >> 4;
			uint8_t radio = (frame[2] & 0xC0) >> 6;
			uint8_t tv = (frame[3] & 0x03);
			uint8_t satellite = (frame[3] & 0x0C) >> 2;
			uint8_t awning = (frame[3] & 0x30) >> 4;
			uint8_t fridge = (frame[3] & 0xC0) >> 6;
			uint8_t stoveIgnition = (frame[4] & 0x03);
			uint8_t floorHeating = (frame[4] & 0x0C) >> 2;
			uint8_t power12v = (frame[5] & 0x03);
			uint8_t power230v = (frame[5] & 0x0C) >> 2;
			uint8_t mainSwitch = (frame[5] & 0x30) >> 4;
			uint8_t fairMode = (frame[5] & 0xC0) >> 6;
			uint8_t multimedia = (frame[6] & 0x03);
			uint8_t waterPump = (frame[7] & 0x03);
			uint8_t emptyValve = (frame[7] & 0x0C) >> 2;
			uint8_t doorStep = (frame[8] & 0x30) >> 4;
			
			topic[0] = InternalLigths_Type; 
			topic[1] = iLigths;
			this->processTopic(topic);
			
			topic[0] = ExternalLigths_Type; 
			topic[1] = eLigths;
			this->processTopic(topic);
			
			topic[0] = Ligths1_Type;//Simula nigth ligths
			topic[1] = nligths;
			this->processTopic(topic);
			
			topic[0] = ExternalLigths2_Type;
			topic[1] = eligths2;
			//this->processTopic(topic);
			
			topic[0] = Ligths9_Type;//Simula Radio
			topic[1] = radio;
			//this->processTopic(topic);
			
			topic[0] = Ligths7_Type; //Simula TV
			topic[1] = tv;
			//this->processTopic(topic);
			
			topic[0] = Sat_Type;
			topic[1] = satellite;
			//this->processTopic(topic);
			
			topic[0] = Ligths8_Type;// Simula awning
			topic[1] = awning;
			//this->processTopic(topic);
			
			topic[0] = Fridge_Type;
			topic[1] = fridge;
			//this->processTopic(topic);
			
			topic[0] = Ligths10_Type;// Simula stove ignition;
			topic[1] = stoveIgnition;
			//this->processTopic(topic);
			
			topic[0] = FloorHeating_Type; // Comprobar cual sera el valor que corresponde realmente
			topic[1] = floorHeating;
			this->processTopic(topic);
			
			topic[0] = Ligths2_Type;// Simula power 12v;
			topic[1] = power12v;
			//this->processTopic(topic);
			
			topic[0] = Ligths3_Type;// Simula power 230v;
			topic[1] = power230v;
			//this->processTopic(topic);
			
			topic[0] = MainSwitch_Type;
			topic[1] = mainSwitch;
			//this->processTopic(topic);
			
			topic[0] = Ligths4_Type;// Simula fair mode;
			topic[1] = fairMode;
			//this->processTopic(topic);
			
			topic[0] = Multimedia_Type;
			topic[1] = multimedia;
			this->processTopic(topic);
			
			topic[0] = WaterPump_Type;
			topic[1] = waterPump;
			this->processTopic(topic);
			
			topic[0] = EmptyingValve_Type;
			topic[1] = emptyValve;
			this->processTopic(topic);
			
			topic[0] = DoorStep_Type;
			topic[1] = doorStep;
			//this->processTopic(topic);
			
			break;
		}
		case ctrl_waterMng:
		{ 
			uint8_t measureFWater = frame[1] & 0x03;
			uint8_t measureGWater = (frame[1] & 0x06) >> 2;
			
			topic[0] = FreshWater1_Type; //23; // Comprobar cual sera el valor que corresponde realmente
			topic[1] = measureFWater; 
			this->processTopic(topic);
			
			topic[0] = GrayWater1_Type;//29; // Comprobar cual sera el valor que corresponde realmente
			topic[1] = measureGWater; 
			this->processTopic(topic);
			
			break;
		}
		case ctrl_battMng:
		{
			uint8_t inverter = frame[1] & 0x03;
			
			topic[0] = 35; // Comprobar cual sera el valor que corresponde realmente
			topic[1] = inverter; 
			this->processTopic(topic);
			break;
		}
		case ctrl_batt_properties :
		default:
		{
			break;
		}
	}
	
}

void Lin::sendFrame(unsigned char* frame, short sizeBuffer)
{
	Tx_UART1(frame+1, sizeBuffer);
}

void Lin::updateInfoFrames()
{
	{
			
		memset(infoSwitch,0, SIZE_BUFFER_LIN);
	
		infoSwitch[0] = info_switchs;//id msg info

		//representa byte 0 de la doc
		infoSwitch[1] |= Utils::setBits(0, 1, _ni);
		infoSwitch[1] |= Utils::setBits(2, 3, _ni);
		infoSwitch[1] |= Utils::setBits(4, 5, _ni);
		infoSwitch[1] |= Utils::setBits(6, 7, this->getTopicState(InternalLigths_Type)); //iligths
	
		//representa byte 1 de la doc
		infoSwitch[2] |= Utils::setBits(0, 1, this->getTopicState(ExternalLigths_Type));//eligths
		infoSwitch[2] |= Utils::setBits(2, 3, this->getTopicState(Ligths1_Type));//ligth1 simula nigth_ligths
		infoSwitch[2] |= Utils::setBits(4, 5, _ni/*this->getTopicState(ExternalLigths2_Type)*/);//eligths2
		infoSwitch[2] |= Utils::setBits(6, 7, _ni);//ligth9 simula radio*/
		
		//representa byte 2 de la doc
		infoSwitch[3] =0xFF;
		/*infoSwitch[3] |= Utils::setBits(0, 1, _ni);//ligth7 simula tv
		infoSwitch[3] |= Utils::setBits(2, 3, _ni);//satellite
		infoSwitch[3] |= Utils::setBits(4, 5, _ni);//ligth8 simula Awning
		infoSwitch[3] |= Utils::setBits(6, 7, this->getTopicState(Fridge_Type));//fridge*/
		
		//representa byte 3 de la doc
	
		infoSwitch[4] |= Utils::setBits(0, 1, _ni);//lihgt10 simula stove_ignition
		infoSwitch[4] |= Utils::setBits(2, 3, this->getTopicState(FloorHeating_Type));//floorHeating
		infoSwitch[4] |= Utils::setBits(4, 5, _ni);
		infoSwitch[4] |= Utils::setBits(6, 7, _ni);
		
		//representa byte 4 de la doc
		infoSwitch[5] =0xFF;
		/*infoSwitch[5] |= Utils::setBits(0, 1, _ni);//ligth2 simula 12v power
		infoSwitch[5] |= Utils::setBits(2, 3, _ni);//ligth3 simula 230v power
		infoSwitch[5] |= Utils::setBits(4, 5, this->getTopicState(MainSwitch_Type));// mainSwitch
		infoSwitch[5] |= Utils::setBits(6, 7, this->getTopicState(Ligths4_Type));*/
		
		//representa byte 5 de la doc
		
		infoSwitch[6] |= Utils::setBits(0, 1, this->getTopicState(Multimedia_Type));//multimedia
		infoSwitch[6] |= Utils::setBits(2, 3, _ni);
		infoSwitch[6] |= Utils::setBits(4, 5, _ni);
		infoSwitch[6] |= Utils::setBits(6, 7, _ni);
		
		//representa byte 6 de la doc 
		infoSwitch[7] |= Utils::setBits(0, 1, this->getTopicState(WaterPump_Type));//fresh water pump
		infoSwitch[7] |= Utils::setBits(2, 3, this->getTopicState(EmptyingValve_Type));//gray water valve
		infoSwitch[7] |= Utils::setBits(4, 5, _ni);
		infoSwitch[7] |= Utils::setBits(6, 7, _ni);
		
		//representa byte 7 de la doc
		infoSwitch[8] =0xFF;
		/*infoSwitch[8] |= Utils::setBits(0, 1, _ni);
		infoSwitch[8] |= Utils::setBits(2, 3, _ni);
		infoSwitch[8] |= Utils::setBits(4, 5, this->getTopicState(DoorStep_Type));//doorStep
		infoSwitch[8] |= Utils::setBits(6, 7, _ni);*/
		
		infoSwitch[9] = this->calculateCheckSum(infoSwitch, 8, true);//crc
	}

	{
		infoWaterMng[0] = info_waterMng;
		infoWaterMng[1] = this->getTopicState(FreshWater1_Type);
		infoWaterMng[2] = this->getTopicState(GrayWater1_Type);
		infoWaterMng[3] = 0xFF;
		infoWaterMng[4] = 0xFF;
		infoWaterMng[5] = 0xFF;
		infoWaterMng[6] = 0xFF;
		infoWaterMng[7] = 0xFF;
		infoWaterMng[8] = 0x00;
		infoWaterMng[9] = this->calculateCheckSum(infoWaterMng, 8, true);//crc
	}

	{
		memset(infoVehicleBatt,0xFF, SIZE_BUFFER_LIN);
		
		infoVehicleBatt[0] = info_vehicleBatt;//id msg info
		infoVehicleBatt[1] = 0;
		infoVehicleBatt[2] = 0;
		infoVehicleBatt[3] = 0;
		infoVehicleBatt[4] = 0;
		//representa byte 0 de la doc
		infoVehicleBatt[1] |= Utils::setBits(0, 3, 0xF);// representa un ni de la doc
		
		short volts = eBatteryIntance->volts;
		infoVehicleBatt[1] |=  Utils::setBits(4, 7, volts & 0x000F);
		
		//representa byte 1 de la doc
		infoVehicleBatt[2] = (volts >> 4);
		int mAmp = (163830 - eBatteryIntance->mAmps);

		infoVehicleBatt[3] = mAmp & 0x00FF;
		infoVehicleBatt[4] = (mAmp & 0xFF00) >> 8;
		infoVehicleBatt[9] = this->calculateCheckSum(infoVehicleBatt, 8, true); //crc
	}

	{
		memset(infoLeisure1Batt,0xFF, SIZE_BUFFER_LIN);
	
		infoLeisure1Batt[0] = info_leisure_batt1;//id msg info
		infoLeisure1Batt[1] = 0;
		infoLeisure1Batt[1] |= Utils::setBits(0, 3, 0xF);// representa un ni de la doc;
		short volts = batteryInstance->volts;//this->getTopicState(36);
		infoLeisure1Batt[1] |= Utils::setBits(4, 7, volts & 0x000F);
		infoLeisure1Batt[2] = (volts >> 4);
		int mAmp = 163830 - batteryInstance->mAmps; //(163830 - ArviGet_mA(DRV)/10);

		infoLeisure1Batt[3] = mAmp & 0x00FF;
		infoLeisure1Batt[4] = (mAmp & 0xFF00) >> 8;
		short soc = batteryInstance->soc;
		infoLeisure1Batt[5] = (soc < 0) ? 0xFE : soc;
		infoLeisure1Batt[9] = this->calculateCheckSum(infoLeisure1Batt, 8, true);//crc
	}
	
	{
		memset(infoLeisure2Batt, 0xFF, SIZE_BUFFER_LIN);
	
		infoLeisure2Batt[0] = info_leisure_batt2;//id msg info
		infoLeisure2Batt[9] = this->calculateCheckSum(infoLeisure2Batt, 8,true); //crc
	}
	
	{
		memset(infoBatteryMng, 0, SIZE_BUFFER_LIN);
		
		infoBatteryMng[0] = info_battMng;//id msg info9
		//representa byte 0 de la doc
		infoBatteryMng[1] |= Utils::setBits(0, 1, this->getTopicState(Inverter_Type));
		infoBatteryMng[1] |= Utils::setBits(2, 3, _ni);
		infoBatteryMng[1] |= Utils::setBits(4, 5, _ni);
		infoBatteryMng[1] |= Utils::setBits(6, 7, _ni);
		int mAmps = this->getTopicState(SolarRegulator1_Type);
		infoBatteryMng[3] = mAmps & 0x00FF;
		infoBatteryMng[4] = mAmps >> 8;
		infoBatteryMng[5] = 0xFE;
		infoBatteryMng[6] = 0xFF;
		infoBatteryMng[7] = 0xFF;
		infoBatteryMng[8] = 0xFF;
		infoBatteryMng[9] = this->calculateCheckSum(infoBatteryMng, 8, true); // crc
	}
}

uint8_t Lin::calculateCheckSum(unsigned char* data, short length, bool enhancedMode)
{
	unsigned short sum = 0;// por defecto se realiza el calculo en Modo Classic.
	
	if(enhancedMode)
		sum = data[0]; //Tomamos en cuenta el identificador del frame para hacer el calculo en Modo Enhanced

	// realizamos calculo de crc
	for (int i = 1; i <= length; i++)
			sum = (sum + data[i]);
	
	return (0xFF - ((sum >> 8) + sum));
	
}

