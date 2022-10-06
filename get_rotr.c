#include "monty.h"

/**
 *  get_rotr - Rotate the right
 *
 *  @stack: Stack
 *
 *  @line_number: Line number
 *
 *  Return: Void
 */
void get_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *last;

	(void)line_number;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		;
	}
	else
	{
		first = last = *stack;
		while (last->next)
		{
			last = last->next;
		}
		last->prev->next = NULL;
		last->prev = NULL;
		last->next = first;
		first->prev = last;
		*stack = last;
	}
}
