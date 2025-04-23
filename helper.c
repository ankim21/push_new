/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankim <ankim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 11:35:42 by ankim             #+#    #+#             */
/*   Updated: 2025/04/23 18:24:30 by ankim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void printstack(t_node *headnode)
{
	t_node *current;
	
	current = headnode;
	while (1)
	{
		ft_printf("%d \n", current->data);
		current = current->next;
		if (current == headnode)
			break ;
	}
}

int	stack_size(t_node *stack)
{
	t_node *current;

	if (!stack)
		return (0);
	int size = 0;
	current = stack;
	while (1)
	{
		size++;
		current = (current)->next;
		if (current == stack)
			break ;
	}
	return (size);
}

t_node *find_max (t_node *stack)
{
    long    max;
    t_node *max_node;
    t_node *tmp;

    if (!stack)
        return(NULL);
    max = LONG_MIN;
    tmp = stack->next;
    while (tmp != stack)
    {
        if (tmp->data > max)
        {
            max = tmp->data;
            max_node = tmp;
        }
        tmp = tmp->next;
    }
    return (max_node);
}

t_node *find_min(t_node *stack)
{
    long    min; 
    t_node *min_node;
    t_node *tmp;

    if (!stack)
        return(NULL);
    tmp = stack;
    min = LONG_MAX;
    while (1)
    {
        if (stack->data < min)
        {
            min = stack->data;
            min_node = stack;
        }
        stack = stack->next;
        if (stack == tmp)
            break ;
    }
    return(min_node);
}

void ft_final_check(t_node *stack_a)
{
	t_node *current;

	current = stack_a;
	while (1)
	{
		if (stack_a->data < (stack_a->next->data))
			stack_a = stack_a->next;
		else
		{
			if (stack_a->next == current)
					break ;
			printstack(stack_a);
		}
	}
}
int	ft_max (int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	ft_min (int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}