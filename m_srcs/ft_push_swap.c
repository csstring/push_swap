/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 11:53:49 by schoe             #+#    #+#             */
/*   Updated: 2022/06/13 12:19:43 by schoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	ft_b_short(t_stack *b)
{
	int		all;
	int		i;
	t_stack	*temp;

	all = 0;
	i = 0;
	temp = b;
	while (b != NULL)
	{
		b = b->next;
		all++;
	}
	while (temp != NULL)
	{
		if (all / 2 < i)
			temp -> b_count = i - all;
		else
			temp -> b_count = i;
		temp = temp -> next;
		i++;
	}
}

int	ft_find_target(t_stack *a, int b_val)
{
	int	min;
	int	temp;

	min = ft_max_min_check(a, b_val);
	if (min >= 0)
		return (min);
	temp = a->val;
	while (a ->next != NULL)
	{
		if (b_val > a->val && b_val < a->next->val)
			return (a->next->val);
		a = a ->next;
	}
	if (temp < a->val)
		return (a->val);
	else
		return (temp);
}

int	ft_a_short(t_stack *a, int target)
{
	int		all;
	int		i;
	t_stack	*temp;

	all = 0;
	i = 0;
	temp = a;
	while (a != NULL)
	{
		a = a->next;
		all++;
	}
	while (temp != NULL)
	{
		if (temp -> val == target)
		{
			if (all / 2 < i)
				return (i - all);
			else
				return (i);
		}
		temp = temp -> next;
		i++;
	}
	return (0);
}

void	ft_sort_stack(t_cmd **cmd, t_stack **a, t_stack **b)
{
	t_stack	*temp;
	int		target;

	temp = *b;
	ft_b_short(temp);
	while (temp != NULL)
	{
		target = ft_find_target(*a, temp->val);
		temp -> a_count = ft_a_short(*a, target);
		if ((temp->a_count < 0 && temp->b_count < 0) || \
				(temp->a_count > 0 && temp->b_count > 0))
		{
			if (ft_abs(temp->a_count) > ft_abs(temp->b_count))
				temp -> sum = ft_abs(temp->a_count);
			else
				temp -> sum = ft_abs(temp->b_count);
		}
		else
			temp -> sum = ft_abs(temp->a_count) + ft_abs(temp->b_count);
		temp = temp -> next;
	}
	ft_rot_stack(cmd, a, b);
	push_a(cmd, a, b);
}

void	ft_push_swap(t_cmd **cmd, t_stack **a, t_stack **b, t_push **sort_list)
{
	int	rot_val;

	if (*b == NULL)
	{
		ft_div(cmd, a, b, sort_list);
		if (*a == NULL)
			push_a(cmd, a, b);
	}
	while (*b != NULL)
		ft_sort_stack(cmd, a, b);
	rot_val = ft_a_short(*a, 0);
	if (rot_val < 0)
		while ((*a)->val != 0)
			rrot_a(cmd, a);
	else
		while ((*a)->val != 0)
			rot_a(cmd, a);
	ft_print_cmd(cmd);
}
