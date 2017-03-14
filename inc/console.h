/**
 * @file        console.h
 *
 * @date        29 Jan 2017
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
#ifndef CONSOLE_H_
#define CONSOLE_H_

#ifdef __cplusplus
 extern "C" {
#endif 
 	
#include "arm_math.h"
#include "globals.h"

//#define IDX_CMD     1       // index 0 is @ or ! or #
//#define IDX_VAL     5   // index 5
//
//#define UART_BUFF_SIZE      (1+NC+FS+NV+1)
//#define VALUE_BUFF_SIZE     (NV+1)
//#define CMD_BUFF_SIZE       (NC+1)
//
//typedef enum {
//    KP, KI, KD, W, UNKNOWN
//} cmd_items_t;
//
////Struct for switch by string casees
//struct items {
//    char *name;
//    cmd_items_t id;
//};
//
//void fastConsoleCase(arm_pid_instance_f32 *pid);

#ifdef __cplusplus
}
#endif

#endif /* CONSOLE_H_ */
