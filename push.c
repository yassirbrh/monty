#include "monty.h"
/**
 * push -  Function
 *
 * @head: Head of stack.
 * @count: Line counter.
 *
 * Return: No return because it's a void function.
 */
void push(stack_t **head, unsigned int count)
{
	int i, j = 0, n, flag = 0;

	if (info.arg)
	{
		if (info.arg[0] == '-')
			j++;
		for (i = j; info.arg[i] != '\0'; i++)
		{
			if (info.arg[i] > 57 || info.arg[i] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", count);
			fclose(info.fp);
			free(info.line);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(info.fp);
		free(info.line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(info.arg);
	if (info.lif == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
