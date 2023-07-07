/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xredm <xredm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:39:38 by xredm             #+#    #+#             */
/*   Updated: 2023/06/18 15:45:41 by xredm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//swaps 2 elements on top of the stack a, in case of 1 or no elements do nothing
void	sa(t_stack **a, int	flag)
{
	t_stack	*tmp;

	if (!*a || !((*a)->next))
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	if (flag == 0)
		write(1, "sa\n", 3);
}

//swaps 2 elementsw on top of b, do nothing if there is 1 or none
void	sb(t_stack **b, int flag)
{
	t_stack	*tmp;

	if (!*b || !((*b)->next))
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	if (flag == 0)
		write(1, "sb\n", 3);
}
// swap a and swap b (top 2 elements) at the same time
void	ss(t_stack **a, t_stack **b, int flag)
{
	if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;
	sa(a, 1);
	sb(b, 1);
	if (flag == 0)
		write(1, "ss\n", 3);
}