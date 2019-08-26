#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>





static void simple_string()
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;
	int		gnl_ret;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "abc\n\n", 5);
	close(p[1]);
	dup2(out, fd);

	/* Read abc and new line */
	gnl_ret = get_next_line(p[0], &line);

	/* Read new line */
	gnl_ret = get_next_line(p[0], &line);

	/* Read again, but meet EOF */
	gnl_ret = get_next_line(p[0], &line);

	/* Let's do it once again */
	gnl_ret = get_next_line(p[0], &line);
}

int main()
{
    simple_string();
    return (0);
}


// int main(int ac, char **av)
// {
//     char *line;
//     int fd;
    
//     fd = 0;
//     if(ac == 2)
//         fd = open(av[1], O_RDONLY);
//     while(get_next_line(fd, &line) > 0)
//     {
//         ft_putendl(line);
//         ft_strdel(&line);
//     }
//         sleep(60);
//         close(fd);
// }

// #include <string.h>
// #include <strings.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <ctype.h>
// #include <math.h>

// #include <fcntl.h>
// #include <regex.h>
// #include <assert.h>

//  static void test01()
// {
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
//         ft_putnbr(sizeof(line));
//         ft_putendl("");
//         ft_putendl((!line) ? "NO" : "YES");
//         write(fd2, line, strlen(line));
//         write(fd2, "\n", 1);
//     }
//      if (line)
//          write(fd2, line, strlen(line));
//     close(fd);
//     close(fd2);

//      system("diff sandbox/one_big_fat_line.txt sandbox/one_big_fat_line.txt.mine > sandbox/one_big_fat_line.diff");
//      fd3 = open("sandbox/one_big_fat_line.diff", O_RDONLY);
//      diff_file_size = read(fd3, NULL, 10);
//      close(fd3);
// }

// int main(void)
// {
//     test01();
//     return 0;
// }
