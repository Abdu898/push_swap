/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 04:05:42 by ashahin           #+#    #+#             */
/*   Updated: 2022/11/01 04:48:23 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstbeforelast(t_list *lst)
{
	if (!lst || !lst->next->next)
		return (lst);
	return (ft_lstbeforelast(lst->next));
}

void	rev_rotate(t_list **stack)
{
	t_list	*tmp;

	tmp = ft_lstlast(*stack);
	ft_lstbeforelast(*stack)->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
}

void	rra(t_list **stack_a)
{
	rev_rotate(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_list **stack_b)
{
	rev_rotate(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_printf("rrr\n");
}
