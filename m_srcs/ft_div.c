/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 21:02:51 by schoe             #+#    #+#             */
/*   Updated: 2022/06/13 12:13:55 by schoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_fix_way(int i, int r_temp, int rr_temp)
{
	if (r_temp == rr_temp)
	{
		if (r_temp == -1)
			return (2);
		else if (r_temp < i / 2)
			return (1);
		else
			return (0);
	}
	else if (r_temp < i - rr_temp)
		return (1);
	else
		return (0);
}

int	ft_short_rot(t_stack *c, int min, int max)
{
	int	i;
	int	r_temp;
	int	rr_temp;

	i = 0;
	r_temp = -1;
	rr_temp = -1;
	while (c != NULL)
	{
		if (c->val >= min && c->val <= max)
			rr_temp = i;
		if (r_temp == -1 && (c->val >= min && c->val <= max))
			r_temp = i;
		c = c->next;
		i++;
	}
	return (ft_fix_way(i, r_temp, rr_temp));
}

void	ft_quick_rot(t_cmd **cmd, t_stack **a, t_stack **b, t_push *sort_list)
{
	int			i;
	static int	min;
	static int	max;

	if (max != 0)
	{
		min = sort_list->piv1;
		max = sort_list->piv2;
	}
	else
		max = sort_list->piv1;
	while (1)
	{
		i = ft_short_rot(*a, min, max);
		if (i == 1)
			ft_cw(cmd, a, b, max);
		else if (i == 0)
			ft_ccw(cmd, a, b, max);
		else
			break ;
	}
}

void	ft_div(t_cmd **cmd, t_stack **a, t_stack **b, t_push **sort_list)
{
	t_push	*temp;

	temp = *sort_list;
	while (temp->next != NULL)
		temp = temp -> next;
	if (temp -> index > 99)
	{
		(*sort_list)->piv1 = temp -> index / 3;
		(*sort_list)->piv2 = temp -> index / 3 * 2;
		ft_quick_rot(cmd, a, b, *sort_list);
		ft_quick_rot(cmd, a, b, *sort_list);
	}
	while (*a != NULL)
		push_b(cmd, a, b);
}
