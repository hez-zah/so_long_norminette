/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handl_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sellyani <sellyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:40:11 by sellyani          #+#    #+#             */
/*   Updated: 2025/02/09 20:40:11 by sellyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**line_arg(char *str, char **sp)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			break ;
		i++;
	}
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	sp = ft_split(str, ' ');
	free(str);
	return (sp);
}

static char	**split_arg(int ac, char **av)
{
	char	*line;
	char	*temp_line;
	char	*temp_line2;
	char	**sp;
	int		i;

	i = 1;
	line = ft_strdup("");
	sp = NULL;
	while (i < ac)
	{
		temp_line = line;
		free_arg(av, line, i);
		temp_line2 = ft_strjoin(av[i], " ");
		line = ft_strjoin(temp_line, temp_line2);
		free(temp_line);
		free(temp_line2);
		i++;
	}
	sp = line_arg(line, sp);
	return (sp);
}

static int	ft_is_number(char *str)
{
	int	i;

	i = 0;
	if (str == NULL || *str == '\0')
		return (0);
	if ((str[i] == '-' || str[i] == '+') && str[i] && ft_isdigit(str[i + 1]))
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static char	**check_number(char **sp, int num, int i)
{
	int	j;

	if (!ft_is_number(sp[i]))
	{
		free_memory(sp);
		return (ft_putendl_fd("Error", 2), NULL);
	}
	num = ft_atoi(sp[i]);
	if (num > INT_MAX || num < INT_MIN)
	{
		free_memory(sp);
		return (ft_putendl_fd("Error", 2), NULL);
	}
	j = i + 1;
	while (sp[j])
	{
		if (num == ft_atoi(sp[j]))
		{
			free_memory(sp);
			return (ft_putendl_fd("Error", 2), NULL);
		}
		j++;
	}
	return (sp);
}

char	**ft_validate_input(int ac, char **av)
{
	int		i;
	int		num;
	char	**sp;

	i = 0;
	num = 0;
	sp = split_arg(ac, av);
	if (!sp || !(*sp))
		return (ft_putendl_fd("Error", 2), NULL);
	while (sp[i])
	{
		sp = check_number(sp, num, i);
		if (!sp)
			break ;
		i++;
	}
	return (sp);
}
