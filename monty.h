#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
/**
 * struct info_s - struct
 * @arg: value
 * @fp: pointer to monty file
 * @line: line content
 * @lif: flag change queue <-> stack
 * Description: stores values through the program.
 */
typedef struct info_s
{
	char *arg;
	FILE *fp;
	char *line;
	int lif;
} info_t;
extern info_t info;
void push(stack_t **head, unsigned int count);
void pall(stack_t **head, unsigned int count);
void free_stack(stack_t *head);
void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);
int exec_op(char *line, stack_t **stack, unsigned int count, FILE *fp);
#endif /* MONTY_H */