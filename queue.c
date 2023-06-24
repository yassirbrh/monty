#include "monty.h"
/**
 * queue - Function
 *
 * @stack: stack head
 * @line_number: line_number
 *
 * Return: No return because it's a void function.
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	info.flag = 1;
}

/**
 * addqueue - Function
 *
 * Description: add node to the tail of list.
 *
 * @n: New value
 * @stack: Head of the stack
 *
 * Return: No return because it's a void function.
 */
void addqueue(stack_t **stack, int n)
{
	stack_t *new, *node;

	node = *stack;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = NULL;
	if (node)
	{
		while (node->next)
			node = node->next;
	}
	if (!node)
	{
		*stack = new;
		new->prev = NULL;
	}
	else
	{
		node->next = new;
		new->prev = node;
	}
}

