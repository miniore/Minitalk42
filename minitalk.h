/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porellan <porellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:57:43 by porellan          #+#    #+#             */
/*   Updated: 2024/03/20 11:12:01 by porellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stddef.h>
# include "Libft/libft.h"
# include "Libft/Printf/ft_printf.h"


size_t	g_newstr_len;
//char	*g_str;
//char		*g_str;

size_t	global_function(void);
void	argument_handler(int pid, char *message);
void	signal_handler(int signum);

#endif