/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stacks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sellyani <sellyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:31:19 by sellyani          #+#    #+#             */
/*   Updated: 2025/03/06 19:31:19 by sellyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	target_node(t_stack *a, t_stack *b)
{
	t_stack	*target_node;
	long	top_index;
	t_stack	*node_a;

	while (b)
	{
		top_index = LONG_MAX;
		node_a = a;
		while (node_a)
		{
			if (node_a->value > b->value && node_a->value < top_index)
			{
				top_index = node_a->value;
				target_node = node_a;
			}
			node_a = node_a->next;
		}
		if (top_index == LONG_MAX)
			b->target_node = smaller(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	price_node_utils(t_stack *a, t_stack *b, int len_a, int len_b)
{
	int	index_a;
	int	index_b;

	(void)a;
	if (b->medlin && b->target_node->medlin)
	{
		if (b->index >= b->target_node->index)
			b->price = b->target_node->index
				+ (b->index - b->target_node->index);
		else if (b->index < b->target_node->index)
			b->price = b->index + (b->target_node->index - b->index);
	}
	else if (!b->medlin && !b->target_node->medlin)
	{
		index_a = len_a - b->target_node->index;
		index_b = len_b - b->index;
		if (index_b >= index_a)
			b->price = index_a + (index_b - index_a);
		else if (index_b < index_a)
			b->price = index_b + (index_a - index_b);
	}
}

void	price_node(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = size_stack(a);
	len_b = size_stack(b);
	while (b)
	{
		b->price = b->index;
		if (!(b->medlin))
			b->price = len_b - (b->index);
		if (b->target_node->medlin)
			b->price += b->target_node->index;
		else
			b->price += len_a - b->target_node->index;
		price_node_utils(a, b, len_a, len_b);
		b = b->next;
	}
}

void	cheapest_node(t_stack *b)
{
	long	cheap;
	t_stack	*node_cheap;

	if (!b)
		return ;
	cheap = LONG_MAX;
	while (b)
	{
		if (b->price < cheap)
		{
			cheap = b->price;
			node_cheap = b;
		}
		b = b->next;
	}
	node_cheap->cheapest = true;
}

void	big_stack(t_stack **a, t_stack **b)
{
	t_stack	*small_node;

	while (size_stack(*a) > 3)
		pb(b, a, true);
	sort_3(a);
	while (*b)
	{
		init_stack(a, b);
		move_node(a, b);
	}
	sort_index(*a);
	small_node = smaller(*a);
	if (small_node->medlin)
	{
		while (*a != small_node)
			ra(a, true);
	}
	else
	{
		while (*a != small_node)
			rra(a, true);
	}
}
