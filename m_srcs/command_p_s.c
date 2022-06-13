/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_p_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:57:48 by schoe             #+#    #+#             */
/*   Updated: 2022/06/13 19:57:45 by schoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_a(t_cmd **cmd, t_stack *a)
{
	int	temp;

	if (a == NULL || a->next == NULL)
		return (0);
	else
	{
		temp = a->val;
		a->val = a->next->val;
		a->next->val = temp;
		ft_cmd_node(cmd, "sa\n");
	}
	return (0);
}

int	swap_b(t_cmd **cmd, t_stack *b)
{
	int	temp;

	if (b == NULL || b->next == NULL)
		return (0);
	else
	{
		temp = b->val;
		b->val = b->next->val;
		b->next->val = temp;
		ft_cmd_node(cmd, "sb\n");
	}
	return (0);
}

void	swap_ab(t_cmd **cmd, t_stack *a, t_stack *b)
{
	swap_b(cmd, b);
	swap_a(cmd, a);
	ft_2node_clear(cmd, "ss\n");
}

int	push_a(t_cmd **cmd, t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (*b == NULL)
		return (0);
	else
	{
		temp = *b;
		*b = temp->next;
		temp->next = *a;
		*a = temp;
		ft_cmd_node(cmd, "pa\n");
	}
	return (0);
}

int	push_b(t_cmd **cmd, t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (*a == NULL)
		return (0);
	else
	{
		temp = *a;
		*a = temp->next;
		temp->next = *b;
		*b = temp;
		ft_cmd_node(cmd, "pb\n");
	}
	return (0);
}
