/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:12:10 by chuleung          #+#    #+#             */
/*   Updated: 2023/12/24 17:49:01 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stddef.h>
//#include <stdlib.h>

static size_t	nr_of_arrays(char const *s, char d)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (s[i])
	{
		while (s[i] == d)
			i++;
		if (s[i] != d && s[i])
			sum++;
		while (s[i] != d && s[i])
			i++;
	}
	return (sum);
}

static char	*extract_str(char const *s, char c)
{
	char	*out_str;
	size_t	i;
	size_t	len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	out_str = (char *)malloc((len + 1) * sizeof(char));
	i = 0;
	while (s[i] != c && i < len)
	{
		out_str[i] = s[i];
		i++;
	}
	out_str[i] = '\0';
	return (out_str);
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		j;
	size_t		total;
	char		**strs;

	i = 0;
	j = 0;
	total = nr_of_arrays(s, c);
	strs = (char **)malloc(sizeof(char *) * (total + 1));
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			strs[j] = extract_str(&s[i], c);
			j++;
		}
		while (s[i] != c && s[i])
			i++;
	}
	strs[j] = NULL;
	return (strs);
}


/*int		multi_strs_len(char **strs)
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

char	*replace_quote_with_space(char	*str, size_t len)
{
	size_t		i;
	char	*str_without_quote = NULL;

	str_without_quote = (char *)malloc(sizeof(char) * (len + 1));
	if (str_without_quote == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == '"')
			str_without_quote[i] = ' ';
		else
			str_without_quote[i] = str[i];
		i++;
	}
	str_without_quote[i] = '\0';
	return (str_without_quote);
}




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

/*int	main(void)
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
