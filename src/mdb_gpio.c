﻿/**
 * @file        mdb_gpio.c
 *
 * @date        28 Jan 2017
 * @author      Manuel Del Basso (mainster)
 * @email       manuel.delbasso@gmail.com
 *
 * @ide         System Workbench ac6 (eclipse stm32)
 * @stdperiph   STM32F4xx Standard peripheral drivers version 1.4.0 or greater required
 * @license		GNU GPL v3
 *
 * @brief       DESCRIPTION
 *
   @verbatim

	------------------------------------------------------------------------

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

	------------------------------------------------------------------------

   @endverbatim

 *
 */
#include "mdb_gpio.h"

/**
 * @brief      Defines a list of used GPIO pins and their configurations. It
 *             provides clarity and simplifies initialization procedure. Needs
 *             to be ordered like in typedef GPIO_NAME_t
 */
MDB_GPIO_t MDB_GPIO[] = {
	{ 	LED_GREEN_A,  	GPIOG, GPIO_Pin_13, RCC_AHB1Periph_GPIOG, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_NOPULL, GPIO_Speed_50MHz,  GPIO_OFF },
	{ 	LED_RED_A,		GPIOG, GPIO_Pin_14, RCC_AHB1Periph_GPIOG, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_NOPULL, GPIO_Speed_50MHz,  GPIO_OFF },

#ifndef HELLO_WORLD_PINOUT

	{ 	BEAM_INTERRUPT, GPIOE, GPIO_Pin_10, RCC_AHB1Periph_GPIOE, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_NOPULL, GPIO_Speed_100MHz,  GPIO_OFF },
	{ 	TRIGGER_SRC,	GPIOE, GPIO_Pin_12, RCC_AHB1Periph_GPIOE, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_NOPULL, GPIO_Speed_100MHz,  GPIO_OFF },

	// {	BEAM_INTERRUPT, GPIOE, GPIO_Pin_10, GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, RCC_AHB1Periph_GPIOE, GPIO_OFF},
	// {	TRIGGER_SRC, GPIOE, GPIO_Pin_12, GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, RCC_AHB1Periph_GPIOE, GPIO_OFF},

	{ 	DBG_TIMING_PE2, GPIOE, GPIO_Pin_2, RCC_AHB1Periph_GPIOE, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_NOPULL, GPIO_Speed_100MHz,  GPIO_OFF },
	{ 	DBG_TIMING_PE4, GPIOE, GPIO_Pin_4, RCC_AHB1Periph_GPIOE, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_NOPULL, GPIO_Speed_100MHz,  GPIO_OFF },
	{ 	DBG_TIMING_PE6, GPIOE, GPIO_Pin_6, RCC_AHB1Periph_GPIOE, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_NOPULL, GPIO_Speed_100MHz,  GPIO_OFF },

	// {	DBG_TIMING_PE2, GPIOE, GPIO_Pin_2, GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, RCC_AHB1Periph_GPIOE, GPIO_OFF},
	// {	DBG_TIMING_PE4, GPIOE, GPIO_Pin_4, GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, RCC_AHB1Periph_GPIOE, GPIO_OFF},
	// {	DBG_TIMING_PE6, GPIOE, GPIO_Pin_6, GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, RCC_AHB1Periph_GPIOE, GPIO_OFF},

	{ 	ADC_X_CHAN_IO, GPIOA, GPIO_Pin_6, RCC_AHB1Periph_GPIOA, GPIO_Mode_AIN, GPIO_OType_OD, GPIO_PuPd_NOPULL, GPIO_Speed_100MHz,  GPIO_OFF },
	{ 	ADC_Y_CHAN_IO, GPIOB, GPIO_Pin_0, RCC_AHB1Periph_GPIOB, GPIO_Mode_AIN, GPIO_OType_OD, GPIO_PuPd_NOPULL, GPIO_Speed_100MHz,  GPIO_OFF },
	{ 	ADC_Ix_CHAN_IO,GPIOC, GPIO_Pin_3, RCC_AHB1Periph_GPIOC, GPIO_Mode_AIN, GPIO_OType_OD, GPIO_PuPd_NOPULL, GPIO_Speed_100MHz,  GPIO_OFF },
	{ 	ADC_X_CHAN_IO, GPIOA, GPIO_Pin_3, RCC_AHB1Periph_GPIOA, GPIO_Mode_AIN, GPIO_OType_OD, GPIO_PuPd_NOPULL, GPIO_Speed_100MHz,  GPIO_OFF },

	// {	ADC_X_CHAN_IO, GPIOA, GPIO_Pin_6, GPIO_Mode_AIN, GPIO_Speed_100MHz, GPIO_OType_OD, GPIO_PuPd_NOPULL, RCC_AHB1Periph_GPIOA, GPIO_OFF},
	// {	ADC_Y_CHAN_IO, GPIOB, GPIO_Pin_0, GPIO_Mode_AIN, GPIO_Speed_100MHz, GPIO_OType_OD, GPIO_PuPd_NOPULL, RCC_AHB1Periph_GPIOB, GPIO_OFF},
	// {	ADC_Ix_CHAN_IO, GPIOC, GPIO_Pin_3, GPIO_Mode_AIN, GPIO_Speed_100MHz, GPIO_OType_OD, GPIO_PuPd_NOPULL, RCC_AHB1Periph_GPIOC, GPIO_OFF},
	// {	ADC_W_CHAN_IO, GPIOA, GPIO_Pin_3, GPIO_Mode_AIN, GPIO_Speed_100MHz, GPIO_OType_OD, GPIO_PuPd_NOPULL, RCC_AHB1Periph_GPIOA, GPIO_OFF},
#endif
};


