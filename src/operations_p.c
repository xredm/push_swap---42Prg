/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xredm <xredm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 13:33:41 by xredm             #+#    #+#             */
/*   Updated: 2023/07/07 16:51:14 by xredm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
void	p_apply(t_stack **first, t_stack **second)
{
	t_stack	*temp;

	if (!*second)
		return ;
	temp = *first;
	*first = *second;
	*second = (*second)->next;
	(*first)->next = temp;
}
//pushes top element from 'a' to top of the 'b' 
void	pb(t_stack **a, t_stack **b, int flag)
{
	p_apply(b, a);
	if (flag == 0)
		ft_printf("pb\n");
}
//push the top element of b to a, do nothing id stack is empty
void	pa(t_stack **a, t_stack **b, int flag)
{
	p_apply(a, b);
	if (flag == 0)
		ft_printf("pa\n");
}