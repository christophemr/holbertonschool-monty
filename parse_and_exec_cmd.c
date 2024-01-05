#include "monty.h"
/**
 * parse_and_exec_cmd - parses and executes commands
 * @stack: pointer to the stack
 * @line: command
 * @line_number: line number in the file
 * Return: 1 on succes 0 on failure
 */
int parse_and_exec_cmd(stack_t **stack, char *line, unsigned int line_number)
{
	char *token;
	int integer;

	token = strtok(line, " \n");
	if (!token)
		return (1);

	if (execute_opcode(stack, token, line_number))
		return (1);

	if (strcmp(token, "push") == 0)
	{
		token = strtok(NULL, " ");
		if (token)
		{
			if (is_digit(token))
			{
				integer = atoi(token);
				push(stack, integer, line_number);
				return (1);
			}
		}
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		cleanup(stack);
		exit(EXIT_FAILURE);
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
	cleanup(stack);
	exit(EXIT_FAILURE);
}

