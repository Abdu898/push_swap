/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:36:23 by ashahin           #+#    #+#             */
/*   Updated: 2022/11/04 00:09:43 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define LEN 1001

# include "ft_printf/libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_bucket
{
	int	arr[10][500];
	int	ind_arr[10];
}	t_bucket;

//################# to be deleted ####################
void	print_list(t_list **list, char *name);
//handle_errors.c
int		handle_errors(int length, char **argv);
int		check_dups_sorted(int length, char **argv);
int		check_dups(int length, int *numbers);
int		check_sorted(int length, int *numbers);
int		check_errors(const char *strn);
//push_swap.c
long	ft_atol(const char *strn);
t_list	*lst_smallest_index(t_list **stack_a);
//swap.c
void	swap(t_list **stack);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
// rotate.c
void	rotate(t_list **stack);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
// rev_rotate.c
t_list	*ft_lstbeforelast(t_list *lst);
void	rev_rotate(t_list **stack);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
//push.c
void	push(t_list **stack_dst, t_list **stack_src);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_b, t_list **stack_a);
//sort_5.c
void	sort_cases(t_list **stack_a, int *a);
void	sort_3(t_list **stack_a);
void	sendup_pushb(t_list **stack_a, t_list **stack_b, t_list **smallest);
void	push_smallest2_b(t_list **stack_a, t_list **stack_b);
void	sort_5(t_list **stack_a, t_list **stack_b);
//push_swap.c
int		ft_max_bits(t_list *stack);
void	push_swap(t_list **stack_a, t_list **stack_b);

//alloc_free.c
t_list	*create_stack_a(int length, char **argv);
void	ft_free_stack(t_list **stack);
void	ft_lst_index(t_list **stack);
char	*ft_strjoin_ps(char *s1, char *s2);

//operations_b.c
int		swap_check(t_list **stack);
int		rotate_check(t_list **stack);
int		rev_rotate_check(t_list **stack);
int		push_check(t_list **stack_dst, t_list **stack_src);
int		ft_compstr(char	*s1, char *s2);
//checker.c
int		ft_get_move1(t_list **stack_a, t_list **stack_b, char *move);
int		ft_get_move(t_list **stack_a, t_list **stack_b, char *move);
char	**ft_check_moves(t_list **stack_a, t_list **stack_b);
int		ft_check_sorted(t_list **stack_a, t_list **stack_b);
void	free_op(char **op_list);

#endif