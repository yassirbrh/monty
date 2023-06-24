#include "monty.h"
/**
 * addnode - Function
 *
 * Description: Add node to the head of stack.
 *
 * @stack: Head of stack.
 * @n: Value to add in the node.
 *
 * Return: No return because it's a void function.
 */
void addnode(stack_t **stack, int n)
{
	stack_t *new, *node = *stack;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (node != NULL)
		node->prev = new;
	new->n = n;
	new->next = *stack;
	new->prev = NULL;
	*stack = new;
}
