/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evente.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sellyani <sellyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:56:32 by sellyani          #+#    #+#             */
/*   Updated: 2025/03/07 00:58:08 by sellyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_ft(t_map *slong)
{
	mlx_destroy_image(slong->mlx, slong->mlx_img);
	slong->mlx_img = mlx_xpm_file_to_image(slong->mlx, ODOOR,
			&slong->h_map, &slong->w_map);
	mlx_put_image_to_window(slong->mlx, slong->mlx_win, slong->mlx_img,
		slong->y_e * SIZE, slong->x_e * SIZE);
}

void	demi_move(t_map *slong, int i, int j, bool sign)
{
	if (i == 1 && !j)
		slong->mlx_img = mlx_xpm_file_to_image(slong->mlx,
				PMAN_D, &slong->h_map, &slong->w_map);
	else if (i == -1 && !j)
		slong->mlx_img = mlx_xpm_file_to_image(slong->mlx,
				PMAN_U, &slong->h_map, &slong->w_map);
	else if (!i && j == 1)
		slong->mlx_img = mlx_xpm_file_to_image(slong->mlx,
				PMAN_R, &slong->h_map, &slong->w_map);
	else if (!i && j == -1)
		slong->mlx_img = mlx_xpm_file_to_image(slong->mlx,
				PMAN_L, &slong->h_map, &slong->w_map);
	if (sign)
		mlx_put_image_to_window(slong->mlx, slong->mlx_win, slong->mlx_img,
			(slong->y_p + j) * SIZE, (slong->x_p + i) * SIZE);
	else
		mlx_put_image_to_window(slong->mlx, slong->mlx_win, slong->mlx_img,
			slong->y_p * SIZE, slong->x_p * SIZE);
}

void	put_move(t_map *slong, int i, int j)
{
	char	*str;
	char	*dmp;

	mlx_destroy_image(slong->mlx, slong->mlx_img);
	slong->mlx_img = mlx_xpm_file_to_image(slong->mlx,
			SPACE, &slong->h_map, &slong->w_map);
	mlx_put_image_to_window(slong->mlx, slong->mlx_win, slong->mlx_img,
		(slong->y_p) * SIZE, (slong->x_p) * SIZE);
	mlx_destroy_image(slong->mlx, slong->mlx_img);
	demi_move(slong, i, j, true);
	slong->x_p += i;
	slong->y_p += j;
	mlx_destroy_image(slong->mlx, slong->mlx_img);
	slong->mlx_img = mlx_xpm_file_to_image(slong->mlx,
			WALL, &slong->h_map, &slong->w_map);
	mlx_put_image_to_window(slong->mlx, slong->mlx_win, slong->mlx_img, 0, 0);
	dmp = ft_itoa(slong->move);
	str = ft_strjoin("MV:", dmp);
	free(dmp);
	mlx_string_put(slong->mlx, slong->mlx_win, 5, 15, 0x00ffff, str);
	free(str);
	printf("move : %d\n", slong->move);
}

void	ft_go(t_map **slong, int i, int j)
{
	if ((*slong)->map[(*slong)->x_p + i][(*slong)->y_p + j] == '1' ||
		(*slong)->map[(*slong)->x_p + i][(*slong)->y_p + j] == 'E' &&
		(*slong)->collect)
		return (demi_move(*slong, i, j, false));
	if ((*slong)->map[(*slong)->x_p + i][(*slong)->y_p + j] == 'C' ||
		(*slong)->map[(*slong)->x_p + i][(*slong)->y_p + j] == '0')
	{
		if ((*slong)->map[(*slong)->x_p + i][(*slong)->y_p + j] == 'C')
			(*slong)->collect -= 1;
		(*slong)->map[(*slong)->x_p][(*slong)->y_p] = '0';
		(*slong)->map[(*slong)->x_p + i][(*slong)->y_p + j] = 'P';
		(*slong)->move += 1;
	}
	else if ((*slong)->map[(*slong)->x_p + i][(*slong)->y_p + j] == 'E' &&
		!(*slong)->collect)
	{
		ft_putendl_fd("You Win :)", 1);
		fr_stack(*slong);
		mlx_destroy_window((*slong)->mlx, (*slong)->mlx_win);
		exit(0);
	}
	if (!(*slong)->collect)
		ft_ft(*slong);
	put_move(*slong, i, j);
}

int	ft_hook(int prees, t_map **slong)
{
	if (prees == 1)
		ft_go(slong, 1, 0);
	else if (prees == 13)
		ft_go(slong, -1, 0);
	else if (prees == 2)
		ft_go(slong, 0, 1);
	else if (prees == 0)
		ft_go(slong, 0, -1);
	else if (prees == 53)
	{
		ft_putendl_fd("Exit :(", 1);
		free_double((*slong)->map);
		mlx_destroy_window((*slong)->mlx, (*slong)->mlx_win);
		exit(1);
	}
	return (1);
}
