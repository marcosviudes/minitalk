/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:20:41 by mviudes           #+#    #+#             */
/*   Updated: 2021/08/08 19:48:15 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>
#include <minitalk.h>

t_data	g_data;

int	str_error(char const *error)
{
	write(STDERR_FILENO, error, ft_strlen(error));
	write(STDERR_FILENO, "\n", 1);
	return (1);
}

void	print_pid(void)
{
	ft_putstr_fd("Server PID : [", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("]\n", 1);
}

void	handler(int signum)
{
	if (g_data.num_bits == 8)
	{
		write(1, &g_data.recived_char, 1);
		if (g_data.recived_char == '\0')
			write(1, "\n", 1);
		g_data.num_bits = 0;
		g_data.recived_char = 0;
		return ;
	}
	if (signum == SIGUSR1)
		g_data.recived_char |= (1 << g_data.num_bits);
	if (signum == SIGUSR2)
		g_data.recived_char |= (0 << g_data.num_bits);
	g_data.num_bits++;
}

int	main(int argc, char *argv[])
{
	(void)argv;
	g_data.num_bits = 0;
	g_data.recived_char = 0;
	if (argc != 1)
		return (str_error("Try: ./server"));
	print_pid();
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (42)
		pause();
	return (0);
}
