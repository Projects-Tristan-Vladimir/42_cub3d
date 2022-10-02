#include "libft.h"

char	*ft_strndup(const char *s, int len)
{
	char	*dup;
	int		i;

	if (s == NULL)
		return (NULL);
	dup = ft_calloc(len + 1, sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
