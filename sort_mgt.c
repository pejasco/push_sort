/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mgt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:43:00 by chuleung          #+#    #+#             */
/*   Updated: 2024/01/16 16:46:28 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_median(list **stack_b, int tot_items, int unsorted_items, int chunk_nbr, int root)
{
    int     median;
    int     accum_median;
    int     i; 

    i = root;
    accum_median = 0;
    if (unsorted_items > 3)
    

    while (root == chunk_nbr)
    {
        median = items_in_chunk(tot_items, i, root);
        accum_median = accum_median + median; 
        i--;
    }

}



int sort_algo_for_chunk(list **stack_a, list **stack_b, int unsorted_items, int root)
{
    int push_rank;


    while (root == )
    push_rank = 




}


int sort_mgt_for_chunk(list **stack_a, list **stack_b, int tot_items, int root)
{
        int     chunk_nbr;
        int     unsorted_items;
        int     sorted_items_in_chunk;
        int     accu_sorted_nbrs_in_chunk;
        int     median;

        sorted_items_in_chunk = 0;
        chunk_nbr = root;
        while (chunk_nbr)
       {
            unsorted_items = items_in_chunk(tot_items, chunk_nbr, root); 
            while (unsorted_items < 4)
            {
                find_median() ;
                median = sort_algo_rev(stack_a, stack_b, unsorted_items);
                unsorted_items = (unsorted_items - sorted_items_in_chunk);
            }
            small_sort_rev(stack_a, stack_b);
            chunk_nbr--;
       }

}








int sort_mgt(list **stack_a, list **stack_b, int nbr_of_args)
{
    int sorted;
    int root;
    
    root = finding_root(nbr_of_args);
    init_sort_a_to_b(stack_a, stack_b, nbr_of_args, root);
    sort_mgt_for_chunk(stack_a, stack_b, nbr_of_args, root);
    sorted = if_stack_a_sorted(stack_a);
    return (sorted)
}

    

    

    while (sorted_nbrs <= (nbr_of_args - 4))
    {
        i = i + sort_mgt_a_to_b(stack)



    }
    small_sort(stack_a);
}