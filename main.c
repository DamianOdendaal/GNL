#include "get_next_line.h"
#include <fcntl.h>

#include <stdio.h>

int main(int ac, char **av)
{
    char *line;
    int fd;
    
    /*if(ac == 1)
        return(0);*/
    if(ac == 2)
        fd = open(av[1], O_RDONLY);
    while(get_next_line(fd, &line) > 0)
    {
        ft_putendl(line);
        free(line);
    }
    /*if(ac == 2)*/
        close(fd);
}