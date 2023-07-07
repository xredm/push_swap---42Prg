/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xredm <xredm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:27:53 by xredm             #+#    #+#             */
/*   Updated: 2023/06/18 15:22:40 by xredm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// rotate a by shifting all elements up by 1, first element becomes last
void	ra(t_stack **a, int flag)
{
	t_stack	*tmp;

	if (!*a || !((*a)->next))
		return ;
	tmp = *a;
	*a = find_last(*a);
	(*a)->next = tmp;
	*a = tmp->next;
	tmp->next = NULL;
	if (flag == 0)
		write(1, "ra\n", 3);
}
// rotate b by shifting all elements up by 1, first element becomes last
void	rb(t_stack **b, int flag)
{
	t_stack	*tmp;

	if (!*b || !((*b)->next))
		return ;
	tmp = *b;
	*b = find_last(*b);
	(*b)->next = tmp;
	*b = tmp->next;
	tmp->next = NULL;
	if (flag == 0)
		write(1, "rb\n", 3);
}

// ra and rb at the same time
void	rr(t_stack **a, t_stack **b, int flag)
{
	if (!*a || !*b || !((*a)->next) || !((*b)->next))
		return ;
	ra(a, 1);
	rb(b, 1);
	if (flag == 0)
		write(1, "rr\n", 3);
}