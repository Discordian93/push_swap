#include "push_swap.h"
#include <stdio.h>

int	find_target_in_b(t_node *node, t_stack *b)
{
	t_node	*current;
	t_node	*target_node;

	target_node = NULL;
	current = b->head;
	while (current)
	{
		if ((!target_node || current->value > target_node->value)
			&& (current->value < node->value))
		{
			target_node = current;
		}
		current = current->next;
	}
	if (!target_node)
		target_node = max(b);
	if (!target_node)
	{
		write(2, "unable to find target node in b\n", 32);
		exit(1);
	}
	return (target_node->value);
}

int	find_target_in_a(t_node *node, t_stack *a)
{
	t_node	*current;
	t_node	*target_node;

	target_node = NULL;
	current = a->head;
	while (current)
	{
		if ((!target_node || current->value < target_node->value)
			&& (current->value > node->value))
		{
			target_node = current;
		}
		current = current->next;
	}
	if (!target_node)
		target_node = min(a);
	if (!target_node)
	{
		write(2, "unable to find target node in a\n", 32);
		exit(1);
	}
	return (target_node->value);
}

void	give_targets(t_stack *sourcestack, t_stack *targetstack)
{
	t_node	*current;

	if (sourcestack->name == 'a')
	{
		current = sourcestack->head;
		while (current)
		{
			current->target = find_target_in_b(current, targetstack);
			current = current->next;
		}
	}
	else
	{
		current = sourcestack->head;
		while (current)
		{
			current->target = find_target_in_a(current, targetstack);
			current = current->next;
		}
	}
}

t_node	*select_node_to_push(t_stack*sourcestack, t_stack *targetstack)
{
	t_node	*chosen_node;
	t_node	*current;

	chosen_node = NULL;
	current = sourcestack->head;
	while (current)
	{
		if (!chosen_node
			|| compute_cost(current->value, current->target,
				sourcestack, targetstack)
			< compute_cost(chosen_node->value, chosen_node->target,
				sourcestack, targetstack))
		{
			chosen_node = current;
		}
		current = current->next;
	}
	if (!chosen_node)
	{
		write(2, "unable to select node to push\n", 30);
		exit(1);
	}
	return (chosen_node);
}
