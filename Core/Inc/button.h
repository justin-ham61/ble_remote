/*
 * button.h
 *
 *  Created on: Jan 30, 2025
 *      Author: jiheo
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "stm32wbxx_hal.h"
#include "globals.h"
#include "structs.h"
#include "main.h"
#include "private_config.h"
#include "hw.h"

typedef struct {
	int sm1;
} Button_SM;

typedef struct {
	union{
		uint8_t all;
		struct{
			uint8_t left 		: 1;
			uint8_t right   	: 1;
			uint8_t up     		: 1;
			uint8_t down  		: 1;
			uint8_t select   	: 1;
			uint8_t all         : 1;
			uint8_t unused      : 2;
		} button_bit;
	};
	uint8_t err;
} Button_t;

extern Button_t button_handle;

extern uint16_t button_array[4];

void ButtonJob(void);
uint8_t addToQueue(Command_Package *command);

#endif /* INC_BUTTON_H_ */
