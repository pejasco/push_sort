/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utili_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Scofield <Scofield@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:29:38 by chuleung          #+#    #+#             */
/*   Updated: 2024/01/28 18:57:36 by Scofield         ###   ########.fr       */
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
