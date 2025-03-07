/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sellyani <sellyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:40:36 by sellyani          #+#    #+#             */
/*   Updated: 2025/02/09 20:40:36 by sellyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **head)
{
	t_stack	*tmp;

	if (!head || !(*head) || !(*head)->next)
		return ;
	tmp = lstlast(*head);
	tmp->prev->next = NULL;
	tmp->next = *head;
	(*head)->prev = tmp;
	tmp->prev = NULL;
	*head = tmp;
}

void	rra(t_stack **a, bool check)
{
	reverse_rotate(a);
	if (check)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, bool check)
{
	reverse_rotate(b);
	if (check)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, bool check)
{
	rra(a, false);
	rrb(b, false);
	if (check)
		write(1, "rrr\n", 4);
}
