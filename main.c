#include "push_swap.h"
#include "ft_atoi.h"
#include "aux.h"

static t_node	*create_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (node);
	node->value = value;
	node->next = NULL;
	return (node);
}

static int	validate_append(int value, t_stack *stack)
{
	t_node	*current;

	current = stack->head;
	while (current)
	{
		if (current->value == value)
			return (0);
		current = current->next;
	}
	return (1);
}

static int	append_node(int value, t_stack *a)
{
	t_node	*current;
	t_node	*appendable;

	current = a->head;
	if (current == NULL)
	{
		appendable = create_node(value);
		if (appendable == NULL)
			return (0);
		a->head = appendable;
		return (1);
	}
	else
	{
		while (current->next)
			current = current->next;
		appendable = create_node(value);
		if (appendable == NULL)
			return (0);
		current->next = appendable;
		return (1);
	}
}

static void	free_lst(t_node *node)
{
	if (node == NULL)
		return ;
	if (node->next)
		free_lst(node->next);
	free(node);
}

int	main(int argc, char **argv)
{
	t_stack a;
	t_stack b;
	char 	**nums;
	int 	i;
	int		j;

	a.head = NULL;
	b.head = NULL;
	a.name = 'a';
	b.name = 'b';
	if (argc <  2)
		return (0);
	i = 0;
		nums = ft_split(argv[1]);
		if (nums == NULL)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		while (nums[i])
		{	
			
			if (!is_valid_integer(nums[i])
			|| !validate_append(ft_atoi(nums[i]), &a)
			|| !append_node(ft_atoi(nums[i]), &a))
			{
				free_array(nums, i);
				free_lst(a.head);
				write(2, "Error\n", 6);
				exit(1);
			}
			i++;
		}

		j = 2;
		while (j < argc)
		{
			if (!is_valid_integer(argv[j])
			|| !validate_append(ft_atoi(argv[j]), &a)
			|| !append_node(ft_atoi(argv[j]), &a))
			{
				free_lst(a.head);
				write(2, "Error\n", 6);
				exit(1);
			}
			j++;
		}
	sort(&a, &b);
	free_lst(a.head);
	free_array(nums, i);
}
