#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>

extern char *value_n;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * flor stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
int f_read(const char *filename, int count);
void op_start(stack_t **stack, char **toks, int line);
void push(stack_t **head, unsigned int line_number);
void pall(stack_t **head, unsigned int line_number);
void pint(stack_t **head, unsigned int line_number);
void pop(stack_t **head, unsigned int line_number);
void swap(stack_t **head, unsigned int line_number);
void add(stack_t **head, unsigned int line_number);
void nop(stack_t **head, unsigned int line_number);
void pstr(stack_t **head, unsigned int line_number);
void pchar(stack_t **head, unsigned int line_number);
void sub(stack_t **head, unsigned int line_number);
void mod(stack_t **head, unsigned int line_number);
void rotl(stack_t **head, unsigned int line_number);
void my_free(char **mem);
void free_stack(stack_t *head);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
char **line_parse1(char *s);
char **line_parse2(char *s);
int blank_line(const char *line);
#endif
