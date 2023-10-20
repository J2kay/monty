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
