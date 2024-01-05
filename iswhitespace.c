#include "monty.h"
/**
 * _iswhitespace - check for whitespace
 *
 * Return: 1 if only whitespace 0 if not only whitespace
 */
int _iswhitespace(void)
{
	int i, j;
	char *ws = "\r\n\t ";

	for (i = 0; globes.lineptr[i] != '\0'; i++)
		for (j = 0; ws[j] != '\0' && ws[j] != globes.lineptr[i]; j++)
			if (ws[j] == '\n')
				return (0);
	return (1);
}
