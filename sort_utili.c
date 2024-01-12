/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utili.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:25:47 by chuleung          #+#    #+#             */
/*   Updated: 2024/01/09 14:25:49 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int count_in_stack(list **stack)
{
    int count;
    list *current;
    if (*stack == NULL || stack == NULL)
        return (0);
    //print_list('C', stack);
    count = 1;
    current = (*stack)->next;
    //print_list('C', &current);
    while (current != *stack)
    {
        current = current->next;
        count++;
    }
    return (count);
}

int min_in_stack(list **stack)
{
    int     min;
    list    *current; 

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

list *copy_init_a(list **stack)
{
    list *stack_a;
    list *copy_of_a;
    list *tail_of_stack_a;
    list *tail_of_copy_a;

    if ((*stack) == NULL || stack == NULL)
        return (NULL);
    tail_of_stack_a = NULL;
    tail_of_copy_a = NULL;
    stack_a = *stack;
    tail_of_copy_a = append(tail_of_copy_a, stack_a->data);
    copy_of_a = tail_of_copy_a;
    tail_of_stack_a = stack_a->next;
    while (tail_of_stack_a != stack_a)
    {
        tail_of_copy_a = append(tail_of_copy_a, tail_of_stack_a->data);
        tail_of_stack_a = tail_of_stack_a->next;
    }
    return (copy_of_a);
}
