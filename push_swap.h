/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.london.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:25:18 by chuleung          #+#    #+#             */
/*   Updated: 2024/02/03 20:40:31 by chuleung         ###   ########.fr       */
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
	int		high;
	int		low;
	int		rotate;
	int		push;
	char	from;
}	t_qs_stats;


//dupli_ctrl.c
int			dupli_ctrl(int argc, int *arry_of_ints);

//input_ctrl.c
int			input_ctrl(char **argv);

//limit_ctrl.c
int			limit_ctrl(char **argv);

//linked_list_mgt.c
t_list		*push(t_list *tail, int data, int rank);
t_list		*append(t_list *tail, int data, int rank);
t_list		*pop(t_list *tail, t_list **stack);
t_list		*poplast(t_list *tail);

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
void		auto_push_a(t_list **stack_a, t_list **stack_b, 
				int no_of_time, int print);
void		auto_push_b(t_list **stack_a, t_list **stack_b, 
				int no_of_time, int print);

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

// sort_utili_2.c
void		position_in_stacks(t_list **stack);
t_list		*find_post_with_rank(t_list **stack, int rank);
int			if_stack_a_sorted(t_list **stack);

//sort_rank.c
t_list		*rank_in_stack(t_list **stack);
void		rank_from_copy_a_to_a(t_list **a, t_list **copy_of_a);
int			rank_exist(t_list **stack);

//sort_rank_2.c
int			max_in_rank(t_list **stack);
int			min_in_rank(t_list **stack);


//mini_sort.c
void		sort_3(t_list **stack);
void		mini_sort(t_list **stack);

//sort_2.c
void 		sort_2(t_list **stack);

//sort_5.c
void 		sort_5(t_stacks *stacks);

//quicksort.c
void		sort_mgt(t_stacks *stacks, int nbr_of_args);
void		quicksort(t_stacks *stacks, t_qs_stats stats);




#endif
