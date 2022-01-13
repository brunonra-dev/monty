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
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * _pint - prints the value at the top of the stack.
 *
 * @stack: Pointer to stack.
 * @line_number: line number.
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
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
 * _swap - Swaps the first two elements of the stack.
 *
 * @stack: Pointer to stack.
 * @line_number: Line number.
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		monty_error(8, line_number, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

