#include "e8.h"

int load_ram(e8 *cpu, char *filename)
{
	FILE *fileptr;
	uint8_t *buffer;
	long filelen;
	
	fileptr = fopen(filename, "rb");  // Open the file in binary mode
	fseek(fileptr, 0, SEEK_END);          // Jump to the end of the file
	filelen = ftell(fileptr);             // Get the current byte offset in the file
	rewind(fileptr);                      // Jump back to the beginning of the file

	buffer = (uint8_t *) malloc((filelen + 1) * sizeof(uint8_t));	
	fread(buffer, filelen, 1, fileptr); // Read in the entire file
	fclose(fileptr);
	
	for (int i = 0; i < filelen; i++) {
		cpu->RAM[i] = buffer[i];
	}	
	
	return 1;	
}

int init_e8(e8 *cpu)
{

	return 1;
}

int main(int argc, char *argv[])
{
	e8 *cpu;

	printf("Initialising CPU...\n");
	init_e8(cpu);

	printf("Loading program...\n");
	load_ram(cpu, argv[1]);
	return 0;
}
