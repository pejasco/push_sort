/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utili.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:11:28 by chuleung          #+#    #+#             */
/*   Updated: 2024/01/06 19:23:57 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

list *tail_find(list **stack)
{
	list *tail;

	if (*stack == NULL)
		return (NULL);
	tail = *stack;
	if (tail->next == *stack)
		return (tail);
	while (tail->next != *stack)
		tail = tail->next;
	return (tail);
}

void free_whole_stack(list **stack)
{
	list *aux;
	list *del;

	if (*stack == NULL)
		return;
	aux = (*stack)->next;
	del = NULL;
	if (aux == *stack)
	{
		free (*stack);
		*stack = NULL;
		return ;		
	}
	while (aux	!= *stack)
	{
		del = aux;
		aux = aux->next;
		free (del);
	}
	free(*stack);
	*stack = NULL;
}
