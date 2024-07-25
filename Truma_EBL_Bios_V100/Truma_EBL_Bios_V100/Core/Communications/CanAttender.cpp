#include "CanAttender.h"
#include "Init.h"
#include "Utils.h"
#include "Truma_EBL_Bios_V100.h"
#include "ErrorManager.h"
#include <vector>


#define ARVI_CORE_LITE 0x02
#define ARDUINO 0x01
#define SIZE_BUFFER 8

extern UART_HandleTypeDef huart1;// usamos para debug
//extern stDrvCAN DrvCAN;

std::vector<uint8_t*> queueMsgCan;

/****Funciones especiales de CAN****/
void addMsg2CanQueue(uint8_t* msg)
{
	queueMsgCan.push_back(msg);
}

uint8_t* getMsgCanQueue()
{
	uint8_t buffer[SIZE_BUFFER];
	
	memset(buffer, 0, SIZE_BUFFER);
	
	if(!queueMsgCan.empty())
	{
		memcpy(buffer, queueMsgCan[0], SIZE_BUFFER),
		queueMsgCan.erase(queueMsgCan.begin());
	}

	return buffer;
	
}
/***********************************/

CanAttender::CanAttender() : CommunicationManager()
{
	//ArviSet(CAN_TERM, 1);
	/*DrvCAN.TxDLC = 8;
	DrvCAN.TxExtID = 0;
	DrvCAN.TxStdID = ARVI_CORE_LITE;*/
}

void CanAttender::sendCanMsg(uint8_t* msg)
{
	/*if(Utils::emptyBuffer((char*)msg))//proteccion ante mensajes vacios
			return;
	
	memcpy(DrvCAN.TxData, msg, SIZE_BUFFER);

	//ArviSet(LED_VD_B7, 1);// Led indicador de envio de mensajes
	Tx_CAN();
	
	Utils::delay_ms(5);*/
}

uint8_t* CanAttender::receiveCanMsg()
{
	return getMsgCanQueue();
}

void CanAttender::msgIdentifier()
{
		uint8_t* msg = receiveCanMsg();
	
		if(Utils::emptyBuffer((char*)msg)) //proteccion ante mensajes vacios
      return;
    
	/*	if(DrvCAN.RxStdID != ARDUINO) //verificamos si el mensaje es para nosotros
			return;*/
		
		this->traslate2Topic(msg);
		//ArviSet(LED_AM_B7, 1);// Led indicador de recepcion de mensajes
}

void CanAttender::alive()
{
		//enviamos mensaje para indicar que estamos vivos
		uint8_t msg[]= {255,255,255,255,255,255,255,255};// definir estructura adecuada para este mensaje
		sendCanMsg(msg);
}

void CanAttender::traslate2Topic(uint8_t* msg)
{
	uint8_t topic[2];
	
	/*if(msg[0] == 0) // proteccion ante mensajes basura
		return;*/
	
	topic[0] = msg[0]; // id device
	topic[1] = msg[3]; // Action
	
	this->processTopic(topic);
}
