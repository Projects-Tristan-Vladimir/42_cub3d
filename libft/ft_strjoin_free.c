#include "libft.h"

char	*ft_strjoin_free(char **s1, char **s2)
{
	char	*dst;
	size_t	dst_size;
	size_t	i;
	size_t	j;

	if (!*s1 && !*s2)
		return (NULL);
	dst_size = ft_strlen(*s1) + ft_strlen(*s2) + 1;
	dst = ft_calloc(dst_size, sizeof(char));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, *s1, dst_size);
	j = 0;
	i = ft_strlen(dst);
	while ((*s2)[j] && (i + j + 1 < dst_size))
	{
		dst[i + j] = (*s2)[j];
		j++;
	}
	if (i != dst_size)
		dst[i + j] = 0;
	ft_free_null_str(s1);
	ft_free_null_str(s2);
	return (dst);
}
