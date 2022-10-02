#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t n)
{
	unsigned int	i;
	char			*s;

	i = 0;
	s = (char *) ptr;
	while (i < n)
	{
		s[i] = (unsigned char) c;
		i++;
	}
	return (ptr);
}
