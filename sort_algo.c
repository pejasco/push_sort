/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:59:04 by chuleung          #+#    #+#             */
/*   Updated: 2024/01/16 13:48:46 by chuleung         ###   ########.fr       */
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
    printf("root---->%d\n", root);
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
        printf("items_in_chunk---->%d\n", nbr_of_nodes);
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

void sort_algo(list **stack_a, list **stack_b, int items, int accum_items)
{
    int     j;
    int     rank;
    //list    *parti_head;

    //printf("items---->%d\n", items);
    //printf("accum_items---->%d\n", accum_items);
    j = 0;
    while (j < (items))
    {
        if ((*stack_a)->rank > accum_items)
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


void init_sort_a_to_b(list **stack_a, list **stack_b, int nbr_of_args, int root)
{
    int     root;
    int     items;
    int     i;
    int     accum_items;

    i = 1;
    accum_items = 0;
    if (nbr_of_args < 4)
    {
        small_sort(stack_a);
        return ;
    }
    root = finding_root(nbr_of_args);
    while (i <= root && nbr_of_args >= 4)
    {
        items = items_in_chunk(nbr_of_args, i, root);
        accum_items = accum_items + items;
        sort_algo(stack_a, stack_b, items, accum_items);
        //add_partition_to_b(stack_b, accum_items);
        i++;
    }
    small_sort(stack_a);
}

/*
void add_partition_to_b(list **stack_b, int accum_items)
{
    int     i;
    list    *current;

    i = 0;
    current = *stack_b;
    while (i == (accum_items + 1))
    {
        current = current->next;
        i++;
    }
    current->parti = 'P';
}*/