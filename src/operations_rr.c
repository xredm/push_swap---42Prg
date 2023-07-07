/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xredm <xredm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 13:34:48 by xredm             #+#    #+#             */
/*   Updated: 2023/07/07 16:51:56 by xredm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rr_apply(t_stack **s)
{
	t_stack	*temp;
	int		i;

	if (!*s || !(*s)->next)
		return ;
	i = 0;
	temp = *s;
	while ((*s)->next)
	{
		*s = (*s)->next;
		i++;
	}
	(*s)->next = temp;
	while (i > 1)
	{
		temp = temp->next;
		i--;
	}
	temp->next = NULL;
}
// reverse rotate a by shifting all elements by 1 down, last becomes first
void	rra(t_stack **a, int flag)
{
	rr_apply(a);
	if (flag == 0)
		ft_printf("rra\n");
}
//reverse rotate b by shifting them all by 1 down, last one becomes first
void	rrb(t_stack **b, int flag)
{
	rr_apply(b);
	if (flag == 0)
		ft_printf("rrb\n");
}
void	rrr(t_stack **a, t_stack **b, int flag)
{
	rr_apply(a);
	rr_apply(b);
	if (flag == 0)
		ft_printf("rrr\n");
}