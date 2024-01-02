#include "monty.h"

/**
 * cleanup - Cleans up the allocated memory associated with the stack
 * @stack: Pointer to the to of the stack.
 */

void cleanup(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
}

