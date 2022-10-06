#include "monty.h"
#define BUFSIZE 64

char *operand;

/**
 * main - monty interpreter
 * @argc: int
 * @argv: list of arguments
 * Return: nothing
 */
int main(int argc, char const *argv[])
{
	line_t *lines;
	char **line;
	int line_number;
	stack_t *stack;
	char *content;
	void (*func)(stack_t**, unsigned int);

	stack = NULL;

	if (argc == 1)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	lines = textfile_to_array(argv[1]);
	if (lines == NULL)
		return (0);

	line_number = 0;
	while ((lines + line_number)->content != NULL)
	{
		content = (lines + line_number)->content;
		line = split_line(content);
		operand = line[1];

		func = get_op_func(line[0]);
		if (func == NULL)
		{
			/*TODO: Refactor: Edit more efifcient way to free memory on exit*/
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number + 1, line[0]);
			free(line);
			free_stack(stack);
			free_lines(lines);
			exit(EXIT_FAILURE);
		}

		func(&stack, line_number + 1);
		free(line);
		line_number++;
	}

	free_stack(stack);
	free_lines(lines);
	return (0);
}
