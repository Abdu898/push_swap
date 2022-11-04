/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:27:27 by ashahin           #+#    #+#             */
/*   Updated: 2022/11/04 02:34:16 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*if not numbers */
int	check_errors(const char *strn)
{
	long	num;
	int		i;

	i = 0;
	while (strn[i])
	{
		if ((strn[i] < '0' || strn[i] > '9') && \
		!(i == 0 && (strn[i] == '-' || strn[i] == '+')))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	num = ft_atol(strn);
	if (num < INT_MIN || num > INT_MAX)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	check_dups(int length, int *numbers)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < length)
	{
		j = i + 1;
		while (j < length)
		{
			if (numbers[i] == numbers[j])
			{
				write(2, "Error\n", 6);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_sorted(int length, int *numbers)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < length)
	{
		j = i + 1;
		while (j < length)
		{
			if (numbers[i] > numbers[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_dups_sorted(int length, char **argv)
{
	int	numbers[LEN];
	int	i;

	i = 0;
	while (i < length)
	{
		numbers[i] = ft_atoi((const char *) argv[i + 1]);
		i++;
	}
	if (!check_dups(length, numbers))
		return (0);
	if (!check_sorted(length, numbers))
		return (2);
	return (1);
}

int	handle_errors(int length, char **argv)
{
	int	i;
	int	chk_sd;

	if (length < 1)
		return (3);
	i = 1;
	while (i <= length)
	{
		if (!(check_errors(argv[i])))
			return (0);
		i++;
	}
	if (length == 1)
		return (2);
	chk_sd = check_dups_sorted(length, argv);
	if (!chk_sd)
		return (0);
	else if (chk_sd == 2)
		return (2);
	return (1);
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
	int32_t	i = 1;
	t_list	*node = NULL;

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