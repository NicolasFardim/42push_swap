#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "libft.h"

typedef struct s_node
{
	int				index; //posiçao
	int				value; //valor/numero
	struct s_node	*next; //valor abaixo
	struct s_node	*prev; //valor cima
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*top; //primeiro valor do stack
}	t_stack;

int	parse_flags(char **argv);

void	parse_input(int argc, char **argv, t_stack *stack_a, t_stack *stack_b);
void	parse_number(char *str, t_stack *stack_a, t_stack *stack_b);
void	parse_split(char *arg, t_stack *stack_a, t_stack *stack_b);
int		check_duplicates(t_stack *stack, int value);
void	error_exit(t_stack *stack_a, t_stack *stack_b);
void	free_stack(t_stack *stack);
int		is_a_number(const char *input);

void	stack_add_node(t_stack *stack, t_node *new_node);
t_node	*create_new(int value);


# endif
