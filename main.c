#include "libft.h"
#include "push_swap.h"
int	main(int ac, char **av)
{
	t_push **sort_list;
	t_stack	**a;
	t_stack	**b;
	t_stack *stack_temp;
	t_cmd	*cmd_temp;
	t_cmd	**cmd;

	(void)ac;
	sort_list = (t_push **)malloc(sizeof(t_push *));
	cmd = (t_cmd **)malloc(sizeof(t_cmd *));
	a = (t_stack **)malloc(sizeof(t_stack *));
	b = (t_stack **)malloc(sizeof(t_stack *));
	get_sort_val(av, sort_list);
	//get_stack_val(av, a, *sort_list);
	stack_temp = *a;
	ft_quick(*sort_list, ft_last_node(*sort_list));
	ft_sort_check(*sort_list);
	get_stack_val(av, a, *sort_list);
//	printf("(main)piv_l:%d\npiv_s:%d",(*sort_list)->piv_l, (*sort_list)->piv_s);
	//
	ft_push_swap(cmd, a, b, sort_list);
	//
/*	printf("%s","a_stack\n");
	stack_temp = *a;
	while (stack_temp != NULL)//a print
	{
		printf("%d\n",stack_temp ->val);
		stack_temp = stack_temp->next;
	}
	printf("%s","b_stack\n");
	stack_temp = *b;
	while (stack_temp != NULL)//b print
	{
		printf("%d\n",stack_temp ->val);
		stack_temp = stack_temp->next;
	}
	printf("%s","cmd\n");*/
	cmd_temp = *cmd;
	while (cmd_temp != NULL)//cmd print
	{
		printf("%s", cmd_temp->str);
		cmd_temp = cmd_temp ->next;
	}
	return (0);
}
