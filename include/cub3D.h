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
	int				win_width;
	int				win_length;
	char			*map;
	int				error;
}	t_game;





/* ********************* FUNCTIONS ********************* */

/* ********* INITIALIZATION ********* */

/* ********* PARSING ********* */
int	parse_map(t_game *game, char *filename);

/* ********* ERRORS ********* */

/* ********* UTILS ********* */

#endif
