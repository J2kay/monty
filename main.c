#include "main.h"
/**
 * main - entry point for program
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	char *file = NULL;
	char **content, **tok_line;
	int i, count = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = f_read(argv[1]);
	content = line_parse1(file);
	count = 1;

	for (i = 0; content[i] != NULL; i++)
	{
		tok_line = line_parse2(content[i]);
		op_start(&stack, tok_line, count);
		count++;
	}
	return (0);
}
