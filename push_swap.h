/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:25:18 by chuleung          #+#    #+#             */
/*   Updated: 2023/12/29 21:07:52 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
    struct s_stack *prev;
	int nbr;
	struct s_stack *next;	
} stack_node

//input_control.c
int		input_ctrl(char **argv);


//push_swap_utili
int		multi_strs_len(char **strs);
char	*comb_multi_strs(char **strs);
char	*replace_quote_with_space(char *str, size_t len);
#endif
