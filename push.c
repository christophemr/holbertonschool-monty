#include "monty.h"
/**
 * push - push a node onto the stack
 * @stack: stack
 * @line_number: line number in monty .m file
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *tmp;

	tmp = malloc(sizeof(stack_t)); /* not freed */
	if (tmp == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit_free(*stack);
		exit(EXIT_FAILURE);
	}
	tmp->n = globes.data;
	tmp->prev = NULL;
	tmp->next = NULL;
	if (*stack != NULL)
	{
		tmp->next = *stack;
		(*stack)->prev = tmp;
	}
	*stack = tmp;
}
