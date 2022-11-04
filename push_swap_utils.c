/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 00:28:06 by ashahin           #+#    #+#             */
/*   Updated: 2022/11/04 00:03:47 by ashahin          ###   ########.fr       */
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

int	ft_compstr(char	*s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (((unsigned char *) s1)[i] != ((unsigned char *) s2)[i])
			return (((unsigned char *) s1)[i] - ((unsigned char *) s2)[i]);
		i++;
	}
	return (((unsigned char *) s1)[i] - ((unsigned char *) s2)[i]);
}
