#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <signal.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "libft.h"
// # include "mlx.h"

typedef struct	s_img_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img_data;

/* ************** STRUCTURE PRINCIPALE ************** */
typedef struct s_game
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_img_data		img;
	char			**map;
	int				nb_rows;
	int				nb_cols;
	int				player_pos[2];
	int				player_dir[2];
	int				error;
}	t_game;

//******************** DEFINE KEYS ********************//

# define SCREEN_WIDTH	1920
# define SCREEN_HEIGHT	1080
# define FOV			45
# define KEY_ESC		53
# define KEY_UP			13
# define KEY_RIGHT		2
# define KEY_DOWN		1
# define KEY_LEFT		0
# define RED_CROSS		17

/* ********************* FUNCTIONS ********************* */

/* ********* INITIALIZATION ********* */

/* ********* PARSING ********* */
int	parse_map(t_game *game, char *filename);

/* ********* ERRORS ********* */

/* ********* UTILS ********* */

#endif
