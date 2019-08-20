#include "get_next_line.h"

int		ft_output(char **hold, char **line)
{
	char *temp;
	char *newl;
	newl = ft_strchr(*hold, '\n');
	if(newl)
	{
		*newl = '\0';
		*line = ft_strdup(*hold);
		temp = ft_strdup(newl + 1);
		free(*hold);
		if(temp)
		{
			*hold = ft_strdup(temp);
			free(temp);
		}
	}
	else
	{
		*line = ft_strdup(*hold);
		free(*hold);
	}
	return(1);
}

int 	buff_read(int fd, char **stat)
{
	char temp[BUFF_SIZE + 1];
	char *store;
	size_t ret;
	if (*stat == NULL)
		*stat = ft_strnew(0);
	while ((ft_strchr(*stat, '\n') == NULL))
	{
		ret = read(fd, temp, BUFF_SIZE);
		if(ret <= 0)
			return(0);
		temp[ret] = '\0';
		store = ft_strjoin(*stat, temp);
		free(*stat);
		*stat = ft_strdup(temp);
	}
	return(1);


}

int		get_next_line(const int fd, char **line)
{
	static char *stat[MFD];
	int			ret;
	if(fd < 0 || fd > MFD || read(fd, NULL, 0 || !line))
		return(-1);
	ret = buff_read(fd, &stat[fd]);
	if(ret < 0)
		return(-1);
	if(ft_strlen(stat[fd]) == 0)
		return(0);
	return(ft_output(&stat[fd], line));
}
