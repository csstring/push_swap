#include "push_swap.h"

static int	ft_short_rot(t_stack *c, int min, int max)
{
	int	i;
	int	r_temp;
	int rr_temp;

	i = 0;
	r_temp = -1;
	rr_temp = -1;
	while (c != NULL)
	{
		if (c->val >= min && c->val <= max)
			rr_temp = i;
		if (r_temp == -1 && (c->val >= min && c->val <= max))
			r_temp = i;
		c = c->next;
		i++;
	}
	if (r_temp == -1 && rr_temp == -1)
		return (2);
	else if (r_temp == rr_temp)
	{
		if (r_temp < i / 2)
			return (1);
		else
			return (2);
	}
	else if (r_temp < i - rr_temp)
		return (1);//cw
	else
		return (0);//ccw
}

static void	ft_cw(t_cmd **cmd, t_stack **a, t_stack **b, int max)
{
	while ((*a)->val > max)
	{
		if (*b != NULL && (*b)->next != NULL && ((*b)->val < (*b)->next->val))
			rot_ab(cmd, a, b);
		else
			rot_a(cmd, a);
	}
}

 void	ft_ccw(t_cmd **cmd, t_stack **a, t_stack **b, int max)
{
	t_stack *temp;

	temp = *b;
	while (*b != NULL && temp->next != NULL)
	{
		temp = temp->next;
	}
	while ((*a)->val > max)
	{
		if (*b != NULL && (*b)->next != NULL && ((*b)->val < temp->val))
				rrot_ab(cmd, a, b);
		else
			rrot_a(cmd,a);
	}
}
void	ft_quick4(t_cmd **cmd, t_stack **a, t_stack **b, int min, int max)
{
	int	i;
	while (1)
	{
		i = ft_short_rot(*a, min, max);
		if (i == 1)
		{
			ft_cw(cmd, a, b, max);
			push_b(cmd, a, b);
		}
		else if (i == 0)
		{
			ft_ccw(cmd, a, b, max);
			push_b(cmd, a, b);
		}		
		else
			break;
	}
}
void	ft_div(t_cmd **cmd, t_stack **a, t_stack **b, t_push **sort_list)
{
	t_push *temp;

	temp = *sort_list;
//	ft_quick4(cmd, a, b, (*sort_list)->val, (*sort_list)->piv1);
//	ft_quick4(cmd, a, b, (*sort_list)->piv1, (*sort_list)->piv2);
//ft_quick4(cmd, a, b, (*sort_list)->val, (*sort_list)->piv1);
//	ft_quick4(cmd, a, b, (*sort_list)->piv2, (*sort_list)->piv3);
//ft_quick4(cmd, a, b, (*sort_list)->piv3, (*sort_list)->piv4);
	while (*a != NULL)
		push_b(cmd, a, b);
}
