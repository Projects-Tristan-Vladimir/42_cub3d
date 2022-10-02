#include "cub3d.h"

void	use_minilibx(t_game *game)
{
	init_mlx(game);
	update_window(game);
	mlx_key_hook(game->win_ptr, &handle_keys, game);
	mlx_hook(game->win_ptr, RED_CROSS, 0L, &clear_program, game);
	mlx_loop(game->mlx_ptr);
}


int main(int argc, char **argv)
{
	//use_minilibx(&game);
	printf("coucou\n");
    return (0);
}