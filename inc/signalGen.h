/**
 * @file        signalGen.h
 *
 * @date
 * @author      Manuel Del Basso (mainster)
 * @email       manuel.delbasso@gmail.com
 *
 * @ide         System Workbench ac6 (eclipse stm32)
 * @stdperiph   STM32F4xx Standard peripheral drivers version 1.4.0 or greater required
 * @license     GNU GPL v3
 *
 * @brief       Provides DAC driven signal generator functions.
 *
   @verbatim

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

    @endverbatim
 *
 */
#ifndef _SIGNALGEN_H
#define _SIGNALGEN_H

#ifdef __cplusplus
 extern "C" {
#endif 
    
#include <stdio.h>

/**
 * @addtogroup MD_APP
 * @{
 */

/**
 * @addtogroup  APP_Signal_Gen Signal generator
 * @{
 */

/**
 * @addtogroup Signal_Gen_Macros
 * @{
 */

/**
 * @brief      Vector length definition for 2D array column number. 
 */
#define N_TUPEL   3

/** @} */

/**
 * @addtogroup Signal_Gen_Typedefs
 * @{
 */

/**
 * @brief      Waveform parameters for triangular waveforms.
 * @note       The amplitude value could be derived by @tex{(top-bottom)\cdot
 *             n_{OVF}} where @tex{n_{OVF}} describes the amount of timer
 *             overflows.
 */
struct triangWave {
    uint16_t    triCtr;     //!< Counter variable.
    float       bottom;     //!< @tex{-V_{peak}} value.
    float       top;        //!< @tex{+V_{peak}} value.
    float       derivate;   /**< derivative to increase V-DAC by Amplitude after n Timer Ovf's */
};

/** @} */

/**
 * @addtogroup Signal_Gen_Arrays
 * @{
 */

/* TODO */
static int16_t Cosine[] __attribute__ ((unused)) = {
    0, 889, 1601, 1997, 1997, 1601, 889, 0
};


/* TODO */
static float CosineN[ ] __attribute__ ((unused)) = {
    0, 4.338837e-01, 7.818315e-01, 9.749279e-01,
    9.749279e-01, 7.818315e-01, 4.338837e-01, 1.224647e-16
};


/* TODO */
static int16_t calcTab[ ] __attribute__ ((unused)) = {
    -2048, -1463, -878, -293, 3803, 3217, 2632, 2048
};


/* TODO */
static int16_t Quadratic[ ] __attribute__ ((unused)) = {
    -2048, -2027, -1964, -1860, -1714, -1526, -1296, -1024
};


/* TODO */
static int16_t I_Quadratic[ ] __attribute__ ((unused)) = {
    2048, 2027, 1964, 1860, 1714, 1526, 1296, 1024
};


/* TODO */
static int16_t Sawtooth[ ] __attribute__ ((unused)) = {
    -2048, -1755, -1463, -1170, -878, -585, -293, 0
};

static uint8_t interrupterBuff[] = { 0, 1, 0, 1 };

/* TODO */
static float squarewaveBuff[] __attribute__ ((unused)) =     { 1, -1, '\0' };

// extern uint16_t vectorCtr;

/* TODO */
static float line1[ ][N_TUPEL] __attribute__ ((unused)) = {
    { 0.000000, -1.250019,  0.000000},
    { 1.000000, -1.015640,  0.000000},
    { 0.000000, -0.844739,  0.000000},
    { 1.000000, -0.737316,  0.000000},
    { 0.000000, -0.368658,  0.000000},
    { 1.000000, -0.070802,  0.000000},
    { 0.000000,  0.058595,  0.000000},
    { 1.000000,  0.605478,  0.000000},
    { 0.000000,  0.717784,  0.000000},
    { 1.000000,  0.852064,  0.000000},
    { 0.000000,  0.969253,  0.000000},
    { 1.000000,  1.084001,  0.000000},
    { 0.000000,  1.188983,  0.000000}
};

/* TODO */
static float line2[ ][N_TUPEL] __attribute__ ((unused)) = {
    {1.000000, -0.900000, 0.000000},
    {0.000000, -0.800000, 0.000000},
    {1.000000, -0.700000, 0.000000},
    {0.000000, -0.600000, 0.000000},
    {1.000000, -0.500000, 0.000000},
    {0.000000, -0.400000, 0.000000},
    {1.000000, -0.300000, 0.000000},
    {0.000000, -0.200000, 0.000000},
    {1.000000, -0.100000, 0.000000},
    {0.000000, 0.000000, 0.000000},
    {1.000000, 0.100000, 0.000000},
    {0.000000, 0.200000, 0.000000},
    {1.000000, 0.300000, 0.000000},
    {0.000000, 0.400000, 0.000000},
    {1.000000, 0.500000, 0.000000},
    {0.000000, 0.600000, 0.000000},
    {1.000000, 0.700000, 0.000000},
    {0.000000, 0.800000, 0.000000},
    {1.000000, 0.900000, 0.000000},
    {0.000000, 1.000000, 0.000000}
};

/** @} */

/**
 * @addtogroup Signal_Gen_Variables
 * @{
 */

/**
 * @brief      External defined triangWave structure.
 */
extern struct triangWave triStruct;

/**
 * @brief      DAC values sequence pointer.
 *
 *             This pointer is used in case of enabled waveform generator and
 *             provides dynamically switching between different waveforms.
 */
static int16_t *pSeq __attribute__ ((unused)) = NULL;

/**
 * @brief      DAC values sequence pointer for float represented waveform buffers.
 *
 *             This pointer is used in case of enabled waveform generator and
 *             provides dynamically switching between different waveforms.
 */
static float *pSeq_f __attribute__ ((unused)) = NULL;

/**
 * Feature in progress.
 * TODO: Implement.
 */
static unsigned short cSeq __attribute__ ((unused));

/**
 * @brief      Signal generator Integer array pointer.
 */
static uint8_t *pInt __attribute__ ((unused)) = &interrupterBuff[0];

/** @} */

/**
 * @addtogroup Signal_Gen_Functions
 * @{
 */

/** @} */

/** @} */

/** @} */

#ifdef __cplusplus
}
#endif

#endif
    
