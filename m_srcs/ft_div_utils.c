/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:10:29 by schoe             #+#    #+#             */
/*   Updated: 2022/06/13 12:13:44 by schoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_cw(t_cmd **cmd, t_stack **a, t_stack **b, int max)
{
	while ((*a)->val > max)
	{
		if (*b != NULL && (*b)->next != NULL && ((*b)->val < (*b)->next->val))
			rot_ab(cmd, a, b);
		else
			rot_a(cmd, a);
	}
	push_b(cmd, a, b);
}

void	ft_ccw(t_cmd **cmd, t_stack **a, t_stack **b, int max)
{
	t_stack	*temp;

	temp = *b;
	while (*b != NULL && temp->next != NULL)
		temp = temp->next;
	while ((*a)->val > max)
	{
		if (*b != NULL && (*b)->next != NULL && ((*b)->val < temp->val))
			rrot_ab(cmd, a, b);
		else
			rrot_a(cmd, a);
	}
	push_b(cmd, a, b);
}
