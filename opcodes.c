#include "monty.h"
/**
 * pop - removes the top element of the stack
 * @head: pointer to the head of a list
 * @line_number: line number of the instruction
 * Return: void
 */
void pop(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an stack empty\n", line_number + 1);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = (*head)->next;
	free(temp);
	temp = NULL;
}
/**
 * swap - swaps the top two elements of a stack
 * @head: pointer to the head of a list
 * @line_number: line number of the instruction
 * Return: void
 */
void swap(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	int v, count = 0;

	temp = *head;

	while (temp)
	{
		temp = temp->next;
		count++;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	v = temp->n;
	temp->n = temp->next->n;
	temp->next->n = v;

}
/**
 * add - adds the top two elements of a stack
 * @head: pointer to the head of a list
 * @line_number: line number of the instruction
 * Return: void
 */
void add(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *head;

	temp->next->n = temp->n + temp->next->n;

	*head = (*head)->next;
	free(temp);
}
/**
 * nop - does nothing
 * @head: pointer to the head of a list
 * @line_number: line number of the instruction
 * Return: void
 */
void nop(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
}
