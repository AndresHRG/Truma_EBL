#include <stdlib.h>
#include <stdbool.h>

#include "main.h"
#include "Analog.h"
#include "Truma_EBL_Bios_V100.h"

uint16_t Conversion_MUX_FUSE_1[8];
uint16_t Conversion_MUX_FUSE_2[8];
uint16_t Conversion_MUX_LIGHT[8];
uint16_t Conversion_MUX_WATER[8];
uint16_t Conversion_MUX_CS[8];

uint16_t convAD1[2];
uint16_t convAD2[9];

void Scan_AD_Mux(unsigned char Canal)
{
	Conversion_MUX_FUSE_1[Canal] = convAD2[8];
	Conversion_MUX_FUSE_2[Canal] = convAD2[6];
	Conversion_MUX_LIGHT[Canal] = convAD2[7];
	Conversion_MUX_WATER[Canal] = convAD2[0];
	Conversion_MUX_CS[Canal] = convAD2[1];
}

void Set_Ctrl_Mux (unsigned char canal)
{
	HAL_GPIO_WritePin(MUX_A_GPIO_Port, MUX_A_Pin, (canal & 0x01));
	HAL_GPIO_WritePin(MUX_B_GPIO_Port, MUX_B_Pin, (canal & 0x02));
	HAL_GPIO_WritePin(MUX_C_GPIO_Port, MUX_C_Pin, (canal & 0x04));
}

void ScanMultiplexores(void)
{
static unsigned char CanalMux=0;
	
	Scan_AD_Mux(CanalMux);
	CanalMux++;
	Set_Ctrl_Mux(CanalMux);
	
	if(CanalMux >= 8)CanalMux=0;
}

uint16_t ArviGet_AD(uint8_t Component)
{
	uint16_t Ret=0xFFFF;

	switch (Component)
	{
		case BLK1_1:
			Ret = Conversion_MUX_CS[2];
		break;	
		case BLK1_2:
			Ret = Conversion_MUX_CS[1];
		break;	
		case BLK10_2:
			Ret = Conversion_MUX_CS[3];
		break;	
		case BLK10_3:
			Ret = convAD2[3];
		break;	
		case BLK3_1:
			Ret = Conversion_MUX_CS[0];
		break;	
		case BLK5_1:
			Ret = Conversion_MUX_LIGHT[4];
		break;	
		case BLK5_2:
			Ret = Conversion_MUX_LIGHT[6];
		break;	
		case BLK5_3:
			Ret = Conversion_MUX_LIGHT[3];
		break;	
		case BLK5_4:
			Ret = Conversion_MUX_LIGHT[0];
		break;	
		case BLK5_5:
			Ret = Conversion_MUX_LIGHT[1];
		break;	
		case BLK5_6:
			Ret = Conversion_MUX_LIGHT[2];
		break;	
		case BLK6_C_2:
			Ret = Conversion_MUX_WATER[3];
		break;	
		case BLK6_C_3:
			Ret = Conversion_MUX_WATER[0];
		break;	
		case BLK6_C_4:
			Ret = Conversion_MUX_WATER[1];
		break;	
		case BLK6_C_5:
			Ret = Conversion_MUX_WATER[2];
		break;	
		case BLK7_C_2:
			Ret = Conversion_MUX_WATER[4];
		break;	
		case BLK7_C_3:
			Ret = Conversion_MUX_WATER[6];
		break;	
		case BLK7_C_4:
			Ret = Conversion_MUX_WATER[7];
		break;	
		case BLK7_C_5:
			Ret = Conversion_MUX_WATER[5];
		break;	
		case BLK6_A:
			Ret = Conversion_MUX_CS[7];
		break;	
		case BLK7_A:
			Ret = Conversion_MUX_CS[4];
		break;	
		case BLK6_B:
			Ret = Conversion_MUX_CS[5];
		break;	
		case BLK7_B:
			Ret = Conversion_MUX_CS[6];
		break;	
		case DRV:
			Ret = convAD1[1];
		break;
		case BAT_2:
			Ret = convAD2[4];
		break;	
		case BAT_M:
			Ret = convAD2[5];
		break;			
		default:
		break;	
	}
	return Ret;
}

float ArviGet_mV(uint8_t Component)
{
	float Ret=999999;

	switch (Component)
	{
		case BLK6_B:
			Ret = (float)Conversion_MUX_CS[5] * 10.3;
			if(Ret > 10500)Ret = 999998;
		break;	
		case BLK7_B:
			Ret = (float)Conversion_MUX_CS[6] * 10.3;
			if(Ret > 10500)Ret = 999998;
		break;	
		case BAT_2:
			Ret = (float)convAD2[4] * 17.3;
			if(Ret > 17000)Ret = 999998;
		break;	
		case BAT_M:
			Ret = (float)convAD2[5] * 17.1;
			if(Ret > 17000)Ret = 999998;
		break;	
		default:
		break;	
	}
	return Ret;
}

float ArviGet_mA(uint8_t Component)
{
	float Ret=999999;

	switch (Component)
	{
		case BLK6_B:
			Ret = (float)Conversion_MUX_CS[5] * 20.5;
			if(Ret > 20500)Ret = 999998;
		break;	
		case BLK7_B:
			Ret = (float)Conversion_MUX_CS[6] * 20.5;
			if(Ret > 20500)Ret = 999998;
		break;	
		case BLK1_1:
			Ret = (float)Conversion_MUX_CS[2] * 36.6;
			if(Ret > 20500)Ret = 999998;
		break;	
		case BLK1_2:
			Ret = (float)Conversion_MUX_CS[1] * 36.6;
			if(Ret > 20500)Ret = 999998;
		break;	
		case DRV:
			Ret = (float)convAD1[1] * 63.8;
		break;	
		default:
		break;	
	}
	return Ret;
}





