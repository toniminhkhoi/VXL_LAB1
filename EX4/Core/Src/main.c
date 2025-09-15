/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#define SEG_A_Pin GPIO_PIN_0
#define SEG_B_Pin GPIO_PIN_1
#define SEG_C_Pin GPIO_PIN_2
#define SEG_D_Pin GPIO_PIN_3
#define SEG_E_Pin GPIO_PIN_4
#define SEG_F_Pin GPIO_PIN_5
#define SEG_G_Pin GPIO_PIN_6
#define SEG_Port  GPIOB
// Định nghĩa các chân cho Làn 1 (DỌC)
#define LANE1_RED_PORT      GPIOA
#define LANE1_RED_PIN       GPIO_PIN_0
#define LANE1_YELLOW_PORT   GPIOA
#define LANE1_YELLOW_PIN    GPIO_PIN_1
#define LANE1_GREEN_PORT    GPIOA
#define LANE1_GREEN_PIN     GPIO_PIN_2

// Định nghĩa các chân cho Làn 2 (NGANG)
#define LANE2_RED_PORT      GPIOA
#define LANE2_RED_PIN       GPIO_PIN_3
#define LANE2_YELLOW_PORT   GPIOA
#define LANE2_YELLOW_PIN    GPIO_PIN_4
#define LANE2_GREEN_PORT    GPIOA
#define LANE2_GREEN_PIN     GPIO_PIN_5
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
void display7SEG(int num);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	int counter = 0;
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
	  // ----- Trạng thái 1: Làn 1 XANH (3s), Làn 2 ĐỎ -----
	      HAL_GPIO_WritePin(LANE1_GREEN_PORT, LANE1_GREEN_PIN, GPIO_PIN_RESET);
	      HAL_GPIO_WritePin(LANE1_YELLOW_PORT, LANE1_YELLOW_PIN, GPIO_PIN_SET);
	      HAL_GPIO_WritePin(LANE1_RED_PORT, LANE1_RED_PIN, GPIO_PIN_SET);
	      HAL_GPIO_WritePin(LANE2_RED_PORT, LANE2_RED_PIN, GPIO_PIN_RESET);
	      HAL_GPIO_WritePin(LANE2_YELLOW_PORT, LANE2_YELLOW_PIN, GPIO_PIN_SET);
	      HAL_GPIO_WritePin(LANE2_GREEN_PORT, LANE2_GREEN_PIN, GPIO_PIN_SET);
	      for (int i = 0; i < 3; i++) {
	          if (counter > 9) counter = 0;
	          display7SEG(counter++);
	          HAL_Delay(1000);
	      }

	      // ----- Trạng thái 2: Làn 1 VÀNG (2s), Làn 2 vẫn ĐỎ -----
	      HAL_GPIO_WritePin(LANE1_GREEN_PORT, LANE1_GREEN_PIN, GPIO_PIN_SET);
	      HAL_GPIO_WritePin(LANE1_YELLOW_PORT, LANE1_YELLOW_PIN, GPIO_PIN_RESET);
	      for (int i = 0; i < 2; i++) {
	          if (counter > 9) counter = 0;
	          display7SEG(counter++);
	          HAL_Delay(1000);
	      }

	      // ----- Trạng thái 3: Làn 1 ĐỎ, Làn 2 XANH (3s) -----
	      HAL_GPIO_WritePin(LANE1_YELLOW_PORT, LANE1_YELLOW_PIN, GPIO_PIN_SET);
	      HAL_GPIO_WritePin(LANE1_RED_PORT, LANE1_RED_PIN, GPIO_PIN_RESET);
	      HAL_GPIO_WritePin(LANE2_RED_PORT, LANE2_RED_PIN, GPIO_PIN_SET);
	      HAL_GPIO_WritePin(LANE2_GREEN_PORT, LANE2_GREEN_PIN, GPIO_PIN_RESET);
	      for (int i = 0; i < 3; i++) {
	          if (counter > 9) counter = 0;
	          display7SEG(counter++);
	          HAL_Delay(1000);
	      }

	      // ----- Trạng thái 4: Làn 1 vẫn ĐỎ, Làn 2 VÀNG (2s) -----
	      HAL_GPIO_WritePin(LANE2_GREEN_PORT, LANE2_GREEN_PIN, GPIO_PIN_SET);
	      HAL_GPIO_WritePin(LANE2_YELLOW_PORT, LANE2_YELLOW_PIN, GPIO_PIN_RESET);
	      for (int i = 0; i < 2; i++) {
	          if (counter > 9) counter = 0;
	          display7SEG(counter++);
	          HAL_Delay(1000);
	      }


	    }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}
void display7SEG(int num)
{
  // Mảng mã hóa cho LED 7 đoạn Common Anode (0=ON, 1=OFF)
  // Thứ tự bit: g, f, e, d, c, b, a
  const uint8_t segmentCodes[10] = {
    0x40,  // Số 0, 0110 0000
    0x79,  // Số 1, 0111 1001
    0x24,  // Số 2, 0010 0100
    0x30,  // Số 3, 0011 0000
    0x19,  // Số 4, 0001 1001
    0x12,  // Số 5, 0001 0010
    0x02,  // Số 6, 0000 0010
    0x78,  // Số 7, 0111 1000
    0x00,  // Số 8, 0000 0000
	0x10   // Số 9, 0001 0000
  };

  if (num >= 0 && num <= 9)
  {
    uint8_t code = segmentCodes[num];
    HAL_GPIO_WritePin(SEG_Port, SEG_A_Pin, (code >> 0) & 0x01);
    HAL_GPIO_WritePin(SEG_Port, SEG_B_Pin, (code >> 1) & 0x01);
    HAL_GPIO_WritePin(SEG_Port, SEG_C_Pin, (code >> 2) & 0x01);
    HAL_GPIO_WritePin(SEG_Port, SEG_D_Pin, (code >> 3) & 0x01);
    HAL_GPIO_WritePin(SEG_Port, SEG_E_Pin, (code >> 4) & 0x01);
    HAL_GPIO_WritePin(SEG_Port, SEG_F_Pin, (code >> 5) & 0x01);
    HAL_GPIO_WritePin(SEG_Port, SEG_G_Pin, (code >> 6) & 0x01);
  }
}
/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LED_RED_Pin|LED_REDB1_Pin|LED_REDB2_Pin|LED_REDB3_Pin
                          |LED_REDB4_Pin|LED_REDB5_Pin|LED_REDB6_Pin, GPIO_PIN_SET);

  /*Configure GPIO pins : PA0 PA1 PA2 PA3
                           PA4 PA5 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : LED_RED_Pin LED_REDB1_Pin LED_REDB2_Pin LED_REDB3_Pin
                           LED_REDB4_Pin LED_REDB5_Pin LED_REDB6_Pin */
  GPIO_InitStruct.Pin = LED_RED_Pin|LED_REDB1_Pin|LED_REDB2_Pin|LED_REDB3_Pin
                          |LED_REDB4_Pin|LED_REDB5_Pin|LED_REDB6_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
