#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


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

int atoi_limit_chk_sign(char *argv_sign)
{
    int    sign;

    sign = 1;
    if (*argv_sign == '-')
        sign = -1;
    return (sign);
}

int atoi_limit_chk_algo(long projected_int_val, char *argv, int sign)
{
    int        digit;

    while(*argv)
    {
        digit = *argv - '0';
        if (sign > 0)
        {
            if (projected_int_val > (INT_MAX - digit) / 10)
                return (0);
            projected_int_val = projected_int_val * 10 + digit;
        }
        if (sign < 0)
        {
            if (projected_int_val < (INT_MIN + digit) / 10)
                return (0);
            projected_int_val = projected_int_val * 10 - digit;
        }
        argv++;
    }
    return (1);
}

int atoi_for_limit_chk(char *argv)
{
    int    element;
    int    sign;
    int    chk_result;

    element = 0;
    sign = atoi_limit_chk_sign(&argv[element]);
    if (argv[element] == '-' || argv[element] == '+')
        element++;
    chk_result = atoi_limit_chk_algo(0, &argv[element], sign);
    if (!chk_result)
        return (0);
    return (1);
}


//the i has to be 1
int limit_chk(char **argv)
{
    int        i;
    int        atoi_for_limit_chk_res;


    i = 1;
    while (argv[i])
    {
        atoi_for_limit_chk_res = atoi_for_limit_chk(argv[i]);
        if (!atoi_for_limit_chk_res)
            return (0);
        i++;
    }
    return (1);
}

int limit_ctrl(char **argv)
{
    int        limit_chk_res;

    limit_chk_res = limit_chk(argv);
    if (!limit_chk_res)
        return (0);
    return (1);
}

int main(int argc, char **argv)
{
	int input_result;
    int limit_result;
    int i;
            
	i = 1;
	while (i < argc)
	{
        input_result = input_chk(argv[i]);
		limit_result = atoi_for_limit_chk(argv[i]);
		printf("Input Result: %d\n", input_result);
        printf("Limit Result: %d\n", limit_result);
        printf("################################################\n");
		i++;
	}
    
    return (0);
}
