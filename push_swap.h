/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:25:18 by chuleung          #+#    #+#             */
/*   Updated: 2024/01/05 18:46:24 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_node
{
    struct s_node *prev;
	int data;
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
void	stack_mgt(list **stack_a, list **stack_b);

//linked_list_mgt.c
list *addtoempty(int data);
list *addatbeg(list *tail, int data);
list *addatend(list *tail, int data);
list *delfirst(list *tail);
list *dellast(list *tail);

//stack_in_out.c
list	*init_stack_a(list **ptr_to_stack, int *arry_of_ints);
list	*stack_in(list **ptr_to_stack, list **tail, int data);
list	*stack_out(list **ptr_to_stack, list **tail);

//swap.c
void	swap_a(list **stack_a);
void	swap_b(list **stack_b);;


#endif
