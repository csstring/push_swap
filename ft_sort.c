#include "libft.h"
#include "push_swap.h"

int	ft_sortsize(t_push *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		lst = lst -> next;
		i++;
	}
	return (i);
}

t_push	*ft_sortnew(int val, int index)
{
	t_push	*temp;

	temp = (t_push *)malloc(sizeof(t_push));
	if (temp == NULL)
		return (NULL);
	temp->val = val;
	temp->index = index;
	temp->next = NULL;
	temp->rev = NULL;
	return (temp);
}

void	ft_sortadd_back(t_push **lst, t_push *new)
{
	t_push	*temp;

	if (*lst == NULL)
		*lst = new;
	else
	{
		temp = *lst;
		while (temp -> next != NULL)
			temp = temp -> next;
		temp -> next = new;
		new -> rev = temp;
	}
}

void	get_sort_val(char **av, t_push **sort_list)
{
	int	i;

	*sort_list = NULL;
	i = 1;
	while (av[i])
	{
		ft_sortadd_back(sort_list, ft_sortnew(ft_atoi(av[i]), i - 1));
		i++;
	}
}
void	ft_swap_val(t_push *a, t_push *b)
{
	int	temp;

	temp = a->val;
	a->val = b->val;
	b->val = temp;
}

t_push	*ft_last_node(t_push *list)
{
	while (list->next != NULL)
		list = list->next;
	return (list);
}

t_push	*ft_part(t_push *start, t_push *end)
{
	int	piv;
	t_push	*right;
	t_push	*left;

	piv = start->val;
	left = start;
	right = end;
	while (left->index < right->index)
	{
		while (right->val > piv)
			right = right->rev;
		while (left->val <= piv && left->index < right->index)
			left = left->next;
		ft_swap_val(right, left);
	}
	start->val = left->val;
	left->val = piv;
	return (left);
}

int	ft_quick(t_push *start, t_push *end)
{
	t_push	*last;

	if (start->index >= end->index )
		return (0);
	last = ft_part(start,end);
	if (last -> rev != NULL)
		ft_quick(start, last->rev);//left
	if (last -> next != NULL)
		ft_quick(last->next, end);//right
	return (0);
}
int	ft_find_val(t_push *sort_list, int index)
{
	while (sort_list != NULL)
	{
		if (sort_list->index == index)
			return (sort_list->val);
		sort_list = sort_list->next;
	}
	return (0);
}

void	ft_sort_check(t_push *sort_list)
{
	int check;
	t_push *temp;

	temp = sort_list;
	while (sort_list->next != NULL)
	{
		check = sort_list->val;
		if (check == sort_list->next->val)
			exit(0);
		sort_list = sort_list->next;
	}
	temp->piv1 = ft_find_val(temp, (sort_list->index)/2);
	temp->piv2 = ft_find_val(temp, (sort_list->index)/3*2);
//temp->piv3 = ft_find_val(temp, (sort_list->index)/5*3);
//temp->piv4 = ft_find_val(temp, (sort_list->index)/5*4);
}
