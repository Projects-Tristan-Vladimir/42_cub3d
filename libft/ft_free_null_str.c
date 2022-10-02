#include "libft.h"

void	ft_free_null_str(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}
