#include "monty.h"
#include <stdio.h>
char *value_n;
/**
 * f_read - reads lines from a file
 * @filename: file to read
 * Return: pointer to a string
*/
char *f_read(const char *filename)
{
	char *buffer = NULL, *content = NULL;
	size_t buff_len = 0;
	FILE *fd;
	ssize_t status, size = 0;

	fd = fopen(filename, "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((status = getline(&buffer, &buff_len, fd)) != -1)
	{
		content = realloc(content, size + status + 1);

		if (content == NULL)
		{
			fprintf(stderr, "Memory allocation error\n");
			exit(EXIT_FAILURE);
		}

		memcpy(content + size, buffer, status);
		size += status;
	}

	content[size] = '\0';
	fclose(fd);
	free(buffer);

	return (content);
}
/**
 * op_start - checks for opcode then executes
 * @stack: data structure in use
 * @toks: tokenized arguments
 * @line: line number
 * eturn: void
 */
void op_start(stack_t **stack, char **toks, int line)
{
	int i, instruction_found = 0;

	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop}
	};

	if (strlen(*toks) > 1 && toks[1] != NULL)
		value_n = toks[1];
	else
		value_n = NULL;

	if (toks[0] == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line, toks[0]);
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < 7; i++)
	{
		if (strcmp(toks[0], instructions[i].opcode) == 0)
			instructions[i].f(stack, line);
		instruction_found = 1;
	}
	if (!instruction_found)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line, toks[0]);
		exit(EXIT_FAILURE);
	}
}
/**
 * push - pushes an element to the stack
 * @head: pointer to the head of a list
 * @line_number: line number of the instruction
 * Return: void
 */
void push(stack_t **head, unsigned int line_number)
{
	stack_t  *newnode;

	if (value_n != NULL && strcmp("0", value_n) != 0  && atoi(value_n) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
		exit(EXIT_FAILURE);

	if (*head == NULL)
	{
		newnode->next = NULL;
		newnode->n = atoi(value_n);
		newnode->prev = NULL;
		*head = newnode;
	}
	else
	{
		newnode->n = atoi(value_n);
		newnode->next = (*head);
		*head = newnode;
	}

}
/**
 * pall - prints all the values on the stack
 * @head: pointer to the head of a list
 * @line_number: line number of the instruction
 * Return: void
 */
void pall(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	temp = *head;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}

}
/**
 * pint - prints the value at the top of the stack
 * @head: pointer to the head of a list
 * @line_number: line number of the instruction
 * Return: void
 */
void pint(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (*head == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_number);
	}
	temp = *head;

	printf("%d\n", temp->n);
}
