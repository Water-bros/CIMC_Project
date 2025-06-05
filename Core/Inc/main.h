/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "adc.h"
#include "dma.h"
#include "i2c.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "stdio.h"
#include "string.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
void print(const char *format, ...);
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define ADC_Pin GPIO_PIN_0
#define ADC_GPIO_Port GPIOC
#define LED6_Pin GPIO_PIN_10
#define LED6_GPIO_Port GPIOE
#define LED5_Pin GPIO_PIN_11
#define LED5_GPIO_Port GPIOE
#define LED4_Pin GPIO_PIN_12
#define LED4_GPIO_Port GPIOE
#define LED1_Pin GPIO_PIN_13
#define LED1_GPIO_Port GPIOE
#define LED2_Pin GPIO_PIN_14
#define LED2_GPIO_Port GPIOE
#define LED3_Pin GPIO_PIN_15
#define LED3_GPIO_Port GPIOE
#define FLASH_CS_Pin GPIO_PIN_12
#define FLASH_CS_GPIO_Port GPIOB
#define KEY6_Pin GPIO_PIN_8
#define KEY6_GPIO_Port GPIOD
#define KEY5_Pin GPIO_PIN_9
#define KEY5_GPIO_Port GPIOD
#define KEY4_Pin GPIO_PIN_10
#define KEY4_GPIO_Port GPIOD
#define KEY3_Pin GPIO_PIN_11
#define KEY3_GPIO_Port GPIOD
#define KEY2_Pin GPIO_PIN_12
#define KEY2_GPIO_Port GPIOD
#define KEY1_Pin GPIO_PIN_13
#define KEY1_GPIO_Port GPIOD
#define SD_CD_Pin GPIO_PIN_7
#define SD_CD_GPIO_Port GPIOC
#define OLED_SCL_Pin GPIO_PIN_8
#define OLED_SCL_GPIO_Port GPIOB
#define OLED_SDA_Pin GPIO_PIN_9
#define OLED_SDA_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
