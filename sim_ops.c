#include "push_swap.h"

void	sim_rotate(t_stack *a, t_stack *b)
{
	silent_rotate(a);
	silent_rotate(b);
	write(1, "rr\n", 3);
}

void	sim_reverse_rotate(t_stack *a, t_stack *b)
{
	silent_reverse_rotate(a);
	silent_reverse_rotate(b);
	write(1, "rrr\n", 4);
}

void	swap(t_stack *stack)
{
	t_node	*second;
	t_node	*tmp;

	if (stack == NULL || stack_len(stack) <= 1)
		return ;
	second = stack->head->next;
	tmp = stack->head;
	tmp->next = second->next;
	second->next = tmp;
	stack->head = second;
	write(1, "s", 1);
	write(1, &(stack->name), 1);
	write(1, "\n", 1);
}
