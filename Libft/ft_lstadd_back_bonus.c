/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniore <miniore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:06:21 by porellan          #+#    #+#             */
/*   Updated: 2024/08/29 18:09:12 by miniore          ###   ########.fr       */
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
		while (actual -> next != NULL)
			actual = actual -> next;
		actual -> next = new;
	}
}
