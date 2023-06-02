/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelchab <achabrer@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 09:51:08 by axelchab          #+#    #+#             */
/*   Updated: 2023/06/02 10:28:38 by axelchab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	animate_torche(t_game *game)
{
	t_point		pos;
	static int	i;

	if (!i || i == 5)
		i = 0;
	pos.y = 0;
	while (pos.y < game->map->width)
	{
		pos.x = 0;
		while (pos.x < game->map->length)
		{
			if (game->map->matrix[pos.y][pos.x] == TORCHE)
			{
				mlx_put_image_to_window(game->graph.mlx_ptr,
					game->graph.mlx_win, game->sp_torches[i].img,
					game->sp_torches[i].width * pos.x,
					game->sp_torches[i].height * pos.y);
			}
			pos.x++;
		}
		pos.y++;
	}
	usleep(500);
	i++;
	return (i);
}

void	animate_death(t_game *game)
{
	int	i;

	i = 1;
	while (i < 4)
	{
		mlx_put_image_to_window(game->graph.mlx_ptr, game->graph.mlx_win,
			game->p->sp_front[i].img, game->p->sp_front[i].width
			* game->p->pos.x, game->p->sp_front[i].height * game->p->pos.y);
		sleep(1);
		i++;
	}
}
