/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_cases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xredm <xredm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:38:42 by xredm             #+#    #+#             */
/*   Updated: 2023/07/07 17:44:23 by xredm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// perform rotation of both stacks in the same direction needed amount of times
int	apply_ra_rb(t_stack **a, t_stack **b, int num, char c)
{
	if (c == 'a')
	{
		while ((*a)->content != num && find_place_in_b(*b, num) > 0)
			rr(a, b, 0);
		while ((*a)->content != num)
			ra(a, 0);
		while (find_place_in_b(*b, num) > 0)
			rb(b, 0);
		pb(a, b, 0);
	}
	else
	{
		while ((*b)->content != num && find_place_in_a(*a, num) > 0)
			rr(a, b, 0);
		while ((*b)->content != num)
			rb(b, 0);
		while (find_place_in_a(*a, num) > 0)
			ra(a, 0);
		pa(a, b, 0);
	}
	return (-1);
}

// apply reverse rotation of both stacks needed amount of times
int	apply_rra_rrb(t_stack **a, t_stack **b, int num, char c)
{
	if (c == 'a')
	{
		while ((*a)->content != num && find_place_in_b(*b, num) > 0)
			rrr(a, b, 0);
		while ((*a)->content != num)
			rra(a, 0);
		while (find_place_in_b(*b, num) > 0)
			rrb(b, 0);
		pb(a, b, 0);
	}
	else
	{
		while ((*b)->content != num && find_place_in_a(*a, num) > 0)
			rrr(a, b, 0);
		while ((*b)->content != num)
			rrb(b, 0);
		while (find_place_in_a(*a, num) > 0)
			rra(a, 0);
		pa(a, b, 0);
	}
	return (-1);
}

// rotate stack a and reverse rotate b needed amount of times
int	apply_ra_rrb(t_stack **a, t_stack **b, int num, char c)
{
	if (c == 'a')
	{
		while ((*a)->content != num)
			ra(a, 0);
		while (find_place_in_b(*b, num) > 0)
			rrb(b, 0);
		pb(a, b, 0);
	}
	else
	{
		while (find_place_in_a(*a, num) > 0)
			ra(a, 0);
		while ((*b)->content != num)
			rrb(b, 0);
		pa(a, b, 0);
	}
	return (-1);
}

// reverse rotate stack a and rotate b needed amount of times
int	apply_rra_rb(t_stack **a, t_stack **b, int num, char c)
{
	if (c == 'a')
	{
		while ((*a)->content != num)
			rra(a, 0);
		while (find_place_in_b(*b, num) > 0)
			rb(b, 0);
		pb(a, b, 0);
	}
	else
	{
		while (find_place_in_a(*a, num) > 0)
			rra(a, 0);
		while ((*b)->content != num)
			rb(b, 0);
		pa(a, b, 0);
	}
	return (-1);
}
