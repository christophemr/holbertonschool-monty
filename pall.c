#include "monty.h"

/**
 * pall - prints all the values on the stack
 * @stack: stack
 * @line_number: current line number
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void) line_number;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
