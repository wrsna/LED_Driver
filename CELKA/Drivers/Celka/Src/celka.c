/*
 * celka.c
 *
 *  Created on: Jul 27, 2024
 *      Author: Miha
 */

#include "celka.h"


LAMP_HandleTypedef hlamp;


void Lamp_Start(void)
{

	if(hlamp.status == LAMP_OFF)
	{
		hlamp.status = LAMP_ON;

		MX_DMA_Init();
	    MX_ADC1_Init();
	    MX_TIM14_Init();
	    MX_TIM3_Init();

		// start 5s setup timer
		if(HAL_TIM_Base_Start_IT(&htim14) != HAL_OK)
		{
			Error_Handler();
		}


		hlamp.setup = LAMP_SETUP_ON;

		// start adc timer
		if(HAL_TIM_Base_Start(&htim3) != HAL_OK)
		{
			Error_Handler();
		}



		if(HAL_ADC_Start_DMA(&hadc1, hlamp.ADC_Results, 2) != HAL_OK)
		{
			Error_Handler();
		}
	}

}


void Lamp_SetPower(void)
{

	if(hlamp.setup == LAMP_SETUP_ON)
	{
		switch(hlamp.button)
		{
		case 1:
			__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, 300);
			break;
		case 2:
		    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, 600);
			break;
		case 3:
		    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, 1000);
			break;
		default:
		    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, 0);
		    Lamp_DeInit();

		    hlamp.button = 0;
		    hlamp.status = LAMP_OFF;
		    hlamp.setup = LAMP_SETUP_OFF;
			break;
		}

	}
	// turn off lamp
	else
	{
		__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, 0);

		Lamp_DeInit();
		hlamp.status = LAMP_OFF;
		hlamp.button = 0;
	}

	//forcee low state (batt, Temp)
	if((hlamp.helth != LAMP_OK) && (hlamp.status != LAMP_OFF))
	{
		__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, 300);
	}

}

void Lamp_DeInit(void)
{
	//#############ADC_Deinit################################
	if(HAL_ADC_Stop_DMA(&hadc1) != HAL_OK)
	{
		Error_Handler();
	}


	if(HAL_ADC_DeInit(&hadc1) != HAL_OK)
	{
		Error_Handler();
	}
	//#######################################################



	//###########5sTIM_Deinit################################
	if(HAL_TIM_OnePulse_Stop_IT(&htim14,0) != HAL_OK)
	{
		Error_Handler();
	}
	if(HAL_TIM_OnePulse_DeInit(&htim14) != HAL_OK)
	{
		Error_Handler();
	}
	if(HAL_TIM_Base_DeInit(&htim14) != HAL_OK)
	{
		Error_Handler();
	}
	//#######################################################




	//#############PWM_OUT_Deinit############################

	//#######################################################




	//###########ADC_Triger_Deinit##########################
	if(HAL_TIM_Base_Stop(&htim3) != HAL_OK)
	{
		Error_Handler();
	}
	if(HAL_TIM_Base_DeInit(&htim3) != HAL_OK)
	{
		Error_Handler();
	}
	//######################################################

}

/*
void Lamp_CheckCondition(void)
{
	if((hlamp.status == LAMP_ON) && ((hlamp.ADC_Results[1] <= TEMP_TH) || (hlamp.ADC_Results[2] >= BATT_TH)))
	{
		__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, 300);
	}
}
*/
