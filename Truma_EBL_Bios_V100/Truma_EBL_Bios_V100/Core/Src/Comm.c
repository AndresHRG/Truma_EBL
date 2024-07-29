#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#include "main.h"
#include "Comm.h"
#include "Init.h"
#include "Truma_EBL_Bios_V100.h"

void TxChar_UD(uint8_t p_data)
{
    HAL_UART_Transmit(&huart2, (uint8_t*)&p_data, 1, 1);
}

void Arvi_printf(char *s,...)
{
    int i=0;
    va_list vl;
    char buff[512];

    va_start(vl, s);
    vsprintf(buff, s, vl);

    while(1)
    {
        if(buff[i]) 
					TxChar_UD(buff[i++]);
        else 
					break;
    }
    va_end(vl);
}

void Tx_UART1(uint8_t *Data, uint8_t Len)
{
    HAL_UART_Transmit(&huart1, Data, Len, 1);
}

void Tx_UART2(uint8_t *Data, uint8_t Len)
{
    HAL_UART_Transmit(&huart2, Data, Len, 100);
}

void Tx_UART3(uint8_t *Data, uint8_t Len)
{
    HAL_UART_Transmit(&huart3, Data, Len, 1);
}

void Write_IO_Expander(uint8_t output)
{
#define OUT_PORT	0x01	
	
    if (HAL_I2C_Mem_Write(&hi2c3, ADD_IO_EXPANDER << 1, OUT_PORT, I2C_MEMADD_SIZE_8BIT, (uint8_t*)&output, 1, HAL_MAX_DELAY) != HAL_OK)
    {
		Error_Handler();
    }
}

uint8_t Read_IO_Expander(void)
{
#define OUT_PORT	0x01	
uint8_t value=0;

    if (HAL_I2C_Mem_Read(&hi2c3, ADD_IO_EXPANDER << 1, OUT_PORT, I2C_MEMADD_SIZE_8BIT, &value, 1, HAL_MAX_DELAY) != HAL_OK)
    {
        // Manejar el error
    }
	return value;
}
