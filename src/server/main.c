/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:20:41 by mviudes           #+#    #+#             */
/*   Updated: 2021/07/29 14:46:46 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>
#include <minitalk.h>

void decimalToBinary(int decimalnum)
{
	for (int i = 0; i < 8; i++) {
      printf("%d", !!((decimalnum << i) & 0x80));
  }
  printf("\n");
}

typedef struct s_data
{
	char	recived_char;
	int		num_bits;
}			t_data;

typedef t_data g_data;
g_data	data;

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

//		data.recived_char += (1 << data.num_bits);
//		data.recived_char |= 1 << (data.num_bits + 1);
/*	else if (signum == SIGUSR2)
		data.recived_char |= 0 << data.num_bits;*/
	//printf("%d\t", data.num_bits);
	///decimalToBinary((int)data.recived_char);
//	data.num_bits++;
	if(data.num_bits == 7)
	{
		ft_putchar_fd(data.recived_char, 1);
		//write(1, "\t", 1);
		if(data.recived_char == '\0')
			write(1, "\n", 1);
		data.num_bits = 0;
		data.recived_char = 0;
	//	decimalToBinary(data.recived_char);
		return;
	}
	if(signum == SIGUSR1)
		data.recived_char |= (1 << data.num_bits);
	data.num_bits++;
}
/*
char *decode_bin()
{

}*/
g_data	data;

int main(int argc, char *argv[])
{
	(void)argv;

	data.num_bits = 0;
	data.recived_char = 0;
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
