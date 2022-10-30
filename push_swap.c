/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:26:11 by ashahin           #+#    #+#             */
/*   Updated: 2022/10/30 07:39:24 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lst_index(t_list **stack)
{
	t_list	*tmp;
	t_list	*min;
	int		i;
	int		length;

	tmp = *stack;
	min = *stack;
	length = ft_lstsize(*stack);
	i = 0;
	while (i < length)
	{
		tmp = *stack;
		while (tmp)
		{
			if ((tmp->number < min->number || min->index != -1) \
						&& tmp->index == -1)
			{
				min = tmp;
			}
			tmp = tmp->next;
		}
		min->index = i++;
	}
}

int	ft_max_bits(t_list *stack)
{
	t_list	*tmp;
	t_list	*max;
	int		max_n;
	int		max_bits;

	tmp = stack;
	max = stack;
	while (tmp)
	{
		if (tmp->number > max->number)
			max = tmp;
		tmp = tmp->next;
	}
	max_n = max->number;
	max_bits = 0;
	while (max_n >> max_bits != 0)
		max_bits++;
	return (max_bits);
}

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;
	int		length;
	int		max_bits;
	int		i;
	int		j;

	head = *stack_a;
	length = ft_lstsize(*stack_a);
	max_bits = ft_max_bits(*stack_a);
	i = 0;
	j = 0;
							// 	t_list	*tmp = *stack_a;
							// 	while ((*stack_a))
							// {
							// 	ft_printf("tmp->index= %d\n", (*stack_a)->number);
							// 	(*stack_a) = (*stack_a)->next;
							// }
							// (*stack_a) = tmp;
	while (i < max_bits)
	{
		j = 0;
		while (j++ < length)
		{
			head = *stack_a;
			if ((head->index >> i) > 0)
			{
					// ft_printf("head->index= %d\n", head->index);
					// ft_printf("head->number= %d\n", head->number);

				rotate(stack_a, 'a');
					// ft_printf("head->number= %d\n", head->number);
			}
			else
				push(stack_b, stack_a, 'b');
		}
					// ft_printf("GOOD!\n");
		while (ft_lstsize(*stack_b))
			push(stack_a, stack_b, 'a');
		i++;
	}
}
