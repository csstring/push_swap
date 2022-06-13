/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:04:28 by schoe             #+#    #+#             */
/*   Updated: 2022/06/13 19:52:32 by schoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include <stdlib.h>

typedef struct s_push_list
{
	int					val;
	int					index;
	struct s_push_list	*next;
	struct s_push_list	*rev;
	int					piv1;
	int					piv2;
}	t_push;

typedef struct s_stack
{
	int				val;
	int				a_count;
	int				b_count;
	int				sum;
	struct s_stack	*next;
}	t_stack;

//quick_sort
void	ft_swap_val(t_push *a, t_push *b);
t_push	*ft_part(t_push *start, t_push *end);
int		ft_quick_sort(t_push *start, t_push *end);
t_push	*ft_last_node(t_push *list);
//get_argv
t_push	*ft_avnew(int val, int index);
void	ft_avadd_back(t_push **lst, t_push *new);
void	ft_get_av(char **av, t_push **sort_list);
//command//
int		swap_a(t_stack *a);
int		swap_b(t_stack *b);
void	swap_ab(t_stack *a, t_stack *b);
int		push_a(t_stack **a, t_stack **b);
int		push_b(t_stack **a, t_stack **b);
int		rot_a(t_stack **a);
int		rot_b(t_stack **b);
int		rrot_a(t_stack **a);
int		rrot_b(t_stack **b);
void	rot_ab(t_stack **a, t_stack **b);
void	rrot_ab(t_stack **a, t_stack **b);
//error_check
void	ft_digit_check(char **av);
void	ft_int_check(char **av);
int		ft_dup_check(t_stack *a);
//stack_list
void	ft_stackadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_stacknew(int val);
void	get_stack_val(char **av, t_stack **a, t_push *sort_list);
#endif
