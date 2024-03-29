/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utili.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Scofield <Scofield@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:25:47 by chuleung          #+#    #+#             */
/*   Updated: 2024/01/28 19:00:51 by Scofield         ###   ########.fr       */
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

t_list	*copy_init_a(t_list **stack)
{
	t_list	*stack_a;
	t_list	*copy_of_a;
	t_list	*tail_of_stack_a;
	t_list	*tail_of_copy_a;

	if ((*stack) == NULL || stack == NULL)
		return (NULL);
	tail_of_stack_a = NULL;
	tail_of_copy_a = NULL;
	stack_a = *stack;
	tail_of_copy_a = append(tail_of_copy_a, stack_a->data, stack_a->rank);
	copy_of_a = tail_of_copy_a;
	tail_of_stack_a = stack_a->next;
	while (tail_of_stack_a != stack_a)
	{
		tail_of_copy_a = append(tail_of_copy_a, \
			tail_of_stack_a->data, stack_a->rank);
		tail_of_stack_a = tail_of_stack_a->next;
	}
	return (copy_of_a);
}

int	if_stack_a_sorted(t_list **stack)
{
	t_list		*current;
	int			i;

	i = 1;
	if ((*stack) == NULL || stack == NULL)
		return (0);
	if ((*stack)->next == *stack)
		return (0);
	current = (*stack)->next;
	while (current != *stack)
	{
		if ((current->prev->rank - current->rank) != -1)
			return (0);
		i++;
		current = current->next;
	}
	return (1);
}

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
