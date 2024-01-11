/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:25:18 by chuleung          #+#    #+#             */
/*   Updated: 2024/01/06 19:55:48 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_node
{
    struct s_node *prev;
	int data;
	int rank;
	struct s_node *next;	
} list;

//dupli_ctrl.c
int		dupli_chk(int argc, int *arry_of_ints);
int		dupli_ctrl(int argc, int *arry_of_ints);

//input_ctrl.c
int		input_chk_algo(char *argv);
int		input_chk(char **argv);
int		input_ctrl(char **argv);

//limit_ctrl.c
int		atoi_limit_chk_sign(char *argv_sign);
int		atoi_limit_chk_algo(long projected_int_val, char *argv, int sign);
int		atoi_for_limit_chk(char *argv);
int		limit_chk(char **argv);
int		limit_ctrl(char **argv);

//push_swap.c
int		*arry_of_ints(char **argv);
int		*input_mgt(int argc, char **argv);
void	print_list(char stackname, list **stack);
void	print_list_rank(char stackname, list **stack);
void	stack_mgt(list **stack_a, list **stack_b);

//linked_list_mgt.c
list *addtoempty(int data);
list *push(list *tail, int data);
list *append(list *tail, int data);
list *pop(list *tail);
list *poplast(list *tail);

//stack_in_out.c
list	*init_stack_a(list **ptr_to_stack, int *arry_of_ints);
list	*stack_in(list **ptr_to_stack, list **tail, int data);
list	*stack_out(list **ptr_to_stack, list **tail);

//linked_list_utili.c
list	*tail_find(list **stack);
void	free_whole_stack(list **stack);

//swap.c
void	swap_a(list **stack_a, int print);
void	swap_b(list **stack_b, int print);
void	swap_anb(list **stack_a, list **stack_b, int print);

// push.c
void	push_a(list **stack_a, list **stack_b, int print);
void	push_b(list **stack_a, list **stack_b, int print);

// rotate.c
void	rotate_a(list **stack_a, int print);
void	rotate_b(list **stack_b, int print);
void	rotate_anb(list **stack_a, list **stack_b, int print);

//reverse.c
void	reverse_a(list **stack_a, int print);
void	reverse_b(list **stack_b, int print);
void	reverse_anb(list **stack_a, list **stack_b, int print);

// sort_utili.c
int count_in_stack(list **stack);
int min_in_stack(list **stack);
list *copy_init_a(list **stack);

//sort_rank.c
list *rank_in_stack(list **stack);
list *rank_algo(list *copy_of_a, list *copy_of_b);
list *rank_assign_to_copy_b(list *copy_of_b);
list *push_copy_b_to_copy_a(list *copy_of_a, list *copy_of_b);
list *rank_from_copy_a_to_a(list *a, list *copy_of_a);

#endif
