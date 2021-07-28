/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:20:41 by mviudes           #+#    #+#             */
/*   Updated: 2021/07/24 17:21:32 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>
#include <minitalk.h>

typedef struct s_data
{
	char	recive_char;

}			t_data;

typedef t_data g_data;

int	str_error(char const *error)
{
	write(STDERR_FILENO, error, ft_strlen(error));
	write(STDERR_FILENO, "\n", 1);
	return (1);
}

void print_pid(void)
{
	ft_putstr_fd("Server PID : [", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("]\n", 1);
}

void handler(int signum)
{
	static int number;

/*	write(1, "HOLA BB ", ft_strlen("HOLA BB "));
	ft_putnbr_fd(signum, 1);
	ft_putnbr_fd(number, 1);
	write(1, "\n", 1);*/
	if(signum == SIGUSR2)
		write(1, "1", 1);
	else if (signum == SIGUSR1)
		write(1, "\n", 1);
	else
		write(1, "0", 1);
}
/*
char *decode_bin()
{

}*/

int main(int argc, char *argv[])
{
	(void)argv;

	if(argc != 1)
		return(str_error("This program don't recive arguments, try: ./server"));
	print_pid();
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while(42)
	{
		//ft_putstr_fd("\n", 1);
		pause();
	}
	return(0);
}
