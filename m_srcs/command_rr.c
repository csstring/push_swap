/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:59:48 by schoe             #+#    #+#             */
/*   Updated: 2022/06/13 19:57:31 by schoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrot_ab(t_cmd **cmd, t_stack **a, t_stack **b)
{
	rrot_a(cmd, a);
	rrot_b(cmd, b);
	ft_2node_clear(cmd, "rrr\n");
}

int	rrot_a(t_cmd **cmd, t_stack **a)
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
		ft_cmd_node(cmd, "rra\n");
	}
	return (0);
}

int	rrot_b(t_cmd **cmd, t_stack **b)
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
		ft_cmd_node(cmd, "rrb\n");
	}
	return (0);
}
