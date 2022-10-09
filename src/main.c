#include "cub3D.h"

void	ft_mlx_pixel_put(t_img_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	// the bytes are not aligned, this means that the line_length differs from the actual window width.
	// We therefore should ALWAYS calculate the memory offset using the line length set by mlx_get_data_addr.
	// int offset/index = (y * line_length + x * (bits_per_pixel / 8));
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	update_window(t_game *game)
{
	int	x;
	int	y;

	x = 120;
	while (x < game->win_width)
	{
		y = 20;
		while (y < 40)
		{
			ft_mlx_pixel_put(&game->img, x, y, 0x00FF0000);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
	game->img.img, 0, 0);
}

// voir ce tuto pour l'initialisation d'une fenetre avec la mlx : https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html
void	init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
	{
		ft_putstr_fd("Error\n", 1);
		// clear_program(game);
	}

	//https://aurelienbrabant.fr/blog/pixel-drawing-with-the-minilibx#Screen-metrics
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->win_width, game->win_length, "my game");
	// drawing img on screen : https://aurelienbrabant.fr/blog/pixel-drawing-with-the-minilibx#Using-minilibx-images-to-draw-on-the-screen
	game->img.img = mlx_new_image(game->mlx_ptr, game->win_width, game->win_length);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel, &game->img.line_length, &game->img.endian);
	printf("img data: bits_per_pixel=%d, line_length=%d, endian=%d\n",
		game->img.bits_per_pixel,
		game->img.line_length,
		game->img.endian
	);
}

void	use_minilibx(t_game *game)
{
	init_mlx(game);
	update_window(game);
	mlx_loop(game->mlx_ptr);
}

void init_variables(t_game *game)
{
	// ft_memset(game, 0, sizeof(game));
	game->win_width = 1920;
	game->win_length = 1080;
}

int main(int argc, char **argv)
{
	t_game	game;
	printf("%d\n",argc);
	if (argc != 2)
		return (1);
	init_variables(&game);
	if (parse_map(&game, argv[1]))
		return (1);

	use_minilibx(&game);
	return (0);
}
