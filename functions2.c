#include "monty.h"

/**
 * _sub - Adds top two elements.
 *
 * @stack: Pointer stack.
 * @line_number: line number.
 */

void _sub(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (!stack || !(*stack) || !((*stack)->next))
		monty_error(8, line_number, "sub");

	(*stack) = (*stack)->next;
	sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sum;

	free((*stack)->prev);

	(*stack)->prev = NULL;
}
