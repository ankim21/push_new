/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankim <ankim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:29:16 by ankim             #+#    #+#             */
/*   Updated: 2025/04/24 18:55:07 by ankim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void min_on_top(t_node *stack_a)
{
    t_node *min;

	min = find_min(stack_a);
	if (min->above_mid && stack_a != min)
	{
		while (min->prev->above_mid)
		{
			rotate_a(&stack_a);
			refresh_positions(stack_a);
		}
	} 
	else if (!min->above_mid)
	{
		while (!min->above_mid)
		{
			reverse_rotate_a(&stack_a);
			refresh_positions(stack_a);
		}
	}
	return ;
}

void	sort_me_easy (t_node **stack_a, t_node **stack_b)
{	
	int	index_total;

	index_total = 0;
	
	if (!*stack_a)
		return ;
	if (stack_size(*stack_a) <= 3)
		small_sort(stack_a);
	else if (stack_size(*stack_a) >= 4 && stack_size(*stack_a) <= 10)
		bigger_small_sort(stack_a, stack_b);
	else
	{
		index_total = stack_size(*stack_a);
		assign_index(*stack_a);
		push_a_to_b(stack_a, stack_b);
		push_b_to_a(stack_a, stack_b, index_total);
	}
	min_on_top(*stack_a);
	return ;
}

