#include "push_swap.h"

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

void	parse_input(int argc, char **argv, t_stack *stack_a)
{
	int	i;

	if (argc == 2)
	{
		parse_split(argv[1], stack_a);
		return ;
	}
	i = 1;
	while (i < argc)
	{
		if (!parse_number(argv[i], stack_a))
		{
			free_stack(stack_a);
			error_exit();
		}
		i++;
	}
}

static void	free_split(char **split_result)
{
	int	i;

	i = 0;
	while (split_result[i])
		free(split_result[i++]);
	free(split_result);
}

void	parse_split(char *arg, t_stack *stack_a)
{
	char	**split_result;
	int		i;

	split_result = ft_split(arg, ' ');
	if (!split_result)
		return ;
	i = 0;
	while (split_result[i])
	{

		if (!parse_number(split_result[i], stack_a))
		{
			free_split(split_result);
			free_stack(stack_a);
			error_exit();
		}
		i++;
	}
	free_split(split_result);
}

int	parse_number(char *str, t_stack *stack_a)
{
	long	num;

	if (!is_a_number(str))
		return (0);
	num = ft_atoi(str);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	if (check_duplicates(stack_a, (int)num))
		return (0);
	stack_add_node(stack_a, create_new((int)num));
	return (1);
}
