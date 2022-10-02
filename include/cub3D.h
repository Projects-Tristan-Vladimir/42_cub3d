#ifndef CUB3D_H
# define CUB3D_H

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

/* ********************* EXIT STATUS ********************* */

// typedef enum s_exit_status
// {
// 	SUCCESS = 0,
// 	FAILURE = 1,
// 	MAJOR_FAILURE = 2,
// 	CMD_NOT_FOUND = 127,
// 	PGM_ABORTED = 132,
// 	INVALID_EXIT = 255
// }	t_exit_status;

/* ************** STRUCTURE PRINCIPALE ************** */
// typedef struct s_sh
// {
// 	char			**env;
// 	t_token			*token_lst;
// 	t_cmd_line		*cmd_line_lst;
// 	t_exit_status	exit_status;
// 	char			*prompt;
// 	int				p_index;
// 	int				p_quote;
// 	int				error;
// 	int				has_pipe;
// }	t_sh;

/* ********************* FUNCTIONS ********************* */

/* ********* INITIALIZATION ********* */

/* ********* ERRORS ********* */

/* ********* UTILS ********* */

#endif
