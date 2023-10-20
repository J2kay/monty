#include "monty.h"
#include <ctype.h>
/**
 * blank_line - checks if line is blank
 * @line: line to check
 * Return: 1 if line is blank
 */
int blank_line(const char *line)
{
	while (*line != '\0')
	{
		if (!isspace((unsigned char)*line))
			return (0);
		line++;
	}
	return (1);
}

