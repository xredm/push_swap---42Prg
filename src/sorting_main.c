/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xredm <xredm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:59:27 by xredm             #+#    #+#             */
/*   Updated: 2023/07/07 16:53:22 by xredm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
// mini sort for only 3 elements
void	sort_for_three(t_stack **a)
{
	if (min_val(*a) == (*a)->content)
	{
		rra(a, 0);
		sa(a, 0);
	}
	else if (max_val(*a) == (*a)->content)
	{
		ra(a, 0);
		if (!is_sorted(*a))
			sa(a, 0);
	}
	else
	{
		if (get_index(*a, max_val(*a)) == 1)
			rra(a, 0);
		else
			sa(a, 0);
	}
}
// reduces stack a, till there are 3 elements 
void	push_sort_b_till3(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int	i;

	while(stack_size(*a) > 3 && !is_sorted(*a))
	{
		tmp = *a;
		i = rotation_type2b(*a, *b);
		while (i >= 0)
		{
			if (i == case_ra_rb_b(*a, *b, tmp->content))
				i = apply_ra_rb(a, b, tmp->content, 'a');
			else if (i == case_rra_rrb_b(*a, *b, tmp->content))
				i = apply_rra_rrb(a, b, tmp->content, 'a');
			else if (i == case_ra_rrb_b(*a, *b, tmp->content))
				i = apply_ra_rrb(a, b, tmp->content, 'a');
			else if (i == case_rra_rb_b(*a, *b, tmp->content))
				i = apply_rra_rb(a, b, tmp->content, 'a');
			else
				tmp = tmp->next;
		}
	}
}
// for b we ll stast pushing elements from stack a until there are 3 left  in a
// when push - we sort in stack b
// when 3 left in stack a, we sort 'em
t_stack	*sort_b(t_stack **a)
{
	t_stack	*b;

	b = NULL;
	if (stack_size(*a) > 3 && !is_sorted(*a))
		pb(a, &b, 0);
	if (stack_size(*a) > 3 && !is_sorted(*a))
		pb(a, &b, 0);
	if (stack_size(*a) > 3 && !is_sorted(*a))
		push_sort_b_till3(a, &b);
	if (!is_sorted(*a))
		sort_for_three(a);
	return (b);
}
// using this we push all the elements from stack b to a and till there are none
t_stack	**sort_a(t_stack **a, t_stack **b)
{
	int	i;
	t_stack	*tmp;

	while (*b)
	{
		tmp = *b;
		i = rotation_type2a(*a, *b);
		while (i >= 0)
		{
			if (i == case_ra_rb_a(*a, *b, tmp->content))
				i = apply_ra_rb(a, b, tmp->content, 'b');
			else if (i == case_rra_rrb_a(*a, *b, tmp->content))
				i = apply_rra_rrb(a, b, tmp->content, 'b');
			else if (i == case_ra_rrb_a(*a, *b, tmp->content))
				i = apply_ra_rrb(a, b, tmp->content, 'b');
			else if (i == case_rra_rb_a(*a, *b, tmp->content))
				i = apply_rra_rb(a, b, tmp->content, 'b');
			else
				tmp = tmp->next;
		}
	}
	return (a);
}
void	sort_stacks(t_stack **a)
{
	int	i;
	t_stack	*b;

	b = NULL;
	if (stack_size(*a) == 2)
	{
		sa(a, 0);
	}
	else
	{
		i = get_index(*a, min_val(*a));
		b = sort_b(a);
		a = sort_a(a, &b);
		if (i < (stack_size(*a) - i))
		{
			while ((*a)->content != min_val(*a))
			{
				ra(a, 0);
			}
		}
		else
		{
			while((*a)->content != min_val(*a))
			{
				rra(a, 0);
			}
		}
	}
}