//  MD_GPIO_NAME_t      _GPIO_NAME;       //!< GPIO name
//  GPIO_TypeDef*       _GPIO_PORT;       //!< GPIO port pointer.
//  const uint16_t      _GPIO_PIN;        //!< GPIO pin address.
//  const uint32_t      _GPIO_AHB_CLK;    //!< GPIO AHB peripheral clock source .
//  GPIOMode_TypeDef    _GPIO_Mode;       //!< GPIO mode.
//  GPIOOType_TypeDef   _GPIO_OType;      //!< GPIO output type.
//  GPIOPuPd_TypeDef    _GPIO_PuPd;       //!< GPIO pull resistor.
//  GPIOSpeed_TypeDef   _GPIO_Speed;      //!< GPIO driving strength.
//  MD_GPIO_STATE_t     _GPIO_INIT;       //!< Initial GPIO state
//} MDB_GPIO_t;


/**< LED toggeln
 */
void MDB_GPIO_BeamPin(MD_GPIO_NAME_t name, MD_GPIO_DRIVER_STATE_t newState) {
	GPIO_InitTypeDef GPIO_InitStructure;

	GPIO_InitStructure.GPIO_Pin = MDB_GPIO[name]._GPIO_PIN;
	GPIO_InitStructure.GPIO_Speed = MDB_GPIO[name]._GPIO_Speed;

	if (newState == GPIO_DRIVER_ON) {
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	} else {
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
		GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
	}
	GPIO_Init(MDB_GPIO[name]._GPIO_PORT, &GPIO_InitStructure);
}

/**
 * @brief      Initialize all GPIOs from MDB_GPIO.
 */
