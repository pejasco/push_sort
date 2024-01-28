/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort_rev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:19:29 by chuleung          #+#    #+#             */
/*   Updated: 2024/01/18 22:13:32 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_algo_rev(t_list **stack, t_list **fir_node
		, t_list **sec_node, t_list **thi_node)
{
	if (((*thi_node)->rank > (*fir_node)->rank)
		&& (*fir_node)->rank > (*sec_node)->rank)
		reverse_b(stack, 1);
	else if (((*thi_node)->rank > (*sec_node)->rank)
		&& (*sec_node)->rank > (*fir_node)->rank)
	{
		swap_b(stack, 1);
		reverse_b(stack, 1);
	}
	else if (((*fir_node)->rank > (*thi_node)->rank)
		&& (*thi_node)->rank > (*sec_node)->rank)
	{
		reverse_b(stack, 1);
		swap_b(stack, 1);
	}
	else if (((*sec_node)->rank > (*thi_node)->rank)
		&& (*thi_node)->rank > (*fir_node)->rank)
		rotate_b(stack, 1);
	else if (((*sec_node)->rank > (*fir_node)->rank)
		&& (*fir_node)->rank > (*thi_node)->rank)
		swap_b(stack, 1);
	return ;
}

void	sort_2_rev(t_list **stack)
{
	int	exist_res;

	exist_res = rank_exist(stack);
	sort_2_rank(stack, exist_res);
	if ((*stack)->rank < (*stack)->next->rank)
		swap_b(stack, 1);
}

void	sort_3_rev(t_list **stack)
{
	t_list	*fir_node;
	t_list	*sec_node;
	t_list	*thi_node;
	int		exist_res;

	exist_res = rank_exist(stack);
	sort_3_rank(stack, exist_res);
	fir_node = *stack;
	sec_node = (*stack)->next;
	thi_node = (*stack)->next->next;
	sort_3_algo_rev(stack, &fir_node, &sec_node, &thi_node);
}

void	auto_push_a(t_list **stack_a, t_list **stack_b
		, int no_of_time, int print)
{
	int	i;

	i = 0;
	while (i < no_of_time)
	{
		push_a(stack_a, stack_b, print);
	}
	i++;
}

void	auto_push_b(t_list **stack_a, t_list **stack_b
		, int no_of_time, int print)
{
	int	i;

	i = 0;
	while (i < no_of_time)
	{
		push_b(stack_a, stack_b, print);
	}
	i++;
}

void	mini_sort_rev(t_list **stack_a, t_list **stack_b)
{
	int	count;

	count = count_in_stack(stack_b);
	if (count <= 0 || count > 3)
		return ;
	if (count == 1)
		push_a(stack_a, stack_b, 1);
	if (count == 2)
	{
		sort_2_rev(stack_b);
		auto_push_a(stack_a, stack_b, 2, 1);
	}
	if (count == 3)
	{
		sort_3_rev(stack_b);
		auto_push_a(stack_a, stack_b, 3, 1);
	}
}
