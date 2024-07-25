#include <stdlib.h>
#include <stdbool.h>
#include "main.h"
#include "Init.h"
#include "Digital.h"
#include "Analog.h"
#include "Comm.h"
#include "Truma_EBL_Bios_V100.h"

uint8_t ArviSet(uint8_t Component, uint8_t Value)
{
	uint8_t Ret=0, Value_IO;
		
	switch (Component)
	{
		case BLK1_1:
			if(Value)OnBLK1_1
			else OffBLK1_1
		break;	
		case BLK1_2:
			if(Value)OnBLK1_2
			else OffBLK1_2
		break;	
		case BLK3_1:
			Value_IO = Read_IO_Expander();
			if(Value)Write_IO_Expander(Value_IO | 0x01<<4);
			else Write_IO_Expander(Value_IO & ~(0x01<<4));
		break;	
		case BLK3_2:
			Value_IO = Read_IO_Expander();
			if(Value)Write_IO_Expander(Value_IO | 0x01<<5);
			else Write_IO_Expander(Value_IO & ~(0x01<<5));
		break;	
		case BLK3_3:
			Value_IO = Read_IO_Expander();
			if(Value)Write_IO_Expander(Value_IO | 0x01<<7);
			else Write_IO_Expander(Value_IO & ~(0x01<<7));
		break;	
		case BLK3_4:
		case BLK3_5:
		case BLK3_6:
			Value_IO = Read_IO_Expander();
			if(Value)Write_IO_Expander(Value_IO | 0x01<<2);
			else Write_IO_Expander(Value_IO & ~(0x01<<2));
		break;	
		case BLK3_7:
		case BLK3_8:
		case BLK3_9:
			Value_IO = Read_IO_Expander();
			if(Value)Write_IO_Expander(Value_IO | 0x01<<6);
			else Write_IO_Expander(Value_IO & ~(0x01<<6));
		break;	
		case BLK3_10:
			Value_IO = Read_IO_Expander();
			if(Value)Write_IO_Expander(Value_IO | 0x01<<3);
			else Write_IO_Expander(Value_IO & ~(0x01<<3));
		break;	
		case BLK3_11:
			Value_IO = Read_IO_Expander();
			if(Value)Write_IO_Expander(Value_IO | 0x01<<0);
			else Write_IO_Expander(Value_IO & ~(0x01<<0));
		break;	
		case BLK4:
			if(Value)OnOUT_D
			else OffOUT_D
		break;	
		case BLK6_C_1:
		case BLK7_C_1:
			if(Value)Enable_Sens
			else Disable_Sens
		break;	
		case BLK11_1:
			if(Value)OnBLK11_1
			else OffBLK11_1
		break;	
		case BLK11_2:
			if(Value)OnBLK11_2
			else OffBLK11_2
		break;	
		case BLK11_3:
			if(Value)OnBLK11_3
			else OffBLK11_3
		break;	
		case BLK11_4:
			if(Value)OnBLK11_4
			else OffBLK11_4
		break;	
		case BLK11_5:
			if(Value)OnBLK11_5
			else OffBLK11_5
		break;	
		case BLK11_6:
			if(Value)OnBLK11_6
			else OffBLK11_6
		break;	
		case BLK11_7:
			if(Value)OnBLK11_7
			else OffBLK11_7
		break;	
		case BLK11_9:
			if(Value)OnBLK11_9
			else OffBLK11_9
		break;	
		case DRV:
			if(Value)OnDRV
			else OffDRV
		break;	
		case RELAY:
			if(Value)OnREL
			else OffREL
		break;	
		default:
			Ret=1;
		break;	
	}
	return Ret;
}

