/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sellyani <sellyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:40:16 by sellyani          #+#    #+#             */
/*   Updated: 2025/02/09 20:40:16 by sellyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*smaller(t_stack *head)
{
	t_stack	*small;

	if (!head)
		return (NULL);
	small = head;
	while (head)
	{
		if (head->value < small->value)
			small = head;
		head = head->next;
	}
	return (small);
}

t_stack	*biggest(t_stack *head)
{
	t_stack	*big;

	if (!head)
		return (NULL);
	big = head;
	while (head)
	{
		if (head->value > big->value)
			big = head;
		head = head->next;
	}
	return (big);
}

int	size_stack(t_stack *head)
{
	int	size;

	size = 0;
	if (!head)
		return (0);
	while (head)
	{
		size++;
		head = head->next;
	}
	return (size);
}

void	free_memory(char **sp)
{
	int	i;

	i = 0;
	while (sp[i])
	{
		free(sp[i]);
		i++;
	}
	free(sp);
}

void	free_arg(char **av, char *line, int i)
{
	char	**ptr;

	ptr = ft_split(av[i], ' ');
	if (!ptr[0])
	{
		free(line);
		free_memory(ptr);
		write(2, "Error\n", 6);
		exit(1);
	}
	free_memory(ptr);
}
