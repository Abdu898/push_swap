/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 00:28:06 by ashahin           #+#    #+#             */
/*   Updated: 2022/10/30 08:37:38 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *strn)
{
	long	res;
	size_t	i;
	int		sign;

	i = 0;
	while ((strn[i] >= 9 && strn[i] <= 13) || strn[i] == 32)
		i++;
	res = 0;
	sign = 1;
	if (strn[i] == '-' || strn[i] == '+')
	{
		if (strn[i] == '-')
			sign = -1;
		i++;
	}
	while (strn[i] != '\0' && (strn[i] >= '0' && strn[i] <= '9'))
		res = res * 10 + (strn[i++] - '0');
	return (res * sign);
}

t_list	*lst_smallest_index(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*smallest;
	int		i;

	i = 0;
	tmp = *stack_a;
	smallest = *stack_a;
	while (tmp)
	{
		if (tmp->number < smallest->number)
		{
			smallest = tmp;
			smallest->index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (smallest);
}
