#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;

	tmp = 0;
	if (c == 0)
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	while (*s)
	{
		if (c == *s)
			tmp = (char *)s;
		s++;
	}
	return (tmp);
}


#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main() {
	char *mem = "test";

  printf("%p",ft_strrchr(mem, '\0'));
  return 0;
}
