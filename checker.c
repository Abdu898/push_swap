/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 21:52:48 by ashahin           #+#    #+#             */
/*   Updated: 2022/11/04 02:25:54 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_move1(t_list **stack_a, t_list **stack_b, char *move)
{
	if (!ft_compstr(move, "rrr"))
	{
		rev_rotate_check(stack_a);
		rev_rotate_check(stack_b);
	}
	else if (!ft_compstr(move, "pa"))
		push_check(stack_a, stack_b);
	else if (!ft_compstr(move, "pb"))
		push_check(stack_b, stack_a);
	else if (!ft_compstr(move, "ss"))
	{
		swap_check(stack_a);
		swap_check(stack_b);
	}
	else if (!ft_compstr(move, "rr"))
	{
		rotate_check(stack_a);
		rotate_check(stack_b);
	}
	else
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	ft_get_move(t_list **stack_a, t_list **stack_b, char *move)
{
	if (!ft_compstr(move, "sa"))
		swap_check(stack_a);
	else if (!ft_compstr(move, "ra"))
		rotate_check(stack_a);
	else if (!ft_compstr(move, "rra"))
		rev_rotate_check(stack_a);
	else if (!ft_compstr(move, "sb"))
		swap_check(stack_b);
	else if (!ft_compstr(move, "rb"))
		rotate_check(stack_b);
	else if (!ft_compstr(move, "rrb"))
		rev_rotate_check(stack_b);
	else
	{
		if (!ft_get_move1(stack_a, stack_b, move))
			return (0);
	}
	return (1);
}

char	**ft_check_moves(t_list **stack_a, t_list **stack_b)
{
	char	*moves;
	char	*tmp;
	char	**op_list;
	int		i;

	tmp = get_next_line(0);
	moves = NULL;
	while (tmp)
	{
		moves = ft_strjoin_ps(moves, tmp);
		free(tmp);
		tmp = get_next_line(0);
	}
	op_list = ft_split(moves, '\n');
	free(moves);
	i = -1;
	while (op_list[++i])
	{
		if (ft_get_move(stack_a, stack_b, op_list[i]) != 1)
		{
			free_op(op_list);
			return (NULL);
		}
	}
	return (op_list);
}

int	ft_check_sorted(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;
	int		num;

	head = *stack_a;
	num = head->number;
	while (head->next)
	{
		head = head->next;
		if (num > head->number)
			return (ft_printf("KO\n"));
		num = head->number;
	}
	if (!(*stack_b))
		return (ft_printf("OK\n"));
	return (ft_printf("KO\n"));
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**op_list;

	if (!handle_errors(argc - 1, argv))
		return (1);
	else if (handle_errors(argc - 1, argv) >= 2)
	{
		if (handle_errors(argc - 1, argv) == 2)
			write(2, "OK\n", 3);
		return (0);
	}
	stack_a = create_stack_a(argc - 1, argv);
	if (!stack_a)
		return (1);
	stack_b = NULL;
	op_list = ft_check_moves(&stack_a, &stack_b);
	if (op_list)
		ft_check_sorted(&stack_a, &stack_b);
	if (op_list)
		free(op_list);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}

/*
void	print_list(t_list **list, char *name)
{
	printf("----------\n[%s]:\n", name);
	if (*list == NULL)
	{
		printf("list_pos_1: (NULL)\n");
		return ;
	}
	int32_t i = 1;
	t_list *node = NULL;
	node = (*list);
	while (node->next != NULL)
	{
		printf("list_pos_%d: %d\n", i, node->number);
		i++;
		node = node->next;
	}
	printf("list_pos_%d: %d\n", i, node->number);
	i++;
	if (node->next == NULL)
		printf("list_pos_%d: (NULL)\n", i);
	else
		printf("something wrong! (print_list function)\n");
	printf("-- done --\n\n");
}
*/