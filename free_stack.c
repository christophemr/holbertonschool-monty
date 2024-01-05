#include "monty.h"
/**
 * free_stack - free a stack with single ptr reference
 * @stack: pointer to a ll
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}
