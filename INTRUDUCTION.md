# Project XY-GalvoScanner

## Introduction

## Determine base addresses of peripheral registers

```c
/* From CMSIS/device/stm32f4xx.h: */
#define PERIPH_BASE         ((uint32_t)0x40000000)
#define APB1PERIPH_BASE     PERIPH_BASE
#define DAC_BASE            (APB1PERIPH_BASE + 0x7400)

/* From DM00031020.pdf
 * (14.5.15 DAC register map): 
 * ------------------------------- 
 * DAC_DHR12R1_Reg_Offset  = 0x08 
 * DAC_DHR12R2_Reg_Offset  = 0x14 
 * DAC_DHR8R1_Reg_Offset   = 0x10 
 * DAC_DHR8R2_Reg_Offset   = 0x1C 
 */

/* RegisterAddress = DAC_BASE + DAC_DHR*_Reg_Offset */

#define  DAC_DHR12R1_ADDRESS     0x40007408
#define  DAC_DHR12R2_ADDRESS     0x40007414
#define  DAC_DHR8R1_ADDRESS      0x40007410
#define  DAC_DHR8R2_ADDRESS      0x40007410
```
