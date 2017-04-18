#ifndef _EATER_8_H
#define _EATER_8_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct e8 {
	uint8_t opcode;
	uint8_t pc;
	uint8_t A;
	uint8_t B;
	uint8_t RAM[512];
} e8;

#endif	
