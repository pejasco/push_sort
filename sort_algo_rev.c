/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo_rev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:09:20 by chuleung          #+#    #+#             */
/*   Updated: 2024/01/15 23:02:15 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


count_pack below_median(list **stack_a, list **stack_b, count_pack c)
{
    rotate_b(stack_b, 1);
    c.rb_count++;
    return (c);
}

count_pack above_median(list **stack_a, list **stack_b, count_pack c)
{
    int     rank;
    int     sort_res;

    rank = ((*stack_b)->rank);
    push_a(stack_a, stack_b, 1);
    c.pa_count++;
    (*stack_a)->rank = rank;
    return (c);
}

    sort_res = if_items_sorted(stack_a, c.pa_count, 'a');
    auto_push_b(stack_a, stack_b, c.pa_count, 1);



count_pack sort_algo_rev(list **stack_a, list **stack_b, int items, int accum_items)
{
    int         j;
    count_pack  c;

    j = 0;
    c.rb_count = 0;
    c.pa_count = 0;
    while (j < (items))
    {
        if ((*stack_b)->rank < accum_items)
            c = below_median(stack_a, stack_b, c);
        else
            c = above_median(stack_a, stack_b, c);
        j++;
    }
    re
}


int  if_items_sorted(list **stack_a, int nbr_of_items)
{
    list    *current;
    int     i;
    int     count;

    current = *stack_a;
    i = 0;
    count = 0;
    while (i < (nbr_of_items))
    {
        current = current->next;
        i++;
    }
    while (i)
    {
        if (current->rank - current->next->rank == -1)
            count++;
        i--;
        current = current->prev;
    }
    return (count);
}

int  if_items_sorted_rev(list **stack_b, int nbr_of_items)
{
    list    *current;
    int     i;
    int     count;

    current = *stack_b;
    i = 0;
    count = 0;
    while (i < (nbr_of_items))
    {
        current = current->next;
        i++;
    }
    while (i)
    {
        if (current->rank - current->next->rank == 1)
            count++;
        i--;
        current = current->prev;
    }
    return (count);
}








void sort_mgt_b_to_a(list **stack_a, list **stack_b, int chunk_nbr, int root, int nbr_of_nodes)
{
    int     i;
    int     items;
    int     accum_items;

    accum_items = 0;
    items = items_in_chunk(nbr_of_nodes, chunk_nbr, root);
    if (items < 4)
    {
        small_sort_rev(stack_b);
        return ;
    }
    while (!chunk_nbr && (items >= 4))
    {
        sort_algo_rev(stack_a, stack_b,items, acc)
        
        


    }

























    root = finding_root(items_in_chunk);
    i = 1;
    accum_items = 0;
    if (items_in_chunk < 4)
    {
        small_sort_rev(stack_b);
    }
    root = finding_root(items_in_chunk);
    while (i <= root && items_in_chunk >= 4)
    {
        items = items_in_chunk(, i, root);
        accum_items = accum_items + items;
        sort_algo(stack_a, stack_b, items, accum_items);
        add_partition_to_b(stack_b, accum_items);
        i++;
    }
    small_sort_rev(stack_b);
}
