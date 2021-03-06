/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absatol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 16:00:25 by mviudes           #+#    #+#             */
/*   Updated: 2021/08/07 16:08:41 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>
#define MAX_ABSTOL_LEN	20

static size_t	absatol_len(char *string)
{
	size_t	i;

	i = 0;
	while (string[i])
		i++;
	return (i);
}

static int	is_abs_num(const char *number)
{
	int		i;

	i = 0;
	while (number[i])
	{
		if (number[i] > '9' || number[i] < '0')
			return (0);
		i++;
	}
	return (1);
}

/*  function return a long acording with the parsed string
**  if string is NULL or less than 0, return an error
*/
long	ft_absatol(const char *string)
{
	char	*ptr;
	long	ret;

	ptr = (char *)string;
	ret = 0;
	if (!string)
		return (ABSTOL_ERROR);
	while (*ptr == ' ' || *ptr == '0')
		ptr++;
	if (absatol_len(ptr) > MAX_ABSTOL_LEN || !is_abs_num(ptr))
		return (ABSTOL_ERROR);
	while (*ptr)
		ret = ret * 10 + (*ptr++ - '0');
	return (ret);
}
