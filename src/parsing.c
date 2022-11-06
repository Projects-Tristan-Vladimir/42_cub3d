#include "cub3D.h"

int	open_file_check(int fd, char *filename)
{
	
	if (fd == -1)
	{
		ft_putstr_fd(filename, 2);
		if (errno == 13)
			ft_putstr_fd(": Permission denied\n", 2);
		else if (errno == 2)
			ft_putstr_fd(": No such file or directory\n", 2);
		else
			ft_putstr_fd(": An error occured\n", 2);
		return (1);
	}
	return (0);
}

// coordonnées (de départ pour l'instant) du joueur
void	update_player_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->nb_rows)
	{
		j = 0;
		while (j < game->nb_cols)
		{
			if (is_in_charset(game->map[i][j], "NSEW"))
			{
				game->player_pos[0] = j;
				game->player_pos[1] = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

// composants du vecteur direction du joueur
void	update_player_direction(t_game *game)
{
	game->player_dir[0] = 1;
	game->player_dir[1] = 0;
}

void	update_map_details(t_game *game)
{
	//count map rows and columns
	while (game->map[game->nb_rows])
		game->nb_rows++;
	game->nb_cols = (int)ft_strlen(game->map[0]);
	update_player_direction(game);
	update_player_position(game);
}

int	parse_map(t_game *game, char *filename)
{
	int		fd;
	char	*data;
	ssize_t	len_file;

	//0) check if file is readable
	fd = open(filename, O_RDONLY);
	if (open_file_check(fd, filename))
		return (1);

	//1) Read file data
	data = ft_calloc(100000, sizeof(char));
	len_file = read(fd, data, 100000);
	if (len_file < 0)
	{
		printf("errno=%d\n", errno);
		printf("read error : %s\n", strerror(errno));
	}
	data[len_file] = 0;
	//2) check if all requirements are in file

	//3) check if map is valid

	//4) store data in variables
		//4-a) store map data : map, number of rows and columns ....
		game->map = ft_split(data, '\n');
		update_map_details(game);

	close(fd);
	return (0);
}
