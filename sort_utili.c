/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utili.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.london.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:25:47 by chuleung          #+#    #+#             */
/*   Updated: 2024/02/03 20:22:47 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_in_stack(t_list **stack)
{
	int		count;
	t_list	*current;

	if (*stack == NULL || stack == NULL)
		return (0);
	count = 1;
	current = (*stack)->next;
	while (current != *stack)
	{
		current = current->next;
		count++;
	}
	return (count);
}

int	min_in_stack(t_list **stack)
{
	int		min;
	t_list	*current;

	if (*stack == NULL || stack == NULL)
		return (0);
	min = (*stack)->data;
	current = (*stack)->next;
	while (current != *stack)
	{
		if (current->data < min)
			min = current->data;
		current = current->next;
	}
	return (min);
}

int	max_in_stack(t_list **stack)
{
	int		max;
	t_list	*current;

	if (*stack == NULL || stack == NULL)
		return (0);
	max = (*stack)->data;
	current = (*stack)->next;
	while (current != *stack)
	{
		if (current->data > max)
			max = current->data;
		current = current->next;
	}
	return (max);
}
