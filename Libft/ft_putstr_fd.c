/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porellan <porellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:41:39 by porellan          #+#    #+#             */
/*   Updated: 2023/10/16 18:40:30 by porellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	x;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		x = s[i];
		write (fd, &x, 1);
		i++;
	}
}
