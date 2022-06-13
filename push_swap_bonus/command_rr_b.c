/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:59:48 by schoe             #+#    #+#             */
/*   Updated: 2022/06/13 14:49:10 by schoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rrot_ab(t_stack **a, t_stack **b)
{
	rrot_a(a);
	rrot_b(b);
}

int	rrot_a(t_stack **a)
{
	t_stack	*find;
	t_stack	*temp;

	find = *a;
	if (find == NULL || find->next == NULL)
		return (0);
	else
	{
		while (find -> next != NULL)
		{
			temp = find;
			find = find->next;
		}
		find->next = *a;
		*a = find;
		temp->next = NULL;
	}
	return (0);
}

int	rrot_b(t_stack **b)
{
	t_stack	*find;
	t_stack	*temp;

	find = *b;
	if (find == NULL || find->next == NULL)
		return (0);
	else
	{
		while (find -> next != NULL)
		{
			temp = find;
			find = find->next;
		}
		find->next = *b;
		*b = find;
		temp->next = NULL;
	}
	return (0);
}
