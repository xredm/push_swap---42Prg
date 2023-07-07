/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xredm <xredm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 13:33:41 by xredm             #+#    #+#             */
/*   Updated: 2023/06/18 15:44:59 by xredm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//pushes top element from 'a' to top of the 'b' 
void	pb(t_stack **a, t_stack **b, int flag)
{
	t_stack	*tmp;

	if (!*a)
		return ;
	tmp = *b;
	*b = *a;
	*a = (*a)->next;
	(*b)->next = tmp;
	if (flag == 0)
		write(1, "pb\n", 3);
}

//push the top element of b to a, do nothing id stack is empty
void	pa(t_stack **a, t_stack **b, int flag)
{
	t_stack	*tmp;

	if (!*b)
		return ;
	tmp = *a;
	*a = *b;
	*b = (*b)->next;
	(*a)->next = tmp;
	if (flag == 0)
		write(1, "pa\n", 3);
}