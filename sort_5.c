/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.london.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:26:39 by chuleung          #+#    #+#             */
/*   Updated: 2024/02/03 19:33:50 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_one_n_two(t_stacks *stacks)
{
	t_list	*temp;
	int		i;
	int		push;

	i = 0;
	push = 0;
	temp = stacks->stack_a;
	while (i < 5 && push <= 2)
	{
		if (temp->rank == 1 || temp->rank == 2)
		{
			temp = temp->next;
			push_b(&(stacks->stack_a), &(stacks->stack_b), 1);
			push++;
		}
		else
		{
			temp = temp->next;
			rotate_a(&(stacks->stack_a), 1);
		}
		i++;
	}
}

void	sort_5(t_stacks *stacks)
{
	int		count_b;

	if ((if_stack_a_sorted(&(stacks->stack_a))))
		return ;
	push_one_n_two(stacks);
	mini_sort(&(stacks->stack_a));
	count_b = count_in_stack(&(stacks->stack_b));
	if (count_b != 2)
		return ;
	if (stacks->stack_b->data < stacks->stack_b->next->data)
		swap_b(&(stacks->stack_b), 1);
	auto_push_a(&(stacks->stack_a), &(stacks->stack_b), 2, 1);
}
