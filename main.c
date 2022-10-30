/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:26:04 by yabad             #+#    #+#             */
/*   Updated: 2022/10/30 11:47:06 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define PURP "\033[0;35m"

int	main(void)
{
	int	fd;
	int	n;

	n = 9;
	fd = open("./files/file1.txt", O_RDONLY);
	while (n--)
		printf("%s%s", GREEN, get_next_line(fd));
	close(fd);
}
