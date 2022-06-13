/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:59:12 by schoe             #+#    #+#             */
/*   Updated: 2022/06/13 14:49:02 by schoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	rot_a(t_stack **a)
{
	t_stack	*temp;
	t_stack	*find;

	find = *a;
	if (find == NULL || find->next == NULL)
		return (0);
	else
	{
		temp = *a;
		*a = temp->next;
		while (find -> next != NULL)
			find = find->next;
		find -> next = temp;
		temp->next = NULL;
	}
	return (0);
}

int	rot_b(t_stack **b)
{
	t_stack	*temp;
	t_stack	*find;

	find = *b;
	if (find == NULL || find->next == NULL)
		return (0);
	else
	{
		temp = *b;
		*b = temp->next;
		while (find -> next != NULL)
			find = find->next;
		find -> next = temp;
		temp->next = NULL;
	}
	return (0);
}

void	rot_ab(t_stack **a, t_stack **b)
{
	rot_a(a);
	rot_b(b);
}
