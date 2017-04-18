#include "e8.h"


void decode_opcode(e8 *cpu)
{
	//printf("%d\n", cpu->pc);
	uint8_t op = HIGH_NIBBLE(cpu->opcode);
	
	//printf("%d\n", op);	

	switch(op) {
		// NOP
		case 0b0000:
			break;
	
		// LDA
		case 0b0001:
			cpu->A = cpu->RAM[LOW_NIBBLE(cpu->opcode)];
			break;

		// ADD
		case 0b0010:
			cpu->A = (int) cpu->A + (cpu->RAM[LOW_NIBBLE(cpu->opcode)]);
			break;

		// SUB
		case 0b0011:
			// not impl
			break;

		// STA
		case 0b0100:
			//not impl
			break;
		
		// OUT 
		case 0b0101:
			cpu->out = (int) cpu->A;
			break;

		// JMP
		case 0b0110:
			//not impl
			break;
	
		// LDI
		case 0b0111:
			// not impl
			break;

		// JC
		case 0b1000:
			//not impl
			break;
	
		// HLT
		case 0b1111:
			cpu->halt = true;
			break;

		default:
			printf("Unrecognized opcode\n");
			exit(1);			

	}			
}


int load_ram(e8 *cpu, char *filename)
{
	FILE *fileptr;
	uint8_t *buffer;
	long filelen;
	
/*
	fileptr = fopen(filename, "rb");  // Open the file in binary mode
	fseek(fileptr, 0, SEEK_END);          // Jump to the end of the file
	filelen = ftell(fileptr);             // Get the current byte offset in the file
	rewind(fileptr);                      // Jump back to the beginning of the file

	buffer = (uint8_t *) malloc((filelen + 1) * sizeof(uint8_t));	
	fread(buffer, filelen, 1, fileptr); // Read in the entire file
	fclose(fileptr);
	
	for (int i = 0; i < filelen; i++) {
		cpu->RAM[i] = buffer[i];
		printf("%d", buffer[i]);
	}	
*/

	cpu->RAM[0b0000] = 0b00010100;
	cpu->RAM[0b0001] = 0b00100101;
	cpu->RAM[0b0010] = 0b01010000;
	cpu->RAM[0b0011] = 0b11110000;
	cpu->RAM[0b0100] = 0b00001110;
	cpu->RAM[0b0101] = 0b00011100;
	
	return 1;	
}

int init_e8(e8 *cpu)
{
	cpu->halt = 0;
	cpu->A = 0;
	cpu->B = 0;
	cpu->pc = 0b0000;
	cpu->out = -1;
	memset(cpu->RAM, 0, 512);
	
	return 1;
}

int main(int argc, char *argv[])
{
	e8 cpu;

	printf("Initialising CPU...\n");
	init_e8(&cpu);

	printf("Loading program...\n");
	load_ram(&cpu, argv[1]);

	int i = 0;
	while(!cpu.halt) {
		cpu.opcode = cpu.RAM[cpu.pc];
		//printf("%d\n", cpu.opcode);
		decode_opcode(&cpu);
		cpu.pc += 0b0001;
		i++;
	}

	printf("%d\n", cpu.out);		

	return 0;
}
