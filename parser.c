#include "push_swap.h"
#include <stdio.h>

int	parse_flags(char **argv)
{
	if (ft_strcmp(argv[1], "--simple") == 0)
		return (1);
	else if (ft_strcmp(argv[1], "--medium") == 0)
		return (2);
	else if (ft_strcmp(argv[1], "--complex") == 0)
		return (3);
	else if (ft_strcmp(argv[1], "--adaptive") == 0)
		return (4);
	return (0);
}

void	parse_input(int argc, char **argv, t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	if (argc == 2)
	{
		parse_split(argv[1], stack_a, stack_b);
		return ;
	}
	i = 1;
	while (i < argc)
	{
		parse_number(argv[i], stack_a, stack_b);
		i++;
	}
}

void	parse_split(char *arg, t_stack *stack_a, t_stack *stack_b)
{
	char	**split_result;
	int		i;
	split_result = ft_split(arg, ' ');
	if (!split_result)
		return ;
	i = 0;
	while (split_result[i])
	{
		parse_number(split_result[i], stack_a, stack_b);
		i++;
	}
	i = 0;
	while (split_result[i])
		free(split_result[i++]);
	free(split_result);
}

void	parse_number(char *str, t_stack *stack_a, t_stack *stack_b)
{
	long	num;

	if (!is_a_number(str))
		error_exit(stack_a, stack_b);
	num = ft_atoi(str);
	if (num < INT_MIN || num > INT_MAX)
		error_exit(stack_a, stack_b);
	if (check_duplicates(stack_a, (int)num))
		error_exit(stack_a, stack_b);
	stack_add_node(stack_a, create_new((int)num));
}
