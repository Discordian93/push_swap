#include "push_swap.h"
#include <stdio.h>

int	node_cost(int sourcevalue, t_stack *sourcestack)
{
	int	source_direction;
	int	sourcecost;

	source_direction = direction(sourcevalue, sourcestack);
	if (source_direction == 0)
		sourcecost = stack_len(sourcestack)
			- find_value_position(sourcestack, sourcevalue);
	else
		sourcecost = find_value_position(sourcestack, sourcevalue);
	return (sourcecost);
}

int	compute_cost(int sourcevalue, int targetvalue,
t_stack *sourcestack, t_stack *targetstack)
{
	int	sourcecost;
	int	targetcost;
	int	source_direction;
	int	target_direction;

	source_direction = direction(sourcevalue, sourcestack);
	target_direction = direction(targetvalue, targetstack);
	sourcecost = node_cost(sourcevalue, sourcestack);
	targetcost = node_cost(targetvalue, targetstack);
	if (sourcecost == targetcost && source_direction == target_direction)
		return (sourcecost);
	else
		return (sourcecost + targetcost);
}
