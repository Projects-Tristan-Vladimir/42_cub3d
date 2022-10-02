#include "cub3D.h"


void	ft_mlx_pixel_put(t_img_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	// the bytes are not aligned, this means that the line_length differs from the actual window width.
	// We therefore should ALWAYS calculate the memory offset using the line length set by mlx_get_data_addr.
	// int offset = (y * line_length + x * (bits_per_pixel / 8));
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
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
	game->win_ptr = mlx_new_window(game->mlx_ptr, 1920, 1080, "my game");
	game->img.img = mlx_new_image(game->mlx_ptr, 1920, 1080);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel, &game->img.line_length, &game->img.endian);
	printf("img data: bits_per_pixel=%d, line_length=%d, endian=%d\n",
		game->img.bits_per_pixel,
		game->img.line_length,
		game->img.endian
	);

	ft_mlx_pixel_put(&game->img, 50, 50, 0x00FF0000);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.img, 0, 0);
}

void	use_minilibx(t_game *game)
{
	init_mlx(game);
	// update_window();
	// mlx_key_hook(game->win_ptr, &handle_keys, game);
	// mlx_hook(game->win_ptr, RED_CROSS, 0L, &clear_program, game);
	mlx_loop(game->mlx_ptr);
}


int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_game	game;

	use_minilibx(&game);
    return (0);
}

// game->img_player = mlx_xpm_file_to_image(game->mlx_ptr,
// 		"./assets/player.xpm", &(game->img_width), &(game->img_height));
