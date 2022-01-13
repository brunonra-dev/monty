#include "monty.h"

/**
 * _sub - subtracts the top element of the stack from the second top element
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

/**
 * _div -  divides the second top element of the stack by the top element.
 *
 * @stack: Pointer to stack.
 * @line_number: line number.
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int div;

	if (!stack || !(*stack) || !((*stack)->next))
		monty_error(8, line_number, "div");

	if ((*stack)->n == 0)
		monty_error(9, line_number);

	(*stack) = (*stack)->next;
	div = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = div;

	free((*stack)->prev);
	(*stack)->prev = NULL;
}
