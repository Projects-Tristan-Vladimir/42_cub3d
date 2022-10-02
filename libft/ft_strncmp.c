#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 1;
	while ((i < n) && str1[i - 1] && str2[i - 1])
	{
		if (str1[i - 1] != str2[i - 1])
			return (str1[i - 1] - str2[i - 1]);
		i++;
	}
	return (str1[i - 1] - str2[i - 1]);
}
