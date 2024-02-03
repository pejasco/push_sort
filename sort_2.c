/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.london.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:55:51 by chuleung          #+#    #+#             */
/*   Updated: 2024/02/03 19:59:43 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_2_rank(t_list **stack, int rank_exist)
{
	int     max;
	int     min;
	int     i;
	t_list	*current;

	if (rank_exist == 1)
		return ;
	i = 0;
	max = max_in_stack(stack);
	min = min_in_stack(stack);
	current = *stack;
	while (i < 2)
	{
		if (current->data == max)
			(current)->rank = 1;
		if (current->data == min)
			(current)->rank = 0;
		current = current->next;
		i++;
	}
}

void sort_2(t_list **stack)
{
	int     exist_res;

	exist_res = rank_exist(stack);
	sort_2_rank(stack, exist_res);
	if((*stack)->rank > (*stack)->next->rank)
		swap_a(stack, 1);
}