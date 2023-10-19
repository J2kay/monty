#include "monty.h"
/**
 * line_parse1 - tokenizes the lines read from the file
 * @s: pointer to a string
 * Return: double pointer to array of strings
 */
char **line_parse1(char *s)
{
	char **toks = NULL;
	int num = 0;
	char *token = NULL, *delimiter = "\n";

	toks = malloc(sizeof(char *) * 25);
	if (toks == NULL)
		return (NULL);

	token = strtok(s, delimiter);

	while (token != NULL)
	{
		toks[num] = token;
		token = strtok(NULL, delimiter);
		num++;
	}

	toks[num] = NULL;
	return (toks);
}
/**
 * line_parse2 - tokenizes the lines read from the file
 * @s: pointer to a string
 * Return: double pointer to array of strings
 */
char **line_parse2(char *s)
{
	char **toks = NULL;
	int num = 0;
	char *token = NULL, *delimiter = " \t\n";

	toks = malloc(sizeof(char *) * 25);
	if (toks == NULL)
		return (NULL);

	token = strtok(s, delimiter);

	while (token != NULL)
	{
		toks[num] = token;
		token = strtok(NULL, delimiter);
		num++;
	}

	toks[num] = NULL;
	return (toks);
}
