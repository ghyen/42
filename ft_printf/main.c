#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
int	main(void)
{
	char a = '0';
	int len1;
	int len2;

	//len1 = ft_printf(" %p ", -1);
	//printf("\n");
	len2 = printf("\001\002\007\v\010\f\r\n");
	printf("\n n2: %d", len2);
	return (0);
}
