/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_utili.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Scofield <Scofield@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:20:46 by Scofield          #+#    #+#             */
/*   Updated: 2024/01/28 18:35:07 by Scofield         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_in_rank(t_list **stack)
{
	int		max;
	t_list	*current;

	if (*stack == NULL || stack == NULL)
		return (0);
	max = (*stack)->rank;
	current = (*stack)->next;
	while (current != *stack)
	{
		if (current->data > max)
			max = current->rank;
		current = current->next;
	}
	return (max);
}

int	check_moves_before_push(t_stacks *stacks, int rank_of_first_b_node)
{
	t_list	*temp;
	int		i;

	temp = stacks->stack_a;
	i = 0;
	if (rank_of_first_b_node == 3)
	{
		while (temp->rank < rank_of_first_b_node)
		{
			i++;
			temp = temp->next;
		}
		return (i);
	}
	else if (rank_of_first_b_node == 4)
	{
		if (max_in_rank(&(stacks->stack_a)) == 5)
			return (1);
		return (0);
	}
	return (0);
}

void	ra_n_rra_for_push_a(t_stacks *stacks, int rank)
{
	int	count_in_ra_or_rra;
	int	i;

	count_in_ra_or_rra = check_moves_before_push(stacks, rank);
	i = -1;
	if (rank == 3)
	{
		while (++i <= count_in_ra_or_rra)
			rotate_a(&(stacks->stack_a), 1);
	}
	if (rank == 4)
	{
		if (count_in_ra_or_rra)
			reverse_a(&(stacks->stack_a), 1);
	}
	return ;
}

void	auto_rotate_a(t_list **stack_a, int no_of_time, int print)
{
	int	i;

	i = 0;
	while (i < no_of_time)
	{
		rotate_a(stack_a, print);
	}
	i++;
	return ;
}

void	auto_reverse_a(t_list **stack_a, int no_of_time, int print)
{
	int	i;

	i = 0;
	while (i < no_of_time)
	{
		reverse_a(stack_a, print);
	}
	i++;
	return ;
}
