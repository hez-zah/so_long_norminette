/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sellyani <sellyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 23:52:57 by sellyani          #+#    #+#             */
/*   Updated: 2025/02/18 15:52:11 by sellyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

static void	read_line(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strncmp(line, "rra", 3))
		rra(a, false);
	else if (!ft_strncmp(line, "rrb", 3))
		rrb(b, false);
	else if (!ft_strncmp(line, "rrr", 3))
		rrr(a, b, false);
	else if (!ft_strncmp(line, "sa", 2))
		sa(a, false);
	else if (!ft_strncmp(line, "sb", 2))
		sb(b, false);
	else if (!ft_strncmp(line, "ss", 2))
		ss(a, b, false);
	else if (!ft_strncmp(line, "ra", 2))
		ra(a, false);
	else if (!ft_strncmp(line, "rb", 2))
		rb(b, false);
	else if (!ft_strncmp(line, "rr", 2))
		rr(a, b, false);
	else if (!ft_strncmp(line, "pa", 2))
		pa(a, b, false);
	else if (!ft_strncmp(line, "pb", 2))
		pb(b, a, false);
}

void	set_move(t_stack **a, t_stack **b, char **lr)
{
	int	i;

	i = -1;
	while (lr[++i])
	{
		read_line(a, b, lr[i]);
		free(lr[i]);
	}
	free(lr);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**sp;
	char	**lr;

	if (ac > 1)
	{
		sp = ft_validate_input(ac, av);
		if (!sp)
			return (0);
		a = ft_list(sp);
		b = NULL;
		lr = get_moves(b);
		if (!lr)
			return (ft_putendl_fd("Error", 2), free_linkdlist(&a), 0);
		set_move(&a, &b, lr);
		if (is_sorted(a) && !b)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		free_linkdlist(&a);
	}
}
