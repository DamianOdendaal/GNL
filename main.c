#include "get_next_line.h"
#include <fcntl.h>

int main(int ac, char **av)
{
    char *line;
    int fd;
    
    fd = 0;
    if(ac == 2)
        fd = open(av[1], O_RDONLY);
    while(get_next_line(fd, &line) > 0)
    {
        ft_putendl(line);
        ft_strdel(&line);
    }
    char    *str;
        close(fd);
}

// static void test01(t_test *test)
// {
//     test->timeout = 1;

//     char *line;
//     int fd;
//     int fd2;
//     int fd3;
//     int diff_file_size;

//     system("mkdir -p sandbox");
//     system("openssl rand -base64 $((30 * 1000 * 3/4)) | tr -d '\n' | tr -d '\r' > sandbox/one_big_fat_line.txt");
//     system("echo '\n' >> sandbox/one_big_fat_line.txt");

//     fd = open("sandbox/one_big_fat_line.txt", O_RDONLY);
//     fd2 = open("sandbox/one_big_fat_line.txt.mine", O_CREAT | O_RDWR | O_TRUNC, 0755);

//     while (get_next_line(fd, &line) == 1)
//     {
//         write(fd2, line, strlen(line));
//         write(fd2, "\n", 1);
//     }
//     if (line)
//         write(fd2, line, strlen(line));
//     close(fd);
//     close(fd2);

//     system("diff sandbox/one_big_fat_line.txt sandbox/one_big_fat_line.txt.mine > sandbox/one_big_fat_line.diff");
//     fd3 = open("sandbox/one_big_fat_line.diff", O_RDONLY);
//     diff_file_size = read(fd3, NULL, 10);
//     close(fd3);

//     mt_assert(diff_file_size == 0);
// }