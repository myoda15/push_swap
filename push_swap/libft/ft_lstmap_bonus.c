/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mande-so <mande-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:37:48 by mande-so          #+#    #+#             */
/*   Updated: 2025/11/05 18:37:51 by mande-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newnode;
	t_list	*newlst;
	void	*newcontent;

	if (!lst || !f || !del)
		return (NULL);
	newlst = NULL;
	while (lst != NULL)
	{
		newcontent = f(lst->content);
		newnode = ft_lstnew(newcontent);
		if (!newnode)
		{
			del(newcontent);
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, newnode);
		lst = lst->next;
	}
	return (newlst);
}

/* #include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	*duplica_de_verdade(void *content)
{
	char	*str;
	size_t	len;
	char	*copy;

	str = (char *)content;
	len = strlen(str);
	copy = malloc(2 * len + 1);
	if (copy)
	{
		strcpy(copy, str);
		strcat(copy, str);
	}
	return (copy);
}

void	libera(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*original;
	t_list	*nova;
	t_list	*tmp;

	original = ft_lstnew(strdup("Olá"));
	ft_lstadd_back(&original, ft_lstnew(strdup("Mundo")));
	ft_lstadd_back(&original, ft_lstnew(strdup("!")));
	nova = ft_lstmap(original, duplica_de_verdade, libera);
	tmp = nova;
	while (tmp != NULL)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
	ft_lstclear(&nova, libera);
	ft_lstclear(&original, libera);
	return (0);
}
 */