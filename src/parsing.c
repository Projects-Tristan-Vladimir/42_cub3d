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

int	parse_map(t_game *game, char *filename)
{
	int		fd;
	char	*data;
	ssize_t	count;
	(void)game;
	//0) check if file is readable
	fd = open(filename, O_RDONLY);
	if (open_file_check(fd, filename))
		return (1);

	//1) Read file data
	data = NULL;
	count = read(fd, data, 2000);

	printf("%s\n", data);
	//2) check if all requirements are in file

	//3) check if map is valid

	//4) store data in variables
		//4-a) store map data


	return (0);
}
