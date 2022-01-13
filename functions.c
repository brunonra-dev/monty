#include "monty.h"

/**
 * _pall - print stack.
 *
 * @stack: Pointer to stack.
 * @line_number: line number.
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void) line_number;

	if (!(stack))
		exit(EXIT_FAILURE);

	tmp = *stack;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * _pint - prints the top of the stack.
 *
 * @stack: Pointer to stack.
 * @line_number: line number.
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	if (!(stack) || !(*stack))
		monty_error(6, line_number);

	printf("%d\n", (*stack)->n);
}

/**
 * _nop - Does nothing
 *
 * @stack: Pointer to stack
 * @line_number: line number.
 */

void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * _swap - Swaps two elements of the stack.
 *
 * @stack: Pointer to stack.
 * @line_number: Line number.
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!(stack) || !(*stack) || !((*stack)->next))
		monty_error(8, line_number, "swap");

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = *stack;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * _add - Adds elements.
 *
 * @stack: Pointer to stack.
 * @line_number: line number.
 */

void _add(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (!(stack) || !(*stack) || !((*stack)->next))
		monty_error(8, line_number, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;

	free((*stack)->prev);

	(*stack)->prev = NULL;
}

