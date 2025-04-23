/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankim <ankim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:47:17 by ankim             #+#    #+#             */
/*   Updated: 2025/04/23 22:21:07 by ankim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(t_node *headnode)
{
	t_node *current;
	t_node *runner;

	current = headnode;
	if (!headnode || headnode->next == headnode)
		return (0);
	while (1)
	{
		runner = current->next;
		while (runner != headnode)
		{	
			if (current->data == runner->data)
				return (-1);
			runner = runner->next;
		}
		if (current == headnode)
			break;
		current = current->next;
	}
	return (0);
}

int add_node(int data, int index, t_node **headnode)
{
	t_node *new;
	t_node *previous;

	previous = (*headnode)->prev;
	new = malloc (sizeof(t_node));
	if (!new)
		return (-1);
	new->data = data;
	new->index = index; 
	new->next = *headnode;
	new->prev = previous;
	previous->next = new;
	(*headnode)->prev = new;;
	new->above_mid = true;
	return (0);
}

int	create_headnode(int data, int index, t_node **headnode)
{
	*headnode = malloc(sizeof(t_node));
	if (!*headnode)
		return (-1);
	(*headnode)->data = data;
	(*headnode)->prev = *headnode;
	(*headnode)->next = *headnode;
	(*headnode)->above_mid = true;
	(*headnode)->index = index;
	return (0);
}

int create_stack(int data, t_node **stack_a)
{
	if (!*stack_a)
		return (create_headnode(data, 0, stack_a));
	else 
		return (add_node(data, 0, stack_a));
}

void	free_stack(t_node **stack_a)
{
	t_node *temp;
	int i;
	int size = stack_size(*stack_a);
	
	i = 0;
	while (i < size)
	{
		temp = (*stack_a)->next;
		free((*stack_a));
		(*stack_a) = temp;
		i++;
	}
}
