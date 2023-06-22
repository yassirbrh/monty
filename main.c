#include "monty.h"
char *filename;
/**
 * main - Entry point
 *
 * Description: Monty program.
 *
 * @argc: Number of arguments passed to the program.
 * @argv: Pointer to the array of arguments.
 *
 * Return: 0 (Always)
 */
int main(int argc, char **argv)
{
	FILE *fp;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	filename = argv[1];
	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		fclose(fp);
		exit(EXIT_FAILURE);
	}
	fclose(fp);
	interface();
	return (0);
}
