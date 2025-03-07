/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sellyani <sellyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:39:38 by sellyani          #+#    #+#             */
/*   Updated: 2025/02/09 20:39:38 by sellyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack **a, t_stack **b)
{
	sort_index(*a);
	sort_index(*b);
	target_node(*a, *b);
	price_node(*a, *b);
	cheapest_node(*b);
}

static t_stack	*lstnew(char *content, int index)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (new_node == NULL)
		return (NULL);
	new_node->value = ft_atoi(content);
	new_node->index = index;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_stack	*lstlast(t_stack *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next != NULL)
		head = head->next;
	return (head);
}

static void	lstadd_back(t_stack **head, t_stack *new_node)
{
	t_stack	*tmp;

	if (!head || new_node == NULL)
		return ;
	tmp = lstlast(*head);
	if (*head != NULL)
	{
		tmp->next = new_node;
		new_node->prev = tmp;
	}
	else
	{
		*head = new_node;
		new_node->prev = NULL;
	}
}

t_stack	*ft_list(char **sp)
{
	t_stack	*a;
	int		i;

	i = 0;
	a = NULL;
	while (sp[i])
	{
		lstadd_back(&a, lstnew(sp[i], i));
		free(sp[i]);
		i++;
	}
	free(sp);
	return (a);
}
