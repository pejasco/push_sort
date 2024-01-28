/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utili.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Scofield <Scofield@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:11:28 by chuleung          #+#    #+#             */
/*   Updated: 2024/01/28 15:41:44 by Scofield         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*tail_find(t_list **stack)
{
	t_list	*tail;

	if (*stack == NULL)
		return (NULL);
	tail = *stack;
	if (tail->next == *stack)
		return (tail);
	while (tail->next != *stack)
		tail = tail->next;
	return (tail);
}

void	free_whole_stack(t_list **stack)
{
	t_list	*aux;
	t_list	*del;

	if (*stack == NULL)
		return ;
	aux = (*stack)->next;
	del = NULL;
	if (aux == *stack)
	{
		free (*stack);
		*stack = NULL;
		return ;
	}
	while (aux != *stack)
	{
		del = aux;
		aux = aux->next;
		free (del);
	}
	free(*stack);
	*stack = NULL;
}
