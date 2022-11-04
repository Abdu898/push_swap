/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 21:01:33 by ashahin           #+#    #+#             */
/*   Updated: 2022/11/04 02:24:48 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		length;
	int		hand_err;

	length = argc - 1;
	hand_err = handle_errors(length, argv);
	if (!hand_err)
		return (1);
	else if (hand_err >= 2)
		return (0);
	stack_a = create_stack_a(length, argv);
	stack_b = NULL;
	if (length <= 5)
		sort_5(&stack_a, &stack_b);
	else
		push_swap(&stack_a, &stack_b);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}
