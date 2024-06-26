/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porellan <porellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:06:21 by porellan          #+#    #+#             */
/*   Updated: 2023/10/11 17:01:51 by porellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*actual;

	actual = *lst;
	if (!actual)
		*lst = new;
	else
	{
		while (actual -> next != '\0')
			actual = actual -> next;
		actual -> next = new;
	}
}
