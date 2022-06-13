/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_av.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 13:16:42 by schoe             #+#    #+#             */
/*   Updated: 2022/06/13 13:17:16 by schoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_push	*ft_avnew(int val, int index)
{
	t_push	*temp;

	temp = (t_push *)malloc(sizeof(t_push));
	if (temp == NULL)
		return (NULL);
	temp->val = val;
	temp->index = index;
	temp->next = NULL;
	temp->rev = NULL;
	return (temp);
}

void	ft_avadd_back(t_push **lst, t_push *new)
{
	t_push	*temp;

	if (*lst == NULL)
		*lst = new;
	else
	{
		temp = *lst;
		while (temp -> next != NULL)
			temp = temp -> next;
		temp -> next = new;
		new -> rev = temp;
	}
}

void	ft_get_av(char **av, t_push **sort_list)
{
	int	i;

	*sort_list = NULL;
	i = 1;
	while (av[i])
	{
		ft_avadd_back(sort_list, ft_avnew(ft_atoi(av[i]), i - 1));
		i++;
	}
}
