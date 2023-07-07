/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xredm <xredm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:08:59 by xredm             #+#    #+#             */
/*   Updated: 2023/07/07 16:50:56 by xredm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
//makes a new node with the number and sets next one to NULL
t_stack	*create_new_node(int element)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		print_error();
	new->content = element;
	new->next = NULL;
	return (new);
}
//assigns a new node or a new last (adds last back)
void	add_node_back(t_stack **stack, t_stack *new)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = new;
	else
		(find_last(*stack))->next = new;
}
//differs from ft_atoi that it checks for max int and prints errors
int	modified_atoi(const char *arr)
{
	long long int	res;
	int				sign;

	res = 0;
	sign = 1;
	while (*arr == ' ' || (*arr >= 9 && *arr <= 13))
		arr++;
	if (*arr == '-')
	{
		sign *= -1;
		arr++;
	}
	else if (*arr == '+')
		arr++;
	while (*arr)
	{
		if (!ft_isdigit(*arr))
			print_error();
		res = res * 10 + (*arr - '0');
		arr++;
	}
	if ((sign * res) > 2147483647 || (sign * res) < -2147483648)
		print_error();
	return (res * sign);
}
//Here we must check if more arguments are actually passed inside the quotes
// Then add them accordingly
t_stack	*fill_42(char **av)
{
	t_stack	*input;
	char	**tmp;
	int		count;
	int		element;

	tmp = ft_split(av[1], ' ');
	count = 0;
	input = NULL;
	while (tmp[count])
	{
		element = modified_atoi(tmp[count]);
		add_node_back(&input, create_new_node(element));
		count++;
	}
	free_str(tmp);
	free(tmp);
	return (input);
}
// 1. Here we check if the number of inputs is legit or print error
// 2. if count is 2, then we fill for two
// 3. Else we check the legitimacy of the number (not > max int) then add back 
t_stack	*fill_stack(int ac, char **av)
{
	t_stack	*input;
	int		count;
	int		element;

	count = 1;
	input = NULL;
	if (ac == 2)
	{
		input = fill_42(av);
	}
	else
	{
		while (count < ac)
		{
			element = modified_atoi(av[count]);
			add_node_back(&input, create_new_node(element));
			count++;
		}
	}
	return (input);
}
