/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 15:54:22 by schoe             #+#    #+#             */
/*   Updated: 2022/06/13 19:55:13 by schoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_sort_low_count(t_cmd **cmd, t_stack **a, t_stack **b, int ac)
{
	int	n0;
	int	n1;
	int	n2;
	int	temp;

	while (ac-- > 4)
		push_b(cmd, a, b);
	n0 = (*a)->val;
	n1 = (*a)->next->val;
	n2 = (*a)->next->next->val;
	if ((n0 < n2 && n0 > n1) || (n1 > n2 && n1 < n0) || (n2 > n0 && n2 < n1))
	{
		swap_a(cmd, *a);
		temp = n0;
		n0 = n1;
		n1 = temp;
	}
	if (n2 < n0 && n2 > n1)
		rot_a(cmd, a);
	else if (n0 > n2 && n0 < n1)
		rrot_a(cmd, a);
}

void	ft_low_count(t_cmd **cmd, t_stack **a, t_stack **b, int ac)
{
	if (ac == 3)
	{
		ft_printf("%s\n", "sa");
		exit(0);
	}
	if (ac <= 6)
	{
		ft_sort_low_count(cmd, a, b, ac);
		if (*(b) == NULL)
		{
			ft_print_cmd(cmd);
			exit(0);
		}
	}
}

int	main(int ac, char **av)
{
	t_push	**sort_list;
	t_stack	**a;
	t_stack	**b;
	t_cmd	**cmd;

	if (ac == 1)
		return (0);
	sort_list = (t_push **)malloc(sizeof(t_push *));
	cmd = (t_cmd **)malloc(sizeof(t_cmd *));
	a = (t_stack **)malloc(sizeof(t_stack *));
	b = (t_stack **)malloc(sizeof(t_stack *));
	if (sort_list == NULL || cmd == NULL || a == NULL || b == NULL)
		return (0);
	ft_digit_check(av);
	ft_int_check(av);
	ft_get_av(av, sort_list);
	ft_quick_sort((*sort_list), ft_last_node(*sort_list));
	get_stack_val(av, a, *sort_list);
	ft_sort_check(*a, ac);
	ft_low_count(cmd, a, b, ac);
	ft_push_swap(cmd, a, b, sort_list);
	return (0);
}
