/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankim <ankim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:51:23 by ankim             #+#    #+#             */
/*   Updated: 2025/04/22 19:40:30 by ankim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index (t_node *stack_a)
{
	t_node *current;
	t_node *temp;
	int		count;

	current = stack_a;
	count = 0; 
	while (1)
	{
		temp = stack_a;
		while (1)
		{
			if (temp->data < current->data)
				count++;
			temp = temp->next;
			if (temp == stack_a)
				break ;
		}
		current->index = count + 1;
		current = current->next;
		if (current == stack_a)
			break ;
	}
}

int		calculate_delta (t_node *stack)
{
	int	delta;

	delta = stack_size(stack)/20 + 7;
	return (delta);
}

void	push_a_to_b (t_node **stack_a, t_node **stack_b)
{
	int	threshold;
	t_node *current;

	threshold = 0;
	current = *stack_a; 
	while (*stack_a)
	{
		if (current->index <= threshold + calculate_delta(*stack_a))
		{
			push_b (stack_a, stack_b);
			if (current->index <= threshold)
				rotate_b(stack_b);
			threshold++;
		}
			else
				rotate_a(stack_a);
	}
}

void	push_b_to_a (t_node **stack_a, t_node **stack_b)
{
	int	index_total;
	int	position; 
	

	index_total = stack_size(stack_b);
	
	refresh_positions(stack_a);
	refresh_positions(stack_b);

	while (*stack_b)
	{
		if ((*stack_b)->index == index_total)
		{
			if ((*stack_b)->above_mid)
			{
				while ((*stack_b)->above_mid)
				{
					rotate_b(stack_b);
					refresh_positions(stack_b);
					position--;
					if (position == 1)
					{
						push_a(stack_a, stack_b);
						break ;
					}
				}
			}
			else if (!(*stack_b)->above_mid)
			{
				while ((*stack_b)->above_mid)
				{
					rotate_b(stack_b);
					refresh_positions(stack_b);
					position--;
					if (position == 1)
					{
						push_a(stack_a, stack_b);
						break ;
					}
				}
			}
		}
		else
			*stack_b = (*stack_b)->next ;
		index_total--;
	}
}

int	refresh_positions(t_node *stack)
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
		else
			stack->above_mid = false;
		stack = stack->next;
		position++;
		if (stack == current)
			break ;
	}
	return(position); 
}