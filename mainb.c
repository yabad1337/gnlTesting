/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:41:35 by yabad             #+#    #+#             */
/*   Updated: 2022/10/29 11:41:16 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define PURP "\033[0;35m"

int	main(void)
{
	int	fd1;
	int	fd2;
	int	fd3;
	int	n;

	n = 7;
	fd1 = open("./files/file1.txt", O_RDONLY);
	fd2 = open("./files/file2.txt", O_RDONLY);
	fd3 = open("./files/file3.txt", O_RDONLY);
	while (n--)
	{
		printf("%s%s", GREEN, get_next_line(fd1));
		printf("%s%s", RED, get_next_line(fd2));
		printf("%s%s", PURP, get_next_line(fd3));
	}
	printf("\nfd1 = %d\n", fd1);
	printf("fd2 = %d\n", fd2);
	printf("fd3 = %d\n", fd3);
	close(fd1);
	close(fd2);
	close(fd3);
}
