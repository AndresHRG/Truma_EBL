#include "main.h"
#include "Init.h"
#include "Analog.h"
#include "Digital.h"
#include "Comm.h"
#include "Truma_EBL_Bios_V100.h"

uint64_t Arvi_Tick;

unsigned int Timer1ms;
unsigned int Timer20ms;

uint64_t GetMilliSec(void)
{
	return Arvi_Tick;
}

void OnAll()
{
	ArviSet(BLK1_2, 1);
	ArviSet(BLK2_3, 1);
	ArviSet(BLK3_1, 1);
	ArviSet(BLK3_2, 1);
	ArviSet(BLK3_3, 1);
	ArviSet(BLK3_4, 1);
	ArviSet(BLK3_5, 1);
	ArviSet(BLK3_6, 1);
	ArviSet(BLK3_7, 1);
	ArviSet(BLK3_8, 1);
	ArviSet(BLK3_9, 1);
	ArviSet(BLK3_10, 1);
	ArviSet(BLK3_11, 1);
	ArviSet(BLK4, 1);
	ArviSet(BLK6_C_1, 1);
	ArviSet(BLK7_C_1, 1);
	ArviSet(BLK11_1, 1);
	ArviSet(BLK11_2, 1);
	ArviSet(BLK11_3, 1);
	ArviSet(BLK11_4, 1);
	ArviSet(BLK11_5, 1);
	ArviSet(BLK11_6, 1);
	ArviSet(BLK11_7, 1);
	ArviSet(BLK11_9, 1);
}

void OffAll()
{
	ArviSet(BLK1_2, 0);
	ArviSet(BLK2_3, 0);
	ArviSet(BLK3_1, 0);
	ArviSet(BLK3_2, 0);
	ArviSet(BLK3_3, 0);
	ArviSet(BLK3_4, 0);
	ArviSet(BLK3_5, 0);
	ArviSet(BLK3_6, 0);
	ArviSet(BLK3_7, 0);
	ArviSet(BLK3_8, 0);
	ArviSet(BLK3_9, 0);
	ArviSet(BLK3_10, 0);
	ArviSet(BLK3_11, 0);
	ArviSet(BLK4, 0);
	ArviSet(BLK6_C_1, 0);
	ArviSet(BLK7_C_1, 0);
	ArviSet(BLK11_1, 0);
	ArviSet(BLK11_2, 0);
	ArviSet(BLK11_3, 0);
	ArviSet(BLK11_4, 0);
	ArviSet(BLK11_5, 0);
	ArviSet(BLK11_6, 0);
	ArviSet(BLK11_7, 0);
	ArviSet(BLK11_9, 0);
}

void Bios_Init(void)
{
	HAL_Init();

	SystemClock_Config();

	MX_GPIO_Init();
	MX_DMA_Init();
	MX_FDCAN1_Init();
	MX_USART1_UART_Init();
	MX_USART2_UART_Init();
	MX_USART3_UART_Init();
	MX_ADC1_Init();
	MX_ADC2_Init();
	MX_I2C2_Init();
	MX_I2C3_Init();
	MX_DAC1_Init();
	IO_Extender_Init();

	HAL_ADC_Start_DMA(&hadc1, (uint32_t *)convAD1, 2);
	HAL_ADC_Start_DMA(&hadc2, (uint32_t *)convAD2, 9);

	OnDRV
	OnBLK1_1
	OnBLK1_2
	Enable_LIN1	
	Enable_LIN2
	//Arvi_printf("Truma-EBL-Bios-V1.0.0\n");
}

int main (void)
{
	static uint8_t LedCount;

	Bios_Init();
	
	int sysclk_freq = HAL_RCC_GetSysClockFreq();

	Arvi_Setup();
	
	while(1)
	{
		if(Timer1ms >= 5)
		{
			ScanMultiplexores();
			Timer1ms = 0;
		}
		if(Timer20ms >= 500)
		{
			LedCount++;
			if(LedCount&0x3F)OffLED
			else OnLED
			Timer20ms = 0;
		}
		
		Arvi_Main();
	}
}


