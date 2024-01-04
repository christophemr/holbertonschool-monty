#include "monty.h"
extern instruction_t opc[];
/**
 * main: Entry point
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 (Succes)
 */
int main(int argc, char *argv[])
{
	FILE *file;
	int readstatus = 1;
	char *linebuffer, *opcode;
	unsigned int line_number;
	stack_t *stack = NULL;


	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (readstatus > 0)
	{
		linebuffer = NULL;
		readstatus = getline(&linebuffer, &(size_t){0}, file);
		line_number++;
		if (readstatus > 0 && linebuffer[0] != '#' && linebuffer[0] != '\n')
		{
			opcode = strtok(linebuffer, " \n");
			run_instruction(&stack, line_number, opcode);
		}
		free(linebuffer);
	}
	cleanup(stack);
	fclose(file);return (0);
}
