#include "push_swap.h"

void	error_exit(t_stack *stack_a, t_stack *stack_b) // em caso de falhar seguimos as regras que e dar free em tudo e imprimir erro com new line
{
	if (stack_a) // so para verificar no caso da b se ja foi criado
		free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	free_stack(t_stack *stack)
{
	t_node	*current; // criar uma variavel para darmos free uma a uma
	t_node	*next_node;
	int		i;

	if (!stack || stack->size == 0)
		return ; // n tem nada entao damos so return
	current = stack->top; //meter como o primeiro
	i = 0;
	while (i < stack->size) // darmos loop pa ir dando free um a um com as posicoes
	{
		next_node = current->next;
		free(current);
		current = next_node;
		i++;
	}
	stack->top = NULL;
	stack->size = 0;
}

int	check_duplicates(t_stack *stack, int value) // n pode ter duplicados
{
	t_node	*current;
	int		i;

	if (!stack || stack->size == 0)
		return (0);
	current = stack->top; // começa na primeira
	i = 0;
	while (i < stack->size) //loop de posicao so pa verificar se tem algum igual
	{
		if (current->value == value)
			return (1);
		current = current->next;
		i++;
	}
	return (0);
}

 // vai iniciar antes do atoi para garantir que vai tudo limpo po atoi e transformar nos numeros para nos depois inplementarmos
int	is_a_number(const char *input)
{
	int	i;

	i = 0;
	if (input[i] == '+' || input[i] == '-') //verificar o primeiro sinal
		i++;
	if (!input[i]) // caso n tenha nada depois ele deve retornar imediatamente
		return (0);
	while (input[i]) //verificar se o input e so numeros
	{
		if (!ft_isdigit(input[i]))
			return (0);
		i++;
	}
	return (1);
}
