/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sellyani <sellyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:13:44 by sellyani          #+#    #+#             */
/*   Updated: 2025/02/13 20:16:49 by sellyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_cheapest_node(t_stack *b)
{
	t_stack	*cheap_node;

	if (!b)
		return (NULL);
	cheap_node = b;
	while (b)
	{
		if (b->cheapest)
			cheap_node = b;
		b = b->next;
	}
	return (cheap_node);
}

static void	double_rotate(t_stack **a, t_stack **b, t_stack *cheap_node)
{
	while (*a != cheap_node->target_node && *b != cheap_node)
		rr(a, b, true);
	sort_index(*a);
	sort_index(*b);
}

static void	reverse_double_rotate(t_stack **a, t_stack **b, t_stack *cheap_node)
{
	while (*a != cheap_node->target_node && *b != cheap_node)
		rrr(a, b, true);
	sort_index(*a);
	sort_index(*b);
}

void	last_rotate(t_stack **head, t_stack *top_node, char name)
{
	while (*head != top_node)
	{
		if (name == 'a')
		{
			if (top_node->medlin)
				ra(head, true);
			else
				rra(head, true);
		}
		else if (name == 'b')
		{
			if (top_node->medlin)
				rb(head, true);
			else
				rrb(head, true);
		}
	}
}

void	move_node(t_stack **a, t_stack **b)
{
	t_stack	*cheap_node;

	cheap_node = get_cheapest_node(*b);
	if (cheap_node->medlin && cheap_node->target_node->medlin)
		double_rotate(a, b, cheap_node);
	else if (!(cheap_node->medlin) && !(cheap_node->target_node->medlin))
		reverse_double_rotate(a, b, cheap_node);
	last_rotate(b, cheap_node, 'b');
	last_rotate(a, cheap_node->target_node, 'a');
	pa(a, b, true);
}
