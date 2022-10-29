/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:36:23 by ashahin           #+#    #+#             */
/*   Updated: 2022/10/29 07:37:11 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
// {
// typedef struct s_list
// {
// 	void			*number;
// 	size_t			*idex;
// 	struct s_list	*next;
// }	t_list;
// }
//
int		handle_errors(int length, char **argv);
int		check_dups_sorted(int length, char **argv);
int		check_dups(int length, int *numbers);
int		check_sorted(int length, int *numbers);
int		check_int(const char *strn);
//
long	ft_atol(const char *strn);
//
void	swap(t_list **stack, char c);
void	swap_both(t_list **stack_a, t_list **stack_b);
void	rotate(t_list **stack, char c);
void	rotate_both(t_list **stack_a, t_list **stack_b);
t_list	*ft_lstbeforelast(t_list *lst);
void	rev_rotate(t_list **stack, char c);
void	rev_rotate_both(t_list **stack_a, t_list **stack_b);
void	push(t_list **stack_dst, t_list **stack_src, char c);
void	push_both(t_list **stack_a, t_list **stack_b);
//
void	sort_cases(t_list **stack_a, int *a);
void	sort_3(t_list **stack_a);
void	sort_4(t_list **stack_a, t_list **stack_b);
void	sort_5(t_list **stack_a, t_list **stack_b);
//
void	sort_cases(t_list **stack_a, int *a);
void	sort_3(t_list **stack_a);
void	sendup_pushb(t_list **stack_a, t_list **stack_b, t_list **smallest);
t_list	*lst_smallest_index(t_list **stack_a);
void	push_smallest2_b(t_list **stack_a, t_list **stack_b);
void	sort_5(t_list **stack_a, t_list **stack_b);

//
t_list	*create_stack_a(int length, char **argv);

#endif