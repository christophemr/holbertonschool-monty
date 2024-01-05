#include "monty.h"

/**
 * run_instruc - executes instruction based on the opcode
 * @stack: double pointer to the stack
 * @line_number: line number in the monty file
 * @opcode: opcode handled
 */

void run_instruc(stack_t **stack, unsigned int line_number, char *opcode)
{
	if ( strcmp(opcode, "push" == 0)
	{
		char *av_count = strtok(NULL, " \n");

		if (!av_count || !is_digit(av_count))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exite(EXIT_FAILURE);
		}
		push(stack, atoi(av_count), line_number);
	}
	else if (strcmp(opcode, "pall") == 0)
		pall(stack);
	else if (strcmp(opcode, "pint") == 0)
                pall(stack);
	else if (strcmp(opcode, "pop") == 0)
                pop(stack);
	else if (strcmp(opcode, "swap") == 0)
                swap(stack);
	else if (strcmp(opcode, "add") == 0)
                add(stack);
	else if (strcmp(opcode, "nop") == 0)
                nop(stack);
	else
	{

		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);

}
