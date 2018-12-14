/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:55:20 by bleveque          #+#    #+#             */
/*   Updated: 2018/12/12 17:49:12 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	get_next_line();

int	main(int argc, char **argv)
{
	int 	fd3;
	int		fd4;
	int		fd5;
	int		i;
	char	*line;
	int ret;

	fd3 = open(argv[1], O_RDONLY);
	fd4 = open(argv[2], O_RDONLY);
	fd5 = open(argv[3], O_RDONLY);
	//fd0 = open(argv[2], O_RDWR);
	i = 0;
/*	if (argc == 3)
	{	while ((ret = get_next_line(fd3, &line)) == 1)
		{
			write(fd0, line, strlen(line));
			write(fd0, "\n", 1);
		}
	}*/
	if (argc == 2)
	{
		while ((ret = get_next_line(fd3, &line)) == 1)
		{
			printf("-------> Ligne %d : %s <-------\n", i, line);
			i++;
			free(line);
		}
	}
	else 
	{
		while (i < 3)
		{
			get_next_line(fd3, &line);
			printf("------------> Ligne de fd %d : %s <----------------\n\n", fd3, line);
			free(line);
			get_next_line(fd4, &line);
			printf("-------------> Ligne de fd %d : %s <----------------\n\n", fd4, line);
			free(line);
			get_next_line(fd5, &line);
			printf("--------------> Ligne de fd %d : %s <----------------\n\n", fd5, line);
			free(line);
			printf("\n----------------------\n\n");
			i++;
		}
	}
	return (0);
}
