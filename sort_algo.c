/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:59:04 by chuleung          #+#    #+#             */
/*   Updated: 2024/01/11 18:59:30 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int finding_root(int nbr_of_nodes)
{
    int     root_index;
    int     radicand;
    int     root;

    radicand = nbr_of_nodes;
	if (radicand == 0)
	{
		root = 0;
		return (root);
	}
	if (radicand < 4)
	{
		root = 1;
		return (root);
	}
    root_index = 2;
    root = 1;
    while (radicand >= 4)
    {
        radicand = (radicand / root_index);
        root++;
    }
    return (root);
}

int items_in_chunk(int nbr_of_nodes, int current_i, int root)
{
    int     i;

    i = 0;
    if (current_i == root)
    {
        while (i < root)
        {
            nbr_of_nodes = (nbr_of_nodes / 2);
            i++;
        }
        return (nbr_of_nodes);
    }
    while (i < current_i)
    {
        nbr_of_nodes = (nbr_of_nodes / 2);
        i++;
    }
    return (nbr_of_nodes);
}


void sort_algo(list **stack_a, list **stack_b, int nbr_of_args)
{
    int     root;
    int     items;
    int     i;
    int     j;
    int     rank;

    i = 1;
    root = finding_root(nbr_of_args);
    printf("root---->%d\n\n", root);
    items = items_in_chunk(nbr_of_args, i, root);
    printf("items--->%d\n\n", items);
    while (i++ <= root)
    {
        j = 0;
        while (j++ < items)
        {
            if ((*stack_a)->rank <= items)
                rotate_a(stack_a, 1);
            else
            {
                rank = ((*stack_a)->rank);
                push_b(stack_a, stack_b, 1);
                (*stack_b)->rank = rank;
            }
        }
    }
}
