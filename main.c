#include "monty.h"
info_t info = {NULL, NULL, NULL, 0};
/**
 * main - Entry point
 *
 * @argc: Number of arguments.
 * @argv: Arguments to the program.
 *
 * Return: 0 (Success)
 */
int main(int argc, char **argv)
{
	char *line;
	FILE *fp;
	ssize_t rd_line = 1;
	size_t size = 0;
	stack_t *stack = NULL;
	unsigned int count = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	info.fp = fp;
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (rd_line > 0)
	{
		line = NULL;
		rd_line = getline(&line, &size, fp);
		info.line = line;
		count++;
		if (rd_line > 0)
			exec_op(line, &stack, count, fp);
		free(line);
	}
	free_stack(stack);
	fclose(fp);
	return (0);
}
