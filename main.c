#include "push_swap.h"
#include <stdio.h>

//adicionar o node com o valor ao stack
void	stack_add_node(t_stack *stack, t_node *new_node)
{
	t_node	*last;

	if (!stack || !new_node)
		return ;
	if (stack->size == 0) //caso nao tenha ainda valor nenhum
	{
		stack->top = new_node; //adicionar o primeiro valor
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else
	{
		last = stack->top->prev; //last o ultimo valor adicionado prev do primeiro
		new_node->next = stack->top;
		new_node->prev = last; // o anterior mais "abaixo
		last->next = new_node;
		stack->top->prev = new_node;
	}
	stack->size++; //aumentar o tamnho do size
}

t_node	*create_new(int value) //criar novo node para colocar o numero
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1; //aloco o -1 para ele ainda n ter um index fixo
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

//funcao de debug para printar o stack
static void print_stack(t_stack *stack)
{
	t_node	*current;
	int		i;

	if (!stack || stack->size == 0)
	{
		printf("Stack is empty.\n");
		return ;
	}
	current = stack->top;
	i = 0;
	while (i < stack->size)
	{
		printf("%d ", current->value);
		current = current->next;
		i++;
	}
	printf("\n");
}

static void	init_stack(t_stack *start)
{
	start->size = 0;
	start->top = NULL;
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		strategy;

	if (argc < 2)
		return (0);

	// init the thing
	init_stack(&stack_a);
	init_stack(&stack_b);

	// parsing
	strategy = parse_flags(argv);
	if (strategy)
	{
		argv++;
		argc--;
	}
	parse_input(argc, argv, &stack_a);
	print_stack(&stack_a);

	// DEBUG SECTION
	printf("strat: %d", strategy);

	// freeing
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}


// TODO
// parser - done
// INIT STACKS
// MOVES
// algoritmhs
