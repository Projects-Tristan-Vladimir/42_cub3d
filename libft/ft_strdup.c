#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*dst;
	int		i;
	int		len_src;

	if (src == NULL)
		return (NULL);
	len_src = ft_strlen(src);
	dst = ft_calloc(len_src + 1, sizeof(char));
	if (!dst)
		return (0);
	i = 0;
	while (src[i] != 0)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
