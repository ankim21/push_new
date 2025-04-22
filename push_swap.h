/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankim <ankim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:32:14 by ankim             #+#    #+#             */
/*   Updated: 2025/04/22 19:07:17 by ankim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "LIBFT/libft.h"
#include "PRINTF/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <stdbool.h>

typedef struct s_node {
	int 	data;
	int 	index;
	bool	above_mid;
	struct s_node *next;
	struct s_node *prev;
} t_node;

char	**ft_split_string(char **str);
int		ft_check1(int argc, char **argv);
char	**ft_parsing_1(int argc, char **argv);
void	printstack(t_node *headnode);
int		stack_size(t_node *stack);
int		check_duplicates(t_node *headnode);
int		add_node (int data, t_node **headnode);
int		create_headnode(int data, t_node **headnode);
int		create_stack(int data, t_node **stack_a);
void	free_stack(t_node **stack_a);
bool	is_sorted (t_node **stack_a);
void	check_before_push (t_node **stack_1, t_node **stack_2);
int		ft_max (int a, int b);
void	push_a(t_node **stack_a, t_node **stack_b);
void	push_b(t_node **stack_a, t_node **stack_b);
void	rotate_a (t_node **stack_a);
void	rotate_b (t_node **stack_b);
void	rr (t_node **stack_a, t_node **stack_b, t_node *cheapest);
void	reverse_rotate_a(t_node **stack_a);
void	reverse_rotate_b(t_node **stack_b);
void	reverse_rotate_both (t_node **stack_a, t_node **stack_b, t_node *cheapest);
void	swap_a(t_node **stack_a);
void	swap_b(t_node **stack_b);
void	swap_a_b(t_node **stack_a, t_node **stack_b);

int		calculate_delta (t_node *stack);

void	refresh_positions(t_node *stack);
void	small_sort(t_node **stack_a);
void	turk_algo(t_node **stack_a, t_node **stack_b);


void	ft_final_check(t_node *stack_a);


#endif