uint8_t ArviGet(uint8_t Component)
{
#define THR_LIGHT	0x100
#define THR_WATER	0x100
#define FUSE_HIST	0x80

	uint8_t Ret=2;

	switch (Component)
	{
		case BLK1_1:
			Ret = HAL_GPIO_ReadPin(ON_BLK1_1_GPIO_Port, ON_BLK1_1_Pin);
		break;	
		case BLK1_2:
			Ret = HAL_GPIO_ReadPin(ON_BLK1_2_GPIO_Port, ON_BLK1_2_Pin);
		break;	
		case BLK4:
			Ret = HAL_GPIO_ReadPin(OUT_D_GPIO_Port, OUT_D_Pin);
		break;	
		case BLK3_1:
			Ret = (Read_IO_Expander() & 0x01<<4)>>4;
		break;	
		case BLK3_2:
			Ret = (Read_IO_Expander() & 0x01<<5)>>5;
		break;	
		case BLK3_3:
			Ret = (Read_IO_Expander() & 0x01<<7)>>7;
		break;	
		case BLK3_4:
		case BLK3_5:
		case BLK3_6:
			Ret = (Read_IO_Expander() & 0x01<<2)>>2;
		break;	
		case BLK3_7:
		case BLK3_8:
		case BLK3_9:
			Ret = (Read_IO_Expander() & 0x01<<6)>>6;
		break;	
		case BLK3_10:
			Ret = (Read_IO_Expander() & 0x01<<3)>>3;
		break;	
		case BLK3_11:
			Ret = (Read_IO_Expander() & 0x01<<0)>>0;
		break;	
		case BLK11_1:
			Ret = HAL_GPIO_ReadPin(BLK11_1_GPIO_Port, BLK11_1_Pin);
		break;	
		case BLK11_2:
			Ret = HAL_GPIO_ReadPin(BLK11_2_GPIO_Port, BLK11_2_Pin);
		break;	
		case BLK11_3:
			Ret = HAL_GPIO_ReadPin(BLK11_3_GPIO_Port, BLK11_3_Pin);
		break;	
		case BLK11_4:
			Ret = HAL_GPIO_ReadPin(BLK11_4_GPIO_Port, BLK11_4_Pin);
		break;	
		case BLK11_5:
			Ret = HAL_GPIO_ReadPin(BLK11_5_GPIO_Port, BLK11_5_Pin);
		break;	
		case BLK11_6:
			Ret = HAL_GPIO_ReadPin(BLK11_6_GPIO_Port, BLK11_6_Pin);
		break;	
		case BLK11_7:
			Ret = HAL_GPIO_ReadPin(BLK11_7_GPIO_Port, BLK11_7_Pin);
		break;	
		case BLK11_9:
			Ret = HAL_GPIO_ReadPin(BLK11_9_GPIO_Port, BLK11_9_Pin);
		break;	
		case BLK5_1:
			if(Conversion_MUX_LIGHT[4]>THR_LIGHT)Ret = 1;
			else Ret = 0;
		break;	
		case BLK5_2:
			if(Conversion_MUX_LIGHT[6]>THR_LIGHT)Ret = 1;
			else Ret = 0;
		break;	
		case BLK5_3:
			if(Conversion_MUX_LIGHT[3]>THR_LIGHT)Ret = 1;
			else Ret = 0;
		break;	
		case BLK5_4:
			if(Conversion_MUX_LIGHT[0]>THR_LIGHT)Ret = 1;
			else Ret = 0;
		break;	
		case BLK5_5:
			if(Conversion_MUX_LIGHT[1]>THR_LIGHT)Ret = 1;
			else Ret = 0;
		break;	
		case BLK5_6:
			if(Conversion_MUX_LIGHT[2]>THR_LIGHT)Ret = 1;
			else Ret = 0;
		break;	
		case BLK6_C_1:
		case BLK7_C_1:
			HAL_GPIO_ReadPin(EN_SENS_GPIO_Port, EN_SENS_Pin);
		break;	
		case BLK6_C_2:
			if(Conversion_MUX_WATER[3]>THR_WATER)Ret = 1;
			else Ret = 0;
		break;	
		case BLK6_C_3:
			if(Conversion_MUX_WATER[0]>THR_WATER)Ret = 1;
			else Ret = 0;
		break;	
		case BLK6_C_4:
			if(Conversion_MUX_WATER[1]>THR_WATER)Ret = 1;
			else Ret = 0;
		break;	
		case BLK6_C_5:
			if(Conversion_MUX_WATER[2]>THR_WATER)Ret = 1;
			else Ret = 0;
		break;	
		case BLK7_C_2:
			if(Conversion_MUX_WATER[4]>THR_WATER)Ret = 1;
			else Ret = 0;
		break;	
		case BLK7_C_3:
			if(Conversion_MUX_WATER[6]>THR_WATER)Ret = 1;
			else Ret = 0;
		break;	
		case BLK7_C_4:
			if(Conversion_MUX_WATER[7]>THR_WATER)Ret = 1;
			else Ret = 0;
		break;	
		case BLK7_C_5:
			if(Conversion_MUX_WATER[5]>THR_WATER)Ret = 1;
			else Ret = 0;
		break;	
		case DRV:
			Ret = HAL_GPIO_ReadPin(ON_DRV_GPIO_Port, ON_DRV_Pin);
		break;	
		case RELAY:
			Ret = HAL_GPIO_ReadPin(CTRL_REL_GPIO_Port, CTRL_REL_Pin);
		break;	
		case FUSE1:
			if(abs(convAD2[4] - Conversion_MUX_FUSE_1[4]) > FUSE_HIST)Ret = true;
			else Ret = false;
		break;	
		case FUSE3:
			if(abs(convAD2[4] - Conversion_MUX_FUSE_1[5]) > FUSE_HIST)Ret = true;
			else Ret = false;
		break;	
		case FUSE4:
			if(abs(convAD2[4] - Conversion_MUX_FUSE_1[3]) > FUSE_HIST)Ret = true;
			else Ret = false;
		break;	
		case FUSE5:
			if(abs(convAD2[4] - Conversion_MUX_FUSE_1[0]) > FUSE_HIST)Ret = true;
			else Ret = false;
		break;	
		case FUSE6:
			if(abs(convAD2[4] - Conversion_MUX_FUSE_1[1]) > FUSE_HIST)Ret = true;
			else Ret = false;
		break;	
		case FUSE7:
			if(abs(convAD2[4] - Conversion_MUX_FUSE_1[2]) > FUSE_HIST)Ret = true;
			else Ret = false;
		break;	
		case FUSE8:
			if(abs(convAD2[4] - Conversion_MUX_FUSE_2[4]) > FUSE_HIST)Ret = true;
			else Ret = false;
		break;	
		case FUSE9:
			if(abs(convAD2[4] - Conversion_MUX_FUSE_2[7]) > FUSE_HIST)Ret = true;
			else Ret = false;
		break;	
		case FUSE10:
			if(abs(convAD2[4] - Conversion_MUX_FUSE_2[0]) > FUSE_HIST)Ret = true;
			else Ret = false;
		break;	
		case FUSE11:
			if(abs(convAD2[4] - Conversion_MUX_FUSE_2[3]) > FUSE_HIST)Ret = true;
			else Ret = false;
		break;	
		case FUSE12:
			if(abs(convAD2[4] - Conversion_MUX_FUSE_2[1]) > FUSE_HIST)Ret = true;
			else Ret = false;
		break;	
		case FUSE13:
			if(abs(convAD2[4] - Conversion_MUX_FUSE_2[5]) > FUSE_HIST)Ret = true;
			else Ret = false;
		break;	
		case FUSE14:
			if(abs(convAD2[4] - Conversion_MUX_FUSE_2[6]) > FUSE_HIST)Ret = true;
			else Ret = false;
		break;	
		default:
		break;	
	}
	return Ret;
}

