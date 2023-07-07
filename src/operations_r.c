/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xredm <xredm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:27:53 by xredm             #+#    #+#             */
/*   Updated: 2023/07/07 17:36:40 by xredm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	r_apply(t_stack **s)
{
	t_stack	*temp;

	if (!*s || !(*s)->next)
		return ;
	temp = *s;
	*s = find_last(*s);
	(*s)->next = temp;
	*s = temp->next;
	temp->next = NULL;
}

// rotate a by shifting all elements up by 1, first element becomes last
void	ra(t_stack **a, int flag)
{
	r_apply(a);
	if (flag == 0)
		ft_printf("ra\n");
}

// rotate b by shifting all elements up by 1, first element becomes last
void	rb(t_stack **b, int flag)
{
	r_apply(b);
	if (flag == 0)
		ft_printf("rb\n");
}

// ra and rb at the same time
void	rr(t_stack **a, t_stack **b, int flag)
{
	r_apply(a);
	r_apply(b);
	if (flag == 0)
		ft_printf("rr\n");
}
