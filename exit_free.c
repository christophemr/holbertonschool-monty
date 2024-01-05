#include "monty.h"
/**
 * exit_free - frees all possible allocs before exiting the program
 * @stack: ptr to a stack
 * Return: void
 */
void exit_free(stack_t *stack)
{
	fclose(globes.fm);
	if (globes.lineptr != NULL)
		free(globes.lineptr);
	free_stack(stack);
}