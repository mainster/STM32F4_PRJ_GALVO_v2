/**
 * @file        nvic_config.c
 *
 * @date        30 Jan 2017
 * @author      Manuel Del Basso (mainster)
 * @email       manuel.delbasso@gmail.com
 *
 * @ide         System Workbench ac6 (eclipse stm32)
 * @stdperiph   STM32F4xx Standard peripheral drivers version 1.4.0 or greater required
 * @license		GNU GPL v3
 * 
 * @brief       TODO
 * 
 * @verbatim

	Copyright (C) 2016	Manuel Del Basso
	
	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.
	
	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.
	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.

	@endverbatim
 *
 */
#include "nvic_config.h"


void NVIC_Configuration(void) {
  /**
   * @brief      Enable the DMA Stream IRQ Channel.
   */
  NVIC_InitStruct_DMA.NVIC_IRQChannel = DMA2_Stream0_IRQn;
  NVIC_InitStruct_DMA.NVIC_IRQChannelPreemptionPriority = 2;
  NVIC_InitStruct_DMA.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStruct_DMA.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStruct_DMA);

  /**
   * @brief      Enable the TIM2 IRQ Channel.
   */
  NVIC_InitStruct_TIM.NVIC_IRQChannel = TIM2_IRQn;
  NVIC_InitStruct_TIM.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStruct_TIM.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStruct_TIM.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStruct_TIM);

  /**
   * @brief      ADC Analog watch-dog interrupt enable.
   */
  NVIC_InitStruct_ADC.NVIC_IRQChannel = ADC_IRQn;
  NVIC_InitStruct_ADC.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStruct_ADC.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStruct_ADC.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStruct_ADC);
  ADC_ITConfig(ADC1, ADC_IT_AWD, ENABLE);
}
