#include "src/push_swap.h"
#include <stdio.h>

//commande apres avoir MAKE : cc -g -Wall -Wextra -Werror test_index.c src/init_stack.c src/manip_lst.c src/swap.c src/rotate.c src/rev_rotate.c -I./src -I./libft -I./ftprintf -L./libft -lft -L./ftprintf -lftprintf -o test_index &&./test_index

void print_list(t_stack *stack, char *stack_name)
{
    t_stack *tmp;

    tmp = stack;
    printf("\n|--------%s---------|\n", stack_name);
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
    t_stack **stack_a;
    int     size_a;
    t_stack **stack_b;
    // int     size_b;

    // Initialisation
    stack_a = malloc(sizeof(t_stack *));
    if (!stack_a)
        return (1);
    *stack_a = NULL;

    stack_b = malloc(sizeof(t_stack *));
    if (!stack_b)
        return (1);
    *stack_b = NULL;

    // Ajout de valeurs de test
    ft_add_new(INT_MIN, stack_a);
    ft_add_new(-42, stack_a);
    ft_add_new(94, stack_a);
    ft_add_new(128, stack_a);
    ft_add_new(INT_MAX, stack_a);
    size_a = 5;

    // ft_add_new(0, stack_b);
    // ft_add_new(1, stack_b);
    // ft_add_new(2, stack_b);
    // ft_add_new(3, stack_b);
    // ft_add_new(4, stack_b);
    // size_b = 0;

    // Affichage initial
    printf("\nListe initiale:");
    print_list(*stack_a, "stack_a");
    print_list(*stack_b, "stack_b");

    // Test de la fonction indexation
    printf("\nTest de l'indexation:");
    indexation(stack_a, size_a);
    // indexation(stack_b, size_b);
    print_list(*stack_a, "stack_a");
    // print_list(*stack_b, "stack_b");

    // Test de swap_a
    printf("\nTest de sa :");
    do_sa(stack_a);
    print_list(*stack_a, "stack_a");

    // Test de ra
    printf("\nTest de ra:");
    do_ra(stack_a);
    print_list(*stack_a, "stack_a");

    // Test de rra
    printf("\nTest de rra:");
    do_rra(stack_a);
    print_list(*stack_a, "stack_a");

    // Test de pa
    printf("\nTest de pa:");
    do_pa(stack_a, stack_b);
    print_list(*stack_a, "stack_a");
    print_list(*stack_b, "stack_b");

    // Test de pb
    printf("\nTest de pb:");
    do_pb(stack_a, stack_b);
    print_list(*stack_a, "stack_a");
    print_list(*stack_b, "stack_b");

    // // Vérification si trié
    // printf("\nValeur retour de is_sorted: %d\n", is_sorted(stack_a));

    // Libération de la mémoire
    while (*stack_a)
    {
        t_stack *tmp = *stack_a;
        *stack_a = (*stack_a)->next;
        free(tmp);
    }
    while (*stack_b)
    {
        t_stack *tmp = *stack_b;
        *stack_b = (*stack_b)->next;
        free(tmp);
    }
    free(stack_a);
    free(stack_b);
    return (0);
}
