#include "libft.h"
#include "push_swap.h"

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
	t_cmd *temp;
	t_cmd	*find;

	temp = *cmd;
	while (temp->next != NULL)
	{
		find = temp;
		temp = temp->next;
	}
	free(find->next);
	find->next = NULL;
	//free(temp->str);
	find->str = str;
}
int	swap_a(t_cmd **cmd, t_stack *a)
{
	int	temp;

	if (a == NULL || a->next == NULL)
		return(0);
	else
	{
		temp = a->val;
		a->val = a->next->val;
		a->next->val = temp;
		ft_cmd_node(cmd, "sa\n");
	}
	return (0);
}

int	swap_b(t_cmd **cmd, t_stack *b)
{
	int	temp;

	if (b == NULL || b->next == NULL)
		return(0);
	else
	{
		temp = b->val;
		b->val = b->next->val;
		b->next->val = temp;
		ft_cmd_node(cmd, "sb\n");
	}
	return (0);
}

int	push_a(t_cmd **cmd, t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (*b == NULL)
		return (0);
	else
	{
		temp = *b;
		*b = temp->next;
		temp->next = *a;
		*a = temp;
		ft_cmd_node(cmd, "pa\n");
	}
	return (0);
}

int	push_b(t_cmd **cmd, t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (*a == NULL)
		return (0);
	else
	{
		temp = *a;
		*a = temp->next;
		temp->next = *b;
		*b = temp;
		ft_cmd_node(cmd, "pb\n");
	}
	return (0);
}

int	rot_a(t_cmd **cmd, t_stack **a)
{
	t_stack	*temp;
	t_stack *find;

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
	t_stack *find;

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

void	rrot_ab(t_cmd **cmd, t_stack **a, t_stack **b)
{
	rrot_a(cmd, a);
	rrot_b(cmd, b);
	ft_2node_clear(cmd, "rrr\n");
}

int	rrot_a(t_cmd **cmd, t_stack **a)
{
	t_stack *find;
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
	t_stack *find;
	t_stack *temp;

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

void	ft_stackadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	if (*lst == NULL)
		*lst = new;
	else
	{
		temp = *lst;
		while (temp -> next != NULL)
			temp = temp -> next;
		temp -> next = new;
	}
}

t_stack	*ft_stacknew(int val)
{
	t_stack	*temp;

	temp = (t_stack *)malloc(sizeof(t_stack));
	if (temp == NULL)
		return (NULL);
	temp->val = val;
	temp->a_count = 0;
	temp->b_count = 0;
	temp->sum = 0;
	temp->next = NULL;
	return (temp);
}

void	get_stack_val(char **av, t_stack **a, t_push *sort_list)
{
	int	i;
	t_push	*temp;

	temp = sort_list;
	*a = NULL;
	i = 1;
	while (av[i])
	{
		sort_list = temp;
		while (sort_list != NULL && sort_list->val != ft_atoi(av[i]))
			sort_list = sort_list->next;
		ft_stackadd_back(a, ft_stacknew(sort_list->index));
		i++;
	}
	//val == index 뒤에 코드 다시 봐야할듯?
	while (temp != NULL)
	{
		temp->val = temp->index;
		temp = temp ->next;
	}
}
