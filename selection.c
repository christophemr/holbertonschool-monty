#include "monty.h"

/**
 * run_instruction - executes instruction based on the opcode
 * @stack: double pointer to the stack
 * @line_number: line number in the monty file
 * @opcode: opcode extracted
 */

void run_instruction(stack_t **stack, unsigned int line_number, char *opcode)
{
	static const instruction_t opc[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}};

	int index;

	for (index = 0; opc[index].opcode != NULL; index++)
	{
		if (strcmp(opcode, opc[index].opcode) == 0)
		{
			opc[index].f(stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number);
	cleanup(*stack);
	exit(EXIT_FAILURE);

}
