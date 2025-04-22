/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankim <ankim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:48:14 by ankim             #+#    #+#             */
/*   Updated: 2025/04/20 13:36:23 by ankim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted (t_node **stack_a)
{
	t_node *current;
	t_node *head;

	head = *stack_a;
	current = head;
	while (current->next != head)
	{
		if (current->data > current->next->data)
		{
			return (false);
		}
		current = current->next;
	}
	return (true);
}
