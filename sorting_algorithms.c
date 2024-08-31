#include "push_swap.h"
#include <stdio.h>

void	sort_small(t_stack *a)
{
	int	maxval;
	int	maxpos;

	maxval = max(a)->value;
	maxpos = find_value_position(a, maxval);
	if (stack_len(a) == 3)
	{
		if (maxpos == 0)
			rotate(a);
		if (maxpos == 1)
			reverse_rotate(a);
	}
	if ((stack_len(a) >= 2) && (a->head->value > a->head->next->value))
		swap(a);
}

static void	a_part(t_stack *a, t_stack *b)
{
	t_node	*to_push;

	while (stack_len(a) > 3)
	{
		give_targets(a, b);
		to_push = select_node_to_push(a, b);
		if (direction(to_push->value, a) == direction(to_push->target, b)
			&& node_cost(to_push->value, a) == node_cost(to_push->target, b))
		{
			sim_bring_to_head(to_push->value, a, b);
		}
		else
		{
			bring_to_head(to_push->value, a);
			bring_to_head(to_push->target, b);
		}
		push(a, b);
	}
}

static void	b_part(t_stack *a, t_stack *b)
{
	t_node	*to_push;

	while (b->head)
	{
		give_targets(b, a);
		to_push = select_node_to_push(b, a);
		if (direction(to_push->value, b) == direction(to_push->target, a)
			&& node_cost(to_push->value, b) == node_cost(to_push->target, a))
		{
			sim_bring_to_head(to_push->value, b, a);
		}
		else
		{
			bring_to_head(to_push->value, b);
			bring_to_head(to_push->target, a);
		}
		push(b, a);
	}
}

void	sort(t_stack *a, t_stack *b)
{
	int		i;

	i = 0;
	while (i < 2)
	{
		if (stack_len(a) > 3)
			push(a, b);
		i++;
	}
	a_part(a, b);
	sort_small(a);
	b_part(a, b);
	bring_to_head(min(a)->value, a);
}
