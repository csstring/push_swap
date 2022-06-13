/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:59:12 by schoe             #+#    #+#             */
/*   Updated: 2022/06/13 19:57:39 by schoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rot_a(t_cmd **cmd, t_stack **a)
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
		ft_cmd_node(cmd, "ra\n");
	}
	return (0);
}

int	rot_b(t_cmd **cmd, t_stack **b)
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
		ft_cmd_node(cmd, "rb\n");
	}
	return (0);
}

void	rot_ab(t_cmd **cmd, t_stack **a, t_stack **b)
{
	rot_a(cmd, a);
	rot_b(cmd, b);
	ft_2node_clear(cmd, "rr\n");
}
