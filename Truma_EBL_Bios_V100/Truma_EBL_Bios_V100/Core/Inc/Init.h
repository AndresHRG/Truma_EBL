#ifndef __INIT_H
#define __INIT_H

#ifdef __cplusplus
extern "C" {
#endif
	
#include "main.h"
	
void SystemClock_Config(void);
void MX_DMA_Init(void);
void MX_ADC1_Init(void);
void MX_ADC2_Init(void);
void MX_GPIO_Init(void);
void MX_DAC1_Init(void);
void MX_FDCAN1_Init(void);
void MX_USART1_UART_Init(void);
void MX_USART2_UART_Init(void);
void MX_USART3_UART_Init(void);
void MX_I2C2_Init(void);
void MX_I2C3_Init(void);
void IO_Extender_Init(void);

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;
extern I2C_HandleTypeDef hi2c3;
extern ADC_HandleTypeDef hadc1;
extern ADC_HandleTypeDef hadc2;
extern DAC_HandleTypeDef hdac1;

#ifdef __cplusplus
}
#endif

#endif /* __INIT_H */