void MDB_GPIO_Init(void) {
	GPIO_InitTypeDef GPIO_InitStructure;
	MD_GPIO_NAME_t name;

	for (int idx = 0; idx < sizeof(MDB_GPIO) / sizeof(MDB_GPIO[0]); idx++) {

		//!< Enable clock source.
		RCC_AHB1PeriphClockCmd(MDB_GPIO[idx]._GPIO_AHB_CLK, ENABLE);

		GPIO_InitStructure.GPIO_Pin = MDB_GPIO[idx]._GPIO_PIN;
		GPIO_InitStructure.GPIO_Mode = MDB_GPIO[idx]._GPIO_Mode;
		GPIO_InitStructure.GPIO_OType = MDB_GPIO[idx]._GPIO_OType;
		GPIO_InitStructure.GPIO_PuPd = MDB_GPIO[idx]._GPIO_PuPd;
		GPIO_InitStructure.GPIO_Speed = MDB_GPIO[idx]._GPIO_Speed;
		GPIO_Init(MDB_GPIO[idx]._GPIO_PORT, &GPIO_InitStructure);

		//!< Default value
		(MDB_GPIO[idx]._GPIO_INIT == GPIO_OFF)
				? 	MDB_GPIO_Off(idx)
				: 	MDB_GPIO_On(idx);

	}

#ifdef OLD_GPIO_INIT
	for (name = (MD_GPIO_NAME_t) 0; name < (MD_GPIO_NAME_t) GPIO_COUNT; name++) {
		///< Enable clock source
		RCC_AHB1PeriphClockCmd(MDB_GPIO[name]._GPIO_AHB_CLK, ENABLE);

		GPIO_InitStructure.GPIO_Pin = MDB_GPIO[name]._GPIO_PIN;
		GPIO_InitStructure.GPIO_Mode = MDB_GPIO[name]._GPIO_Mode;
		GPIO_InitStructure.GPIO_OType = MDB_GPIO[name]._GPIO_OType;
		GPIO_InitStructure.GPIO_PuPd = MDB_GPIO[name]._GPIO_PuPd;
		GPIO_InitStructure.GPIO_Speed = MDB_GPIO[name]._GPIO_Speed;
		GPIO_Init(MDB_GPIO[name]._GPIO_PORT, &GPIO_InitStructure);

		// Default Wert einstellen
		if (MDB_GPIO[name]._GPIO_INIT == GPIO_OFF) {
			MDB_GPIO_Off(name);
		} else {
			MDB_GPIO_On(name);
		}
	}
#endif
}

/**< Enable GPIO 
 */
void MDB_GPIO_Off(MD_GPIO_NAME_t name) {
	MDB_GPIO[name]._GPIO_PORT->BSRRH = MDB_GPIO[name]._GPIO_PIN;
}

/**< Disable GPIO 
 */
void MDB_GPIO_On(MD_GPIO_NAME_t name) {
	MDB_GPIO[name]._GPIO_PORT->BSRRL = MDB_GPIO[name]._GPIO_PIN;
}

/**< LED toggeln
 */
void MDB_GPIO_Toggle(MD_GPIO_NAME_t name) {
	MDB_GPIO[name]._GPIO_PORT->ODR ^= MDB_GPIO[name]._GPIO_PIN;
}

//--------------------------------------------------------------
// LED ein- oder ausschalten
//--------------------------------------------------------------
void MDB_GPIO_Switch(MD_GPIO_NAME_t name, MD_GPIO_STATE_t newState) {
	if (newState == GPIO_OFF) {
		MDB_GPIO_Off(name);
	} else {
		MDB_GPIO_On(name);
	}
}

void gpio_init_mco1(void) {
	//GPIO Init structure
	GPIO_InitTypeDef GPIO_InitDef;
	//Enable GPIOG peripheral clock for leds
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	GPIO_InitDef.GPIO_Pin = GPIO_Pin_8;		// this can be or'd
	GPIO_InitDef.GPIO_OType = GPIO_OType_PP;
	GPIO_InitDef.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitDef.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitDef.GPIO_Speed = GPIO_Speed_100MHz;
	//Initialize pins
	GPIO_Init(GPIOA, &GPIO_InitDef);
}

void gpio_init_mco2(void) {
	//GPIO Init structure
	GPIO_InitTypeDef GPIO_InitDef;
	//Enable GPIOG peripheral clock for leds
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

	GPIO_InitDef.GPIO_Pin = GPIO_Pin_9;		// this can be or'd
	GPIO_InitDef.GPIO_OType = GPIO_OType_PP;
	GPIO_InitDef.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitDef.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitDef.GPIO_Speed = GPIO_Speed_100MHz;
	//Initialize pins
	GPIO_Init(GPIOC, &GPIO_InitDef);
}
