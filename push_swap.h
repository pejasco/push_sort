/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:25:18 by chuleung          #+#    #+#             */
/*   Updated: 2024/02/02 15:49:35 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "math.h"

typedef struct s_node
{
	struct s_node	*prev;
	int				data;
	int				rank;
	int				position;
	struct s_node	*next;
}	t_list;

typedef struct s_stacks
{
	t_list		*stack_a;
	t_list		*stack_b;
	int			nbr_of_args;
}	t_stacks;

typedef struct s_qs_stats
{
	int		med;
	int		high;
	int		low;
}	t_qs_stats;

typedef struct s_stat
{
	int			max;
	int			min;
	int			med;
}	t_stat;

/*
typedef struct s_stac
{
	int		_count;
	int		sb_count;
	int		ra_count;
	int		rb_count;
} t_stac;
*/

//dupli_ctrl.c
int			dupli_chk(int argc, int *arry_of_ints);
int			dupli_ctrl(int argc, int *arry_of_ints);

//input_ctrl.c
int			input_chk_algo(char *argv);
int			input_chk(char **argv);
int			input_ctrl(char **argv);

//limit_ctrl.c
int			atoi_limit_chk_sign(char *argv_sign);
int			atoi_limit_chk_algo(long projected_int_val, char *argv, int sign);
int			atoi_for_limit_chk(char *argv);
int			limit_chk(char **argv);
int			limit_ctrl(char **argv);

//push_swap.c
int			*arry_of_ints(char **argv);
int			*input_mgt(int argc, char **argv);
void		print_list(char stackname, t_list **stack);
void		print_list_rank(char stackname, t_list **stack);
void		stack_mgt(t_list **stack_a, t_list **stack_b);

//linked_list_mgt.c
t_list		*addtoempty(int data, int rank);
t_list		*push(t_list *tail, int data, int rank);
t_list		*append(t_list *tail, int data, int rank);
t_list		*pop(t_list *tail, t_list **stack);
t_list		*poplast(t_list *tail);

//stack_in_out.c
t_list		*init_stack_a(t_list **ptr_to_stack, int *arry_of_ints);
t_list		*stack_in(t_list **ptr_to_stack, t_list **tail, int data);
t_list		*stack_out(t_list **ptr_to_stack, t_list **tail);

//linked_list_utili.c
t_list		*tail_find(t_list **stack);
void		free_whole_stack(t_list **stack);

//swap.c
void		swap_a(t_list **stack_a, int print);
void		swap_b(t_list **stack_b, int print);
void		swap_anb(t_list **stack_a, t_list **stack_b, int print);

// push.c
void		push_a(t_list **stack_a, t_list **stack_b, int print);
void		push_b(t_list **stack_a, t_list **stack_b, int print);

// rotate.c
void		rotate_a(t_list **stack_a, int print);
void		rotate_b(t_list **stack_b, int print);
void		rotate_anb(t_list **stack_a, t_list **stack_b, int print);

//reverse.c
void		reverse_a(t_list **stack_a, int print);
void		reverse_b(t_list **stack_b, int print);
void		reverse_anb(t_list **stack_a, t_list **stack_b, int print);

// sort_utili.c
int			count_in_stack(t_list **stack);
int			max_in_stack(t_list **stack);
int			min_in_stack(t_list **stack);
t_list		*copy_init_a(t_list **stack);
int			if_stack_a_sorted(t_list **stack);
int			max_in_rank(t_list **stack);
int			min_in_rank(t_list **stack);

// sort_utili.c
void		position_in_stacks(t_list **stack);
t_list		*find_post_with_rank(t_list **stack, int rank);

//sort_rank.c
t_list		*rank_in_stack(t_list **stack);
t_list		*rank_algo(t_list *copy_of_a, t_list *copy_of_b);
t_list		*rank_assign_to_copy_b(t_list *copy_of_b);
t_list		*push_copy_b_to_copy_a(t_list *copy_of_a, t_list *copy_of_b);
void		rank_from_copy_a_to_a(t_list **a, t_list **copy_of_a);

//sort_algo.c
int			finding_root(int nbr_of_nodes);
int			items_in_chunk(int nbr_of_nodes, int current_i, int root);
void		init_sort_algo(t_list **stack_a, t_list **stack_b, \
			int items, int push_rank);
int			init_sort_algo_extend(t_list **stack_a, t_list **stack_b, \
			int accum_items, int j);
void		init_sort_a_to_b(t_stacks *stacks, int nbr_of_args, int root);

//mini_sort.c
void		sort_3_algo(t_list **stack, t_list **fir_node, \
			t_list **sec_node, t_list **thi_node);
void		sort_2_rank(t_list **stack, int rank_exist);
void		sort_3_rank(t_list **stack, int rank_exist);
int			rank_exist(t_list **stack);
void		sort_2(t_list **stack);
void		sort_3(t_list **stack);
void		mini_sort(t_list **stack);
void		position_in_stacks(t_list **stack);
t_list		*find_post_with_rank(t_list **stack, int rank);
void		mini_sort(t_list **stack);

//mini_sort_rev.c
void		sort_3_algo_rev(t_list **stack, t_list **fir_node, \
			t_list **sec_node, t_list **thi_node);
void		sort_2_rev(t_list **stack);
void		sort_3_rev(t_list **stack);
void		auto_push_a(t_list **stack_a, t_list **stack_b, \
			int no_of_time, int print);
void		auto_push_b(t_list **stack_a, t_list **stack_b, \
			int no_of_time, int print);
void		mini_sort_rev(t_list **stack_a, t_list **stack_b);

/*
//small_sort.c
void		sort_5_op_pt2(t_stacks *stacks, int rank);
void		sort_5_op(t_stacks *stacks);
void		sort_4(t_stacks *stacks);
void		sort_5(t_stacks *stacks);
void		small_sort(t_stacks *stack);
*/

//sort_five.c
void 		sort_five(t_stacks *stacks);

//small_sort_utili.c
int			check_moves_before_push(t_stacks *stacks, int rank_of_first_b_node);
void		ra_n_rra_for_push_a(t_stacks *stacks, int rank);
void		auto_rotate_a(t_list **stack_a, int no_of_time, int print);
void		auto_reverse_a(t_list **stack_a, int no_of_time, int print);

//quicksort.c
void		sort_mgt(t_stacks *stacks, int nbr_of_args);
void    	quicksort(t_stacks *stacks, t_qs_stats *stats, char from, int push);

//void    	quicksort(t_stacks *stacks, int low, int high, char from);
//void    	quicksort(t_stacks *stacks, int low, int high, char from);

#endif
