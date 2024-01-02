/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:25:18 by chuleung          #+#    #+#             */
/*   Updated: 2024/01/02 16:10:01 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_node
{
    struct s_node *prev;
	int value;
	struct s_node *next;	
} list;

//input_control.c
int		input_ctrl(char **argv);


//push_swap_utili
int		multi_strs_len(char **strs);
char	*comb_multi_strs(char **strs);
char	*replace_quote_with_space(char *str, size_t len);
#endif
