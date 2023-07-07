/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xredm <xredm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:12:53 by xredm             #+#    #+#             */
/*   Updated: 2023/07/07 17:45:21 by xredm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// find index of the element to push in B
int	find_place_in_b(t_stack *b, int num)
{
	t_stack	*tmp;
	int		i;

	i = 1;
	if ((num > (b->content)) && (num < (find_last(b)->content)))
		i = 0;
	else if ((num > max_val(b)) || (num < min_val(b)))
		i = get_index(b, max_val(b));
	else
	{
		tmp = b->next;
		while (((b->content) < num) || ((tmp->content) > num))
		{
			b = b->next;
			tmp = b->next;
			i++;
		}
	}
	return (i);
}

// we find the index of the number when we push it to A
int	find_place_in_a(t_stack *a, int num)
{
	t_stack	*tmp;
	int		i;

	i = 1;
	if (num < (a->content) && num > (find_last(a)->content))
		i = 0;
	else if (num > max_val(a) || num < min_val(a))
		i = get_index(a, min_val(a));
	else
	{
		tmp = a->next;
		while (a->content > num || tmp->content < num)
		{
			a = a->next;
			tmp = a->next;
			i++;
		}
	}
	return (i);
}

void	free_str(char **str)
{
	char	*a;

	if (!str)
		return ;
	while (*str)
	{
		a = *str;
		str++;
		free(a);
	}
	*str = NULL;
}
