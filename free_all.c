#include "monty.h"
/**
 * free_all_strings - Function
 *
 * Description: Free all the array elements and the array.
 *
 * @arr: Pointer to the array of strings.
 *
 * Return: No return because it's a void function.
 */
void free_all_strings(char **arr)
{
	int i = 0;

	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
/**
 * free_stack - Function
 *
 * Description: Free the stack, and it's elements.
 *
 * @stack: Pointer to the stack.
 *
 * Return: No return because it's a void function.
 */
void free_stack(stack_t *stack)
{
	stack_t *node = stack, *prev;

	while (node != NULL)
	{
		prev = node;
		node = node->next;
		free(prev);
	}
}
