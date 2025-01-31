/*
 * globals.c
 *
 *  Created on: Jan 30, 2025
 *      Author: jiheo
 */

#include "globals.h"

void addToCmdBuff(Command_Package *cmd){
	system_buffs.cmd_buff[((system_buffs.cmd_index + 1) % CMD_BUFF_SIZE)] = *cmd;
}

