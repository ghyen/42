#include "libft.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int	total_len(char const *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

char	*get_word(char const *str, int len)
{
	char	*ret;
	int		j;
	int		i;

	j = 0;
	i = 0;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	while (i < len)
	{
		ret[j] = str[j];
		j++;
		i++;
	}
	ret[j] = 0;
	return (ret);
}

int	word_count(char const *str, char c)
{
	int	len;

	len = 0;
	while (str[len] != c && str[len])
		len++;
	return (len);
}

char	**ft_split(char const *s, char c)
{
	int		t_len;
	char	**ret;
	int		i;
	int		count;

	i = 0;
	t_len = total_len(s, c);
	ret = (char **)malloc(sizeof(char *) * (t_len + 1));
	if (!ret)
		return (0);
	while (*s && i < t_len)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			count = word_count(s, c);
			ret[i++] = get_word(s, count);
			s += count;
		}
	}
	ret[i] = 0;
	return (ret);
}

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
	//printf("my = %ld\n",ft_atoi("-9223372036854775809"));
	//printf("or = %ld",atoi("-9223372036854775809"));
	char ** ret = ft_split("hello!", ' ');
	return 0;
}
