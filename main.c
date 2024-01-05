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
	size_t linebuffer = 0;
	char *opcode;
	unsigned int line_number = 0;
	char *line = NULL;
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

	while ((readstatus  = getline(&line, &linebuffer, file)) != -1)
	{
		line_number++;
		opcode = strtok(line, " \n");
		if (opcode)
		{
			run_instruc(&stack, line_number, opcode);
		}
	}
	free(line);
	fclose(file);
	cleanup(stack);
	return (0);
}
