#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dst;
	size_t	len;

	while (is_in_charset(*s1, set))
		s1++;
	len = ft_strlen(s1);
	if (len > 0)
	{
		while (is_in_charset(s1[len - 1], set))
			len--;
	}
	dst = ft_calloc(len + 1, sizeof(char));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s1, len + 1);
	return (dst);
}
