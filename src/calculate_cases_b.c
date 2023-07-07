/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cases_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xredm <xredm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:00:38 by xredm             #+#    #+#             */
/*   Updated: 2023/07/07 17:42:20 by xredm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// here we count how many times we can rotate stacks together, bcs its not 
// always the case and sometimes we need to rotate only one
int	case_ra_rb_b(t_stack *a, t_stack *b, int num)
{
	int	i;

	i = find_place_in_b(b, num);
	if (i < get_index(a, num))
		i = get_index(a, num);
	return (i);
}

// here we calculate how many times we reverse rotate them together
// since the rotation is reverse we calculate reverse index by
// stack size - index
int	case_rra_rrb_b(t_stack *a, t_stack *b, int num)
{
	int	i;

	i = 0;
	if (find_place_in_b(b, num))
		i = stack_size(b) - find_place_in_b(b, num);
	if (i < (stack_size(a) - get_index(a, num)) && get_index(a, num))
		i = stack_size(a) - get_index(a, num);
	return (i);
}

//we caclcualate same for ra and rrb
int	case_ra_rrb_b(t_stack *a, t_stack *b, int num)
{
	int	i;

	i = 0;
	if (find_place_in_b(b, num))
		i = stack_size(b) - find_place_in_b(b, num);
	i += get_index(a, num);
	return (i);
}

// case for rra and rb
int	case_rra_rb_b(t_stack *a, t_stack *b, int num)
{
	int	i;

	i = 0;
	if (get_index(a, num))
		i = stack_size(a) - get_index(a, num);
	i += find_place_in_b(b, num);
	return (i);
}
