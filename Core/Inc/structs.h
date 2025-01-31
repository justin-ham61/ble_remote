/*
 * structs.h
 *
 *  Created on: Jan 30, 2025
 *      Author: jiheo
 */

#ifndef INC_STRUCTS_H_
#define INC_STRUCTS_H_

#include "stm32wbxx_hal.h"

#define BYTE uint8_t

enum mode {
	BOOT = 0,
	LOAD,
	MAIN_MENU,
	DEVICE,
};

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
		}button_bit;
	};
} Command_Package;

typedef struct {
	uint8_t number_of_devices;
	uint8_t current_mode;
} System_Config;
#endif /* INC_STRUCTS_H_ */
