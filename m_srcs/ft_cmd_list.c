/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:53:07 by schoe             #+#    #+#             */
/*   Updated: 2022/06/13 13:16:58 by schoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	ft_print_cmd(t_cmd **cmd)
{
	t_cmd	*temp;

	temp = *cmd;
	while (temp != NULL)
	{
		ft_printf("%s", temp->str);
		temp = temp ->next;
	}
}

void	ft_cmd_node(t_cmd **cmd, char *input)
{
	t_cmd	*new;
	t_cmd	*temp;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (new == NULL)
		exit(0);
	new->str = input;
	new->next = NULL;
	if (*cmd == NULL)
		*cmd = new;
	else
	{
		temp = *cmd;
		while (temp -> next != NULL)
			temp = temp -> next;
		temp -> next = new;
	}
}

void	ft_2node_clear(t_cmd **cmd, char *str)
{
	t_cmd	*temp;
	t_cmd	*find;

	temp = *cmd;
	while (temp->next != NULL)
	{
		find = temp;
		temp = temp->next;
	}
	free(find->next);
	find->next = NULL;
	find->str = str;
}
