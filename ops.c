#include "push_swap.h"

void	silent_rotate(t_stack *stack)
{
	t_node	*head;
	t_node	*current;

	if (stack == NULL || stack_len(stack) <= 1)
		return ;
	head = stack->head;
	stack->head = stack->head->next;
	head->next = NULL;
	current = stack->head;
	while (current->next)
		current = current->next;
	current->next = head;
}

void	rotate(t_stack *stack)
{
	silent_rotate(stack);
	write(1, "r", 1);
	write(1, &(stack->name), 1);
	write(1, "\n", 1);
}

void	push(t_stack *a, t_stack *b)
{
	t_node	*head;

	if (a == NULL || b == NULL || stack_len(a) == 0)
		return ;
	head = a->head;
	a->head = head->next;
	head->next = b->head;
	b->head = head;
	write(1, "p", 1);
	write(1, &(b->name), 1);
	write(1, "\n", 1);
}

void	silent_reverse_rotate(t_stack *stack)
{
	t_node	*pretail;
	t_node	*tail;

	if (stack == NULL || stack_len(stack) <= 1)
		return ;
	pretail = stack->head;
	tail = stack->head->next;
	while (tail->next)
	{
		pretail = tail;
		tail = tail->next;
	}
	pretail->next = NULL;
	tail->next = stack->head;
	stack->head = tail;
}

void	reverse_rotate(t_stack *stack)
{
	silent_reverse_rotate(stack);
	write(1, "rr", 2);
	write(1, &(stack->name), 1);
	write(1, "\n", 1);
}
