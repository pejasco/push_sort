#include <stdio.h>

int finding_root(int count)
{
    int     root_index;
    int     radicand;
    int     root;
	if (count == 0)
	{
		root = 0;
		return (root);
	}
	if (count < 4)
	{
		root = 1;
		return (root);
	}
    root_index = 2;
    radicand = count;
    root = 1;
    while (radicand >= 4)
    {
        radicand = (radicand / root_index);
        root++;
    }
    return (root);
}


int main(void)
{
	int		count;
	int 	res;

	count = 3;
	res = finding_root(count);
	printf("%d", res);	
	return (0);
}



