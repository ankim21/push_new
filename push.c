/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankim <ankim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:23:42 by ankim             #+#    #+#             */
/*   Updated: 2025/04/20 13:32:11 by ankim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_before_push (t_node **stack_1, t_node **stack_2)
{
	if (!*stack_2)
		return ;
	if (!*stack_1)
		create_headnode((*stack_2)->data, stack_1);
	else
		add_node((*stack_2)->data, stack_1);
	return ;
}

void	push_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*topB;
	t_node	*lastB;

	check_before_push(stack_a, stack_b);
	if ((*stack_b)->next == *stack_b)
	{
		free(*stack_b);
		*stack_b = NULL;
	}
	else
	{
		topB = (*stack_b)->next;
		lastB = (*stack_b)-> prev;
		lastB->next = topB;
		topB->prev = lastB;
		free(*stack_b);
		*stack_b = topB;
	}
	refresh_positions(*stack_a);
	refresh_positions(*stack_b);
	ft_printf("pa\n");
}

void push_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*topA;
	t_node	*lastA;

	check_before_push(stack_b, stack_a);
	if ((*stack_a)->next == *stack_a)
	{
		free(*stack_a);
		*stack_a = NULL;
	}
	else
	{
		topA = (*stack_a)->next;
		lastA = (*stack_a)->prev;
		topA->prev = lastA;
		lastA->next = topA;
		free(*stack_a);
		*stack_a = topA;
	}
	refresh_positions(*stack_a);
	refresh_positions(*stack_b);
	ft_printf("pb\n");
}

