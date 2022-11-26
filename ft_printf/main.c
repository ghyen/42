#include "ft_printf.h"
#include <stdio.h>
int	main(void)
{
	int a = -1;
	ft_printf("%p", &a);
	printf("\n%p", &a);
	return (0);
}
