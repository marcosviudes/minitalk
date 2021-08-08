/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:17:45 by mviudes           #+#    #+#             */
/*   Updated: 2021/08/07 16:08:23 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>

# define ABSTOL_ERROR	-1

long	ft_absatol(const char *string);
#endif
