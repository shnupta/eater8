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
	uint8_t pc; // program counter
	
	// the three registers
	uint8_t A;
	uint8_t B;
	uint8_t IR; // instruction register

	uint8_t RAM[16]; //16 bytes of RAM as he only uses 4 bit memory addresses
	bool halt;
	int out;
} e8;

#endif	
