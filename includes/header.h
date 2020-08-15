/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <jremarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 00:04:03 by jremarqu          #+#    #+#             */
/*   Updated: 2020/03/13 20:50:07 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**                               PART ZERO
*/

#ifndef HEADER_H
# define HEADER_H
# include <stdlib.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

typedef struct		s_list
{
	struct s_list	*next;
	int				data;
	int				run_br;
	int				run_bl;
	int				run_ar;
	int				run_al;
	int				res;
}					t_list;

typedef struct		s_ab
{
	t_list			*a;
	t_list			*b;
}					t_ab;

typedef struct		s_order
{
	int				direct_a;
	int				direct_b;
	int				cnt_a_run;
	int				cnt_b_run;
}					t_order;

/*
**                              PART ONE
*/

/*
**         main list
**           actions
*/

t_list				*ft_createlist(int data);
t_list				*ft_add_to_top(t_list **head, int data);
t_list				*ft_add_to_bottom(t_list **head, int data);
t_list				*ft_delete_first_elem(t_list **list);
t_list				*ft_delete_last_elem(t_list **list);

/*
**		subject actions
**       for push swap
*/

void				sa(t_list **list_a);
void				sb(t_list **list_b);
void				ss(t_list **list_a, t_list **list_b);
void				pa(t_list **list_a, t_list **list_b);
void				pb(t_list **list_a, t_list **list_b);
void				ra(t_list **list_a);
void				rb(t_list **list_b);
void				rr(t_list **list_a, t_list **list_b);
void				rra(t_list **list_a);
void				rrb(t_list **list_b);
void				rrr(t_list **list_a, t_list **list_b);

/*
**		subject actions
**       for checker
*/

int					check_dubles(t_list **a_head);
int					sai(t_list **list_a);
int					sbi(t_list **list_b);
int					ssi(t_list **list_a, t_list **list_b);
int					pai(t_list **list_a, t_list **list_b);
int					pbi(t_list **list_a, t_list **list_b);
int					rai(t_list **list_a);
int					rbi(t_list **list_b);
int					rri(t_list **list_a, t_list **list_b);
int					rrai(t_list **list_a);
int					rrbi(t_list **list_b);
int					rrri(t_list **list_a, t_list **list_b);

/*
**                                PART TWO
*/

/*
**          parser's
**    checkers and helpers
*/

void				ft_free_null(char **tmp);
int					just_iter(char *str, int i);
int					ft_strisnum(char *str);
t_list				*ft_get_int(char **tmp, t_list **list);
int					check_elem_of_arg(char *str);
char				*prep_memmory_for_digits(char *str, char *tmp, int i);
int					check_fisrt_zero(char *str);
int					check_last_s(char c, char *tmp);

/*
**         arguments
**          parsing
*/

int					ft_case_sign(char *str);
int					ft_case_no_sign(char *str);
t_list				*body_read_args(char *str, t_list *tmp_l, int i, char *tmp);
t_list				*reed_args(char *str, t_list **a, int i, char *tmp);
int					parser(char **argv, t_list **a, int argc);
int					ft_check_sign_witout_nbr(char *tmp);
int					ft_check_args(char *tmp);
void				first_args_checker(int argc, char **argv);
/*
**          						PART THREE
*/

/*
**   manager for different
**          algoritms
*/

void				algo_manager(t_ab *ab);

/*
**     sorting for simple
**         algoritms
*/

void				for_one_elem_a(t_list **a);
void				for_three_elem_a(t_list **a);
void				for_three_elem(t_ab *ab);
void				for_two_elem_b(t_list **b);
void				for_two_elem_a(t_list **a);
void				for_four_elem(t_ab *ab, int size);
void				for_five_elem(t_ab *ab, int size);

/*
**          simple
**         algoritms
*/

void				for_one_elem_a(t_list **a);
void				for_three_elem_a(t_list **a);
void				for_two_elem_a(t_list **a);

/*
**                                 PART FOUR
*/

/*
**         preparing
**      for main algo
*/

void				quicksort(int *arr, int first, int last);
void				preparing_ab(t_ab *ab, int size);

/*
**			helpers
**   count steps for algo
*/
long				ft_longatoi(const char *str);
void				ini_zero(t_list *list);
void				inicial(t_ab *ab);
int					*create_array(t_list **a_or_b, int last);
int					*create_arr_from_list(t_list **a_list, int stack_len);

/*
**         count
**     steps for algo
*/

void				count_step_b(t_ab *ab);
void				count_step_b_last(t_ab *ab);
int					compare_al(int	*a_list, int last, int i, t_list *b);
int					compare_ar(int	*a_list, int i, int	last, t_list *b);
int					count_run_al(t_list **a, t_list **b_elem);
int					count_run_ar(t_list **a, t_list **b_elem);
int					count_run_al_last(t_list **a, t_list **b_elem);
int					count_run_ar_last(t_list **a, t_list **b_elem);
int					find_the_res(t_list **b_list);
int					find_best(t_ab *ab);

/*
**       write order
**        to algoritm
*/

void				create_moving_order_l(int nbr, t_ab *ab, t_order *com);
void				create_moving_order(int nbr, t_ab *ab, t_order *com);
void				write_order_command_l(t_list **b, t_order *com);
void				write_order_command(t_list **b, t_order *com);
void				inicial_order_list(t_order *com);

/*
**                                 PART FIVE
**                                   FINAL
*/

/*
** main algoritm and others
**  for push swap program
*/

void				run_commander(t_ab *ab);
void				main_algoritm(t_ab *ab);
void				finish_a(t_ab *ab);
int					check_order(t_list **a);

/*
**		run operators
**   for checker program
*/

int					run_operators_i(char *line, t_list **ar, t_list **br);

/*
**   here free functions
**    for lists, int arrs
*/

void				ft_lst_free_chain(t_list **chain);
void				ft_free_struct(t_ab *ab);
void				free_int_arr(int **a_arr);
int					len_of_list(t_list **list);
int					medi(int *arr, int last_index);
int					size_of_list(t_list **list);
int					f_min(t_list	**list);
int					f_max(t_list	**list);
int					size_of_list_i(t_list *list);
t_ab				*pars_and_check(char **argv, int argc);

#endif
