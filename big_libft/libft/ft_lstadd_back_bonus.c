/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:23:07 by tdausque          #+#    #+#             */
/*   Updated: 2024/10/23 13:27:52 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list		*tmp;

	if (!lst && !new)
		return ;
	if (lst && new)
	{
		tmp = ft_lstlast(*lst);
		tmp -> next = new;
	}
}
