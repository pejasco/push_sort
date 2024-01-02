#include <stdio.h>
/*
int input_chk(char *full_str)
 {
      int     i;
      int     j;
  
      i = 0;
      while (full_str[i])
      {
         j = i + 1;
         if ((full_str[i] != '+' && full_str[i] != '-' && full_str[i] != ' ') \
			&& (full_str[i] < '0' || full_str[i] > '9'))
             return (0);
         if ((full_str[i] == '+' || full_str[i] == '-') && \
			(full_str[j] < '0' || full_str[j] > '9' || full_str[j] == '\0'))
             return (0);
         i++;
		if ((full_str[i] >= '0' || full_str[i] <= '9') && \
		 (full_str[j] == '-' || full_str[j] == '+'))
			return (0);
      }
      return (1);
 }
*/

int limit_chk(char **argv)
{	
	int		i;
	int		atoi_for_limit_chk_res;

	i = 0;	
	while (revised_argv[i])
	{
		atoi_for_limit_chk(revised_argv[i]);
		if (!atoi_for_limit_chk_res)
			return (1);
		i++;
	}
	return (0);
}

int limit_ctrl(char **argv)
{
	int		limit_chk_res;

	limit_chk_res = limit_chk(revised_argv);
	if (!limit_chk_res)
	{
		free(arry_of_ints);
		return (1);
	}
	return (0);
}

int atoi_limit_chk_sign(char *revised_argv)
{
	int	1st_element;
	int	sign;

	sign = 1;
	if (revised_argv[1st_element] == '-')
		sign = -1;
	return (sign)
}

int	atoi_limit_chk_algo(long projected_int_val, char *revised_argv, int sign)
{
	int		digit;

	while(*revised_argv)
	{		
		digit = *revised_argv - '0';
		if (sign > 0)
		{
			if (projected_int_val > (INT_MAX - digit) / 10)
				return (1);
			projected_int_val = projected_int_val * 10 + digit;
		}
		if (sign < 0)
		{
			if (projected_int_val < (INT_MIN + digit) / 10)
				return (-1);
			projected_int_val = projected_int_val * 10 - digit;
		}
		revised_argv++;
	}
	return (0);
}

int **atoi_for_limit_chk(char *revised_argv)
{
	int		element;
	int 	sign;
	int		chk_result;

	element = 0;
	sign = atoi_limit_chk_sign(&revised_argv[element])
	if (revised_argv[element] == '-')
		element++;
	chk_result = atoi_limit_chk_algo(0, &revised_argv[element], sign);
	if (!chk_result)
		return (1);
	return (0);		
}

int main(int argc, char **argv)
{
	int result;
	int	i;

	i = 1;
	while (i < argc)
	{
		result = input_chk(argv[i]);
		printf("Result: %d\n", result);
		i++;
	}
	return (0);
}
