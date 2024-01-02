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
