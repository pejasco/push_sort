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
    printf("items_in_chunk---->%d\n", nbr_of_nodes);
    return (nbr_of_nodes);
}

void sort_algo(list **stack_a, list **stack_b, int items, int push_rank)
{
    int     j;
    int     rank;

    //printf("items---->%d\n", items);
    //printf("push_rank---->%d\n", push_rank);
    j = 0;
    while (j < (items))
    {
        if ((*stack_a)->rank >= push_rank)
                rotate_a(stack_a, 1);
        else
        {
            rank = ((*stack_a)->rank);
            push_b(stack_a, stack_b, 1);
            (*stack_b)->rank = rank;
            j++;
        }
    }
}

void sort_mgt(list **stack_a, list **stack_b, int nbr_of_args)
{
    int     root;
    int     items;
    int     i;
    int     push_rank;

    i = 1;
    push_rank = 0;
    if (nbr_of_args < 4)
        sort_3(stack_a);
    root = finding_root(nbr_of_args);
    while (i <= root && nbr_of_args >= 4)
    {
        items = items_in_chunk(nbr_of_args, i, root);
        //printf("item->>>>>%d/n", items);
        push_rank = push_rank + items;
        sort_algo(stack_a, stack_b, items, push_rank);
        i++;
    }
}