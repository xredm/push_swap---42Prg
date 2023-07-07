/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xredm <xredm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:25:55 by xredm             #+#    #+#             */
/*   Updated: 2023/07/07 16:42:45 by xredm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	long    content;
	struct s_stack  *next;
}   t_stack;

t_stack *fill_stack(int ac, char **av);
void	print_prompt(void);
void	print_error(void);
t_stack	*fill_42(char **av);
int	modified_atoi(const char *arr);
void	add_node_back(t_stack **stack, t_stack *new);
t_stack	*create_new_node(int element);
void	free_stack(t_stack **stack);
int	is_duplicate(t_stack *stack);
t_stack	*find_last(t_stack *stack);
int is_sorted(t_stack *stack);
void	sort_stacks(t_stack **stack_a);
int	stack_size(t_stack *stack);
void	sa(t_stack **a, int	flag);
int	min_val(t_stack *stack);
int	max_val(t_stack *stack);
int	get_index(t_stack *stack, int num);
t_stack	*sort_b(t_stack **a);
void	pb(t_stack **a, t_stack **b, int flag);
void	push_sort_b_till3(t_stack **a, t_stack **b);
int	rotation_type2b(t_stack *a, t_stack *b);
int	rotation_type2a(t_stack *a, t_stack *b);
int	find_place_in_b(t_stack *b, int num);
int	find_place_in_a(t_stack *a, int num);
int	case_ra_rb_b(t_stack *a, t_stack *b, int num);
int	case_ra_rb_a(t_stack *a, t_stack *b, int num);
int	case_rra_rrb_b(t_stack *a, t_stack *b, int num);
int	case_rra_rrb_a(t_stack *a, t_stack *b, int num);
int	case_ra_rrb_b(t_stack *a, t_stack *b, int num);
int	case_ra_rrb_a(t_stack *a, t_stack *b, int num);
int	case_rra_rb_b(t_stack *a, t_stack *b, int num);
int	case_rra_rb_a(t_stack *a, t_stack *b, int num);
t_stack	**sort_a(t_stack **a, t_stack **b);
int	apply_ra_rb(t_stack **a, t_stack **b, int num, char c);
int	apply_rra_rrb(t_stack **a, t_stack **b, int num, char c);
int	apply_ra_rrb(t_stack **a, t_stack **b, int num, char c);
int	apply_rra_rb(t_stack **a, t_stack **b, int num, char c);
void	sort_for_three(t_stack **a);
void	ss(t_stack **a, t_stack **b, int flag);
void	pa(t_stack **a, t_stack **b, int flag);
void	rra(t_stack **a, int flag);
void	rrb(t_stack **b, int flag);
void	ra(t_stack **a, int flag);
void	rb(t_stack **b, int flag);
void	rr(t_stack **a, t_stack **b, int flag);
void	rrr(t_stack **a, t_stack **b, int flag);
void	sb(t_stack **b, int flag);
void	free_str(char **str);
void	s_apply(t_stack **s);
void	r_apply(t_stack **s);
void	rr_apply(t_stack **s);
void	p_apply(t_stack **first, t_stack **second);

#endif