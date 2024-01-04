/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <sliashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:13:30 by sliashko          #+#    #+#             */
/*   Updated: 2024/01/04 16:25:56 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_max_node(t_node **head)
{
	t_node	*max_node;
	t_node	*curr_node;

	curr_node = *head;
	max_node = *head;
	while (curr_node != NULL)
	{
		if (curr_node->val > max_node->val)
			max_node = curr_node;
		curr_node = curr_node->next;
	}
	return (max_node);
}

t_node	*find_min_node(t_node **head)
{
	t_node	*min_node;
	t_node	*curr_node;

	curr_node = *head;
	min_node = *head;
	while (curr_node != NULL)
	{
		if (curr_node->val < min_node->val)
			min_node = curr_node;
		curr_node = curr_node->next;
	}
	return (min_node);
}

//This func will rotate both stack
//unless either target node of cheapest is on top in A
//or cheapest itself is on top of B
void	rotate_both_till(t_node **stack_a, t_node **stack_b,
										t_node *cheapest_node)
{
	while (*stack_a != cheapest_node->target
			&& *stack_b != cheapest_node)
		rotate_both(stack_a, stack_b);
	update_pos(stack_a);
	update_pos(stack_b);
}

//This func will reverse rotate both stack
//unless either target node of cheapest is on top in A
//or cheapest itself is on top of B
void	rev_rotate_both_till(t_node **stack_a, t_node **stack_b,
										t_node *cheapest_node)
{
	while (*stack_a != cheapest_node->target
			&& *stack_b != cheapest_node)
		reverse_rotate_both(stack_a, stack_b);
	update_pos(stack_a);
	update_pos(stack_b);
}

//This function will finish lifting up target node if given A
// or cheapest node if given B

//BUG IS HERE
void	complete_rotation(t_node **stack, t_node *top_node, char stack_name)
{	
	
	while ((*stack)->val != top_node->val)
	{
		printf("------\n");
		print_stack(stack);
		printf("------\n");
		printf("complete rotation\n");
		printf("Top node val = %d\n; curr_top = %d\n ", top_node->val, (*stack)->val);
		if (stack_name == 'A')
		{
			if (top_node->above_mid)
				rotate_a(stack, TRUE);
			else
				reverse_rotate_a(stack, TRUE);
		}
		else if (stack_name == 'B')
		{
			if (top_node->above_mid)
				rotate_b(stack, TRUE);
			else
				reverse_rotate_b(stack, TRUE);
		}
	}
	
}
