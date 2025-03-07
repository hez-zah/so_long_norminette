/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sellyani <sellyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 00:42:38 by sellyani          #+#    #+#             */
/*   Updated: 2025/03/07 00:55:56 by sellyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	aid_put_image(t_map *slong, int i, int j)
{
	if (slong->map[i][j] == '1')
	{
		slong->mlx_img = mlx_xpm_file_to_image(slong->mlx, WALL,
				&slong->h_map, &slong->w_map);
		mlx_put_image_to_Window(slong->mlx, slong->mlx_win,
			slong->mlx_img, j * SIZE, i * SIZE);
	}
	else if (slong->map[i][j] == '0')
	{
		slong->mlx_img = mlx_xpm_file_to_image(slong->mlx, SPACE,
				&slong->h_map, &slong->w_map);
		mlx_put_image_to_window(slong->mlx, slong->mlx_win,
			slong->mlx_img, j * SIZE, i * SIZE);
	}
	else if (slong->map[i][j] == 'P')
	{
		slong->mlx_img = mlx_xpm_file_to_image(slong->mlx, PMAN_D,
				&slong->h_map, &slong->w_map);
		mlx_put_image_to_window(slong->mlx, slong->mlx_win,
			slong->mlx_img, j * SIZE, i * SIZE);
	}
	else if (slong->map[i][j] == 'C')
	{
		slong->mlx_img = mlx_xpm_file_to_image(slong->mlx, COLLECT,
				&slong->h_map, &slong->w_map);
		mlx_put_image_to_window(slong->mlx, slong->mlx_win,
			slong->mlx_img, j * SIZE, i * SIZE);
	}
	else if (slong->map[i][j] == 'E')
	{
		slong->mlx_img = mlx_xpm_file_to_image(slong->mlx, CDOOR,
				&slong->h_map, &slong->w_map);
		mlx_put_image_to_window(slong->mlx, slong->mlx_win,
			slong->mlx_img, j * SIZE, i * SIZE);
	}
}

void	put_image(t_map *slong)
{
	int	i;
	int	j;

	i = -1;
	while (slong->map[++i])
	{
		j = -1;
		while (slong->map[i][++j])
			aid_put_image(slong, i, j);
	}
}
