#include "monty.h"

/**
 * pop - removes top item from stack
 * @stack: stack
 * @line_number: line number in the file
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	/* added a check for an empty stack before attempting to pop */
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		cleanup(*stack);
		exit(EXIT_FAILURE);
	}

	temp = *stack;

	if (temp->next == NULL)
	{
		free(*stack);
		*stack = NULL;
	}
	else
	{
		(*stack) = (*stack)->next;
		(*stack)->prev = NULL;
		free(temp);
	}
}
