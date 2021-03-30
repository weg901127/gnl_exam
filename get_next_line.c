//#define BUFFER_SIZE 1
#define ERR -1
#define DONE 1
#define END 0
#include <limits.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

char *ft_strchr(char *str, char c)
{
	while(*str != c && *str != '\0')
		str++;
	return (str);
}

void ft_memcpy(char *d, char *s, int count)
{
	while (count--)
		*d++ = *s++;
}

int	get_next_line(int fd, char **line)
{
	static char bk[1000000];//			= {0,};
	static int	is_end_read;
	static int	i;
	static int	cur;
	static char	*tmp;
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
		bk[i] = '\0';
		tmp = bk;
	}
	if (i > 0)
	{
		if (!*tmp)
			tmp++;
		cur = ft_strchr(tmp, '\n') - tmp;
		*(tmp + cur) = '\0';
		*line = (char *)malloc((cur + 1)*sizeof(char));
		line[cur] = 0;
		ft_memcpy(*line, tmp, cur + 1);
		//*line = *line - cur;
		tmp = tmp + cur;
		i = i-cur-1;
		return (DONE);
	}
	else
	{
		*line = 0;
		return (END);
	}
	//write(1, bk, i);

	//read --> until end (0)
	//get_line --> set line
	//set_next_line -->set 
	//return (0);
}
int main ()
{
	char *line;
	int fd = open("test", O_RDWR);

	while (line != 0)
	{
		get_next_line(fd, &line);
		printf("%s\n",line);
		//free(line);
	}
	//printf("%s", line);
	close(fd);
	return (0);
}
