/*
 * celka.h
 *
 *  Created on: Jul 27, 2024
 *      Author: Miha
 */

#ifndef CELKA_INC_CELKA_H_
#define CELKA_INC_CELKA_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "main.h"
#include "adc.h"
#include "tim.h"
#include "gpio.h"

/* USER CODE BEGIN Private defines */
#define TEMP_TH 1850	//4095 -> 3V3
#define BATT_TH 1850	//4095 -> 3V3

#define TEMP_LOCATION	0
#define BATT_LOCATION	1
/* USER CODE END Private defines */


/* USER CODE BEGIN Private typeDef */

typedef enum
{
	LAMP_OFF		= 0,
	LAMP_ON			= 1,
	LAMP_SETUP_ON	= 2,
	LAMP_SETUP_OFF	= 3
} LampStatus_t;


typedef enum
{
	LAMP_OK			= 0,
	LAMP_BATT_ERR	= 1,
	LAMP_TEMP_ERR	= 2,
} LampStatus_ERR_t;

typedef struct
{
	LampStatus_t status;
	LampStatus_t setup;
	LampStatus_ERR_t helth;
	uint8_t button;
	uint32_t ADC_Results[2];

}LAMP_HandleTypedef;
/* USER CODE END Private typeDef */


/* USER CODE BEGIN Prototypes */
void Lamp_Start(void);
void Lamp_SetPower(void);
void Lamp_DeInit(void);
//void Lamp_CheckCondition(void);
/* USER CODE END Prototypes */


#ifdef __cplusplus
}
#endif

#endif /* CELKA_INC_CELKA_H_ */
