#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32g4xx_hal.h"

//Salida de Led indicador
#define		OnLED		HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
#define		OffLED		HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);

//Control del relay
#define		OnREL		HAL_GPIO_WritePin(CTRL_REL_GPIO_Port, CTRL_REL_Pin, GPIO_PIN_SET);
#define		OffREL		HAL_GPIO_WritePin(CTRL_REL_GPIO_Port, CTRL_REL_Pin, GPIO_PIN_RESET);

//Control del driver principal
#define		OnDRV		HAL_GPIO_WritePin(ON_DRV_GPIO_Port, ON_DRV_Pin, GPIO_PIN_SET);
#define		OffDRV		HAL_GPIO_WritePin(ON_DRV_GPIO_Port, ON_DRV_Pin, GPIO_PIN_RESET);

#define		OnBLK1_1		HAL_GPIO_WritePin(ON_BLK1_1_GPIO_Port, ON_BLK1_1_Pin, GPIO_PIN_SET);
#define		OffBLK1_1		HAL_GPIO_WritePin(ON_BLK1_1_GPIO_Port, ON_BLK1_1_Pin, GPIO_PIN_RESET);
#define		OnBLK1_2		HAL_GPIO_WritePin(ON_BLK1_2_GPIO_Port, ON_BLK1_2_Pin, GPIO_PIN_SET);
#define		OffBLK1_2		HAL_GPIO_WritePin(ON_BLK1_2_GPIO_Port, ON_BLK1_2_Pin, GPIO_PIN_RESET);

#define		OnBLK11_1		HAL_GPIO_WritePin(BLK11_1_GPIO_Port, BLK11_1_Pin, GPIO_PIN_SET);
#define		OffBLK11_1		HAL_GPIO_WritePin(BLK11_1_GPIO_Port, BLK11_1_Pin, GPIO_PIN_RESET);
#define		OnBLK11_2		HAL_GPIO_WritePin(BLK11_2_GPIO_Port, BLK11_2_Pin, GPIO_PIN_SET);
#define		OffBLK11_2		HAL_GPIO_WritePin(BLK11_2_GPIO_Port, BLK11_2_Pin, GPIO_PIN_RESET);
#define		OnBLK11_3		HAL_GPIO_WritePin(BLK11_3_GPIO_Port, BLK11_3_Pin, GPIO_PIN_SET);
#define		OffBLK11_3		HAL_GPIO_WritePin(BLK11_3_GPIO_Port, BLK11_3_Pin, GPIO_PIN_RESET);
#define		OnBLK11_4		HAL_GPIO_WritePin(BLK11_4_GPIO_Port, BLK11_4_Pin, GPIO_PIN_SET);
#define		OffBLK11_4		HAL_GPIO_WritePin(BLK11_4_GPIO_Port, BLK11_4_Pin, GPIO_PIN_RESET);
#define		OnBLK11_5		HAL_GPIO_WritePin(BLK11_5_GPIO_Port, BLK11_5_Pin, GPIO_PIN_SET);
#define		OffBLK11_5		HAL_GPIO_WritePin(BLK11_5_GPIO_Port, BLK11_5_Pin, GPIO_PIN_RESET);
#define		OnBLK11_6		HAL_GPIO_WritePin(BLK11_6_GPIO_Port, BLK11_6_Pin, GPIO_PIN_SET);
#define		OffBLK11_6		HAL_GPIO_WritePin(BLK11_6_GPIO_Port, BLK11_6_Pin, GPIO_PIN_RESET);
#define		OnBLK11_7		HAL_GPIO_WritePin(BLK11_7_GPIO_Port, BLK11_7_Pin, GPIO_PIN_SET);
#define		OffBLK11_7		HAL_GPIO_WritePin(BLK11_7_GPIO_Port, BLK11_7_Pin, GPIO_PIN_RESET);
#define		OnBLK11_9		HAL_GPIO_WritePin(BLK11_9_GPIO_Port, BLK11_9_Pin, GPIO_PIN_SET);
#define		OffBLK11_9		HAL_GPIO_WritePin(BLK11_9_GPIO_Port, BLK11_9_Pin, GPIO_PIN_RESET);

