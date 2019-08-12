int main(int ac, char **av)
{
    char *line;
    int fd;

    fd = Open(fd, O_Rdonly);
    if(ac == 1)
        return(-1);
    while(get_next_line(fd, &line))
    {
        
    }
    if(ac == 2)
        close(fd);
    return()
}