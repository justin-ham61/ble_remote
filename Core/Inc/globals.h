/*
 * globals.h
 *
 *  Created on: Jan 30, 2025
 *      Author: jiheo
 */

#ifndef INC_GLOBALS_H_
#define INC_GLOBALS_H_

#include "structs.h"

#define CMD_BUFF_SIZE 48


typedef union {
    uint8_t all_flags;  // Access all flags as a byte
    struct {
        uint8_t cmd_flag   	: 1;
        uint8_t unused   	: 7;  // Reserve bits for future use
    } flags;
} Global_Flags_t;


typedef struct {
	int cmd_index;
	Command_Package cmd_buff[CMD_BUFF_SIZE];
}System_Buffs_t;

extern System_Buffs_t system_buffs;
extern Global_Flags_t global_flags;
extern System_Config system_config;

void addToCmdBuff(Command_Package *cmd);


#endif /* INC_GLOBALS_H_ */
