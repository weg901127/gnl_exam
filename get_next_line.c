#define BUFFER_SIZE 1
#define ERR -1
#define DONE 1
#define END 0
#include <limits.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char *ft_strchr(void *str, char c)
{
	while(*(char *)str != c || !(*(char *)str))
		str++;
	return (str);
}
int	get_next_line(int fd, char **line)
{
	static char bk[1000000];//			= {0,};
	static int	is_end_read;
	static int	i;
	static int	cur;
	int			k;
	char 		buf[BUFFER_SIZE + 1]	= {0,};

	if (fd <=0 || fd > OPEN_MAX || !line)
		return (ERR);
	if (is_end_read != -1)
	{
		while (is_end_read != -1)
		{
			k = 0;
			if ((is_end_read = read(fd, buf, BUFFER_SIZE)) == 0)
			{
				is_end_read = -1;
				break;
			}
			while (k != is_end_read)
			{
				bk[i] = buf[k++];
				i++;
			}
		}
	}
	printf("\ni = %d\n", i);
	write(1, bk, i-1);

	//read --> until end (0)
	//get_line --> set line
	//set_next_line -->set 
	return (0);
}
int main ()
{
	char *line;
	int fd = open("test", O_RDWR);
	get_next_line(fd, &line);
	//printf("%s", line);
	close(fd);
	return (0);
}
