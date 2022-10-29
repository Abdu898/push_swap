/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 23:04:58 by ashahin           #+#    #+#             */
/*   Updated: 2022/10/29 07:36:57 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_cases(t_list **stack_a, int *a)
{
	if (a[0] > a[1] && a[0] < a[2] && a[1] < a[2])
		swap(stack_a, 'a');
	else if (a[0] > a[1] && a[0] > a[2] && a[1] < a[2])
		rotate(stack_a, 'a');
	else if (a[0] < a[1] && a[0] > a[2] && a[1] > a[2])
		rev_rotate(stack_a, 'a');
	else if (a[1] > a[2])
	{
		swap(stack_a, 'a');
		if (a[0] < a[1] && a[0] < a[2])
			rotate(stack_a, 'a');
		else if (a[0] > a[1] && a[0] > a[2])
			rev_rotate(stack_a, 'a');
	}
}

void	sort_3(t_list **stack_a)
{
	t_list	*tmp;
	int		a[3];
	int		i;

	i = 0;
	tmp = *stack_a;
	while (tmp)
	{
		a[i] = tmp->number;
		tmp = tmp->next;
		i++;
	}
	sort_cases(stack_a, a);
}

/*chooses the way to send up through ra or rra the pb*/
void	sendup_pushb(t_list **stack_a, t_list **stack_b, t_list **smallest)
{
	t_list	*tmp;
	int		i;

	tmp = *stack_a;
	i = (*smallest)->index;
	if ((*smallest)->index >= 2)
	{
		if (ft_lstsize(*stack_a) == 4)
			i++;
		while (i++ <= 4)
			rev_rotate(stack_a, 'a');
		push(stack_b, stack_a, 'b');
	}
	else
	{
		while (i-- > 0)
			rotate(stack_a, 'a');
		push(stack_b, stack_a, 'b');
	}
}

/*search for the smallest number and give it's index in the stack
then: let the sendup_pushb_1 send the smallest number up and pb*/
void	push_smallest2_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*smallest;

	smallest = lst_smallest_index(stack_a);
	sendup_pushb(stack_a, stack_b, &smallest);
	if (ft_lstsize(*stack_a) == 4)
	{
		smallest = lst_smallest_index(stack_a);
		sendup_pushb(stack_a, stack_b, &smallest);
	}
}

/*push the smallest numbers to b the sort_3 then return them sorted*/
void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int	lstsize;

	lstsize = ft_lstsize(*stack_a);
	if (lstsize <= 3)
	{
		if (lstsize == 2)
			swap(stack_a, 'a');
		else
			sort_3(stack_a);
		return ;
	}
	push_smallest2_b(stack_a, stack_b);
	sort_3(stack_a);
	while (ft_lstsize(*stack_b))
		push(stack_a, stack_b, 'a');
}
