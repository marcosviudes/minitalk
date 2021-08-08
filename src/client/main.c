/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:18:52 by mviudes           #+#    #+#             */
/*   Updated: 2021/08/08 19:47:52 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>
#include <minitalk.h>
#include <limits.h>

#define NUM_OF_ARGS 3

int	str_error(char const *error)
{
	write(STDERR_FILENO, error, ft_strlen(error));
	return (-1);
}

int	checkargs(int argc, char **argv)
{
	long	num;

	if (argc != NUM_OF_ARGS)
		return (0);
	if (!ft_isnum(argv[1]))
		return (0);
	num = ft_absatol(argv[1]);
	if (num > INT32_MAX || num < INT_MIN || num == ABSTOL_ERROR)
		return (0);
	return (1);
}

void	send_stirng(pid_t pid, char *messege, size_t len)
{
	size_t		i;
	int			j;

	i = 0;
	while (i < len + 1)
	{
		j = 0;
		while (j < 9)
		{
			if ((messege[i] >> j) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(200);
			j++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;

	if (!checkargs(argc, argv))
		return (str_error("try: ./client [pid] [messege]\n"));
	pid = ft_atoi(argv[1]);
	send_stirng(pid, argv[2], ft_strlen(argv[2]));
	return (0);
}
