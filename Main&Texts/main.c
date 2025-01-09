#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd1 = open("TEXT1", O_RDONLY);
	int fd2 = open("TEXT2", O_RDONLY);
	int fd3 = open("TEXT3", O_RDONLY);
	char *temp;
	int i = 0;
	int j = 0;
	int fds[] = {fd1, fd2, fd3};
	int fdmount = 3;

	while (j < fdmount)
	{
		i = 0;
		while((temp = get_next_line(fds[i])) != NULL)
		{
			printf("%s", temp);
			free(temp);
			if(j == (fdmount - 1))
				printf("\n");
			i++;
		}
		j++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
}