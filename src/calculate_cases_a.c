/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cases_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xredm <xredm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:01:50 by xredm             #+#    #+#             */
/*   Updated: 2023/07/07 17:41:11 by xredm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// calc num of rotations for the case ra rb
int	case_ra_rb_a(t_stack *a, t_stack *b, int num)
{
	int	i;

	i = find_place_in_a(a, num);
	if (i < get_index(b, num))
		i = get_index(b, num);
	return (i);
}

//calc num of rotations for the case rra rrb
int	case_rra_rrb_a(t_stack *a, t_stack *b, int num)
{
	int	i;

	i = 0;
	if (find_place_in_a(a, num))
		i = stack_size(a) - find_place_in_a(a, num);
	if (i < (stack_size(b) - get_index(b, num)) && get_index(b, num))
		i = stack_size(b) - get_index(b, num);
	return (i);
}

// calc num of rotations for the case ra rrb
int	case_ra_rrb_a(t_stack *a, t_stack *b, int num)
{
	int	i;

	i = 0;
	if (get_index(b, num))
		i = stack_size(b) - get_index(b, num);
	i += find_place_in_a(a, num);
	return (i);
}

// calc num of rotations for the case rra rb
int	case_rra_rb_a(t_stack *a, t_stack *b, int num)
{
	int	i;

	i = 0;
	if (find_place_in_a(a, num))
		i = stack_size(a) - find_place_in_a(a, num);
	i += get_index(b, num);
	return (i);
}
