/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xredm <xredm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:39:38 by xredm             #+#    #+#             */
/*   Updated: 2023/07/07 17:42:59 by xredm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//apply swap
void	s_apply(t_stack **s)
{
	t_stack	*temp;

	if (!*s || !((*s)->next))
		return ;
	temp = *s;
	*s = (*s)->next;
	temp->next = (*s)->next;
	(*s)->next = temp;
}

//swaps 2 elements on top of the stack a, in case of 1 or no elements do nothing
void	sa(t_stack **a, int flag)
{
	s_apply(a);
	if (flag == 0)
		ft_printf("sa\n");
}

//swaps 2 elementsw on top of b, do nothing if there is 1 or none
void	sb(t_stack **b, int flag)
{
	s_apply(b);
	if (flag == 0)
		ft_printf("sb\n");
}

// swap a and swap b (top 2 elements) at the same time
void	ss(t_stack **a, t_stack **b, int flag)
{
	s_apply(a);
	s_apply(b);
	if (flag == 0)
		ft_printf("ss\n");
}
