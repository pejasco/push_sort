/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utili.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:25:47 by chuleung          #+#    #+#             */
/*   Updated: 2024/01/16 12:37:52 by chuleung         ###   ########.fr       */
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

int max_in_stack(list **stack)
{
    int     max;
    list    *current;

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

int if_stack_a_sorted(list **stack)
{
    list    *current;
    int     i;

    i = 1;
    if ((*stack) == NULL || stack == NULL)
        return (0);
    if ((*stack)->next == *stack)
        return (0);
    current = (*stack)->next;
    while (current != *stack)
    {
        if (current->prev - current != -1)
        {
            printf("sort problem @ ---->%d", &i);
            return (0);
        }
        i++;
        current = current->next;
    }
    return (1);
}
