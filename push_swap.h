/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:25:18 by chuleung          #+#    #+#             */
/*   Updated: 2024/01/04 17:33:20 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_node
{
    struct s_node *prev;
	int data;;
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
void	print_list(list **stack);

//push_swap_utili.c
//int		int_arry_count(int *int_arry);

//linked_list_mgt.c
list *addtoempty(int data);
list *addatbeg(list *tail, int data);
list *addatend(list *tail, int data);
list *delfirst(list *tail);
list *dellast(list *tail);

//init_stack_a.c
list	*init_stack_a(list **ptr_to_stack, int *arry_of_ints);
list	*stack_in(list **ptr_to_stack, list **tail, int data);
list	*stack_out(list **ptr_to_stack, list **tail);

//int		multi_strs_len(char **strs);
//char	*comb_multi_strs(char **strs);
//char	*replace_quote_with_space(char *str, size_t len);
#endif
