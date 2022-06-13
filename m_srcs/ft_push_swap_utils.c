/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 11:54:03 by schoe             #+#    #+#             */
/*   Updated: 2022/06/13 13:25:31 by schoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rot_stack2(t_cmd **cmd, t_stack **a, t_stack **b, t_stack *temp)
{
	while (temp->b_count < 0)
	{
		rrot_b(cmd, b);
		temp->b_count += 1;
	}
	while (temp->b_count > 0)
	{
		rot_b(cmd, b);
		temp->b_count -= 1;
	}
	while (temp->a_count < 0)
	{
		rrot_a(cmd, a);
		temp->a_count += 1;
	}
	while (temp->a_count > 0)
	{
		rot_a(cmd, a);
		temp->a_count -= 1;
	}
}

void	ft_rot_stack(t_cmd **cmd, t_stack **a, t_stack **b)
{
	t_stack	*temp;

	temp = find_min_count(*b);
	while (temp->a_count > 0 && temp->b_count > 0)
	{
		rot_ab(cmd, a, b);
		temp->a_count -= 1;
		temp->b_count -= 1;
	}
	while (temp->a_count < 0 && temp->b_count < 0)
	{
		rrot_ab(cmd, a, b);
		temp->a_count += 1;
		temp->b_count += 1;
	}
	ft_rot_stack2(cmd, a, b, temp);
}

t_stack	*find_min_count(t_stack *b)
{
	int		min;
	int		temp;
	t_stack	*stack_temp;

	min = b->sum;
	stack_temp = b;
	while (b != NULL)
	{
		temp = b->sum;
		if (min > temp)
		{
			stack_temp = b;
			min = temp;
		}
		b = b->next;
	}
	return (stack_temp);
}

int	ft_max_min_check(t_stack *a, int b_val)
{
	int	min;
	int	max;
	int	temp;

	min = a->val;
	max = a->val;
	while (a != NULL)
	{
		temp = a->val;
		if (temp < min)
			min = temp;
		else if (temp > max)
			max = temp;
		a = a->next;
	}
	if (b_val < min || b_val > max)
		return (min);
	else
		return (-1);
}
