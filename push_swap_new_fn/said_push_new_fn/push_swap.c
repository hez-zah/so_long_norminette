/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sellyani <sellyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:40:20 by sellyani          #+#    #+#             */
/*   Updated: 2025/02/09 20:40:20 by sellyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
		{
			return (0);
		}
		stack = stack->next;
	}
	return (1);
}

static void	free_linkdlist(t_stack **a)
{
	t_stack	*head;

	if (!a || !*a)
		return ;
	head = *a;
	while (*a)
	{
		*a = (*a)->next;
		free(head);
		head = *a;
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	char	**sp;
	t_stack	*b;

	if (ac > 1)
	{
		sp = ft_validate_input(ac, av);
		if (!sp)
			return (1);
		a = ft_list(sp);
		b = NULL;
		if (is_sorted(a))
		{
			free_linkdlist(&a);
			(void)b;
			return (0);
		}
		if (size_stack(a) <= 4)
			small_stack(&a, &b);
		else
			big_stack(&a, &b);
		free_linkdlist(&a);
		(void)b;
	}
	return (0);
}
