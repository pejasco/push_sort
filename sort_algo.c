/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:59:04 by chuleung          #+#    #+#             */
/*   Updated: 2024/02/03 00:29:53 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	finding_root(int nbr_of_nodes)
{
	int		root_index;
	int		radicand;
	int		root;

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

int	items_in_chunk(int nbr_of_nodes, int current_i, int root)
{
	int	i;

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

int	init_sort_algo_extend(t_list **stack_a, \
	t_list **stack_b, int accum_items, int j)
{
	int		rank;
	t_list	*tail;

	tail = tail_find(stack_a);
	if (tail->rank < accum_items)
	{
		reverse_a(stack_a, 1);
		rank = ((*stack_a)->rank);
		push_b(stack_a, stack_b, 1);
		(*stack_b)->rank = rank;
		j++;
	}
	else
		rotate_a(stack_a, 1);
	return (j);
}

void	init_sort_algo(t_list **stack_a, \
	t_list **stack_b, int items, int accum_items)
{
	int	j;
	int	rank;

	j = 0;
	while (j < items)
	{
		if ((*stack_a)->rank < accum_items)
		{
			rank = ((*stack_a)->rank);
			push_b(stack_a, stack_b, 1);
			(*stack_b)->rank = rank;
			j++;
		}
		else
			j = j + init_sort_algo_extend(stack_a, stack_b, accum_items, j);
	}
}

void	init_sort_a_to_b(t_stacks *stacks, int nbr_of_args, int root)
{
	int		items;
	int		i;
	int		accum_items;

	i = 1;
	accum_items = 0;
	if (nbr_of_args < 4)
	{
		mini_sort(&(stacks->stack_a));
		return ;
	}
	root = finding_root(nbr_of_args);
	while (i <= root && nbr_of_args > 4)
	{
		items = items_in_chunk(nbr_of_args, i, root);
		accum_items = accum_items + items;
		init_sort_algo(&(stacks->stack_a), \
			&(stacks->stack_b), items, accum_items);
		i++;
	}
	mini_sort(&(stacks->stack_a));
}

/*
void add_partition_to_b(t_list **stack_b, int accum_items)
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