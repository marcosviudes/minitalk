/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:18:52 by mviudes           #+#    #+#             */
/*   Updated: 2021/07/24 17:36:17 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>
#include <minitalk.h>

#define NUM_OF_ARGS 3

int	str_error(char const *error)
{
	write(STDERR_FILENO, error, ft_strlen(error));
	return (-1);
}

int	checkargs(int argc, char **argv)
{
	if(argc != NUM_OF_ARGS)
		return(0);
	if(!ft_isnum(argv[1]))
		return(0);
	return(1);
}
void send_stirng(int pid, char *messege, size_t len)
{
	int		shift;
	int		i;

	while(i < len)
	{
		shift = 0;
		while (shift < 7)
		{
			if ((messege[i] >> shift) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			shift++;
			usleep(100);
		}
		i++;
	}
}

int		main(int argc, char *argv[])
{
	int pid;

	if(!checkargs(argc, argv))
		return(str_error("try: ./client [pid] [messege]\n"));
	pid = ft_atoi(argv[1]);
	printf("%d\n%s\n", pid, argv[2]);
	send_stirng(pid, argv[2], ft_strlen(argv[2]));
	return(0);
}
