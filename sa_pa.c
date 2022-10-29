/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 23:13:18 by ashahin           #+#    #+#             */
/*   Updated: 2022/10/29 06:39:51 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*swap the first two elements in the stack
(without gaurding if the stack is >= 2 elements)*/
void	swap(t_list **stack, char c)
{
	t_list	*tmp;

	tmp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	tmp->next = (*stack);
	*stack = tmp;
	ft_printf("s%c\n", c);
}

void	swap_both(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a, 'a');
	swap(stack_b, 'b');
}

/*this function is push_a by default;
to push_b change the parameters stack_a and stack_b locations*/
void	push(t_list **stack_dst, t_list **stack_src, char c)
{
	t_list	*tmp;

	tmp = (*stack_src)->next;
	(*stack_src)->next = *stack_dst;
	*stack_dst = *stack_src;
	*stack_src = tmp;
	ft_printf("p%c\n", c);
}

void	push_both(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b, 'a');
	push(stack_b, stack_a, 'b');
}
