/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankim <ankim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:33:00 by ankim             #+#    #+#             */
/*   Updated: 2025/04/23 10:14:30 by ankim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse_rotate_a(t_node **stack_a)
{
	if ((!*stack_a) || (*stack_a)->prev == *stack_a)
		return;
	*stack_a = (*stack_a)->prev;
	refresh_positions(*stack_a);
	ft_printf("rra\n");
}

void reverse_rotate_b(t_node **stack_b)
{
	if ((!*stack_b) || (*stack_b)->prev == *stack_b)
		return;
	*stack_b = (*stack_b)->prev;
	refresh_positions(*stack_b);
	ft_printf("rrb\n");
}

void reverse_rotate_both (t_node **stack_a, t_node **stack_b)
{
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
	ft_printf("rrr\n");
	refresh_positions(*stack_a);
	refresh_positions(*stack_b);
}