/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 06:38:56 by ashahin           #+#    #+#             */
/*   Updated: 2022/10/29 06:39:40 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*rotate stack by putting the first element to the end of the stack
(without gaurding if the stack is >= 2 elements)*/
void	rotate(t_list **stack, char c)
{
	t_list	*tmp;

	tmp = (*stack)->next;
	ft_lstlast(*stack)->next = *stack;
	(*stack)->next = NULL;
	*stack = tmp;
	ft_printf("r%c\n", c);
}

void	rotate_both(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a, 'a');
	rotate(stack_b, 'b');
}

t_list	*ft_lstbeforelast(t_list *lst)
{
	if (!lst || !lst->next->next)
		return (lst);
	return (ft_lstbeforelast(lst->next));
}

void	rev_rotate(t_list **stack, char c)
{
	t_list	*tmp;

	tmp = ft_lstlast(*stack);
	ft_lstbeforelast(*stack)->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
	ft_printf("rr%c\n", c);
}

void	rev_rotate_both(t_list **stack_a, t_list **stack_b)
{
	rev_rotate(stack_a, 'a');
	rev_rotate(stack_b, 'b');
}
