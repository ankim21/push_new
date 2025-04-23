/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankim <ankim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:23:42 by ankim             #+#    #+#             */
/*   Updated: 2025/04/23 22:03:56 by ankim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_before_push (t_node **stack_a, t_node **stack_b)
{
	if (!*stack_b)
		return ;
	if (!*stack_a)
		create_headnode((*stack_b)->data, (*stack_b)->index, stack_a);
	else
		add_node((*stack_b)->data, (*stack_b)->index, stack_a);
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
		topB->data = (*stack_b)->next->data;
		topB->index = (*stack_b)->next->index;
		lastB->next = topB;
		topB->prev = lastB;
		lastB->data = (*stack_b)->prev->data;
		lastB->index = (*stack_b)->prev->index;
		free(*stack_b);
		*stack_b = topB;
	}
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
		topA->data = (*stack_a)->next->data;
		topA->index = (*stack_a)->next->index;
		lastA = (*stack_a)->prev;
		lastA->data = (*stack_a)->prev->data;
		lastA->index = (*stack_a)->prev->index;
		topA->prev = lastA;
		lastA->next = topA;
		free(*stack_a);
		*stack_a = topA;
	}
	ft_printf("pb\n");
}
