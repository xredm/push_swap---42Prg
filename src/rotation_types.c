/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_types.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xredm <xredm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:09:29 by xredm             #+#    #+#             */
/*   Updated: 2023/07/07 16:54:34 by xredm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
//here we decide which comb is the best from a to b
int	rotation_type2b(t_stack *a, t_stack *b)
{
	int	i;
	t_stack	*tmp;

	tmp = a;
	i = case_rra_rrb_b(a, b, a->content);
	while (tmp)
	{
		if (i > case_ra_rb_b(a, b, tmp->content))
			i = case_ra_rb_b(a, b, tmp->content);
		if (i > case_rra_rrb_b(a, b, tmp->content))
			i = case_rra_rrb_b(a, b, tmp->content);
		if (i > case_ra_rrb_b(a, b, tmp->content))
			i = case_ra_rrb_b(a, b, tmp->content);
		if (i > case_rra_rb_b(a, b, tmp->content))
			i = case_rra_rb_b(a, b, tmp->content);
		tmp = tmp->next;
	}
	return (i);
}
// here we choose which comb for rotation is the best fitting from B to A
int	rotation_type2a(t_stack *a, t_stack *b)
{
	int	i;
	t_stack	*tmp;

	tmp = b;
	i = case_rra_rrb_a(a, b, b->content);
	while (tmp)
	{
		if (i > case_ra_rb_a(a, b, tmp->content))
			i = case_ra_rb_a(a, b, tmp->content);
		if (i > case_rra_rrb_a(a, b, tmp->content))
			i = case_rra_rrb_a(a, b, tmp->content);
		if (i > case_ra_rrb_a(a, b, tmp->content))
			i = case_ra_rrb_a(a, b, tmp->content);
		if (i > case_rra_rb_a(a, b, tmp->content))
			i = case_rra_rb_a(a, b, tmp->content);
		tmp = tmp->next;
	}
	return (i);
}