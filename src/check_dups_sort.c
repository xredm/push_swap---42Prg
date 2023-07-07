/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dups_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xredm <xredm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:40:25 by xredm             #+#    #+#             */
/*   Updated: 2023/07/07 16:50:15 by xredm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
// we check if current node's value isn't bigger than next one ret 1 if sorted
int is_sorted(t_stack *stack)
{
	int	value;

	value = stack->content;
	while (stack)
	{
		if (value > stack->content)
		{
			return (0);
		}
		value = stack->content;
		stack = stack->next;
	}
	return (1);
}
//compares a node to with others -> goes to next node and does it till all done
int	is_duplicate(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (stack->content == tmp->content)
				return (1);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (0);
}