#define		OnBLK10_1		HAL_GPIO_WritePin(BLK10_1_GPIO_Port, BLK10_1_Pin, GPIO_PIN_SET);
#define		OffBLK10_1		HAL_GPIO_WritePin(BLK10_1_GPIO_Port, BLK10_1_Pin, GPIO_PIN_RESET);
#define		OnBLK10_2		HAL_GPIO_WritePin(BLK10_2_GPIO_Port, BLK10_2_Pin, GPIO_PIN_SET);
#define		OffBLK10_2		HAL_GPIO_WritePin(BLK10_2_GPIO_Port, BLK10_2_Pin, GPIO_PIN_RESET);
#define		OnBLK10_3		HAL_GPIO_WritePin(BLK10_3_GPIO_Port, BLK10_3_Pin, GPIO_PIN_SET);
#define		OffBLK10_3		HAL_GPIO_WritePin(BLK10_3_GPIO_Port, BLK10_3_Pin, GPIO_PIN_RESET);
#define		OnBLK10_4		HAL_GPIO_WritePin(BLK10_4_GPIO_Port, BLK10_4_Pin, GPIO_PIN_SET);
#define		OffBLK10_4		HAL_GPIO_WritePin(BLK10_4_GPIO_Port, BLK10_4_Pin, GPIO_PIN_RESET);
#define		OnBLK10_7		HAL_GPIO_WritePin(BLK10_7_GPIO_Port, BLK10_7_Pin, GPIO_PIN_SET);
#define		OffBLK10_7		HAL_GPIO_WritePin(BLK10_7_GPIO_Port, BLK10_7_Pin, GPIO_PIN_RESET);
#define		OnBLK10_10		HAL_GPIO_WritePin(BLK10_10_GPIO_Port, BLK10_10_Pin, GPIO_PIN_SET);
#define		OffBLK10_10		HAL_GPIO_WritePin(BLK10_10_GPIO_Port, BLK10_10_Pin, GPIO_PIN_RESET);
#define		OnBLK10_11		HAL_GPIO_WritePin(BLK10_11_GPIO_Port, BLK10_11_Pin, GPIO_PIN_SET);
#define		OffBLK10_11		HAL_GPIO_WritePin(BLK10_11_GPIO_Port, BLK10_11_Pin, GPIO_PIN_RESET);

#define		OnOUT_D			HAL_GPIO_WritePin(OUT_D_GPIO_Port, OUT_D_Pin, GPIO_PIN_SET);
#define		OffOUT_D		HAL_GPIO_WritePin(OUT_D_GPIO_Port, OUT_D_Pin, GPIO_PIN_RESET);

#define		Enable_LIN1		HAL_GPIO_WritePin(EN_LIN1_GPIO_Port, EN_LIN1_Pin, GPIO_PIN_SET);
#define		Disable_LIN1	HAL_GPIO_WritePin(EN_LIN1_GPIO_Port, EN_LIN1_Pin, GPIO_PIN_RESET);
#define		Enable_LIN2		HAL_GPIO_WritePin(EN_LIN2_GPIO_Port, EN_LIN2_Pin, GPIO_PIN_SET);
#define		Disable_LIN2	HAL_GPIO_WritePin(EN_LIN2_GPIO_Port, EN_LIN2_Pin, GPIO_PIN_RESET);

#define		Enable_Sens		HAL_GPIO_WritePin(EN_SENS_GPIO_Port, EN_SENS_Pin, GPIO_PIN_SET);
#define		Disable_Sens	HAL_GPIO_WritePin(EN_SENS_GPIO_Port, EN_SENS_Pin, GPIO_PIN_RESET);

void Error_Handler(void);

extern unsigned int Timer1ms;
extern unsigned int Timer20ms;

extern uint64_t Arvi_Tick;

