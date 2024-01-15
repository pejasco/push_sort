/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mgt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:43:00 by chuleung          #+#    #+#             */
/*   Updated: 2024/01/15 19:15:23 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"




int sort_mgt(list **stack_a, list **stack_b, int nbr_of_args, int accum_sorted_nbrs, char situation)
{
    if (situation == 'I')
        accum_sorted_nbrs = init_sort_a_to_b(stack_a, stack_b, nbr_of_args);
    while (accum_sorted_nbrs <= (nbr_of_args - 4))
    {
        if (situation == 'A')
        sort_mgt_a_to_b(stack_a, stack_b);
        
        
        if (situation == 'B')
        sort_mgt_b_to_a(stack_a, stack_b);

    }

    
    
    accum_sorted_nbrs = 
    

    while (sorted_nbrs <= (nbr_of_args - 4))
    {
        i = i + sort_mgt_a_to_b(stack)



    }
    small_sort(stack_a);
}