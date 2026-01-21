/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mande-so <mande-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:40:23 by dosorio-          #+#    #+#             */
/*   Updated: 2025/11/05 18:09:51 by mande-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/* void	libera(void *content)
{
	free(content);
}

#include <string.h>

int main(void)
{
	t_list *n = ft_lstnew(strdup("Olá"));
	ft_lstdelone(n, libera);
	return (0);
} */