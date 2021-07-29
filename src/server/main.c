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
    long binarynum = 0;
    int rem, temp = 1;

    while (decimalnum!=0)
    {
        rem = decimalnum%2;
        decimalnum = decimalnum / 2;
        binarynum = binarynum + rem*temp;
        temp = temp * 10;
    }
    printf("binary: %li\n", binarynum);
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
	if(data.num_bits == 7)
	{
		decimalToBinary((int)data.num_bits);
		ft_putchar_fd(data.recived_char, 1);
		data.num_bits = 0;
		return;
	}
//	if(signum == SIGUSR1)
		data.recived_char += (1 << data.num_bits);
//		data.recived_char |= 1 << data.num_bits;
/*	else if (signum == SIGUSR2)
		data.recived_char |= 0 << data.num_bits;*/
	printf("%d\n", data.num_bits);
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
