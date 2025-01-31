/*
 * button.c
 *
 *  Created on: Jan 30, 2025
 *      Author: jiheo
 */


#include <button.h>

Button_t button_handle;

uint16_t button_array[4] = {
	LEFT_BUTTON_Pin,
	RIGHT_BUTTON_Pin,
	UP_BUTTON_Pin,
	DOWN_BUTTON_Pin
};

void ButtonJob(void){
	int i;
    APP_DBG_MSG("HELLO FROM BUTTON------------------------\n");
	button_handle.all = 0;
	for (i = 0; i < MAX_BUTTONS; i++) {
		if(!(HAL_GPIO_ReadPin(GPIOA, button_array[i]) & 1)) {
			button_handle.all |= (1 << i);

		}
	}
	if(button_handle.all != 0){
		Command_Package *command;
		command->all = button_handle.all;
		if(addToQueue(command) == 0){

		}
	}
	// exit if no button press is detected
}

uint8_t addToQueue(Command_Package *command){
	if(command == NULL){
		return 0;
	}
	switch(system_config.current_mode){
	case BOOT:
		break;
	case LOAD:
		break;
	case MAIN_MENU:
		addToCmdBuff(command);
		break;
	case DEVICE:
		break;
	}
	return 1;
}


