/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <sliashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:17:52 by sliashko          #+#    #+#             */
/*   Updated: 2024/01/03 18:00:07 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0

typedef struct node
{
	int	curr_pos;
	int	index;
	int	val;
	struct node *next;
	struct node *prev;
	int	cost;
	int	is_cheapest;
	int	above_mid;
}			t_node;

typedef struct push_swap
{
	t_node *stack_a;
	t_node *stack_b;
	
}			t_push_swap;

//Utils
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
void	ft_putstr_fd(char *s, int fd);

//Linkedlist utils
t_node *find_last_node(t_node **head);
t_node	*init_stack(char **args);
int		get_stack_size(t_node **head);
void	update_pos(t_node **stack);

//Stack operations
void	push_a(t_node **stack_a, t_node **stack_b);
void	push_b(t_node **stack_a, t_node **stack_b);
void	swap_a(t_node **stack_a, int verbose);
void	swap_b(t_node **stack_b, int verbose);
void	swap_both(t_node **stack_a, t_node **stack_b);
void	rotate_a(t_node **stack_a, int verbose);
void	rotate_b(t_node **stack_b, int verbose);
void	rotate_both(t_node **stack_a, t_node **stack_b);
void	reverse_rotate_a(t_node **stack_a, int verbose);
void	reverse_rotate_b(t_node **stack_b, int verbose);
void	reverse_rotate_both(t_node **stack_a, t_node **stack_b);

//Sorting
void	sort_3els(t_node **head);
void	sort_4els(t_node **stack_a, t_node **stack_b);
void	sort_5els(t_node **stack_a, t_node **stack_b);
void	sort_small(t_node **stack_a, t_node **stack_b);
int		find_max_val(t_node **head);
int		find_min_val(t_node **head);


#endif
