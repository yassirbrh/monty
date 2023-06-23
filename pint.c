#include "monty.h"
/**
 * pint - Function
 *
 * Description: Prints the top of the stack.
 *
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number.
 *
 * Return: No return because it's a void function.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(info.fp);
		free_stack(*stack);
		free(info.line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
