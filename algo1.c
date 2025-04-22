/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankim <ankim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:10:39 by ankim             #+#    #+#             */
/*   Updated: 2025/04/22 19:02:16 by ankim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_node **stack_a)
{
	int	size;

	size = stack_size(*stack_a);
	if (size == 1)
		return ;
	if (size == 2)
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
			swap_a(stack_a);
		else
			return ;
	}
	if (size == 3)
	{
		if ((*stack_a)->data > (*stack_a)->next->data && (*stack_a)->data 
		> (*stack_a)->next->next->data)
			rotate_a(stack_a);
		else if (((*stack_a)->next->data > (*stack_a)->data) && 
		(*stack_a)->next->data > (*stack_a)->next->next->data)
			reverse_rotate_a(stack_a);
		if ((*stack_a)->data > (*stack_a)->next->data)
			swap_a(stack_a);
	}
}

