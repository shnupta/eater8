#ifndef _EATER_8_H
#define _EATER_8_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#define LOW_NIBBLE(byte) byte & 0x0f
#define HIGH_NIBBLE(byte) (byte & 0xf0) >> 4

typedef struct e8 {
	uint8_t opcode;
	uint8_t pc;
	uint8_t A;
	uint8_t B;
	uint8_t RAM[512];
	bool halt;
	int out;
} e8;

#endif	
