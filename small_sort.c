/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:33:16 by chuleung          #+#    #+#             */
/*   Updated: 2024/01/20 21:57:21 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_3_algo(t_list **stack, t_list **fir_node, t_list **sec_node, t_list **thi_node)
{
	//2>1>3
	if (((*thi_node)->rank > (*fir_node)->rank)
			&& (*fir_node)->rank > (*sec_node)->rank)
		swap_a(stack, 1);
	//3>2>1
	else if (((*fir_node)->rank > (*sec_node)->rank)
			&& (*sec_node)->rank > (*thi_node)->rank)
	{
		rotate_a(stack, 1);
		swap_a(stack, 1);
	}
	//3>1>2
	else if (((*fir_node)->rank > (*thi_node)->rank)
			&& (*thi_node)->rank > (*sec_node)->rank)
		rotate_a(stack, 1);
	//1>3>2
	else if (((*sec_node)->rank > (*thi_node)->rank)
			&& (*thi_node)->rank > (*fir_node)->rank)
	{    
		swap_a(stack, 1);
		rotate_a(stack, 1);
	}
	//2>3>1
	else if (((*sec_node)->rank > (*fir_node)->rank)
			&& (*fir_node)->rank > (*thi_node)->rank)
		reverse_a(stack, 1);
	else
		return ;
}

void sort_2_rank(t_list **stack, int rank_exist)
{
	int     max;
	int     min;
	int     i;
	t_list    *current;

	if (rank_exist == 1)
		return ;
	i = 0;
	max = max_in_stack(stack);
	printf("max--->%d\n", max);
	min = min_in_stack(stack);
	printf("min--->%d\n", min);
	current = *stack;
	while (i < 2)
	{
		if (current->data == max)
			(current)->rank = 1;
		if (current->data == min)
			(current)->rank = 0;
		current = current->next;
		i++;
	}
}

void sort_3_rank(t_list **stack, int rank_exist)
{
	int     max;
	int     min;
	int     i;
	t_list    *current;

	if (rank_exist == 1)
		return ;
	i = 0;
	max = max_in_stack(stack);
	printf("max--->%d\n", max);
	min = min_in_stack(stack);
	printf("min--->%d\n", min);
	current = *stack;
	while (i < 2)
	{
		if (current->data == max)
			(current)->rank = 3;
		else if (current->data == min)
			(current)->rank = 1;
		else
			(current)->rank = 2;
		current = current->next;
		i++;
	}
}

int rank_exist(t_list **stack)
{
	if ((*stack)->rank > -1)
		return (1);
	else
		return (0);
}

void sort_2(t_list **stack)
{
	int     exist_res;

	exist_res = rank_exist(stack);
	sort_2_rank(stack, exist_res);
	if((*stack)->rank > (*stack)->next->rank)
		swap_a(stack, 1);
}

void sort_3(t_list **stack)
{
	t_list    *fir_node;
	t_list    *sec_node;
	t_list    *thi_node;
	int     exist_res;

	exist_res = rank_exist(stack);
	sort_3_rank(stack, exist_res);
	fir_node = *stack; 
	sec_node = (*stack)->next;
	thi_node = (*stack)->next->next;
	sort_3_algo(stack, &fir_node, &sec_node, &thi_node);
}

void small_sort(t_list **stack)
{
	int     count;

	count = count_in_stack(stack);
	if (count <= 1 || count > 3)
		return ;
	if (count == 2)
		sort_2(stack);
	if (count == 3)
		sort_3(stack);
}

