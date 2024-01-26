/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:20:03 by chuleung          #+#    #+#             */
/*   Updated: 2024/01/26 15:19:03 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_a(t_list **stack_a, t_list **stack_b, int print)
{
	t_list *tail_of_a;
	t_list *tail_of_b;
	int nbr;
	int rank;

	if (stack_b == NULL)
		return ;
	if ((*stack_b) == NULL)
		return ;
	else
	{
		nbr = (*stack_b)->data;
		rank = (*stack_b)->rank;
	}
	tail_of_a = tail_find(stack_a);
	tail_of_b = tail_find(stack_b);
	tail_of_b = pop(tail_of_b, stack_b);
	tail_of_a = push(tail_of_a, nbr, rank);
	*stack_a = tail_of_a->next;
    if (print == 1)
        printf("pa\n");
}

void push_b(t_list **stack_a, t_list **stack_b, int print)
{
	t_list *tail_of_a;
	t_list *tail_of_b;
	int nbr;
	int rank;

	if (stack_a == NULL)
		return ;
	if ((*stack_a) == NULL)
		return ;
	else
	{
		nbr = (*stack_a)->data;
		rank = (*stack_a)->rank;
	}
	tail_of_a = tail_find(stack_a);
	tail_of_b = tail_find(stack_b);
	tail_of_a = pop(tail_of_a, stack_a);
	tail_of_b = push(tail_of_b, nbr, rank);
	*stack_b = tail_of_b->next;
    if (print == 1)
        printf("pb\n");
}

// void push_b(t_list **stack_a, t_list **stack_b, int print) XXXX
// {
// 	t_list *tail_of_a;
// 	t_list *tail_of_b;
// 	int nbr;

// 	if (stack_a == NULL)
// 		return ;
// 	if ((*stack_a) == NULL)
// 		return ;
// 	else
// 		nbr = (*stack_a)->data;
// 	tail_of_a = tail_find(stack_a);
// 	tail_of_b = tail_find(stack_b);
// 	tail_of_a = pop(tail_of_a);
// 	if (tail_of_a == NULL)
// 		*stack_a = NULL;
// 	else
// 		*stack_a = tail_of_a->next;
// 	tail_of_b = push(tail_of_b, nbr);
// 	*stack_b = tail_of_b->next;
//     if (print == 1)
//         printf("pb\n");
// }

/*
	nbr = (*stack_a)->data;
	tail/Users/macbook/Desktop/projects _of_a = tail_find(stack_a);
	tail_of_b = tail_find(stack_b);
	test_a = tail_of_a->data;
	test_b = tail_of_b->data;
	printf("diuuuu %d", nbr);
	printf("diuuuu %d", test_a);
	printf("diuuuu %d", test_b);
*/

