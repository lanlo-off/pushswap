#include "src/push_swap.h"
#include <stdio.h>

//commande apres avoir MAKE : cc -g -Wall -Wextra -Werror test_index.c src/init_stack.c src/init_utils.c src/swap.c -I./src -I./libft -I./ftprintf -L./libft -lft -L./ftprintf -lftprintf -o test_index &&./test_index

void print_list(t_stack *stack)
{
    t_stack *tmp;

    tmp = stack;
    printf("\n|--------------------|--------------------|\n");
    printf("|       Value       |       Index       |\n");
    printf("|--------------------|--------------------|\n");
    while (tmp)
    {
        printf("|%18d |%18d |\n", tmp->value, tmp->index);
        tmp = tmp->next;
    }
    printf("|--------------------|--------------------|\n");
}

int	is_sorted(t_stack **stack)
{
	t_stack	*tmp;
	int		highest;
	
	if (!stack)
		return (1);
	tmp = *stack;
	highest = tmp->value;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->value <= highest)
			return (0);
		highest = tmp->value;
		tmp = tmp->next;
	}
	return (1);
}

int main(void)
{
    t_stack **stack;
    int     size;

    // Initialisation
    stack = malloc(sizeof(t_stack *));
    if (!stack)
        return (1);
    *stack = NULL;

    // Ajout de valeurs de test
    ft_add_new(INT_MIN, stack);
    ft_add_new(0, stack);
    ft_add_new(5, stack);
    ft_add_new(45, stack);
    ft_add_new(INT_MAX, stack);
    size = 5;

    // Affichage initial
    printf("\nListe initiale:");
    print_list(*stack);

    // Test de swap_a
    printf("\nTest de sa (swap des 2 premiers éléments):");
    do_sa(stack);
    print_list(*stack);

    // Test de re-swap
    printf("\nTest de sa à nouveau (retour à l'état initial):");
    do_sa(stack);
    print_list(*stack);

    // Test de la fonction indexation
    printf("\nTest de l'indexation:");
    indexation(stack, size);
    print_list(*stack);

    // Test de sa après indexation
    printf("\nTest de sa après indexation:");
    do_sa(stack);
    print_list(*stack);

    // Vérification si trié
    printf("\nValeur retour de is_sorted: %d\n", is_sorted(stack));

    // Libération de la mémoire
    while (*stack)
    {
        t_stack *tmp = *stack;
        *stack = (*stack)->next;
        free(tmp);
    }
    free(stack);
    return (0);
}
