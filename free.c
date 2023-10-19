#include "main.h"
/**
* my_free - frees any allocated memory after use
* @mem: pointer pointer to mem to be freed
*/
void my_free(char **mem)
{
	int i;

	if (mem != NULL)
	{
		for (i = 0; mem[i] != NULL; i++)
		{
			free(mem[i]);
		}
		free(mem);
	}
}

/**
* free_stack - frees the stack
* @head: pointer to the top of the stack
*/
void free_stack(stack_t *head)
{
	stack_t *temp;

	temp = head;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
