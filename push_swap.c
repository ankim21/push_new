/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankim <ankim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:44:40 by ankim             #+#    #+#             */
/*   Updated: 2025/04/22 19:01:09 by ankim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char **result;
	int i = 0;
	t_node *stack_a = NULL;
	t_node *stack_b = NULL;

	if (argc < 2)
	{
		ft_putstr_fd("ERROR", 2);
		return (-1);
	}
	result = ft_parsing_1(argc, argv);
	if (!result)
		return(-1);
	while (result[i] != NULL)
	{
		if (create_stack(ft_atoi(result[i]), &stack_a) == -1)
			return (-1);
		i++;
	}
	if ((check_duplicates(stack_a) == -1) || (is_sorted(&stack_a)))
		ft_putstr_fd("ERROR\n", 2);
	if (stack_size(stack_a) == 2)
		swap_a(&stack_a);
	else if (stack_size(stack_a) == 3)
		small_sort(&stack_a);
	else
		assign_index(&stack_a);
	ft_final_check(stack_a);
	return(0);
}
