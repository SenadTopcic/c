/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopcic <stopcic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:41:23 by stopcic           #+#    #+#             */
/*   Updated: 2023/04/05 21:55:36 by stopcic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
/*read the buffer, add it and return it like a updated variable*/

static char	*read_and_update(int fd, char *buffer, char *remember_me)
{
	int		rff;
	char	*tmp;

	rff = 1;
	while (rff > 0)
	{
		rff = read(fd, buffer, BUFFER_SIZE);
		if (rff < 0)
			return (0);
		else if (rff == 0)
			break ;
		buffer[rff] = '\0';
		if (!remember_me)
			remember_me = ft_strdup("");
		tmp = remember_me;
		remember_me = ft_strjoin(tmp, buffer);
		free(tmp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (remember_me);
}

static char	*take_the_rest(char *line)
{
	char	*container;
	size_t	count;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] != '\n' || line[count + 1] == '\0')
		return (0);
	container = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (*container == '\0')
	{
		free(container);
		return (NULL);
	}
	line[count + 1] = '\0';
	return (container);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*remember_me[1024];

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 1024)
		return (NULL);
	else if (read(fd, 0, 0) < 0)
	{
		free(remember_me[fd]);
		remember_me[fd] = NULL;
		return (NULL);
	}
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = read_and_update(fd, buffer, remember_me[fd]);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	remember_me[fd] = take_the_rest(line);
	return (line);
}
/*
#include <stdio.h>
#include <fcntl.h>
int    main(void)
{
    int        fd;
    char    *line;

    fd = open("read.txt", O_RDONLY);
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break ;
        printf("%s", line);
        free(line);
    }
    printf("BUFFER_SIZE IS %d\n", BUFFER_SIZE);
    return (0);
}
*/
/*
int main()
{
	int fd;
	fd = open("readme.txt", O_RDONLY);
	printf("<%s>", get_next_line(fd));
	printf("<%s>", get_next_line(fd));
	printf("<%s>", get_next_line(fd));
	//printf("|%s\n", get_next_line(fd));
	//printf("|%s\n", get_next_line(fd));
	//printf("%s\n", get_next_line(fd));
	//printf("%s\n", get_next_line(fd));
	//printf("%s\n", get_next_line(fd));
	//printf("%s\n", get_next_line(fd));
	//printf("%s\n", get_next_line(fd));
	//printf("%s\n", get_next_line(fd));
	close(fd);
}*/
/*
int        main(int argc, char **argv)
{
    int    fd;
    int i;

    i = 0;
    if (argc == 3)
    {
        fd = open(argv[1], O_RDWR | O_CREAT);
	if ( fd == -1)
	{
		printf("open() error");
		return (1);
	}
        i = atoi(argv[2]);
        while (i--)
            printf("main /%s/\n", get_next_line(fd));
    }
    return (1);
}*/
