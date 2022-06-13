/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 15:54:22 by schoe             #+#    #+#             */
/*   Updated: 2022/06/13 18:01:50 by schoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap_bonus.h"

int	ft_do_command(t_stack **a, t_stack **b, char *str)
{
	if (!ft_strncmp(str, "sa\n", 4))
		swap_a(*a);
	else if (!ft_strncmp(str, "sb\n", 4))
		swap_b(*b);
	else if (!ft_strncmp(str, "ss\n", 4))
		swap_ab(*a, *b);
	else if (!ft_strncmp(str, "pa\n", 4))
		push_a(a, b);
	else if (!ft_strncmp(str, "pb\n", 4))
		push_b(a, b);
	else if (!ft_strncmp(str, "ra\n", 4))
		rot_a(a);
	else if (!ft_strncmp(str, "rb\n", 4))
		rot_b(b);
	else if (!ft_strncmp(str, "rr\n", 4))
		rot_ab(a, b);
	else if (!ft_strncmp(str, "rra\n", 5))
		rrot_a(a);
	else if (!ft_strncmp(str, "rrb\n", 5))
		rrot_b(b);
	else if (!ft_strncmp(str, "rrr\n", 5))
		rrot_ab(a, b);
	else
		return (1);
	return (0);
}

int	ft_sort_check(t_stack *a, t_stack *b)
{
	int	min;

	if (b != NULL || a == NULL)
	{
		write(1, "KO\n", 3);
		exit (0);
	}
	min = a->val;
	while (a->next != NULL)
	{
		if (min > a->next->val)
		{
			write(1, "KO\n", 3);
			exit (0);
		}
		a = a->next;
		min = a->val;
	}
	write(1, "OK\n", 3);
	return (0);
}

void	ft_checker_sort(t_stack **a, t_stack **b)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (str == NULL)
			break ;
		if (ft_do_command(a, b, str))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		free(str);
	}
	ft_sort_check(*a, *b);
}

int	main(int ac, char **av)
{
	t_push	**sort_list;
	t_stack	**a;
	t_stack	**b;

	if (ac == 1)
		return (0);
	sort_list = (t_push **)malloc(sizeof(t_push *));
	a = (t_stack **)malloc(sizeof(t_stack *));
	b = (t_stack **)malloc(sizeof(t_stack *));
	if (sort_list == NULL || a == NULL || b == NULL)
		return (0);
	ft_digit_check(av);
	ft_int_check(av);
	ft_get_av(av, sort_list);
	ft_quick_sort((*sort_list), ft_last_node(*sort_list));
	get_stack_val(av, a, *sort_list);
	ft_dup_check(*a);
	ft_checker_sort(a, b);
	return (0);
}
