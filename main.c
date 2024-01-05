#include "monty.h"
/**
 * main: Entry point
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
        FILE *monty_file;
        char *monty_line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	monty_file = fopen(argv[1], "r");
	if (!monty_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&monty_line, &len, monty_file) != -1)
	{
	      line_number++;
	      if (!parse_and_exec_cmd(&stack, monty_line, line_number))
	      {
	      		fclose(monty_file);
			free(monty_line);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
	}

	fclose(monty_file);
	free(monty_line);
	free_stack(stack);
	return (EXIT_SUCCESS);

}
