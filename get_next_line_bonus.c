/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 22:35:53 by yabad             #+#    #+#             */
/*   Updated: 2022/10/28 18:20:41 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*cleaner(char *container)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (container[i] && container[i] != '\n')
		i++;
	if (!container[i] || (container[i] == '\n' && !container[i + 1]))
		return (NULL);
	ret = (char *)malloc(ft_strlen(container) - i);
	if (!ret)
		return (NULL);
	while (container[++i])
	{
		ret[j] = container[i];
		j++;
	}
	ret[j] = '\0';
	return (ret);
}

char	*first_line(char *container)
{
	char	*line;
	int		i;

	i = 0;
	while (container[i] && container[i] != '\n')
		i++;
	line = (char *)malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (container[i] && container[i] != '\n')
	{
		line[i] = container[i];
		i++;
	}
	if (container[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*read_from_file(int fd, char *container, int *rd)
{
	char	buff[BUFFER_SIZE + 1];
	char	*tmp;

	while (1)
	{
		*rd = read(fd, buff, BUFFER_SIZE);
		if (*rd <= 0)
			break ;
		buff[*rd] = '\0';
		tmp = container;
		container = ft_strjoin(tmp, buff);
		free(tmp);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (container);
}

char	*get_next_line(int fd)
{
	static char	*container[OPEN_MAX];
	char		*line;
	char		*tmp;
	int			rd;

	container[fd] = read_from_file(fd, container[fd], &rd);
	if (!container[fd] || (rd == 0 && container[fd][0] == '\0'))
		return (NULL);
	tmp = container[fd];
	line = first_line(tmp);
	container[fd] = cleaner(tmp);
	free(tmp);
	return (line);
}
