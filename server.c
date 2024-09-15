/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniore <miniore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:57:43 by porellan          #+#    #+#             */
/*   Updated: 2024/09/13 14:04:12 by miniore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"	

// char	*ft_charjoin(char const *s1, char const s2)
// {
// 	char	*new_str;
// 	size_t	new_str_len;
// 	int		i;

// 	if (!s1 || !s2)
// 		return (0);
// 	new_str_len = ft_strlen(s1) + 1;
// 	new_str = ft_calloc(new_str_len + 1, 1);
// 	i = 0;
// 	if (new_str == NULL)
// 		return (0);
// 	while (s1[i] != '\0')
// 	{
// 		new_str[i] = s1[i];
// 		i++;
// 	}
// 	new_str[i] = s2;
// 	return (new_str);
// }

void	signal_handler(int signum)
{
	static unsigned long		char_counter;
	static int					i;
	static char					s;
	static int					null_counter;
	char						*str;
	//size_t	g_newstr_len = 20;

	//ft_printf("ENTRA\n");
	//g_newstr_len = (size_t)signum;
	//printf("Valor global: %zu\n", g_newstr_len);
	//printf("%d,\n", signum);
	if (char_counter == 0)
		str = (char *)ft_calloc(100 + 1, sizeof(char));
	if (!str)
		return ;
	//ft_printf("%s\n", str);
	if (SIGUSR1 == signum)
		s |= (1 << i);
	if (SIGUSR2 == signum)
		null_counter++;
	//ft_printf("%d\n", null_counter);
	i++;
	if (i == 8 && null_counter != 8)
	{
		//printf("	ENTRA\n");
		str[char_counter] = s;
		//printf("character: %c\n", s);
		//ft_printf("%d\n", null_counter);
		//ft_printf("	ENTRA\n");
		i = 0;
		s = 0;
		null_counter = 0;
		char_counter++;
	}
	//if (char_counter != 0 && str[char_counter - 1] != '\0' && i == 1)
	if (null_counter == 8)
	{
		ft_printf("%s\n", str);
		i = 0;
		s = 0;
		char_counter = 0;
		null_counter = 0;
		free(str);
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("Process ID: %i\n", pid);
	while (1)
	{
		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);
	}
	return (0);
}
