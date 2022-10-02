#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57)
		|| (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
