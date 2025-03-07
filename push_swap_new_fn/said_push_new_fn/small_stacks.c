/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sellyani <sellyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:40:43 by sellyani          #+#    #+#             */
/*   Updated: 2025/02/09 20:40:43 by sellyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_index(t_stack *head)
{
	int	i;
	int	len_head;

	if (!head)
		return ;
	len_head = size_stack(head);
	i = 0;
	while (head)
	{
		head->index = i;
		if (head->index <= (len_head / 2))
			head->medlin = true;
		else
			head->medlin = false;
		head = head->next;
		i++;
	}
}

void	sort_3(t_stack **head)
{
	t_stack	*big;

	big = biggest(*head);
	if (*head == big)
		ra(head, true);
	else if ((*head)->next == big)
		rra(head, true);
	if ((*head)->value > (*head)->next->value)
		sa(head, true);
}

static void	sort_4(t_stack **a, t_stack **b)
{
	int		indx;
	t_stack	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp == smaller(*a))
			indx = tmp->index;
		tmp = tmp->next;
	}
	if (indx == 1)
		ra(a, true);
	else if (indx == 2)
	{
		ra(a, true);
		ra(a, true);
	}
	else if (indx == 3)
		rra(a, true);
	pb(b, a, true);
	sort_3(a);
	pa(a, b, true);
}

void	small_stack(t_stack **a, t_stack **b)
{
	if (size_stack(*a) == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a, true);
	}
	else if (size_stack(*a) == 3)
		sort_3(a);
	else if (size_stack(*a) == 4)
		sort_4(a, b);
}
