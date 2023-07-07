/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xredm <xredm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 13:34:48 by xredm             #+#    #+#             */
/*   Updated: 2023/06/18 15:25:14 by xredm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// reverse rotate a by shifting all elements by 1 down, last becomes first
void	rra(t_stack **a, int flag)
{
	t_stack	*tmp;
	int	i;

	i = 0;
	if (!*a || !((*a)->next))
		return ;
	tmp = *a;
	while ((*a)->next)
	{
		*a = (*a)->next;
		i++;
	}
	(*a)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	if (flag == 0)
		write(1, "rra\n", 4);
}

//reverse rotate b by shifting them all by 1 down, last one becomes first
void	rrb(t_stack **b, int flag)
{
	t_stack	*tmp;
	int	i;

	i = 0;
	if (!*b || !((*b)->next))
		return ;
	tmp = *b;
	while ((*b)->next)
	{
		*b = (*b)->next;
		i++;
	}
	(*b)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	if (flag == 0)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, int flag)
{
	if (!*a || !*b || !((*a)->next) || !((*b)->next))
		return ;
	rra(a, 1);
	rrb(b, 1);
	if (flag == 0)
		write(1, "rrr\n", 4);
}