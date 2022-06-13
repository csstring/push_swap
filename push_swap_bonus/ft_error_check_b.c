/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:49:50 by schoe             #+#    #+#             */
/*   Updated: 2022/06/13 16:11:17 by schoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "libft.h"

void	ft_digit_check(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		if (av[i][j] == 0)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]) && \
					!(j == 0 && (av[i][j] == '-' || av[i][j] == '+')))
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	ft_int_check(char **av)
{
	ssize_t	val;
	int		i;

	i = 1;
	while (av[i])
	{
		val = ft_atoli(av[i]);
		if (val > 2147483647 || val < -2147483648)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}

int	ft_dup_check(t_stack *a)
{
	int	min;

	min = a->val;
	while (a->next != NULL)
	{
		if (min == a->next->val)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		a = a->next;
		min = a->val;
	}
	return (0);
}
