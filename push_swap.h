/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankim <ankim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:32:14 by ankim             #+#    #+#             */
/*   Updated: 2025/04/24 10:39:52 by ankim            ###   ########.fr       */
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
int		add_node (int data, int index, t_node **headnode);
int		create_headnode(int data, int index, t_node **headnode);
int		create_stack(int data, t_node **stack_a);
void	free_stack(t_node **stack_a);
bool	is_sorted (t_node **stack_a);
void	check_before_push (t_node **stack_1, t_node **stack_2);
int		ft_max (int a, int b);
int		stack_size(t_node *stack);
void	push_a(t_node **stack_a, t_node **stack_b);
void	push_b(t_node **stack_a, t_node **stack_b);
void	rotate_a (t_node **stack_a);
void	rotate_b (t_node **stack_b);
void	rr (t_node **stack_a, t_node **stack_b);
void	reverse_rotate_a(t_node **stack_a);
void	reverse_rotate_b(t_node **stack_b);
void	reverse_rotate_both (t_node **stack_a, t_node **stack_b);
void	swap_a(t_node **stack_a);
void	swap_b(t_node **stack_b);
void	swap_a_b(t_node **stack_a, t_node **stack_b);
void	assign_index (t_node *stack_a);
int		calculate_delta (t_node *stack);
void	refresh_positions(t_node *stack);
void	push_a_to_b (t_node **stack_a, t_node **stack_b);
void	push_b_to_a (t_node **stack_a, t_node **stack_b, int index_total);
void	small_sort(t_node **stack_a);
// void	big_small_sort(t_node **stack_a, t_node **stack_b);
void	bigger_small_sort(t_node **stack_a, t_node **stack_b);
void	sort_me_easy(t_node **stack_a, t_node **stack_b);
void 	min_on_top(t_node *stack_a);
void	prep_b(t_node **stack_a, t_node **stack_b, int size_b);
t_node *find_min(t_node *stack);


#endif