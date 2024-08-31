#include "push_swap.h"
#include <stdio.h>

void	bring_to_head(int val, t_stack *stack)
{
	if (direction(val, stack) == 0)
	{
		while (stack->head->value != val)
			reverse_rotate(stack);
	}
	else
	{
		while (stack->head->value != val)
			rotate(stack);
	}
}

void	sim_bring_to_head(int val, t_stack *a, t_stack *b)
{
	if (direction(val, a) == 0)
	{
		while (a->head->value != val)
			sim_reverse_rotate(a, b);
	}
	else
	{
		while (a->head->value != val)
			sim_rotate(a, b);
	}
}
