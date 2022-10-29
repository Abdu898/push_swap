/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 21:01:33 by ashahin           #+#    #+#             */
/*   Updated: 2022/10/29 06:32:08 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_stack_a(int length, char **argv)
{
	int		i;
	t_list	*stack_a;

	i = 1;
	stack_a = ft_lstnew(ft_atol((char *) argv[i]));
	i++;
	while ((i) <= length)
	{
		ft_lstadd_back(&stack_a, ft_lstnew((int) ft_atoi((char *) argv[i])));
		i++;
	}
	return (stack_a);
}

/*
//handle errors working  12:00 29oct
//create_stack working  12:00 29oct
//sort_3 working 28oct
//sort_5 working 6:30 29oct
*/
int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		length;

	length = argc - 1;
	if (!handle_errors(length, argv))
		return (0);
	stack_a = create_stack_a(length, argv);
	stack_b = NULL;
	if (length <= 5)
		sort_5(&stack_a, &stack_b);
	return (0);
}
