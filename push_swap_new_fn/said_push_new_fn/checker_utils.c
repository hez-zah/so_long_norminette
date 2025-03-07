/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sellyani <sellyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 01:00:28 by sellyani          #+#    #+#             */
/*   Updated: 2025/02/18 15:10:59 by sellyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	**get_moves(t_stack *head)
{
	char	*line;
	char	*fr1_line;
	char	*fr2_line;
	char	**sp;

	line = ft_strdup("");
	(void)head;
	while (1)
	{
		fr1_line = line;
		fr2_line = get_next_line(0);
		if (!fr2_line)
			break ;
		if (!check_moves(fr2_line))
			return (double_free(fr1_line, fr2_line), NULL);
		line = ft_strjoin(fr1_line, fr2_line);
		double_free(fr1_line, fr2_line);
	}
	sp = ft_split(line, '\n');
	free(line);
	return (sp);
}

bool	check_moves(char *str)
{
	if (!ft_strncmp(str, "sa\n", 3)
		|| !ft_strncmp(str, "sb\n", 3)
		|| !ft_strncmp(str, "ss\n", 3)
		|| !ft_strncmp(str, "ra\n", 3)
		|| !ft_strncmp(str, "rb\n", 3)
		|| !ft_strncmp(str, "rr\n", 3)
		|| !ft_strncmp(str, "pa\n", 3)
		|| !ft_strncmp(str, "pb\n", 3)
		|| !ft_strncmp(str, "rra\n", 4)
		|| !ft_strncmp(str, "rrb\n", 4)
		|| !ft_strncmp(str, "rrr\n", 4))
		return (true);
	return (false);
}

void	double_free(char *str1, char *str2)
{
	free(str1);
	free(str2);
}
