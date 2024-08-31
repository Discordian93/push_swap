#include "push_swap.h"
#include <stdio.h>

int	stack_len(t_stack *stack)
{
	t_node	*node;
	int		len;

	len = 0;
	node = stack->head;
	while (node)
	{
		len++;
		node = node->next;
	}
	return (len);
}

int	find_value_position(t_stack *stack, int value)
{
	t_node	*node;
	int		position;

	position = 0;
	node = stack->head;
	while (node)
	{
		if (node->value == value)
			return (position);
		position++;
		node = node->next;
	}
	write(2, "fucked, fucked, not in it\n", 26);
	exit(1);
	return (-1);
}

t_node	*max(t_stack *stack)
{
	t_node	*current;
	t_node	*max_node;

	max_node = NULL;
	current = stack->head;
	while (current)
	{
		if (!max_node || current->value > max_node->value)
			max_node = current;
		current = current->next;
	}
	return (max_node);
}

t_node	*min(t_stack *stack)
{
	t_node	*current;
	t_node	*min_node;

	min_node = NULL;
	current = stack->head;
	while (current)
	{
		if (!min_node || current->value < min_node->value)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}

int	direction(int sourcevalue, t_stack *sourcestack)
{
	return (find_value_position(sourcestack, sourcevalue)
		<= (stack_len(sourcestack) / 2));
}
