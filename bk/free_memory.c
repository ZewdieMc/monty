#include "monty.h"

/**
 * free_stack - frees a stack_t list
 * @head: head of linked list
 */

void free_stack(stack_t *head)
{
	stack_t *current;
	stack_t *next;

	current = head;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

/**
 * free_lines - frees a line_t list
 * @lines: hpointer
 */
void free_lines(line_t *lines)
{
	int i = 0;

	while ((lines + i)->content != NULL)
	{
		free((lines + i)->content);
		i++;
	}
	free(lines);
}

