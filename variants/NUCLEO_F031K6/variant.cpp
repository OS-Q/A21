/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "pins_arduino.h"

#ifdef __cplusplus
extern "C" {
#endif

// Pin number
const PinName digitalPin[] = {
  PA_10, //D0
  PA_9,  //D1
  PA_12, //D2 - no PWM
  PB_0,  //D3
  PB_7,  //D4
  PB_6,  //D5
  PB_1,  //D6
  PF_0,  //D7 - no PWM
  PF_1,  //D8 - no PWM
  PA_8,  //D9
  PA_11, //D10
  PB_5,  //D11
  PB_4,  //D12
  PB_3,  //D13 - LED
  PA_0,  //D14//A0
  PA_1,  //D15//A1
  PA_3,  //D16//A2
  PA_4,  //D17//A3
  PA_5,  //D18//A4
  PA_6,  //D19//A5
  PA_7,  //D20//A6
  PA_2,  //D21 - STLink Tx (no A7)
  PA_15  //D22 - STLink Rx
};

#ifdef __cplusplus
}
#endif

// ----------------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif

/**
  * @brief  System Clock Configuration
  * @param  None
  * @retval None
  */
WEAK void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;

  /* No HSE Oscillator on Nucleo, Activate PLL with HSI/2 as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_NONE;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV1;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL12;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
    /* Initialization Error */
    while (1);
  }

  /* Select PLL as system clock source and configure the HCLK, PCLK1 clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK) {
    /* Initialization Error */
    while (1);
  }
}

#ifdef __cplusplus
}
#endif
