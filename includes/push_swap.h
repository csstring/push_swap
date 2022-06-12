#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_push_list
{
	int	val;
	int	index;
	struct s_push_list	*next;
	struct s_push_list	*rev;
	int	piv1;
	int	piv2;
	int	piv3;
	int	piv4;
}	t_push;

typedef	struct s_stack
{
	int	val;
	int	a_count;
	int	b_count;
	int	sum;
	struct s_stack	*next;
}	t_stack;

typedef	struct	s_command_list
{
	char	*str;
	struct	s_command_list	*next;
}	t_cmd;

int	ft_sortsize(t_push *lst);
t_push	*ft_sortnew(int val, int index);
void	ft_sortadd_back(t_push **lst, t_push *new);
void	get_sort_val(char **av, t_push **sort_list);
void	ft_swap_val(t_push *a, t_push *b);
t_push	*ft_last_node(t_push *list);
t_push	*ft_part(t_push *start, t_push *end);
int	ft_quick(t_push *start, t_push *end);
void	ft_cmd_node(t_cmd **cmd, char *input);
int	swap_a(t_cmd **cmd, t_stack *a);
int	swap_b(t_cmd **cmd, t_stack *b);
int	push_a(t_cmd **cmd, t_stack **a, t_stack **b);
int	push_b(t_cmd **cmd, t_stack **a, t_stack **b);
int	rot_a(t_cmd **cmd, t_stack **a);
int	rot_b(t_cmd **cmd, t_stack **b);
int	rrot_a(t_cmd **cmd, t_stack **a);
int	rrot_b(t_cmd **cmd, t_stack **b);
void	rot_ab(t_cmd **cmd, t_stack **a, t_stack **b);
void	rrot_ab(t_cmd **cmd, t_stack **a, t_stack **b);
void	ft_sort_check(t_push *sort_list);
void	ft_stackadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_stacknew(int val);
void	get_stack_val(char **av, t_stack **a, t_push *sort_list);
void	ft_div(t_cmd **cmd, t_stack **a, t_stack **b, t_push **sort_list);
void	ft_push_swap(t_cmd **cmd, t_stack **a, t_stack **b, t_push **sort_list);
#endif
