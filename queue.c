#include "monty.h"
/**
 * f_queue - Function
 *
 * @head: stack head
 * @count: line_number
 *
 * Return: No return because it's a void function.
 */
void f_queue(stack_t **head, unsigned int count)
{
	(void)head;
	(void)count;
	info.lif = 1;
}

/**
 * addqueue - Function
 *
 * Description: add node to the tail of list.
 *
 * @n: New value
 * @head: Head of the stack
 *
 * Return: No return because it's a void function.
 */
void addqueue(stack_t **head, int n)
{
	stack_t *new, *node;

	node = *head;
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
		*head = new;
		new->prev = NULL;
	}
	else
	{
		node->next = new;
		new->prev = node;
	}
}

