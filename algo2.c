/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankim <ankim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:51:23 by ankim             #+#    #+#             */
/*   Updated: 2025/04/23 22:22:33 by ankim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		assign_index (t_node *stack_a)
{
	t_node *current;
	t_node *temp;
	int		count;

	current = stack_a;
	count = 0; 
	while (1)
	{
		temp = stack_a;
		count = 0;
		while (1)
		{
			if (temp->data < current->data)
                count++;
            temp = temp->next;
            if (temp == stack_a)
                break;
		}
		current->index = count + 1;
		current = current->next;
		if (current == stack_a)
			break ;
	}
	return;
}

int		calculate_delta (t_node *stack)
{
	int	delta;
	int	size; 
	
	size = stack_size(stack);
	if (size > 20)
		delta = (stack_size(stack))/20 + 7;
	else
		delta = 2;
	return (delta);
}

void	push_a_to_b (t_node **stack_a, t_node **stack_b)
{
	int	threshold;
	int	delta;
	t_node *current;

	threshold = 1;
	delta = calculate_delta(*stack_a);
	current = *stack_a; 
	while (*stack_a)
	{
		current = *stack_a;
		if (current->index <= threshold + delta)
		{
			push_b(stack_a, stack_b);
			if (*stack_a)
			{
				if ((current)->index <= threshold)
					rotate_b(stack_b);
			}
			threshold++;
		}
		else
			rotate_a(stack_a);
		current = current->next;
	}
	return ;
}

void	push_b_to_a (t_node **stack_a, t_node **stack_b, int index_total)
{

	while (index_total != 0)
	{
		refresh_positions(*stack_b);
		if ((*stack_b)->index == index_total)
		{
			if ((*stack_b)->above_mid)
			{
				if (!(*stack_b)->prev->above_mid)
					push_a(stack_a, stack_b);
			}
			if (index_total == 2)
			{
				push_btwo_to_a(stack_a, stack_b);
				return;				
			}
			index_total--;
		}
		*stack_b = (*stack_b)->next ;
	}
	return ;
}

void	push_btwo_to_a(t_node **stack_a, t_node **stack_b)
{
	int	index_total;

	index_total = stack_size(*stack_b);
	if (index_total == 2)
	{
		if ((*stack_b)->index > (*stack_b)->next->index)
			{
				push_a(stack_a, stack_b);
				push_a(stack_a, stack_b);
				return ;
			}
	}
	else
	{
		while (index_total > 1)
		{
			reverse_rotate_b(stack_b);
			refresh_positions(*stack_b);
			if ((*stack_b)->above_mid)
			{
				push_a(stack_a, stack_b);
				index_total--;
			}
		}
	}
}

void	refresh_positions(t_node *stack)
{	
    int position;
    int mid;
	t_node	*current;
    
    position = 1;
    if (!stack)
        return ;
    mid = stack_size(stack) / 2 + 1;
	current = stack;
	while (1)
	{
		if (position <= mid)
			(stack)->above_mid = true;
		else if (position > mid)
			stack->above_mid = false;
		stack = stack->next;
		position++;
		if (stack == current)
			break ;
	}
	return ; 
}