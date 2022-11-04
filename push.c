/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 04:06:21 by ashahin           #+#    #+#             */
/*   Updated: 2022/11/04 00:03:11 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*this function is push_a by default;
to push_b change the parameters stack_a and stack_b locations*/
void	push(t_list **stack_dst, t_list **stack_src)
{
	t_list	*tmp;

	tmp = (*stack_src)->next;
	(*stack_src)->next = *stack_dst;
	*stack_dst = *stack_src;
	*stack_src = tmp;
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pa\n");
}

void	pb(t_list **stack_b, t_list **stack_a)
{
	push(stack_b, stack_a);
	ft_printf("pb\n");
}

int	push_check(t_list **stack_dst, t_list **stack_src)
{
	if (!*stack_src)
		return (0);
	push(stack_dst, stack_src);
	return (1);
}

int	rev_rotate_check(t_list **stack)
{
	if (!*stack)
		return (0);
	rev_rotate(stack);
	return (1);
}
