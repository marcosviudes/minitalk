/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:18:14 by mviudes           #+#    #+#             */
/*   Updated: 2021/08/07 15:46:21 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>

typedef struct s_data
{
	char	recived_char;
	int		num_bits;
}			t_data;

#endif
