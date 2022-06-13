/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_p_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:57:48 by schoe             #+#    #+#             */
/*   Updated: 2022/06/13 14:48:47 by schoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	swap_a(t_stack *a)
{
	int	temp;

	if (a == NULL || a->next == NULL)
		return (0);
	else
	{
		temp = a->val;
		a->val = a->next->val;
		a->next->val = temp;
	}
	return (0);
}

int	swap_b(t_stack *b)
{
	int	temp;

	if (b == NULL || b->next == NULL)
		return (0);
	else
	{
		temp = b->val;
		b->val = b->next->val;
		b->next->val = temp;
	}
	return (0);
}

void	swap_ab(t_stack *a, t_stack *b)
{
	swap_b(b);
	swap_a(a);
}

int	push_a(t_stack **a, t_stack **b)
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
	}
	return (0);
}

int	push_b(t_stack **a, t_stack **b)
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
	}
	return (0);
}
