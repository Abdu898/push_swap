/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:05:16 by ashahin           #+#    #+#             */
/*   Updated: 2022/11/04 00:04:53 by ashahin          ###   ########.fr       */
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

t_list	*create_stack_a(int length, char **argv)
{
	int		i;
	t_list	*stack_a;

	i = 1;
	stack_a = ft_lstnew(ft_atol((char *) argv[i]));
	if (!stack_a)
		return (stack_a);
	i++;
	while ((i) <= length)
	{
		ft_lstadd_back(&stack_a, ft_lstnew((int) ft_atoi((char *) argv[i])));
		i++;
	}
	if (ft_lstsize(stack_a) > 5)
		ft_lst_index(&stack_a);
	return (stack_a);
}

void	ft_free_stack(t_list **stack)
{
	t_list	*head;

	head = *stack;
	while (head)
	{
		*stack = (*stack)->next;
		free(head);
		head = *stack;
	}
}

char	*ft_strjoin_ps(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	str = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	free(s1);
	return (str);
}

void	free_op(char **op_list)
{
	int	i;

	i = -1;
	while (op_list[++i])
		free(op_list[i]);
	free(op_list);
}
