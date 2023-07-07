/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xredm <xredm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:17:18 by xredm             #+#    #+#             */
/*   Updated: 2023/07/07 12:56:32 by xredm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// here we find the index of the num we need
int	get_index(t_stack *stack, int num)
{
	int	index;

	index = 0;
	while (stack->content != num)
	{
		stack = stack->next;
		index++;
	}
	return (index);
}

//points to last element if the stack
t_stack	*find_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

// returns the size of the stack
int	stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

// finds and returns min val
int	min_val(t_stack *stack)
{
	int	min;

	min = stack->content;
	while (stack)
	{
		if (min > (stack->content))
		{
			min = stack->content;
		}
		stack = stack->next;
	}
	return (min);
}

// finds and returns max val
int	max_val(t_stack *stack)
{
	int	max;

	max = stack->content;
	while (stack)
	{
		if (max < (stack->content))
		{
			max = stack->content;
		}
		stack = stack->next;
	}
	return (max);
}

