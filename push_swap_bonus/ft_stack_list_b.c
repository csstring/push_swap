/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:56:10 by schoe             #+#    #+#             */
/*   Updated: 2022/06/13 14:35:36 by schoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "libft.h"

void	ft_stackadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	if (*lst == NULL)
		*lst = new;
	else
	{
		temp = *lst;
		while (temp -> next != NULL)
			temp = temp -> next;
		temp -> next = new;
	}
}

t_stack	*ft_stacknew(int val)
{
	t_stack	*temp;

	temp = (t_stack *)malloc(sizeof(t_stack));
	if (temp == NULL)
		return (NULL);
	temp->val = val;
	temp->a_count = 0;
	temp->b_count = 0;
	temp->sum = 0;
	temp->next = NULL;
	return (temp);
}

void	get_stack_val(char **av, t_stack **a, t_push *sort_list)
{
	int		i;
	t_push	*temp;

	temp = sort_list;
	*a = NULL;
	i = 1;
	while (av[i])
	{
		sort_list = temp;
		while (sort_list != NULL && sort_list->val != ft_atoi(av[i]))
			sort_list = sort_list->next;
		ft_stackadd_back(a, ft_stacknew(sort_list->index));
		i++;
	}
	while (temp != NULL)
	{
		temp->val = temp->index;
		temp = temp ->next;
	}
}
