/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:27:27 by ashahin           #+#    #+#             */
/*   Updated: 2022/10/29 05:02:07 by ashahin          ###   ########.fr       */
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
			write(1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	num = ft_atol(strn);
	if (num < INT_MIN || num > INT_MAX)
	{
		write(1, "Error\n", 6);
		return (0);
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
				write(1, "Error\n", 6);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_dups_sorted(int length, char **argv)
{
	int	numbers[length];
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
		return (0);
	return (1);
}

int	handle_errors(int length, char **argv)
{
	int	i;

	if (length < 1)
		return (0);
	i = 1;
	while (i <= length)
	{
		if (!(check_errors(argv[i])))
			return (0);
		i++;
	}
	if (length == 1)
		return (0);
	if (!check_dups_sorted(length, argv))
		return (0);
	return (1);
}
