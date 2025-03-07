/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sellyani <sellyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:48:51 by sellyani          #+#    #+#             */
/*   Updated: 2025/03/07 00:58:37 by sellyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_enemy(t_map *slong, int j)
{
	mlx_destroy_image(slong->mlx, slong->mlx_img);
	slong->mlx_img = mlx_xpm_file_to_image(slong->mlx,
			ENEMY, &slong->h_map, &slong->w_map);
	mlx_put_image_to_window(slong->mlx, slong->mlx_win, slong->mlx_img,
		(slong->y_enemy + j) * SIZE, slong->x_enemy * SIZE);
	mlx_destroy_image(slong->mlx, slong->mlx_img);
	slong->mlx_img = mlx_xpm_file_to_image(slong->mlx,
			SPACE, &slong->h_map, &slong->w_map);
	mlx_put_image_to_window(slong->mlx, slong->mlx_win, slong->mlx_img,
		slong->y_enemy * SIZE, slong->x_enemy * SIZE);
	if (j > 0)
		slong->y_enemy += 1;
	else
		slong->y_enemy -= 1;
}

bool	ft_lose(t_map *slong)
{
	if (slong->map[slong->x_enemy][slong->y_enemy + 1] == 'P' && slong->call)
		return (true);
	else if (slong->map[slong->x_enemy][slong->y_enemy - 1] == 'P' &&
		!slong->call)
		return (true);
	else if (slong->x_enemy == slong->x_p && slong->y_enemy == slong->y_p)
		return (true);
	return (false);
}

static int	frame_counter = 0;
const int	MOVE_INTERVAL = 5000;

int	animation(t_map **slong)
{
	frame_counter++;
	if (frame_counter >= MOVE_INTERVAL)
	{
		if (ft_strchr("1EC", (*slong)->map[(*slong)->x_enemy]
				[(*slong)->y_enemy + 1])
			|| ft_strchr("1EC", (*slong)->map[(*slong)->x_enemy]
				[(*slong)->y_enemy - 1]))
			(*slong)->call = !((*slong)->call);
		if (ft_lose(*slong))
		{
			ft_putendl_fd("Tom Eat Jerry :(", 2);
			exit(1);
		}
		if ((*slong)->call)
			put_enemy(*slong, 1);
		else if (!(*slong)->call)
			put_enemy(*slong, -1);
		frame_counter = 0;
	}
	return (0);
}
