/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mande-so <mande-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:16:38 by dosorio-          #+#    #+#             */
/*   Updated: 2025/11/05 18:35:41 by mande-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	free(*lst);
	*lst = NULL;
}

/* void libera(void *content)
{
	free(content);
}

#include <string.h>

int	main(void)
{
	t_list *lst = ft_lstnew(strdup("um"));
	ft_lstadd_back(&lst, ft_lstnew(strdup("dois")));
	ft_lstadd_back(&lst, ft_lstnew(strdup("três")));

	ft_lstclear(&lst, libera);
	return (0);
} */