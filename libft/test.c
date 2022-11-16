#include "libft.h"



#include <unistd.h>
#include <string.h>
#include <stdio.h>

int	ft_atoi(const char *str)
{
	long long ret;
	int		flag;

	ret = 0;
	flag = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			flag = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (*str >= '0' && *str <= '9')
		{
			ret *= 10;
			ret += (*str - '0');
		}
		str++;
	}
	//if (ret * flag <= -4294967295)
	//	return (0);
	//if (ret >= 4294967295)
	//	return (-1);
	return (ret * flag);
}


int main()
{
	printf("my = %ld\n",ft_atoi("-9223372036854775809"));
	printf("or = %ld",atoi("-9223372036854775809"));
	return 0;
}
