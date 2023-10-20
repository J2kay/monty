#include "monty.h"
/**
 * pstr - prints the string starting at the top of the stack
 * @head: pointer to the head of a node list
 * @line_number: line number
 * Return: void
 */
void pstr(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	if (*head == NULL)
	{
		printf("\n");
	}
	temp = *head;
	while (temp)
	{
		if (temp->n > 127 || temp->n <= 0)
		{
			break;
		}
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}
/**
 * pchar - prints the char at the top of the stack
 * @head: pointer to the head of a node list
 * @line_number: line number
 * Return: void
 */
void pchar(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n > 127 || (*head)->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}
/**
 * sub - subtracts the top element of the stack from the second top element
 * @head: pointer to the head of a node list
 * @line_number: line number
 * Return: void
 */
void sub(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	unsigned int sub;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	sub = temp->next->n - temp->n;
	temp->next->n = sub;
	*head = temp->next;
	free(temp);
}
