#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	int				target;
}	t_node;

typedef struct s_stack
{
	char	name;
	t_node	*head;
}	t_stack;

typedef struct t_pair
{
	t_stack	*a;
	t_stack	*b;
}	t_pair;

void	swap(t_stack *stack);
void	push(t_stack *a, t_stack *b);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	sim_rotate(t_stack *a, t_stack *b);
void	sim_reverse_rotate(t_stack *a, t_stack *b);
void	sort(t_stack *a, t_stack *b);
int stack_len(t_stack *stack);
int find_value_position(t_stack *stack, int value);
t_node *max(t_stack *stack);
t_node *min(t_stack *stack);
int find_target_in_b(t_node *node, t_stack *b);
int find_target_in_a(t_node *node, t_stack *a);
void give_targets(t_stack *sourcestack, t_stack *targetstack);
int direction(int sourcevalue, t_stack *sourcestack);
int node_cost(int sourcevalue, t_stack *sourcestack);
int compute_cost(int sourcevalue, int targetvalue, t_stack *sourcestack, t_stack *targetstack);
t_node *select_node_to_push(t_stack *sourcestack, t_stack *targetstack);
void bring_to_head(int val, t_stack *stack);
void sim_bring_to_head(int val, t_stack *a, t_stack *b);
void sort_small(t_stack *a);
void sort(t_stack *a, t_stack *b);
int		is_valid_integer(char *str);
int		is_int_min(char *str);
int		ft_atoi(char *str);

#endif