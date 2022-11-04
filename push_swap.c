/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:26:11 by ashahin           #+#    #+#             */
/*   Updated: 2022/11/03 23:56:10 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max_bits(t_list *stack)
{
	t_list	*tmp;
	t_list	*max;
	int		max_index;
	int		max_bits;

	tmp = stack;
	max = stack;
	while (tmp)
	{
		if (tmp->index > max->index)
			max = tmp;
		tmp = tmp->next;
	}
	max_index = max->index;
	max_bits = 0;
	while (max_index >> max_bits != 0)
		max_bits++;
	return (max_bits);
}

void	ft_decide_ra_pb(t_list **stack_a, t_list **stack_b, int i)
{
	t_list	*head;

	head = *stack_a;
	if ((head->index >> i & 1) == 1)
		ra(stack_a);
	else
		pb(stack_b, stack_a);
}

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	int		length;
	int		max_bits;
	int		i;
	int		j;

	length = ft_lstsize(*stack_a);
	max_bits = ft_max_bits(*stack_a);
	i = 0;
	j = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j++ < length)
		{
			ft_decide_ra_pb(stack_a, stack_b, i);
		}
		while (ft_lstsize(*stack_b))
			pa(stack_a, stack_b);
		i++;
	}
}
