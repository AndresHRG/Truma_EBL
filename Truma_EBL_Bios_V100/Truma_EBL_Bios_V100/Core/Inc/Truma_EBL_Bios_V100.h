#ifndef __TRUMA_EBL_BIOS_V100_H
#define __TRUMA_EBL_BIOS_V100_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

uint64_t GetMilliSec(void);				//Devuelve los milisegundos transcurridos desde el inicio (64 bits)

uint8_t ArviGet(uint8_t Component);		//Devuelve estados de de componentes determinados
										//Pines 
										//Retorno: 0-off 1-on
										//Fusibles
										//Retorno: 0-normal 1-abierto
										//Error
										//Retorno: 2- Componente no corresponde

uint8_t ArviSet(uint8_t Component, uint8_t Value);		//Setea valores en componentes determinados
														//Pines
														//Valor: 0-Reset 1-Set
														//Retorno: 0-Normal 1-Componente no corresponde

uint16_t ArviGet_AD(uint8_t Component);	//Devuelve valores crudos de los conversores A/D
										//En el caso de la lectura del sensor 0-190 Ohms 3FF indica sensor desconectado o abierto 

float ArviGet_mV(uint8_t Component);	//Devuelve valores analógicos de determinados componentes en formato de mili Volt
										//Retorno: 9999-Componente no corresponde	9998-Valor fuera de rango
float ArviGet_mA(uint8_t Component);	//Devuelve valores analógicos de determinados componentes en formato de mili Amper
										//Retorno: 9999-Componente no corresponde	9998-Valor fuera de rango	

int16_t Get_IMU_Data(uint8_t Channel);	//Devuelve datos del modulo inercial (temperatura, aceleración y posición giroscópica)(Raw)
float Get_IMU_Data_f(uint8_t Channel);	//Idem anterior en formato de número flotante con punto medio o de reposo

void Arvi_printf(char *s,...);

void Tx_UART1(uint8_t *Data, uint8_t Len);
void Tx_UART2(uint8_t *Data, uint8_t Len);
void Tx_UART3(uint8_t *Data, uint8_t Len);
void Tx_CAN(void);

uint8_t Rx_UART1(uint8_t Data);

enum eComponentNum
{
	BLK1_1 = 1,	//Entrada cargador
	BLK1_2,			//Entrada solar
	BLK2_3,			//Salida
	BLK3_1,			//Salida
	BLK3_2,			//Salida
	BLK3_3,			//Salida
	BLK3_4,			//Salida
	BLK3_5,			//Salida
	BLK3_6,			//Salida
	BLK3_7,			//Salida
	BLK3_8,			//Salida
	BLK3_9,			//Salida
	BLK3_10,		//Salida
	BLK3_11,		//Salida
	BLK3_12,		//Entrada para medición de batería de motor
	BLK4,			  //Salida D+
	BLK5_1,			//Entrada luces
	BLK5_2,			//Entrada luces
	BLK5_3,			//Entrada luces
	BLK5_4,			//Entrada luces
	BLK5_5,			//Entrada luces
	BLK5_6,			//Entrada luces
	BLK6_A,			//Entrada 0-190
	BLK6_B,			//Entrada 4-20mA
	BLK6_C_1,		//Común bloque 6-C
	BLK6_C_2,		//Entrada aguas
	BLK6_C_3,		//Entrada aguas
	BLK6_C_4,		//Entrada aguas
	BLK6_C_5,		//Entrada aguas
	BLK7_A,			//Entrada 0-190
	BLK7_B,			//Entrada 4-20mA
	BLK7_C_1,		//Común bloque 7-C
	BLK7_C_2,		//Entrada aguas
	BLK7_C_3,		//Entrada aguas
	BLK7_C_4,		//Entrada aguas
	BLK7_C_5,		//Entrada aguas
	BLK10_1,		//Entrada D+
	BLK10_2,		//Entrada
	BLK10_3,		//Entrada
	BLK11_1,		//Salida
	BLK11_2,		//Salida
	BLK11_3,		//Salida
	BLK11_4,		//Salida
	BLK11_5,		//Salida
	BLK11_6,		//Salida
	BLK11_7,		//Salida
	BLK11_9,		//Salida
	DRV,			//Driver principal
	RELAY,
	FUSE1,
	FUSE3,
	FUSE4,
	FUSE5,
	FUSE6,
	FUSE7,
	FUSE8,
	FUSE9,
	FUSE10,
	FUSE11,
	FUSE12,
	FUSE13,
	FUSE14,
	LED,
	LIN_BLK9_A,		//LIN2
	LIN_BLK9_B,		//LIN1
	BAT_M,			//voltaje de batería motor BLK3_12
	BAT_2,			//voltaje en el borne de batería
};	

void Arvi_Setup(void);
void Arvi_Main(void);

extern bool variant;


#ifdef __cplusplus
}
#endif

#endif /* __TRUMA_EBL_BIOS_V100_H */


