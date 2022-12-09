#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd[3];
	char	*s;

	//fd[0] = open("./a.txt", O_RDONLY);
	//fd[1] = open("./b.txt", O_RDONLY);
	//while ((s = get_next_line(fd[0])) != NULL)
	//{
	//	printf("%s", s);
	//}

	//printf("\n--------\n");

	//while ((s = get_next_line(fd[1])) != NULL)
	//{
	//	printf("%s", s);
	//}

	//close (fd[0]);

	//printf("\n--------\n");
	//fd[0] = open("./a.txt", O_RDONLY);

	//while ((s = get_next_line(fd[0])) != NULL)
	//{
	//	printf("%s", s);
	//}

	fd[0] = open("./a.txt", O_RDONLY);
	fd[1] = open("./b.txt", O_RDONLY);
//	fd[2] = open("./c.txt", O_RDONLY);

	printf("1. %s fd : %d\n", get_next_line(fd[0]), fd[0]);
	printf("2. %s fd : %d\n", get_next_line(fd[1]), fd[1]);
			char *temp;
			do
			{
				temp = get_next_line(fd[0]);
				free(temp);
			} while (temp != NULL);
	//close(fd[0]);
	//printf("3. %s fd : %d\n", get_next_line(fd[0]), fd[0]);
	//fd[0] = open("./a.txt", O_RDONLY);
	printf("4. %s fd : %d\n", get_next_line(fd[1]), fd[1]);
//	printf("5. %s fd : %d\n", get_next_line(fd[1]), fd[1]);
	//printf("%s", get_next_line(fd[1]));
	//printf("%s", get_next_line(fd[1]));

	//system("leaks a.out");
	//close(fd[0]);


}
