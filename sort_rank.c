/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rank.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 22:17:22 by chuleung          #+#    #+#             */
/*   Updated: 2024/01/09 22:17:24 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

list *rank_algo(list *copy_of_a, list *copy_of_b)
{
    int     min;
    list    *current_a;
    int     i;
    int     count;

    i = 0;
    //print_list('C',&copy_of_a);
    count = count_in_stack(&copy_of_a);
    //printf("%d", count);
    current_a = copy_of_a;
    min = min_in_stack(&copy_of_a);
    while (i < count)
    {
        min = min_in_stack(&copy_of_a);
        while (current_a->data != min)
        {
            rotate_a(&copy_of_a, 0);
            current_a = copy_of_a;
            if (current_a->data == min)
                push_b(&copy_of_a, &copy_of_b, 0);
        }
        i++;
    }
    //print_list('Y',&copy_of_a);
    //print_list('Y',&copy_of_a);
    //print_list('Z',&copy_of_b);
    //print_list('Z',&copy_of_b);
    return (copy_of_b);
}

list *rank_assign_to_copy_a(list *copy_of_a)
{
    list    *current_a;
    int     i;

    //print_list('X',&copy_of_a);
    //print_list_rank('X',&copy_of_a);
    if (copy_of_a == NULL)
        return NULL;
    copy_of_a->rank = 0;
    current_a = copy_of_a->next;
    i = 1;
    while (current_a != copy_of_a)
    {
        current_a->rank = i;
        current_a = current_a->next;
        i++;
    }
    print_list('X',&copy_of_a);###############################
    print_list_rank('X',&copy_of_a);################################
    return (copy_of_a);
}

list *rank_in_stack(list **stack)
{
    list    *copy_of_a;
    list    *copy_of_b;
    list    *current_a;

    if (*stack == NULL || stack ==NULL)
        return (NULL);
    current_a = *stack;
    copy_of_a = current_a;
    copy_of_b = NULL;
    if (copy_of_a->next == copy_of_a)
        return (copy_of_a);
    //print_list('C',&copy_of_a);
    copy_of_a = rank_algo(copy_of_a, copy_of_b);
    copy_of_a = rank_assign_to_copy_a(copy_of_a);
    return (copy_of_a);
}
