/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 13:19:08 by schoe             #+#    #+#             */
/*   Updated: 2022/06/13 13:17:26 by schoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push	*ft_last_node(t_push *list)
{
	while (list->next != NULL)
		list = list->next;
	return (list);
}

void	ft_swap_val(t_push *a, t_push *b)
{
	int	temp;

	temp = a->val;
	a->val = b->val;
	b->val = temp;
}

t_push	*ft_part(t_push *start, t_push *end)
{
	int		piv;
	t_push	*right;
	t_push	*left;

	piv = start->val;
	left = start;
	right = end;
	while (left->index < right->index)
	{
		while (right->val > piv)
			right = right->rev;
		while (left->val <= piv && left->index < right->index)
			left = left->next;
		ft_swap_val(right, left);
	}
	start->val = left->val;
	left->val = piv;
	return (left);
}

int	ft_quick_sort(t_push *start, t_push *end)
{
	t_push	*last;

	if (start->index >= end->index)
		return (0);
	last = ft_part(start, end);
	if (last -> rev != NULL)
		ft_quick_sort(start, last->rev);
	if (last -> next != NULL)
		ft_quick_sort(last->next, end);
	return (0);
}
