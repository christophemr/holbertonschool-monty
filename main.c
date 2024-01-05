#include "monty.h"
/**
 * main - main function for monty interpreter
 * @argc: arg count
 * @argv: arg vector list
 * Return: 0 on success or EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	char opcode[6] = {0}, wrong[1024] = {0};
	ssize_t read;
	size_t len, matches = 0;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	globes.fm = NULL;
	globes.fm = fopen(argv[1], "r");
	if (globes.fm == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		fclose(globes.fm);
		exit(EXIT_FAILURE);
	}
	globes.lineptr = NULL;
	while ((read = getline(&globes.lineptr, &len, globes.fm)) != -1)
	{
		line_number++;
		if (!_iswhitespace())
		{
			matches = sscanf(globes.lineptr, "%s%d%1s", opcode, &globes.data, wrong);
			if (matches != 2 && strcmp(opcode, "push") == 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit_free(stack);
				exit(EXIT_FAILURE);
			}
			if (opcode != NULL && opcode[0] != '#')
				parse_exec_cmd(&stack, line_number, opcode);
		}
		free(globes.lineptr);
		globes.lineptr = NULL;
	}
	exit_free(stack);
	return (0);
}

