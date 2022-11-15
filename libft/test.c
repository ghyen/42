#include "libft.h"



#include <unistd.h>
#include <string.h>
#include <stdio.h>
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n)
	{
		if ((char)c == *p)
			return ((void *)p);
		p++;
		n--;
	}
	return (0);
}

int main() {
	//char *mem = "teste";

  	//printf("%p",ft_strchr(mem, '\0'));
	char *str = ft_memchr("bonjour", 'j', 6);
	printf("%s",str);
  return 0;
}
