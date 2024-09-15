/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniore <miniore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:57:43 by porellan          #+#    #+#             */
/*   Updated: 2024/09/01 18:16:40 by miniore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	argument_handler(int pid, char *message)
{
	int	i;
	int	j;

	i = 0;
	while (message[i] != '\0')
	{
		j = 0;
		while (j < 8)
		{
			if (message[i] & (1 << j))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j++;
			usleep(3000);
		}
		i++;
	}
	while(j != 0)
	{
		kill(pid, SIGUSR2);
		j--;
		usleep(3000);
	}
	//ft_printf("%d\n", j);
	// if (message[i] & (1 << j))
	// 	kill(pid, SIGUSR1);
	// else
	// 	kill(pid, SIGUSR2);
}

// size_t	global_function(void)
// {
// 	return (g_newstr_len);
// }

int	main(int argc, char *argv[])
{
	if (argc != 3)
		ft_printf("%s\n", "Formato no válido.");
	//g_newstr_len = ft_strlen(argv[2]);
	//ft_printf("en main: %d", g_newstr_len);
	if (argc == 3)
		argument_handler(ft_atoi(argv[1]), argv[2]);
	return (0);
}
