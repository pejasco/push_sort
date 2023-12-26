/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utili.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:02:52 by chuleung          #+#    #+#             */
/*   Updated: 2023/12/26 16:02:57 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		multi_strs_len(char **strs)
{
	int 	i;
	int		j;
	int		len;

	i = 0;
	len = 1;
	while (strs[i])
	{	
		j = 0;
		while(strs[i][j])
		{
			len++;
			j++;
		}
		i++;
	}
	return (len);
}

char	*comb_multi_strs(char **strs)
{
	int		i;
	int		j;
	int		k;
	int		len;
	char	*full_str = NULL;

	i = 0;
	k = 0;
	len = multi_strs_len(strs);
	full_str = (char *)malloc(sizeof(int) * (len + 1));
	while (strs[i])
	{
		j = 0;
		while(strs[i][j] && k < len)
		{
				full_str[k] = strs[i][j];
				k++;
				j++;
		}
		i++;;
	}
	full_str[k] = '\0';
	return (full_str);
}

/*
#include <stdio.h>

int	main(void)
{	
	char	*s = "./a.out \"\"\"\"\"43 \"\"44 45 46 47 48";
	//char	*s = "./a.out \"42 42 45 46 47 48\"";
	//char	*s = "./a.out 42\"44 45 46\"47 48";
	char	c = ' ';
	char	*str_without_quote;
	char	**output;
	size_t	len;

	len = ft_strlen(s);
	str_without_quote = replace_quote_with_space(s, len);
	output = ft_split(str_without_quote, c);
	for (int i = 1; output[i] != NULL; i++)
		printf("%s\n", output[i]);
	return (0);
}
*/



/*#include <stdio.h>

int	main(void)
{	
	//char	*s = "./a.out 42 \"44 45 46\" 47 48";
	char	*s = "./a.out \"42 42 45 46 47 48\"";
	//char	*s = "./a.out 42\"44 45 46\"47 48";
	char	c1 = '"';
	char	c2 = ' ';
	char	**output_del_c1;
	char	*cat_output_del_c1;
	char	**output_del_c1_n_c2;

	output_del_c1 = ft_split(s, c1);
	cat_output_del_c1 = comb_multi_strs(output_del_c1);
	output_del_c1_n_c2 = ft_split(cat_output_del_c1, c2);
	for (int i = 1; output_del_c1_n_c2[i] != NULL; i++)
		printf("%s\n", output_del_c1_n_c2[i]);
	return (0);
}*/
