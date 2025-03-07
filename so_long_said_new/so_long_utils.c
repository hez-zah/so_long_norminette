/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sellyani <sellyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 00:46:14 by sellyani          #+#    #+#             */
/*   Updated: 2025/03/07 00:46:31 by sellyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	fr_stack(t_map *slong)
{
	while (*(slong->map))
	{
		free(*(slong->map));
		(slong->map)++;
	}
}

char	**copy_map(char **map)
{
	char	**cp_map;
	char	*line;
	char	*aid_line;
	char	*fr_line;
	int		i;

	line = ft_strdup("");
	i = -1;
	while (map[++i])
	{
		fr_line = line;
		aid_line = ft_strjoin(line, "\n");
		line = ft_strjoin(aid_line, map[i]);
		free(fr_line);
		free(aid_line);
	}
	cp_map = ft_split(line, '\n');
	free(line);
	return (cp_map);
}

int	ft_exit(t_map *slong)
{
	ft_putstr_fd("Exit\n", 1);
	exit(0);
	return (0);
}

bool	get_enemy_position(t_map **slong)
{
	int	i;
	int	j;

	i = -1;
	while ((*slong)->map[++i])
	{
		j = -1;
		while ((*slong)->map[i][++j])
		{
			if ((*slong)->map[i][j] == '0' &&
				(*slong)->map[i][j + 1] == '0' &&
				(*slong)->map[i][j + 2] == '0')
			{
				(*slong)->x_enemy = i;
				(*slong)->y_enemy = j;
				return (true);
			}
		}
	}
	return (false);
}
