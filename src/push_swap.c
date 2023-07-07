/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xredm <xredm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:51:20 by xredm             #+#    #+#             */
/*   Updated: 2023/07/07 16:52:42 by xredm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
// Freeing the stack before we are done
// storing the pointer to nex tode in tmp_ptr and cleaning and so on
void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		(*stack)->content = 0; 
		free(*stack);
		*stack = tmp;
	}
}
//Subject says in case of 0 params - program must not output anything but prompt
void	print_prompt(void)
{
	ft_printf("Sadly you have not entered anything, please try again ;(\n");
	exit(1);
}
// In case of error we print the error message
void	print_error(void)
{
	ft_printf("Error\n");
	exit(1);
}
// 1. here we assign the inputs and check for errors, dups and if is sorted
// 2. if not we sort and then free ofc
int	main(int ac, char **av)
{
	t_stack	*stack;

	if (ac < 2)
		print_prompt();
	stack = fill_stack(ac, av);
	if (!stack || is_duplicate(stack))
	{
		free_stack(&stack);
		print_error();
	}
	if (!is_sorted(stack))
	{
		sort_stacks(&stack);
	}
	free_stack(&stack);
	return (0);
}
