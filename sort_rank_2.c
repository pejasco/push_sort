/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rank_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.london.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:41:33 by chuleung          #+#    #+#             */
/*   Updated: 2024/02/03 22:25:21 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_in_rank(t_list **stack)
{
	int		max;
	t_list	*current;

	if (*stack == NULL || stack == NULL)
		return (0);
	max = (*stack)->rank;
	current = (*stack)->next;
	while (current != *stack)
	{
		if (current->rank > max)
			max = current->rank;
		current = current->next;
	}
	return (max);
}

int	min_in_rank(t_list **stack)
{
	int		min;
	t_list	*current;

	if (*stack == NULL || stack == NULL)
		return (0);
	min = (*stack)->rank;
	current = (*stack)->next;
	while (current != *stack)
	{
		if (current->rank < min)
			min = current->rank;
		current = current->next;
	}
	return (min);
}

int	rank_exist(t_list **stack)
{
	if ((*stack)->rank > -1)
		return (1);
	else
		return (0);
}
