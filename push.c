 #include "monty.h"
/**
 * push - push an element onto the stack
 * @stack: pointer to the stack
 * @line_number: current line number
 * Return: void
 */
void push(stack_t **stack, int n, unsigned int line_number)
{

	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "L%d: Error: malloc failed\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->next = *stack;
	new_node->prev = NULL;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}

