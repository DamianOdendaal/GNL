int		ft_output(char **hold, char **line)
{
	char *temp;
	char *newl;
	newl = ft_strchr(*hold, '\n')

	if(newl)
	{
		*(ft_strchr(*hold, '\n')) = '\0'; // this is so that we treat what ever we have found as a string 
		*line = ft_strdup(*hold);
		temp = ft_strdup(ft_strchr(*hold, '\0') + 1);
		free(*hold);
		if(temp) // remember this is is what is after the newl char so we dont lose anything
		// when we here we store what we have in hold 
		//NB if you use something like strdup or anything that allocs mem then free
	}
	else
	// this is the case that we need to cater for if we dont find the newl char 
	return(1);// meaning unsuc end 
}

int 	buff_read(int fd, char *stat)
{
	while i havent found a newline
		do the same thing Jenelle and i did 
}

int		get_next_line(const int fd, char **line)
{
	do stuff here
}
