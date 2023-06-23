#include "monty.h"
/**
 * free_stack - Function
 *
 * Description: Frees a linked list.
 *
 * @head: Head of the stack.
 *
 * Return: No return because it's a void function.
 */
void free_stack(stack_t *head)
{
	stack_t *node;

	node = head;
	while (head)
	{
		head = head->next;
		free(node);
		node = head;
	}
}
