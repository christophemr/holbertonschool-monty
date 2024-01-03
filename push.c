#include "monty.h"

/**
 * push - push a node to the stack
 * @stack: stack
 * @line_number: line number in the file
 * @value: value to be pushed onto the stack
 */

void push(stack_t **stack, unsigned int line_number, const char *value_str)
{
	int value = atoi(value_str);
	if (value == 0 && value_str[0] != '\0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		cleanup(*stack);
		exit(EXIT_FAILURE);
	}

	stack_t *temp;

	temp = malloc(sizeof(stack_t));
	if (temp == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		cleanup(*stack);
		exit(EXIT_FAILURE);
	}

	temp->n = value;
	temp->prev = NULL;
	temp->next = (*stack != NULL) ? *stack : NULL;

	if (*stack != NULL)
	{
		(*stack)->prev = temp;
	}

	*stack = temp;
}
