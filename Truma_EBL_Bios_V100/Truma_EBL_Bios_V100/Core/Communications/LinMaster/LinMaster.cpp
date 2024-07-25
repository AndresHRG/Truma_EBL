#include "LinMaster.h"
#include "Truma_EBL_Bios_V100.h"
#include "string.h"
#include "Utils.h"
#include "Init.h"
#include "Lin.h"

extern LinMaster* linMasterInstance;
extern Lin* linInstance;
uint8_t readByteU1;
uint8_t readByteU3;
linStates linstate;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if (huart->Instance == USART3)
	{
		linMasterInstance->composeMsgLin(readByteU3);
		HAL_UART_Receive_IT(&huart3, &readByteU3, 1);
	}
	else if (huart->Instance == USART1)
	{
		linInstance->composeMsgLin(readByteU1);
		HAL_UART_Receive_IT(&huart1, &readByteU1, 1);
	}
}

LinMaster::LinMaster()
{
		ArviSet(LIN_BLK9_A,1);// HABILITAMOS DRV
    linstate = linHeader;
		maxReceiveSize = 9;
		pReceive = 1;
		HAL_UART_Receive_IT(&huart3, &readByteU3, 1);
}
    
void LinMaster::addClient(LinClients* client)
{
    clients.push_back(client);
}

void LinMaster::scanBus()
{
	uint8_t readByte;
	
	if(HAL_UART_Receive(&huart3, &readByte, 1, 1) == HAL_OK)
	{
			composeMsgLin(readByte);	
  }
}

void LinMaster::composeMsgLin (uint8_t byte)
{
	if(byte == 0x55)// comprobar si el caracter es 0x55
	{
		memset(linBuffer, 0, 10);
		linstate = messageId;
		pReceive = 1;
		return;
	}
	
  switch (linstate) 
	{
		case linHeader:
		{
			linstate = linHeader;
			break;
		}
	  case messageId:
		{
			linBuffer[0] = byte;
			linstate = payLoad;
		  break;
		}
		case payLoad:
		{
			// ACUMULA EN EL LINBUFFER
		  linBuffer[pReceive] = byte;
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
			processInfoFrame(linBuffer);
			break;
		}
		default:
		{
			linstate = linHeader;	
			break;
		}
	}
}

void LinMaster::processInfoFrame(uint8_t* frame)
{
	uint8_t idInfo = frame[0];
	
	for(int i = 0; i < clients.size(); i++)
	{
		if(clients[i]->verifyIdInfo(idInfo))
		{
			clients[i]->processInfoFrame(frame+1);
		}
	}
}

uint8_t LinMaster::calculateCheckSum(uint8_t* data, short length)
{
    unsigned short sum = 0;
	sum = data[0]; 

	// realizamos calculo de crc
	for (int i = 1; i <= length; i++)
			sum = (sum + data[i]);
	
	return (0xFF - ((sum >> 8) + sum));
}

uint8_t LinMaster::idCalc(uint8_t idMsg)
{
    uint8_t p, P0, P1, conv0, conv1;
    p = idMsg;
    
		P0 = (p & 1) ^ ((p & 2) >> 1) ^ ((p & 4) >> 2) ^ ((p & 16) >> 4);
		conv0 = (P0 << 6);
	
		P1 = ((p & 2) >> 1) ^ ((p & 8) >> 3) ^ ((p & 16) >> 4) ^ ((p & 32) >> 5);
    
		if (P1)
			conv1 = 0;
    else
      conv1 = 0x80;
		
		return (idMsg | conv0 | conv1);
}

void LinMaster::sendControlFrame(uint8_t* frame, uint8_t sizeBuffer)
{
		uint8_t byteSync = 0x55;
    MX_USART3_UART_Init();
    HAL_LIN_SendBreak(&huart3);
    
    HAL_UART_Transmit(&huart3, &byteSync, 1, 1); //enviamos byte de sincronizacion
    HAL_UART_Transmit(&huart3,(uint8_t*)&frame[0], 1, 1);
    
    for(int i = 1; i < sizeBuffer; i++)
    {
        HAL_UART_Transmit(&huart3,(uint8_t*)&frame[i], 1, 1); // enviamos frame entero de control (incluye id y checksum)
    }

}

void LinMaster::sendInfoFrame(uint8_t idInfo)
{
    uint8_t byteSync = 0x55; // byte de sincronizacion de protocolo lin
		uint8_t readByte = 0;
		int i = 0;
		uint8_t buffer[10];
		memset(buffer,0,10);

		HAL_LIN_SendBreak(&huart3);

		HAL_UART_Transmit(&huart3, &byteSync, 1, 1); //enviamos byte de sincronizacion
		HAL_UART_Transmit(&huart3, &idInfo, 1, 1); //inmediatamente esperamos respuesta del equipo
	
}
