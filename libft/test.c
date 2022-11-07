#include <ctype.h>
#include <stdio.h>
#include "ft_isalpha.c"

int main(int argc, char **argv)
{
	int ret1,ret2;
	int input = (int)argv[1][0];
	ret1 = isalpha(input);
	ret2 = ft_isalpha(input);
	printf("%d",ret1);
	printf("%d",ret2);
}
