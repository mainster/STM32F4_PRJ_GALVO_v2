/**
 * @file        stm32f4xx_it.h
 *
 * @date        14 Mar 2017
 * @author      Manuel Del Basso (mainster)
 * @email       manuel.delbasso@gmail.com
 *
 * @ide         System Workbench ac6 (eclipse stm32)
 * @stdperiph   STM32F4xx Standard peripheral drivers version 1.4.0 or greater required
 * @license     GNU GPL v3
 *
 * @brief       Provides interrupt callback handlers
 *  
   @verbatim

  ------------------------------------------------------------------------

  Copyright (C) 2016  Manuel Del Basso

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

  ------------------------------------------------------------------------

   @endverbatim
 *
 *
 */

#ifndef _STM32F4xx_IT_H_
#define _STM32F4xx_IT_H_

#ifdef __cplusplus
  extern "C" {
#endif 

/* Includes */
#include "stm32f4xx.h"

void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void SVC_Handler(void);
void DebugMon_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);
void TimingDelay_Decrement(void);

#ifdef __cplusplus
  }
#endif

#endif /* _STM32F4xx_IT_H_ */