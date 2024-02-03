/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utili_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.london.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:29:38 by chuleung          #+#    #+#             */
/*   Updated: 2024/02/03 19:47:41 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	position_in_stacks(t_list **stack)
{
	t_list	*head;
	t_list	*current;
	int		i;

	i = 1;
	head = *stack;
	current = head;
	current->position = i;
	current = current->next;
	i++;
	while (current != head)
	{
		current->position = i;
		current = current->next;
		i++;
	}
}

t_list	*find_post_with_rank(t_list **stack, int rank)
{
	t_list	*target;

	target = *stack;
	while (target->rank != rank)
		target = target->next;
	return (target);
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
