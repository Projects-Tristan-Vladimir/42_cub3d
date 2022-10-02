#include "libft.h"

void	ft_bzero(void *ptr, size_t n)
{
	char	*s;

	s = (char *) ptr;
	while (n > 0)
	{
		s[n - 1] = 0;
		n--;
	}
}