#define ON_BLK1_2_Pin GPIO_PIN_13
#define ON_BLK1_2_GPIO_Port GPIOC
#define ON_BLK1_1_Pin GPIO_PIN_14
#define ON_BLK1_1_GPIO_Port GPIOC
#define CTRL_REL_Pin GPIO_PIN_15
#define CTRL_REL_GPIO_Port GPIOC
#define AD_BAT2_Pin GPIO_PIN_0
#define AD_BAT2_GPIO_Port GPIOC
#define AD_BAT_M_Pin GPIO_PIN_1
#define AD_BAT_M_GPIO_Port GPIOC
#define AD_MUX_F2_Pin GPIO_PIN_2
#define AD_MUX_F2_GPIO_Port GPIOC
#define AD_MUX_LIGHT_Pin GPIO_PIN_3
#define AD_MUX_LIGHT_GPIO_Port GPIOC
#define AD_MUX_WATER_Pin GPIO_PIN_0
#define AD_MUX_WATER_GPIO_Port GPIOA
#define AD_MUX_CS_Pin GPIO_PIN_1
#define AD_MUX_CS_GPIO_Port GPIOA
#define OUT_D_Pin GPIO_PIN_4
#define OUT_D_GPIO_Port GPIOA
#define DAC_Pin GPIO_PIN_5
#define DAC_GPIO_Port GPIOA
#define AD_SPLIT_Pin GPIO_PIN_6
#define AD_SPLIT_GPIO_Port GPIOA
#define AD_BLK10_1_Pin GPIO_PIN_7
#define AD_BLK10_1_GPIO_Port GPIOA
#define INT_IMU_Pin GPIO_PIN_5
#define INT_IMU_GPIO_Port GPIOC
#define MUX_C_Pin GPIO_PIN_0
#define MUX_C_GPIO_Port GPIOB
#define MUX_B_Pin GPIO_PIN_1
#define MUX_B_GPIO_Port GPIOB
#define MUX_A_Pin GPIO_PIN_2
#define MUX_A_GPIO_Port GPIOB
#define CS_DRV_Pin GPIO_PIN_12
#define CS_DRV_GPIO_Port GPIOB
#define EN_SENS_Pin GPIO_PIN_13
#define EN_SENS_GPIO_Port GPIOB
#define CS_DRV2_Pin GPIO_PIN_14
#define CS_DRV2_GPIO_Port GPIOB
#define AD_MUX_F1_Pin GPIO_PIN_15
#define AD_MUX_F1_GPIO_Port GPIOB
#define EN_LIN1_Pin GPIO_PIN_6
#define EN_LIN1_GPIO_Port GPIOC
#define EN_LIN2_Pin GPIO_PIN_7
#define EN_LIN2_GPIO_Port GPIOC
#define BLK11_7_Pin GPIO_PIN_15
#define BLK11_7_GPIO_Port GPIOA
#define BLK11_1_Pin GPIO_PIN_10
#define BLK11_1_GPIO_Port GPIOC
#define BLK11_2_Pin GPIO_PIN_11
#define BLK11_2_GPIO_Port GPIOC
#define BLK11_4_Pin GPIO_PIN_12
#define BLK11_4_GPIO_Port GPIOC
#define BLK11_6_Pin GPIO_PIN_2
#define BLK11_6_GPIO_Port GPIOD
#define BLK11_5_Pin GPIO_PIN_3
#define BLK11_5_GPIO_Port GPIOB
#define BLK11_3_Pin GPIO_PIN_4
#define BLK11_3_GPIO_Port GPIOB
#define BLK11_9_Pin GPIO_PIN_5
#define BLK11_9_GPIO_Port GPIOB
#define ON_DRV2_Pin GPIO_PIN_6
#define ON_DRV2_GPIO_Port GPIOB
#define ON_DRV_Pin GPIO_PIN_7
#define ON_DRV_GPIO_Port GPIOB
#define LED_Pin GPIO_PIN_9
#define LED_GPIO_Port GPIOB

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
