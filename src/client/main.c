/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:18:52 by mviudes           #+#    #+#             */
/*   Updated: 2021/07/29 14:48:30 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>
#include <minitalk.h>

#define NUM_OF_ARGS 3

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
void send_stirng(pid_t pid, char *messege, size_t len)
{
	int		shift;
	int		i;
	int		j;
	
	i = 0;
	printf("%d, %s LEN:%i\n", pid, messege, (int)len);
	printf("messege[0]:%d\n", messege[0]);
	decimalToBinary((int)messege[0]);
	while(i < len)
	{

		j = 8;
		while(j--)
		{
			if((messege[i] >> j) & 1)
			{
				write(1, "1", 1);
				kill(pid, SIGUSR1);
			}
			else
			{
				write(1, "0", 1);
				kill(pid, SIGUSR2);
			}
			usleep(25);
		}
		i++;
	}
	write(1, "\n", 1);
}

int		main(int argc, char *argv[])
{
	pid_t pid;

	if(!checkargs(argc, argv))
		return(str_error("try: ./client [pid] [messege]\n"));
	pid = ft_atoi(argv[1]);
	printf("%d\n%s\n", pid, argv[2]);
	send_stirng(pid, argv[2], ft_strlen(argv[2]));
	return(0);
}
