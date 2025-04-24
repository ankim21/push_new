/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankim <ankim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:10:39 by ankim             #+#    #+#             */
/*   Updated: 2025/04/24 20:17:25 by ankim            ###   ########.fr       */
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
	}
	if (size == 3)
	{
		if ((*stack_a)->data > (*stack_a)->next->data && (*stack_a)->data 
		> (*stack_a)->next->next->data)
			rotate_a(stack_a);
		else if (((*stack_a)->next->data > (*stack_a)->data) && 
		(*stack_a)->next->data > (*stack_a)->next->next->data)
			reverse_rotate_a(stack_a);
		if ((*stack_a)->prev->data > (*stack_a)->data && 
				(*stack_a)->next->data < (*stack_a)->prev->data)
			{
				if ((*stack_a)->data > (*stack_a)->next->data)
					swap_a(stack_a);
			}
	}
}

// void big_small_sort(t_node **stack_a, t_node **stack_b)
// {
// 	int	size;
	
// 	size = stack_size(*stack_a);
// 	assign_index(*stack_a);
// 	while (size <= 5 && size > 3)
// 	{
// 		if ((*stack_a)->index < 3)
// 		{
// 			push_b(stack_a, stack_b);
// 			size--;
// 		}
// 	}
// 	if (size == 3)
// 		small_sort(stack_a);
// 	while (*stack_b)
// 	{
// 		if ((*stack_b)->data > ((*stack_b)->next->data))
// 		{
// 			push_a(stack_b, stack_a);
// 			push_a(stack_b, stack_a);
// 		}
// 		else
// 			swap_b(stack_a);
// 	}
// }

void	bigger_small_sort(t_node **stack_a, t_node **stack_b)
{
	int	size;
	
	assign_index(*stack_a);
	size = stack_size(*stack_a);
	while (*stack_a)
	{
		if ((*stack_a)->index <= 3 && size > 3)
		{
			(*stack_a) = (*stack_a)->next;
		}
		else
		{	
			push_b(stack_a, stack_b);
			size--;
		}
	}
	small_sort(stack_a);
	assign_index(*stack_b);
	while (*stack_b)
	{
		if (*stack_b == NULL)
			break ;
		if ((*stack_b)->index == 1)
		{
			push_a(stack_a, stack_b);
			assign_index(*stack_b);			
		}
		else if ((*stack_b)->index != 1)
			(*stack_b) = (*stack_b)->next;
	}
}



